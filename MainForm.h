/***************************************************************************
						  MainForm.h
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

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <string>
#include <ComObj.hpp>
#include <list>

#include "myClasses.h"
#include "cACAD.cpp"
#include "FormNumLine.h"
#include "AboutBoxForm.h"
using namespace std;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TRadioGroup *RGCoord;
	TRadioGroup *RGRMS;
	TEdit *EDestinationFolder;
	TButton *BSelectFolder;
	TLabel *Label1;
	TEdit *EPointZakr;
	TProgressBar *Progress;
	TCheckBox *CHBExistGranic;
	TCheckBox *CBACADDrawing;
	TButton *BAbout;
	TButton *BACAD;
	TBitBtn *BBKadSetka;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall WMDROPFILES(TMessage &Msg);
	void __fastcall BSelectFolderClick(TObject *Sender);
	void __fastcall BACADClick(TObject *Sender);
	void __fastcall BAboutClick(TObject *Sender);
	void __fastcall BBKadSetkaClick(TObject *Sender);
private:	// User declarations
	void __fastcall toExcelCell(Variant Sheet, int Row,int Column, Variant data);
	void __fastcall toExcelCell(Variant Sheet,int Row,int Column, AnsiString data);
	void __fastcall InsertExcelRow(int Sheet,int sRow,int count);

	void Calculate(string file_name);
    void WriteGeoData(const list<CPoint>& list_point);
	void WriteOpisanie1(const list<CPoint>& list_point);
	void WriteOpisanie2(const list<CPoint>& list_point);
	void WriteKatalog(const list<CPoint>& list_point,double area);
	double WriteAreaSheet(const list<CPoint>& list_point);
	void WriteEGRZSheet(const list<CPoint>& list_point,double area);
	void WriteDrawing(const list<CPoint>& list_point);
	void SaveOptions();
	void LoadOptions();
	bool CreateExcel();
	void DestroyExcel();
	AnsiString GetRoundAreaExcel(double Area){return "=Округл("+FloatToStr(Area)+ListSeparator + "0)";}
	AnsiString GetRMSArea(const list<CPoint>& list_point,double area);

	Variant Excel;    //Файл Excel;
	cACAD* acad;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	BEGIN_MESSAGE_MAP
		MESSAGE_HANDLER(WM_DROPFILES,TMessage,WMDROPFILES);
	END_MESSAGE_MAP(TComponent);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
