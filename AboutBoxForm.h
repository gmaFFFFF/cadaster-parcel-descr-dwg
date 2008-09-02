/***************************************************************************
                          AboutBoxForm.h
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

#ifndef AboutBoxFormH
#define AboutBoxFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFAboutBox : public TForm
{
__published:
    TButton *BOK;
    TImage *ILogotip;
    TLabel *Label1;
    TLabel *LAuthor;
    TLabel *LCopyright;
    TLabel *LEmail;
    TLabel *LProductName;
    TLabel *LProductVer;
    TLabel *LVersion;
    TMemo *MComment;

    void __fastcall LEmailClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);

private:
    bool FindProgramVer(void);

public:
    __fastcall TFAboutBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFAboutBox *FAboutBox;
//---------------------------------------------------------------------------
#endif
