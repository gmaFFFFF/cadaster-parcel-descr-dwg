/***************************************************************************
                          BasicDialogForm.h
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

#ifndef BasicDialogFormH
#define BasicDialogFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "BasicForm.h"
//---------------------------------------------------------------------------
class TFDialog : public TFBasic
{
__published:	
private:
public:
    __fastcall TFDialog(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDialog *FDialog;
//---------------------------------------------------------------------------
#endif
