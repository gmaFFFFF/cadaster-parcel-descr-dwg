//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BasicDialogForm.h"
#include "BasicForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BasicForm"
#pragma resource "*.dfm"
TFDialog *FDialog;
//---------------------------------------------------------------------------
__fastcall TFDialog::TFDialog(TComponent* Owner)
    : TFBasic(Owner)
{
}
//---------------------------------------------------------------------------
