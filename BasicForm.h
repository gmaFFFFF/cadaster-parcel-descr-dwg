/***************************************************************************
                          BasicForm.h
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

#ifndef BasicFormH
#define BasicFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TFBasic : public TForm
{
__published:	
private:
public:
    __fastcall TFBasic(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFBasic *FBasic;
//---------------------------------------------------------------------------
#endif
