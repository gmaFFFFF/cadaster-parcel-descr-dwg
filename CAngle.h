/***************************************************************************
                          CAngle.h
                         -------------------
    copyright            : (C) 2004 by FFFFF
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
#ifndef CAngleH
#define CAngleH
//---------------------------------------------------------------------------
#include <Math.hpp>
#include <math.h>
//---------------------------------------------------------------------------
enum ANGLE_FORMAT {af_FULL = 0,af_TO_MINUTE = 1,af_TO_GRADUS = 2,af_RADIAN = 3};
class CAngle
{
public:
    //Конструкторы.
    CAngle(){my_gradus = 0; my_minute = 0; my_secund = 0; my_sign = true;}
    CAngle(double gradus,bool sign = true);
    CAngle(double gradus,double minute,bool sign = true);
    CAngle(double gradus,double minute,double sec,bool sign = true);
    CAngle(AnsiString Value);                //Данные в формате :
                                            //XX°XX'XX".

    //Деструкторы.
    ~CAngle(){}

    //Функции установки новых значений данных класса.
    void SetNewValue(double gradus = 0,double minute = 0,double sec = 0,
                     bool sign = true);
    void SetNewValue(AnsiString Value);     //Данные в формате :
                                            //XX°XX'XX".

    //Функции доступа к данным.
    AnsiString GetValue(ANGLE_FORMAT format = af_FULL)const;
    bool IsPositiv() const {return my_sign;}
    int  GetGradus() const {return my_gradus;}
    int  GetMinute() const {return my_minute;}
    int  GetSecund() const {return my_secund;}

    //Математические операторы.
    CAngle operator + (const CAngle& rhs) const;
    CAngle operator - (const CAngle& rhs) const;
    CAngle operator * (double x) const;
    CAngle operator / (double x) const;

    //Операторы сравнения.
    bool operator == (const CAngle& rhs) const;
    bool operator != (const CAngle& rhs) const;
    bool operator >  (const CAngle& rhs) const;
    bool operator <  (const CAngle& rhs) const;
    bool operator >= (const CAngle& rhs) const;
    bool operator <= (const CAngle& rhs) const;

    //Операторы приведения типов.
    operator double()const;                 //Возвращает градусы.
    friend CAngle StrToAngle(const AnsiString& Value);//Преобразует неформатированную 
                                            //строку в градусы.

    //Геодезические функции.
    AnsiString GetRumb(ANGLE_FORMAT format = af_FULL) const;
    void ReductionAngleToGeodFormat();

    
protected:
    //Вспомогательные функции.
    void ReductionToFormatOfDegrees();      //Преобразует 60 сек к 1 мин,
                                            //а 60 мин. к 1 градусу.      
    double GetRadian() const;               //Возвращает градусы в радианах.

private:
    int  my_gradus;                         //Градусы.
    int  my_minute;                         //Минуты.
    int  my_secund;                         //Секунды.
    bool my_sign;                           //Знак градуса("+","-").

};
//---------------------------------------------------------------------------
double Cos(CAngle& Ang)
{
    return cos(DegToRad(Ang));
}
//---------------------------------------------------------------------------
double Sin(CAngle& Ang)
{
    return sin(DegToRad(Ang));
}
//---------------------------------------------------------------------------
double Tan(CAngle& Ang)
{
    return Tan(DegToRad(Ang));
}
//---------------------------------------------------------------------------
#endif
