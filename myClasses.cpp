//---------------------------------------------------------------------------

#include <math.h>
#include <algorithm>
#pragma hdrstop

#include "cACAD.h"
#include "myClasses.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

float CAutoCADPoint::dopusk = 0;
int CPoint::digits = 2;

CAngle CalculateDirectAngle(CPoint begin,CPoint end)
{
	double dx,dy,rumb;
	dx = end.GetNord() - begin.GetNord();
	dy = end.GetEast() - begin.GetEast();
	rumb = atan2(dy,dx)*180/M_PI;
	if (dx>=0 && dy>=0)
		;  
	else if (dx<=0 && dy >= 0)
		rumb += 0;  
	else if (dx<=0 && dy <= 0)
		rumb += 360;
	else if (dx>=0 && dy <= 0)
		rumb += 360;
	return CAngle(rumb);
}
double CalculateLength(CPoint begin,CPoint end)
{
	double dx,dy;
	dx = end.GetNord() - begin.GetNord();
	dy = end.GetEast() - begin.GetEast();
	return sqrt(dx*dx+dy*dy);
}
//---------------------------------------------------------------------------
bool LoadPointFromFile(string file_name,list<CPoint>& list_point)
{
	char name[5];
	double nord,east;
	CPoint temp;
	ifstream fin (file_name.c_str());
	if(!fin)
		return false;
	while(!fin.eof())
	{
		if(fin.peek() == ' ' || fin.peek() == EOF || fin.peek() == '\n')
        	break;
		//Считываем имя точки
		fin.get(name,5,',');
		//Пропускаем пробелы и запятые после имени
		char delim;
		while((delim = fin.peek()) == ',' || delim == ' ')
			fin.get();
		//Считываем координату Х
		fin>>nord;
		//Пропускаем пробелы и запятые после координаты
		while((delim = fin.peek()) == ',' || delim == ' ')
			fin.get();
		//Считываем координату Y
		fin>>east;
		//пропускаем все символы до конца строки
		fin.ignore(256,'\n');
        //Добавляем точку в список.
		temp.SetPoint(name,nord,east);
		list_point.push_back(temp);
	}
	fin.close();
	//если первая и последняя точки в файле одинаковые, то удаляем последнюю
	if(list_point.front().GetName() == list_point.back().GetName())
		list_point.pop_back();

	return true;
}
//---------------------------------------------------------------------------


CPoint::CPoint(AnsiString name,double nord,double east):
my_point_name(name),my_nord(nord),my_east(east)
{
	if(name == "")
		my_type = tp_UNKNOWN;
	else
		my_type = (name[1]=='н'||name[1]=='Н') ? tp_NEW  : tp_EXIST;
}
//---------------------------------------------------------------------------
CPoint::CPoint(const CPoint& rhs)
{
	my_nord = rhs.GetNord();
	my_east = rhs.GetEast();
	SetName (rhs.GetName());
}
//---------------------------------------------------------------------------
CPoint& CPoint::operator = (const CPoint& rhs)
{
	if(&rhs == this)
		return *this;
	my_nord = rhs.GetNord();
	my_east = rhs.GetEast();
	SetName (rhs.GetName());
	return *this;
}
//---------------------------------------------------------------------------
bool CPoint::operator < (const CPoint& rhs)const
{
	if(rhs.my_type == tp_EXIST && my_type == tp_EXIST)
		return (StrToInt(my_point_name)<StrToInt(rhs.my_point_name));
	else if (rhs.my_type == tp_EXIST && my_type == tp_NEW)
		return true;
	else if (rhs.my_type == tp_NEW && my_type == tp_EXIST)
		return false;
	else if (rhs.my_type == tp_UNKNOWN || my_type == tp_UNKNOWN)
		return true;
	//else if (rhs.my_type == tp_NEW && my_type == tp_NEW)
	AnsiString left=my_point_name,right=rhs.my_point_name;
	left[1]='0';
	right[1]='0';
	return (StrToInt(left)<StrToInt(right));
}
//---------------------------------------------------------------------------
ofstream& operator<< (ofstream& fout,const CPoint& point)
{
	AnsiString n = FloatToStrF(point.GetNord(),ffFixed,15,CPoint::digits);
	AnsiString e = FloatToStrF(point.GetEast(),ffFixed,15,CPoint::digits);
	fout<<point.GetName().c_str()<<","<<n.c_str()<<","<<e.c_str();
	return fout;
}
//---------------------------------------------------------------------------
void CPoint::SetName (AnsiString name)
{
	my_point_name = name;
	if(name == "")
		my_type = tp_UNKNOWN;
	else
		my_type = (name[1]=='н'||name[1]=='Н') ? tp_NEW  : tp_EXIST;
}
//---------------------------------------------------------------------------
void CPoint::SetPoint(AnsiString name,double nord,double east)
{
	SetName(name);
	SetNord(nord);
	SetEast(east);
}
//---------------------------------------------------------------------------




