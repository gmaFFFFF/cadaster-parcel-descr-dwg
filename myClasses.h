/***************************************************************************
						  myClasses.h
						 -------------------
	copyright            : (C) 2008 by FFFFF
	email                : FFFFF@bk.ru
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
//---------------------------------------------------------------------------

#ifndef myClassesH
#define myClassesH
//---------------------------------------------------------------------------
#include <system.hpp>
#include <list>
#include <string>
#include <fstream.h>

class cACAD;

#include "AutoCAD_TLB.h"
#include "CAngle.h"

using namespace std;
//---------------------------------------------------------------------------
enum TYPE_POINT {tp_EXIST,tp_NEW,tp_UNKNOWN};
enum TYPE_LINE {tl_EXIST,tl_NEW,tl_Uto4n,tl_UNKNOWN};
//---------------------------------------------------------------------------
class CPoint;
CAngle CalculateDirectAngle(CPoint begin,CPoint end);
double CalculateLength(CPoint begin,CPoint end);

bool LoadPointFromFile(string file_name,list<CPoint>& list_point);
//---------------------------------------------------------------------------
class CPoint
{
public:
	CPoint():my_nord(0),my_east(0),my_point_name(""),my_type(tp_UNKNOWN){}
	CPoint(AnsiString name,double nord,double east);
	CPoint(const CPoint& rhs);
	~CPoint(){}

	CPoint& operator = (const CPoint& rhs);
	bool operator < (const CPoint& rhs)const;
	friend ofstream& operator<< (ofstream& fout,const CPoint& point);

	double GetNord()const{return my_nord;}
	double GetEast()const{return my_east;}
	TYPE_POINT GetType()const{return my_type;}
	AnsiString GetName()const{return my_point_name;}

	void SetPoint(AnsiString name,double nord,double east);
	void SetNord(double nord) {my_nord=nord;}
	void SetEast(double east) {my_east=east;}
	void SetName (AnsiString name);

	static int digits;
protected:
	double my_nord;
	double my_east;
	AnsiString my_point_name;
	TYPE_POINT my_type;
};


class CKadastrLine
{
public:
	CKadastrLine(){my_type=tl_EXIST;}
	CKadastrLine(CPoint point1,CPoint point2);
	CKadastrLine(const CKadastrLine& rhs);
	~CKadastrLine(){}

	CKadastrLine& operator= (const CKadastrLine& rhs);
	bool operator < (const CKadastrLine& rhs)const;


	double GetLength()const {return CalculateLength(my_begin,my_end);}
	AnsiString GetDirectAngle()const {return CalculateDirectAngle(my_begin,my_end).GetValue(af_TO_MINUTE);}
	TYPE_LINE GetType()const {return my_type;}
	CPoint GetBeginPoint()const {return my_begin;}
	CPoint GetEndPoint()const {return my_end;}

	void SetLine(CPoint point1,CPoint point2);
private:
	CPoint my_begin;
	CPoint my_end;
	TYPE_LINE my_type;
}; 


class CAutoCADPoint : public CPoint
{
public:
	CAutoCADPoint():CPoint(),myAcadBlock(0),my_color(acByLayer){}
	CAutoCADPoint(AnsiString name,double nord,double east);
	CAutoCADPoint(const CAutoCADPoint& rhs);
	~CAutoCADPoint(){}

	CAutoCADPoint& operator=(const CAutoCADPoint& rhs);
	bool operator== (const CAutoCADPoint& rhs)const;

	void SetName (AnsiString name);
	void SetBlock(AcadBlockReference* block);
	AcadBlockReference* GetBlock()const{return myAcadBlock;}
	void SetColor(AcColor color = acByLayer);
	void SetLayer(Variant name);
	AcColor GetColor()const {return my_color;}

	static float dopusk;				//используется оператором сравнения
private:
	AcadBlockReference* myAcadBlock;
	AcColor my_color;
};

class Parcel
{
public:
	Parcel(){};
	Parcel(const list<CAutoCADPoint>& points);
	Parcel(const Parcel& rhs);
	~Parcel(){}

	friend ofstream& operator<< (ofstream& fout,const Parcel& parcel);
	Parcel& operator=(const Parcel& rhs);

	void SetPoints(const list<CAutoCADPoint>& source_points);

	//Удалить одинаковые новые точки с учетом допуска,существующие не удаляются
	void RemoveIdenticalPoints();
	//Присвоить точкам имена и координаты существующих точек, с учетом допуска
	void AppropriateExistingPoints(const list<CAutoCADPoint>& existPoints);
	//Нумеровать новые точки
	void NumeratePoints(int begin_num = 1);
	//Вычертить точки в автокаде
	void DrawParcel(cACAD& acad,double scale = 1);
	//Пользователь может изменять имена блоков в чертеже и их положение, ф-ия
	//получает уточненные значения
	void SpecifyNamesPointsOnDrawing();
	//Изменить порядок нумерации
	void Reverse();
	void SetColor(AcColor color = acByLayer);
	void SetLayer(Variant name);
	list<CAutoCADPoint>& GetPoints(){return points;}

private:
	CAngle GetSumAngle(bool left = true)const;
	void Direction();
	//Возвращает точку участка равную аргументу
	list<CAutoCADPoint>::iterator FindPoint(const CAutoCADPoint& existPoint);

	list<CAutoCADPoint> points;
};
//---------------------------------------------------------------------------
#endif
