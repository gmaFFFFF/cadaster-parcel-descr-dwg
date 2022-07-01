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

#ifndef FKadSetkaH
#define FKadSetkaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "cspin.h"
#include "cACAD.h"
//---------------------------------------------------------------------------
class TFDrawKadSetka : public TForm
{
__published:	// IDE-managed Components
	TRadioGroup *RGSourceCoord;
	TRadioGroup *RGScale;
	TCSpinEdit *CSEScale;
	TLabel *Label1;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	void SetMaxMinCoordParcel();
	void SetMaxMinCoordKwartal();
    void CalcDrawingScale();

	cACAD* acad;
	CPoint ParcelMaxCoord;
	CPoint ParcelMinCoord;
	CPoint KwartalMaxCoord;
	CPoint KwartalMinCoord;

	double scaleDrawing;
public:		// User declarations
	__fastcall TFDrawKadSetka(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDrawKadSetka *FDrawKadSetka;
//---------------------------------------------------------------------------
#endif
