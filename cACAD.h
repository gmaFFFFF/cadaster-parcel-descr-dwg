/***************************************************************************
						  cACAD.h
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

#ifndef CACADH
#define CACADH
//---------------------------------------------------------------------------
#include <string>
#include <list>

#include "AutoCAD_TLB.h"
#include "myClasses.h"

using std::string;
using std::list;
using Autocad_tlb::AcadApplication;

class cACAD
{
public:
    cACAD(bool new_app = true);
    ~cACAD();
    void NewDrawing(const string& templateFileName);
    void SaveDrawingAndClose(const string& fileName);

    void WriteKadastrLine(const CKadastrLine& line);
    void WriteKadastrLines(const list<CKadastrLine>& lines);
	AcadBlockReference* WriteKadastrPoint(const CPoint& point,double scale = 0);
    void WriteKadastrPoints(const list<CPoint>& points);

	void BuildLayout();

	bool GetSelectParcel(Parcel& parcel)const;
	void cACAD::GetPoints(list<CAutoCADPoint>& points)const;

private:
	void CalculateScaleVP(const list<CPoint>& points) const;        //��������� ������� �������� ������,
																	//���������� max � min ���������� �������� �������
	//SetMaxLimit � SetMinLimit ���������� ��� ���� ����� ���������� ������� �������� ������
	void SetMaxMinLimit(const CPoint& point)const;                  //��������� �������� �� ���������� ����� ��
																	//�������� ������(������) �������� max(min) ��������� �������� �������
																	//���� ��,�� ����������� �� max(min) ���������� �������� �������
	Variant GetCoord(const CPoint& point,double z = 0);

	AcadApplication* acad;
	AcadPViewport* viewPort;
	bool newApp;
};

//---------------------------------------------------------------------------
#endif // CACADH
