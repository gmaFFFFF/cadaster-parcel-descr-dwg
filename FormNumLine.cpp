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
		ShowMessage("AutoCAD не запущен");
		return;
	}

	list<CAutoCADPoint> points;

	//Получаем участок выделенный пользователем
	acad->GetSelectParcel(*parcel);
	//Считываем из черетежа имеющиеся точки
	acad->GetPoints(points);

	CAutoCADPoint::dopusk = float(UpDown1->Position)/100;

	//Присваиваем точкам участка именя существующих точек
	parcel->AppropriateExistingPoints(points);
	points.clear();

	//Удаляем одинаковые точки, за исключением существующих
	parcel->RemoveIdenticalPoints();
	//Нумеруем точки
	parcel->NumeratePoints(UDBeginNum->Position);
	//вычерчиваем точки на чертеже
	try
	{
		parcel->DrawParcel(*acad,StrToInt(MEScaleBlock->Text));
	}
	catch(...)
	{
		ShowMessage("В чертеже не определен блок \"Точка\"");
	}

	delete acad;
}
//---------------------------------------------------------------------------
void __fastcall TFNumer::BSaveClick(TObject *Sender)
{
	if(!parcel)
	{
		ShowMessage("Нет точек для сохранения.\nВыполните сначала команду нумеровать"); 
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
		ShowMessage("Файл:\n" + SaveDialog1->FileName + "\nсоздать не удалось");
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
	//Нумеруем новые точки снова
	parcel->NumeratePoints(UDBeginNum->Position);
}
//---------------------------------------------------------------------------

void __fastcall TFNumer::BReverseClick(TObject *Sender)
{
	if(!parcel)
		return;
	parcel->Reverse();  
	//Нумеруем новые точки снова
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