CKadastrLine::CKadastrLine(CPoint point1,CPoint point2)
{
	SetLine(point1,point2);
}
//---------------------------------------------------------------------------
CKadastrLine::CKadastrLine(const CKadastrLine& rhs)
{
	SetLine(rhs.GetBeginPoint(),rhs.GetEndPoint());
}
//---------------------------------------------------------------------------
CKadastrLine& CKadastrLine::operator= (const CKadastrLine& rhs)
{
	SetLine(rhs.GetBeginPoint(),rhs.GetEndPoint());
	return *this;
}
//---------------------------------------------------------------------------
void CKadastrLine::SetLine(CPoint point1,CPoint point2)
{
	if(point1.GetType() == tp_UNKNOWN || point2.GetType() == tp_UNKNOWN)
	{
		my_type = tl_UNKNOWN;
		my_begin = point1;
		my_end = point2;
	}
	else if(point1.GetType() == tp_NEW && point2.GetType() == tp_EXIST)
	{
		my_type = tl_Uto4n;
		my_begin = point2;
		my_end = point1;
	}
	else if(point1.GetType() == tp_EXIST && point2.GetType() == tp_NEW)
	{
		my_type = tl_Uto4n;
		my_begin = point1;
		my_end = point2;
	}
	else if(point1.GetType() == tp_EXIST && point2.GetType() == tp_EXIST)
	{
		my_type = tl_EXIST;
		if(!(point1<point2))
		{
			my_begin = point2;
			my_end = point1;
		}
        else
		{
			my_begin = point1;
			my_end = point2;
        }
	}
	else //if(point1.GetType() == tp_NEW && point2.GetType() == tp_NEW)
	{
		my_type = tl_NEW;
		if(!(point1<point2))
		{
			my_begin = point2;
			my_end = point1;
		}
		else
		{
			my_begin = point1;
			my_end = point2;
		}
	}
}
//---------------------------------------------------------------------------
bool CKadastrLine::operator < (const CKadastrLine& rhs)const
{
	if(my_begin.GetName() == rhs.my_begin.GetName())
		return my_end <rhs.my_end;
		
	return my_begin < rhs.my_begin;
};
//---------------------------------------------------------------------------




CAutoCADPoint::CAutoCADPoint(AnsiString name,double nord,double east):
CPoint(name,nord,east),
myAcadBlock(0),
my_color(acByLayer)
{  
}
//---------------------------------------------------------------------------
CAutoCADPoint::CAutoCADPoint(const CAutoCADPoint& rhs):
CPoint(rhs),
myAcadBlock(rhs.GetBlock()),
my_color(rhs.GetColor())
{
}
//---------------------------------------------------------------------------
CAutoCADPoint& CAutoCADPoint::operator=(const CAutoCADPoint& rhs)
{
	if(this == &rhs)
		return *this;

	myAcadBlock = rhs.GetBlock();
	my_color = rhs.GetColor();
	CPoint::operator =(rhs);
	return *this;
}
//---------------------------------------------------------------------------
bool CAutoCADPoint::operator== (const CAutoCADPoint& rhs)const
{
	//Проверяем расстояние между точками, если оно меньше допуска, то точки одинаковы
	 if (CalculateLength(*this,rhs) <= dopusk)
		return true;

	 return false;
}
//---------------------------------------------------------------------------
void CAutoCADPoint::SetName (AnsiString name)
{
	CPoint::SetName(name);
	if (myAcadBlock)
	{
        AcadAttributeReference* atr = NULL;
		Variant v_atr;
		//Считываем атрибуты блока
		myAcadBlock->GetAttributes(v_atr);
		//получаем указатель на атрибуты
		IDispatch* d_atr = v_atr.GetElement(0);
		d_atr->QueryInterface(IID_IAcadAttributeReference,(void**)&atr);
		//присваиваем имя точки
		atr->TextString = Variant(GetName().c_str());
		atr->Release();
    }	
}
//---------------------------------------------------------------------------
void CAutoCADPoint::SetBlock(AcadBlockReference* block)
{
	myAcadBlock = block;
}
//---------------------------------------------------------------------------
void CAutoCADPoint::SetColor(AcColor color)
{
	if (myAcadBlock)
		myAcadBlock->color = color;
}
//---------------------------------------------------------------------------
void CAutoCADPoint::SetLayer(Variant name)
{
	if (myAcadBlock)
		myAcadBlock->Layer = name;
}
//---------------------------------------------------------------------------



