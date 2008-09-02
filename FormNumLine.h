/***************************************************************************
						  FormNumLine.h
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

#ifndef FormNumLineH
#define FormNumLineH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>  
#include "cACAD.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFNumer : public TForm
{
__published:	// IDE-managed Components
	TButton *BNumerate;
	TButton *BSave;
	TLabeledEdit *LERMS;
	TUpDown *UpDown1;
	TSaveDialog *SaveDialog1;
	TButton *BSpecifyNamesPointsOnDrawing;
	TMaskEdit *MEScaleBlock;
	TLabel *Label1;
	TButton *BReverse;
	TLabeledEdit *LabeledEdit1;
	TUpDown *UDBeginNum;
	void __fastcall BNumerateClick(TObject *Sender);
	void __fastcall BSaveClick(TObject *Sender);
	void __fastcall BSpecifyNamesPointsOnDrawingClick(TObject *Sender);
	void __fastcall BReverseClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
	cACAD* acad;
	Parcel* parcel;
public:		// User declarations
	__fastcall TFNumer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFNumer *FNumer;
//---------------------------------------------------------------------------
#endif
