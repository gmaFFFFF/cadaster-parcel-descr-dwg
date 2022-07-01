//---------------------------------------------------------------------------
#include <math.h>
#include <ComObj.hpp>
#include <algorithm>
#pragma hdrstop

#include "cACAD.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace Autocad_tlb;
namespace
{
	Variant nameLayout("Чертеж на A4");		//Название листа с чертежом
	double viewPortWidth;               	//Ширина видового экрана
	double viewPortHeight;              	//Высота видового экрана

	float scaleDrawing;                    	//Масштаб видового экрана,расчетный
	CPoint minLimitDrawing;                 //Предел чертежа минимальный
	CPoint maxLimitDrawing;                 //Предел чертежа максимальный

	const CPoint insertScaletext("",30,85); //Точка вставки масштаба чертежа

}
cACAD::cACAD(bool new_app):
newApp(new_app)
{
	if (newApp)
	{
		//Запускаем автокад, по умолчанию он скрыт
		Variant v = CreateOleObject("AutoCAD.Application");
		//В типе Variant предусмотрен оператор приведения типа к IDispatch*
		IDispatch* pServ = v;
		//Как-то инициализируем указатель на AcadApplication
		pServ->QueryInterface(IID_IAcadApplication,(void**)&acad);

		//Закрываем чертеж созданный по умолчанию
		acad->Documents->Close();
	}
	else
	{
		//Ищем запущенный экземпляр автокада
		Variant v = GetActiveOleObject("AutoCAD.Application");
		//В типе Variant предусмотрен оператор приведения типа к IDispatch*
		IDispatch* pServ = v;
		//Как-то инициализируем указатель на AcadApplication
		pServ->QueryInterface(IID_IAcadApplication,(void**)&acad);
    }
}
//---------------------------------------------------------------------------
cACAD::~cACAD()
{
	if(newApp)
		acad->Quit();				//Закрыть чертежи и выйти
	else
		acad->Release();
}
//---------------------------------------------------------------------------
void cACAD::NewDrawing(const string& templateFileName)  //Имя шаблона
{
	AcadDocument* doc;
	acad->Documents->Add(Variant(templateFileName.c_str()),&doc);

	//Делаем активной закладку с чертежом
	acad->ActiveDocument->ActiveLayout = acad->ActiveDocument->Layouts->Item(nameLayout);
	//переходим в модель видового экрана
	acad->ActiveDocument->MSpace = true;
	//получаем указатель на видовой экран листа
	acad->ActiveDocument->get_ActivePViewport(&viewPort);
	//Считываем размеры видового экрана
	viewPortWidth  = viewPort->Width;
	viewPortHeight = viewPort->Height;
}
//---------------------------------------------------------------------------
void cACAD::SaveDrawingAndClose(const string& fileName)
{
	acad->ActiveDocument->SaveAs(Variant(fileName.c_str()),Variant(acNative));
	acad->Documents->Close();
	//Пришлось добавить сюда, чтобы отключить видимость приложения включенного в BuildLayout
	acad->Visible = false;
}
//---------------------------------------------------------------------------
void cACAD::WriteKadastrLine(const CKadastrLine& line)
{
	Variant StartPoint = GetCoord(line.GetBeginPoint());
	Variant EndPoint   = GetCoord(line.GetEndPoint());

	IAcadLine* acLine;
	//Рисуем линию
	acad->ActiveDocument->ModelSpace->AddLine(StartPoint,EndPoint,&acLine);

	//Переносим линию в нужный слой
	switch(line.GetType())
	{
	case (tl_EXIST):
		acLine->set_Layer(Variant("Линии существующие"));
		break;
	case (tl_NEW):
		acLine->set_Layer(Variant("Линии новые"));
		break;
	case (tl_Uto4n):
		acLine->set_Layer(Variant("Линии уточненные"));
		break;
	}
}
//---------------------------------------------------------------------------
void cACAD::WriteKadastrLines(const list<CKadastrLine>& lines)
{
	//Записываем все линии в файл методом WriteKadastrLine
	std::for_each(lines.begin(),lines.end(),&WriteKadastrLine);
}
//---------------------------------------------------------------------------
AcadBlockReference* cACAD::WriteKadastrPoint(const CPoint& point,double scale)
{
	if(scale != 0)
		scaleDrawing = scale;
	Variant insertPoint = GetCoord(point);

	AcadBlockReference* block;
	//Вставляем блок
	acad->ActiveDocument->ModelSpace->InsertBlock(insertPoint,Variant("Точка"),
		  Variant(scaleDrawing),Variant(scaleDrawing),Variant(scaleDrawing),
		  Variant(0),Variant(""),&block);


	if(newApp)
		//Переносим в слой "Точки" шаблона
		block->set_Layer(Variant("Точки"));

	AcadAttributeReference* atr = NULL;
	Variant v_atr;
	//Считываем атрибуты блока
	block->GetAttributes(v_atr);
	//получаем указатель на атрибуты
	IDispatch* d_atr = v_atr.GetElement(0);
	d_atr->QueryInterface(IID_IAcadAttributeReference,(void**)&atr);
	//присваиваем имя точки
	atr->TextString = Variant(point.GetName().c_str());
	atr->Release();
	return block;
}
//---------------------------------------------------------------------------
void cACAD::WriteKadastrPoints(const list<CPoint>& points)
{
	//Определяем рекомендуемый масштаб рисунка
	CalculateScaleVP(points);
	//Записываем все точки в файл методом WriteKadastrPoint
	std::for_each(points.begin(),points.end(),&WriteKadastrPoint);
}
//---------------------------------------------------------------------------
void cACAD::CalculateScaleVP(const list<CPoint>& points) const
{
    //Устанавливаем минимальные и максимальные пределы чертежа равными первой точки
    minLimitDrawing = *(points.begin());
    maxLimitDrawing = *(points.begin());
	//Уточняем максимальные и минимальные пределы чертежа по другим точкам
	std::for_each(points.begin(),points.end(),&SetMaxMinLimit);
	//Определяем необходимый масштаб видового экрана
	const float scaleMultip = 1.1;
	CPoint bottomRight("",minLimitDrawing.GetNord(),maxLimitDrawing.GetEast());
	CPoint topLeft("",maxLimitDrawing.GetNord(),minLimitDrawing.GetEast());
	float scaleX = CalculateLength(minLimitDrawing,bottomRight)/viewPortWidth*scaleMultip;
	float scaleY = CalculateLength(minLimitDrawing,topLeft)/viewPortHeight*scaleMultip;
	float scale = max(scaleX,scaleY);
	//Устанавливаем для чертежа стандартный масштабы
	if (scale > 200)
		scaleDrawing = 250;             //М 1:250 000
	else if(scale > 100)
		scaleDrawing = 200;             //М 1:200 000
	else if(scale > 50)
		scaleDrawing = 100;             //М 1:100 000
	else if(scale > 25)
		scaleDrawing = 50;              //М 1:50 000
	else if(scale > 15)
		scaleDrawing = 25;              //М 1:25 000
	else if(scale > 10)
		scaleDrawing = 15;              //М 1:15 000
	else if(scale > 5)
		scaleDrawing = 10;              //М 1:10 000
	else if(scale > 2)
		scaleDrawing = 5;               //М 1:5 000
	else if(scale > 1)
		scaleDrawing = 2;               //М 1:2 000
	else if(scale > 0.5)
		scaleDrawing = 1;               //М 1:1 000
	else if(scale > 0.1)
		scaleDrawing = 0.5;             //М 1:500
	else
		scaleDrawing = 0.1;             //М 1:100

}
//---------------------------------------------------------------------------
void cACAD::SetMaxMinLimit(const CPoint& point)const
{
	double nord = point.GetNord();
	double east = point.GetEast();

	if(maxLimitDrawing.GetNord() < nord)
		maxLimitDrawing.SetNord(nord);
	if(maxLimitDrawing.GetEast() < east)
		maxLimitDrawing.SetEast(east);

	if(minLimitDrawing.GetNord() > nord)
		minLimitDrawing.SetNord(nord);
	if(minLimitDrawing.GetEast() > east)
		minLimitDrawing.SetEast(east);
}
//---------------------------------------------------------------------------
void cACAD::BuildLayout()
{
	//Иначе не работает ZoomExtents
	acad->Visible = true;
	acad->ZoomExtents();
	//выходим из модели
	acad->ActiveDocument->MSpace = false;

	//Устанавливаем масштаб
	viewPort->StandardScale = acVpCustomScale;    //Для доступности CustomScale
	viewPort->CustomScale = Variant(1 / float(scaleDrawing));
	//подписываем масштаб
	AnsiString scaleText = "Масштаб 1 : " + IntToStr(int(scaleDrawing*1000));
	acad->ActiveDocument->PaperSpace->AddMText(GetCoord(insertScaletext),35,Variant(scaleText.c_str()));

	//Делаем изображение видового экрана закрытым
	viewPort->DisplayLocked = Variant(true);
}
//---------------------------------------------------------------------------
Variant cACAD::GetCoord(const CPoint& point,double z)
{
	Variant temp(OPENARRAY(int,(0,2)),varDouble);
	temp.PutElement(point.GetEast(),0);	   				//координата Х
	temp.PutElement(point.GetNord(),1);     			//координаты у
	temp.PutElement(0.0,2);                             //координата z
	return temp;
}
//---------------------------------------------------------------------------
bool cACAD::GetSelectParcel(Parcel& p,AnsiString msg)const
{
	IDispatch* disp=0;
	AcadObject* obj=0;
	AcadLWPolyline* pline=0;
	Variant Pickedpoint;

	acad->ActiveDocument->Utility->GetEntity(&disp,Pickedpoint,Variant(msg.c_str()));
	if(!disp)
		return false;
	disp->QueryInterface(IID_IAcadObject,(void**)&obj);
	if(obj->ObjectName == Variant("AcDbPolyline"))
	{
		obj->Release();
		disp->QueryInterface(IID_IAcadLWPolyline,(void**)&pline);
	}
	else
		return false;
	Variant coord;
	list<CAutoCADPoint> points;
	pline->get_Coordinates(coord);
	for(int i = coord.ArrayLowBound(); i <= coord.ArrayHighBound();)
	{
		double nord,east;
		east = coord.GetElement(i);
		i++;
		nord = coord.GetElement(i);
		i++;
		points.push_back(CAutoCADPoint("",nord,east));
	}
	pline->Release();
	p.SetPoints(points);

	return true;
}
//---------------------------------------------------------------------------
void cACAD::GetPoints(list<CAutoCADPoint>& points)const
{
	IAcadEntity* obj=NULL;

	int count = acad->ActiveDocument->ModelSpace->Count;
	for(int i = 0; i < count; i++)
	{
		acad->ActiveDocument->ModelSpace->Item(Variant(i),&obj);

		if(obj->ObjectName == Variant("AcDbBlockReference"))
		{
			IAcadBlockReference* bl = NULL;
			AcadAttributeReference* atr = NULL;
			Variant v_atr;
			//Получаем указатель на блок
			obj->QueryInterface(IID_IAcadBlockReference,(void**)&bl);
			if(bl->Name != Variant("Точка"))
			{      
				bl->Release();
				continue;
			}
			//Считываем атрибуты блока
			bl->GetAttributes(v_atr);
			//получаем указатель на атрибуты
			IDispatch* d_atr = v_atr.GetElement(0);
			d_atr->QueryInterface(IID_IAcadAttributeReference,(void**)&atr);
			//Получаем точку вставки блока
			Variant insPoint;
			bl->get_InsertionPoint(insPoint);

			CAutoCADPoint point;
			point.SetNord(insPoint.GetElement(1));
			point.SetEast(insPoint.GetElement(0));
			point.SetName(atr->TextString);
			points.push_back(point);

			atr->Release();
			bl->Release();
		}    
	}
}
//---------------------------------------------------------------------------
void cACAD::DrawKadSetka(double scale,CPoint ParcelMaxCoord,CPoint ParcelMinCoord,
CPoint KwartalMaxCoord, CPoint KwartalMinCoord)
{
	double textH = 2;
	textH *= scale;
	double otstup = textH * 2;

	//Рисуем внутреннюю рамку...
	IAcadLine* acLine;
	Variant StartPoint = GetCoord(ParcelMinCoord);
	Variant EndPoint   = GetCoord(CPoint("",ParcelMaxCoord.GetNord(),ParcelMinCoord.GetEast()));
	acad->ActiveDocument->ModelSpace->AddLine(StartPoint,EndPoint,&acLine);

	StartPoint = GetCoord(CPoint("",ParcelMaxCoord.GetNord(),ParcelMinCoord.GetEast()));
	EndPoint   = GetCoord(ParcelMaxCoord);
	acad->ActiveDocument->ModelSpace->AddLine(StartPoint,EndPoint,&acLine);

	StartPoint = GetCoord(ParcelMaxCoord);
	EndPoint   = GetCoord(CPoint("",ParcelMinCoord.GetNord(),ParcelMaxCoord.GetEast()));
	acad->ActiveDocument->ModelSpace->AddLine(StartPoint,EndPoint,&acLine);

	StartPoint = GetCoord(CPoint("",ParcelMinCoord.GetNord(),ParcelMaxCoord.GetEast()));
	EndPoint   = GetCoord(ParcelMinCoord);
	acad->ActiveDocument->ModelSpace->AddLine(StartPoint,EndPoint,&acLine);

	//Рисуем внешнюю рамку...
	CPoint ramMinCoord("",ParcelMinCoord.GetNord() - otstup,ParcelMinCoord.GetEast() - otstup);
	CPoint ramMaxCoord("",ParcelMaxCoord.GetNord() + otstup,ParcelMaxCoord.GetEast() + otstup);
	StartPoint = GetCoord(ramMinCoord);
	EndPoint   = GetCoord(CPoint("",ramMaxCoord.GetNord(),ramMinCoord.GetEast()));
	acad->ActiveDocument->ModelSpace->AddLine(StartPoint,EndPoint,&acLine);

	StartPoint = GetCoord(CPoint("",ramMaxCoord.GetNord(),ramMinCoord.GetEast()));
	EndPoint   = GetCoord(ramMaxCoord);
	acad->ActiveDocument->ModelSpace->AddLine(StartPoint,EndPoint,&acLine);

	StartPoint = GetCoord(ramMaxCoord);
	EndPoint   = GetCoord(CPoint("",ramMinCoord.GetNord(),ramMaxCoord.GetEast()));
	acad->ActiveDocument->ModelSpace->AddLine(StartPoint,EndPoint,&acLine);

	StartPoint = GetCoord(CPoint("",ramMinCoord.GetNord(),ramMaxCoord.GetEast()));
	EndPoint   = GetCoord(ramMinCoord);
	acad->ActiveDocument->ModelSpace->AddLine(StartPoint,EndPoint,&acLine);

	//Расчитываем интервал через которой проходит сетка
	double intervalEast = (KwartalMaxCoord.GetEast() - KwartalMinCoord.GetEast())/10;
	double intervalNord = (KwartalMaxCoord.GetNord() - KwartalMinCoord.GetNord())/10;

	char* horDel = "АБВГДЕЖИКЛ";
	char* verDel = "9876543210";

	IAcadMText* acText;
	//Вычерчиваем вертикальную сетку
	for(int i = 0; i <= 10; i++)
	{
		double left = KwartalMinCoord.GetEast() + intervalEast * i;
		double right = KwartalMinCoord.GetEast() + intervalEast * (i + 1);
		double nord_up = ParcelMaxCoord.GetNord();
		double nord_down = ParcelMinCoord.GetNord();

		if((ParcelMinCoord.GetEast() - left) > intervalEast)
			continue;
		else if(left > ParcelMaxCoord.GetEast())
			break;

		if(left >= ParcelMinCoord.GetEast())
		{
			StartPoint = GetCoord(CPoint("",nord_up,left));
			EndPoint   = GetCoord(CPoint("",nord_up+otstup,left));
			acad->ActiveDocument->ModelSpace->AddLine(StartPoint,EndPoint,&acLine);
			StartPoint = GetCoord(CPoint("",nord_down,left));
			EndPoint   = GetCoord(CPoint("",nord_down-otstup,left));
			acad->ActiveDocument->ModelSpace->AddLine(StartPoint,EndPoint,&acLine);
		}
		if (i < 10)
		{
			if (left < ParcelMinCoord.GetEast())
				left = ParcelMinCoord.GetEast();
			if (right > ParcelMaxCoord.GetEast())
				right = ParcelMaxCoord.GetEast();

			double interval = right - left;
			if (interval < textH)
				continue;

			double insCoordE = left + interval/2 - textH/2;
			Variant str = AnsiString(horDel[i]);
			acad->ActiveDocument->ModelSpace->AddMText(GetCoord(CPoint("",nord_up+otstup - (otstup - textH)/2,insCoordE)),textH,str,&acText);
			acText->Height = textH;
			acad->ActiveDocument->ModelSpace->AddMText(GetCoord(CPoint("",nord_down - (otstup - textH)/2,insCoordE)),textH,str,&acText);
			acText->Height = textH;
		}
	}
	//Вычерчиваем горизонтальную сетку
	for(int i = 0; i <= 10; i++)
	{
		double down = KwartalMinCoord.GetNord() + intervalNord * i;
		double up = KwartalMinCoord.GetNord() + intervalNord * (i + 1);
		double east_right = ParcelMaxCoord.GetEast();
		double east_left = ParcelMinCoord.GetEast();

		if((ParcelMinCoord.GetNord() - down) > intervalNord)
			continue;
		else if(down > ParcelMaxCoord.GetNord())
			break;

		if(down >= ParcelMinCoord.GetNord())
		{
			StartPoint = GetCoord(CPoint("",down,east_left));
			EndPoint   = GetCoord(CPoint("",down,east_left - otstup));
			acad->ActiveDocument->ModelSpace->AddLine(StartPoint,EndPoint,&acLine);
			StartPoint = GetCoord(CPoint("",down,east_right));
			EndPoint   = GetCoord(CPoint("",down,east_right + otstup));
			acad->ActiveDocument->ModelSpace->AddLine(StartPoint,EndPoint,&acLine);
		}
		if (i < 10)
		{
			if (down < ParcelMinCoord.GetNord())
				down = ParcelMinCoord.GetNord();
			if (up > ParcelMaxCoord.GetNord())
				up = ParcelMaxCoord.GetNord();

			double interval = up - down;
			if (interval < textH)
				continue;

			double insCoordN = down + interval/2 + textH/2;
			Variant str = AnsiString(verDel[i]);
			acad->ActiveDocument->ModelSpace->AddMText(GetCoord(CPoint("",insCoordN,east_left  - otstup*0.5 - textH/3)),textH,str,&acText);
			acText->Height = textH;
			acad->ActiveDocument->ModelSpace->AddMText(GetCoord(CPoint("",insCoordN,east_right + otstup*0.5 - textH/3)),textH,str,&acText);
			acText->Height = textH;
		}

	}
}
