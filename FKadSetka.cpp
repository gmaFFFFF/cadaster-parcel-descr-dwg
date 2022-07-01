//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FKadSetka.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TFDrawKadSetka *FDrawKadSetka;
//---------------------------------------------------------------------------
__fastcall TFDrawKadSetka::TFDrawKadSetka(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFDrawKadSetka::Button1Click(TObject *Sender)
{
	//Получение автокада...
	try
	{
		acad = new cACAD(false);
	}
	catch(...)
	{
		ShowMessage("AutoCAD не запущен");
		return;
	}

	SetMaxMinCoordParcel();
	SetMaxMinCoordKwartal();
	CalcDrawingScale();
	acad->DrawKadSetka(scaleDrawing,ParcelMaxCoord,ParcelMinCoord,KwartalMaxCoord,KwartalMinCoord);

	delete acad;
}
//---------------------------------------------------------------------------
void TFDrawKadSetka::SetMaxMinCoordParcel()
{
	//Расчет MAX и MIN координаты границы участка...
	list<CAutoCADPoint> a_points;
	Parcel parc;

	switch(RGSourceCoord->ItemIndex)
	{
	case(0): 			//Координаты участка определить по точкам
		acad->GetPoints(a_points);
		if(!a_points.empty())
			break;
	case(1):            //Координаты участка определить по полилинии
		acad->GetSelectParcel(parc,"Укажите участок...");
		a_points = parc.GetPoints();
	}

	list<CAutoCADPoint>::const_iterator tek = a_points.begin();

	ParcelMaxCoord.SetNord(tek->GetNord());
	ParcelMaxCoord.SetEast(tek->GetEast());
	ParcelMinCoord.SetNord(tek->GetNord());
	ParcelMinCoord.SetEast(tek->GetEast());
	tek++;
	for(;tek != a_points.end();tek++)
	{
		double nord = tek->GetNord();
		double east = tek->GetEast();

		if(ParcelMaxCoord.GetNord() < nord)
			ParcelMaxCoord.SetNord(nord);
		if(ParcelMaxCoord.GetEast() < east)
			ParcelMaxCoord.SetEast(east);

		if(ParcelMinCoord.GetNord() > nord)
			ParcelMinCoord.SetNord(nord);
		if(ParcelMinCoord.GetEast() > east)
			ParcelMinCoord.SetEast(east);
	}
}
//---------------------------------------------------------------------------
void TFDrawKadSetka::SetMaxMinCoordKwartal()
{
	list<CAutoCADPoint> a_points;
	Parcel parc;

	acad->GetSelectParcel(parc,"Укажите квартал...");
	a_points = parc.GetPoints();

	list<CAutoCADPoint>::const_iterator tek = a_points.begin();

	KwartalMaxCoord.SetNord(tek->GetNord());
	KwartalMaxCoord.SetEast(tek->GetEast());
	KwartalMinCoord.SetNord(tek->GetNord());
	KwartalMinCoord.SetEast(tek->GetEast());
	tek++;
	for(;tek != a_points.end();tek++)
	{
		double nord = tek->GetNord();
		double east = tek->GetEast();

		if(KwartalMaxCoord.GetNord() < nord)
			KwartalMaxCoord.SetNord(nord);
		if(KwartalMaxCoord.GetEast() < east)
			KwartalMaxCoord.SetEast(east);

		if(KwartalMinCoord.GetNord() > nord)
			KwartalMinCoord.SetNord(nord);
		if(KwartalMinCoord.GetEast() > east)
			KwartalMinCoord.SetEast(east);
	}
}
//---------------------------------------------------------------------------
void TFDrawKadSetka::CalcDrawingScale()
{

	if(RGScale->ItemIndex == 0)  //Определить масштаб автоматически
	{
		double defVPHeight = 230;
		double defVPWidth = 180;
		const float scaleMultip = 1.1;

		CPoint bottomRight("",ParcelMinCoord.GetNord(),ParcelMaxCoord.GetEast());
		CPoint topLeft("",ParcelMaxCoord.GetNord(),ParcelMinCoord.GetEast());

		float scaleX = CalculateLength(ParcelMinCoord,bottomRight)/defVPWidth*scaleMultip;
		float scaleY = CalculateLength(ParcelMinCoord,topLeft)/defVPHeight*scaleMultip;
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
	else						//Использовать пользовательское значение
		scaleDrawing = (double)CSEScale->Value / 1000;

}
//---------------------------------------------------------------------------
