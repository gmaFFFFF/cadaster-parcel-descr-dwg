//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormNumLine.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFNumer *FNumer;
//---------------------------------------------------------------------------
__fastcall TFNumer::TFNumer(TComponent* Owner)
	: TForm(Owner),parcel(0)
{

}
//---------------------------------------------------------------------------

void __fastcall TFNumer::BNumerateClick(TObject *Sender)
{
	if(parcel)
		delete parcel;
	parcel = new Parcel;
	try
	{
		acad = new cACAD(false);
	}
	catch(...)
	{
		ShowMessage("AutoCAD �� �������");
		return;
	}

	list<CAutoCADPoint> points;

	//�������� ������� ���������� �������������
	acad->GetSelectParcel(*parcel);
	//��������� �� �������� ��������� �����
	acad->GetPoints(points);

	CAutoCADPoint::dopusk = float(UpDown1->Position)/100;

	//����������� ������ ������� ����� ������������ �����
	parcel->AppropriateExistingPoints(points);
	points.clear();

	//������� ���������� �����, �� ����������� ������������
	parcel->RemoveIdenticalPoints();
	//�������� �����
	parcel->NumeratePoints(UDBeginNum->Position);
	//����������� ����� �� �������
	try
	{
		parcel->DrawParcel(*acad,StrToInt(MEScaleBlock->Text));
	}
	catch(...)
	{
		ShowMessage("� ������� �� ��������� ���� \"�����\"");
	}

	delete acad;
}
//---------------------------------------------------------------------------
void __fastcall TFNumer::BSaveClick(TObject *Sender)
{
	if(!parcel)
	{
		ShowMessage("��� ����� ��� ����������.\n��������� ������� ������� ����������"); 
		return;
	}
	Visible = false;
	if(!SaveDialog1->Execute())
	{   
		Visible = true;
		return;
	}
	if(SaveDialog1->FilterIndex == 1)
		SaveDialog1->FileName = ChangeFileExt(SaveDialog1->FileName,".csv");
	ofstream fout(SaveDialog1->FileName.c_str());
	if(!fout)
	{
		ShowMessage("����:\n" + SaveDialog1->FileName + "\n������� �� �������");
		Visible = true;
		return;
	}
	fout<<*parcel;
	Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TFNumer::BSpecifyNamesPointsOnDrawingClick(TObject *Sender)
{
	if(!parcel)
		return;
	parcel->SpecifyNamesPointsOnDrawing();
	//�������� ����� ����� �����
	parcel->NumeratePoints(UDBeginNum->Position);
}
//---------------------------------------------------------------------------

void __fastcall TFNumer::BReverseClick(TObject *Sender)
{
	if(!parcel)
		return;
	parcel->Reverse();  
	//�������� ����� ����� �����
	parcel->NumeratePoints(UDBeginNum->Position);
}
//---------------------------------------------------------------------------

void __fastcall TFNumer::FormClose(TObject *Sender, TCloseAction &Action)
{    	
	if(parcel)
	{
		delete parcel;
		parcel = 0;
	}
}
//---------------------------------------------------------------------------

