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
    //������������.
    CAngle(){my_gradus = 0; my_minute = 0; my_secund = 0; my_sign = true;}
    CAngle(double gradus,bool sign = true);
    CAngle(double gradus,double minute,bool sign = true);
    CAngle(double gradus,double minute,double sec,bool sign = true);
    CAngle(AnsiString Value);                //������ � ������� :
                                            //XX�XX'XX".

    //�����������.
    ~CAngle(){}

    //������� ��������� ����� �������� ������ ������.
    void SetNewValue(double gradus = 0,double minute = 0,double sec = 0,
                     bool sign = true);
    void SetNewValue(AnsiString Value);     //������ � ������� :
                                            //XX�XX'XX".

    //������� ������� � ������.
    AnsiString GetValue(ANGLE_FORMAT format = af_FULL)const;
    bool IsPositiv() const {return my_sign;}
    int  GetGradus() const {return my_gradus;}
    int  GetMinute() const {return my_minute;}
    int  GetSecund() const {return my_secund;}

    //�������������� ���������.
    CAngle operator + (const CAngle& rhs) const;
    CAngle operator - (const CAngle& rhs) const;
    CAngle operator * (double x) const;
    CAngle operator / (double x) const;

    //��������� ���������.
    bool operator == (const CAngle& rhs) const;
    bool operator != (const CAngle& rhs) const;
    bool operator >  (const CAngle& rhs) const;
    bool operator <  (const CAngle& rhs) const;
    bool operator >= (const CAngle& rhs) const;
    bool operator <= (const CAngle& rhs) const;

    //��������� ���������� �����.
    operator double()const;                 //���������� �������.
    friend CAngle StrToAngle(const AnsiString& Value);//����������� ����������������� 
                                            //������ � �������.

    //������������� �������.
    AnsiString GetRumb(ANGLE_FORMAT format = af_FULL) const;
    void ReductionAngleToGeodFormat();

    
protected:
    //��������������� �������.
    void ReductionToFormatOfDegrees();      //����������� 60 ��� � 1 ���,
                                            //� 60 ���. � 1 �������.      
    double GetRadian() const;               //���������� ������� � ��������.

private:
    int  my_gradus;                         //�������.
    int  my_minute;                         //������.
    int  my_secund;                         //�������.
    bool my_sign;                           //���� �������("+","-").

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