Parcel::Parcel(const list<CAutoCADPoint>& points)
{
	SetPoints(points);
}
//---------------------------------------------------------------------------
Parcel::Parcel(const Parcel& rhs)
{
	points = rhs.points;
}
//---------------------------------------------------------------------------
ofstream& operator<< (ofstream& fout,const Parcel& parcel)
{
	for(list<CAutoCADPoint>::const_iterator ci= parcel.points.begin();ci != parcel.points.end();++ci)
		fout<<*ci<<'\n';
	return fout;
}
//---------------------------------------------------------------------------
Parcel& Parcel::operator=(const Parcel& rhs)
{
	if(this == &rhs)
		return *this;
	points.assign(rhs.points.begin(),rhs.points.end());
	return *this;
}
//---------------------------------------------------------------------------
void Parcel::SetPoints(const list<CAutoCADPoint>& source_points)
{
	points.assign(source_points.begin(),source_points.end());

	//Удаляем две одинаковые точки расположенные подряд(допуск = 0)
	float old_dopusk = CAutoCADPoint::dopusk;
	CAutoCADPoint::dopusk = 0;
	points.unique();
	if(points.front() == points.back())
		points.pop_back();
	CAutoCADPoint::dopusk = old_dopusk;

	//Определяем направление обхода участка по часовой стрелке
	Direction();
}
//---------------------------------------------------------------------------
void Parcel::RemoveIdenticalPoints()
{
	list<CAutoCADPoint>::iterator sled = points.begin();
	++sled;
	for(list<CAutoCADPoint>::iterator tek = points.begin(); tek != points.end();)
	{
		if(*tek == *sled)
		{
			if(tek->GetType() != tp_EXIST)
			{
				tek = points.erase(tek);
				++sled;
			}
			else if (sled->GetType() != tp_EXIST)
			{
				sled = points.erase(sled);
			}
			else if(sled->GetName() == tek->GetName())  //Точки равны, им присвоены одинаковые имена,=>они идентичны
			{      
				sled = points.erase(sled);
			}

			else //Если обе точки существующие
				++sled,++tek;
		}
		else
			++sled,++tek;
			
		if(sled == points.end())
			sled = points.begin();
	}
	//Определяем направление обхода участка по часовой стрелке
	Direction();
}
//---------------------------------------------------------------------------
void Parcel::AppropriateExistingPoints(const list<CAutoCADPoint>& existPoints)
{
	//Определяем точки участка уже существующие на чертеже
	for(list<CAutoCADPoint>::const_iterator ci = existPoints.begin(); ci != existPoints.end(); ++ci)
	{
		if(ci->GetType() == tp_EXIST)
		{
			list<CAutoCADPoint>::iterator i = FindPoint(*ci);
			if(i != points.end() && i->GetType() == tp_UNKNOWN)
				*i = *ci;
		}
	}
}
//---------------------------------------------------------------------------
void Parcel::NumeratePoints(int number)
{
	for(list<CAutoCADPoint>::iterator i = points.begin();i != points.end();++i)
		if(i->GetType() != tp_EXIST)
		{
			i->SetName("н"+IntToStr(number));
			number++;
		}
}
//---------------------------------------------------------------------------
void Parcel::DrawParcel(cACAD& acad,double scale)
{
	for(list<CAutoCADPoint>::iterator i = points.begin(); i != points.end(); ++i)
		i->SetBlock(acad.WriteKadastrPoint(*i,scale));
}
//---------------------------------------------------------------------------
void Parcel::SpecifyNamesPointsOnDrawing()
{
	for(list<CAutoCADPoint>::iterator i = points.begin(); i != points.end(); ++i)
		if (i->GetBlock())
		{
			AcadAttributeReference* atr = NULL;
			Variant v_atr;
			//Считываем атрибуты блока
			i->GetBlock()->GetAttributes(v_atr);
			//получаем указатель на атрибуты
			IDispatch* d_atr = v_atr.GetElement(0);
			d_atr->QueryInterface(IID_IAcadAttributeReference,(void**)&atr);
			//присваиваем имя точки
			i->SetName(atr->TextString);
			atr->Release();
		}
}
//---------------------------------------------------------------------------
void Parcel::Reverse()
{
	points.reverse();
	list<CAutoCADPoint>::iterator i = points.end();
	--i;
	rotate(points.begin(),i,points.end());
}
//---------------------------------------------------------------------------
void Parcel::SetColor(AcColor color)
{
	for(list<CAutoCADPoint>::iterator i = points.begin();i != points.end();++i)
		i->SetColor(color);
}
//---------------------------------------------------------------------------
void Parcel::SetLayer(Variant name)
{    
	for(list<CAutoCADPoint>::iterator i = points.begin();i != points.end();++i)
		i->SetLayer(name);
}
//---------------------------------------------------------------------------
void Parcel::Direction()
{
	//При установлении направления обхода по часовой стрелке исходим из того, что
	//сумма левых углов при обходе по часовой стрелке д.б. больше суммы правых
	if(GetSumAngle(true) <  GetSumAngle(false))
		points.reverse();
	//Ищем самую левую нижнюю точку, она станет первой на участке
	list<CAutoCADPoint>::iterator LBPoint = points.begin();
	for(list<CAutoCADPoint>::iterator ci = points.begin();ci != points.end(); ++ci)
	{
		if(ci->GetEast() < LBPoint->GetEast())
		{
			LBPoint = ci;
			continue;
		}
		else if (fabs(ci->GetEast() - LBPoint->GetEast()) <= pow(10,-CPoint::digits))
			 if(ci->GetNord() < LBPoint->GetNord())
				LBPoint = ci;
	}
	//Устанавливаем левую нижнюю точку первой в последовательности точек участка
	rotate(points.begin(),LBPoint,points.end());
}
//---------------------------------------------------------------------------
CAngle Parcel::GetSumAngle(bool left)const
{
	//Формируем список линий
	list<CKadastrLine> list_lines;
	{
	list<CAutoCADPoint>::const_iterator sled = points.begin();
	++sled;
	for(list<CAutoCADPoint>::const_iterator tek = points.begin();tek != points.end();++tek,++sled)
	{
		if(sled == points.end())
			sled = points.begin();
		list_lines.push_back(CKadastrLine(*tek,*sled));
	}
	}
	CAngle sumAngle(0);
	if(left)
	{//Для левых углов Дирекционный угол расчитывается как Aк=Ан-180+B,
	//следовательно B=Aк-Aн+180
	list<CKadastrLine>::const_iterator sled = list_lines.begin();
	++sled;
	for(list<CKadastrLine>::const_iterator tek = list_lines.begin();tek != list_lines.end();++tek,++sled)
	{
		if(sled == list_lines.end())
			sled = list_lines.begin();
		CAngle B =  CalculateDirectAngle(sled->GetBeginPoint(),sled->GetEndPoint()) -
					CalculateDirectAngle(tek->GetBeginPoint(),tek->GetEndPoint()) +
					CAngle(180);
		while (!B.IsPositiv())
			B = B + CAngle(360);
		while (B.GetGradus()>360)
			B = B - CAngle(360);
		sumAngle = B + sumAngle;
	}
	}
	else
	{//Для правых углов Дирекционный угол расчитывается как Aк=Ан-180-B,
	//следовательно B=Aн-Aк-180
	list<CKadastrLine>::const_iterator sled = list_lines.begin();
	++sled;
	for(list<CKadastrLine>::const_iterator tek = list_lines.begin();tek != list_lines.end();++tek,++sled)
	{
		if(sled == list_lines.end())
			sled = list_lines.begin();
		CAngle B = -CalculateDirectAngle(sled->GetBeginPoint(),sled->GetEndPoint()) +
					CalculateDirectAngle(tek->GetBeginPoint(),tek->GetEndPoint()) -
					CAngle(180);
		while (!B.IsPositiv())
			B = B + CAngle(360);
		while (B.GetGradus()>360)
			B = B - CAngle(360);
		sumAngle = B + sumAngle;
	}
	}
	return sumAngle;
}
//---------------------------------------------------------------------------
list<CAutoCADPoint>::iterator Parcel::FindPoint(const CAutoCADPoint& existPoint)
{
	//Определяем точку равную точкt учаcтка. при этом для того, чтобы найти наиболее
	//близкую точку допуск изменяется с шагом 0.01 от 0 до CAutoCADPoint::dopusk
	float old_dopusk = CAutoCADPoint::dopusk;
	for(float dopusk = 0; dopusk <= old_dopusk; dopusk += 0.01)
	{
		CAutoCADPoint::dopusk = dopusk;
		for(list<CAutoCADPoint>::iterator i = points.begin();i != points.end();++i)
			if(*i == existPoint)
			{
				CAutoCADPoint::dopusk = old_dopusk;
				return i;
			}
	}
	CAutoCADPoint::dopusk = old_dopusk;
	return points.end();
}
//---------------------------------------------------------------------------
