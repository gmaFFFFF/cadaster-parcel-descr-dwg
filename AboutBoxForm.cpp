//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AboutBoxForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFAboutBox *FAboutBox;
//---------------------------------------------------------------------------
__fastcall TFAboutBox::TFAboutBox(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFAboutBox::LEmailClick(TObject *Sender)
{
    //Запускаем почтовый клиент по умолчанию.
    AnsiString Str;
    Str = "mailto:" + LEmail->Caption + "?subject=" + LProductName->Caption +
          " " + LVersion->Caption + LProductVer->Caption;
    ShellExecute(NULL, NULL, Str.c_str(), NULL, NULL, SW_SHOWNORMAL);
    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TFAboutBox::FormShow(TObject *Sender)
{     
    //Cчитываем версию программы.
    FindProgramVer();
    //Загружаем логотип. 
    ILogotip->Picture->LoadFromFile(ExtractFileDir(Application->ExeName)+"\\log.bmp");
}
//---------------------------------------------------------------------------
bool TFAboutBox::FindProgramVer(void)
{
    VS_FIXEDFILEINFO* ver_inf = NULL;
    UINT size = GetFileVersionInfoSize(Application->ExeName.c_str(),NULL);
    if(size > 0)
    {
        long* data = new long[size];
        GetFileVersionInfo(Application->ExeName.c_str(),NULL,size,data);
        VerQueryValue(data,"\\",(void**) &ver_inf,&size);
        delete [] data;
    }

    if(size <= 0 || ver_inf == NULL)
    {
        LVersion->Caption = "Unknown";
        return false;
    }
    
    //Версия программы лежит в битовых полях.
    DWORD MS = ver_inf->dwProductVersionMS;
    DWORD LS = ver_inf->dwProductVersionLS;
    LProductVer->Caption = AnsiString(MS >> 16) + "." + 
        AnsiString(MS & 0xFFFF) + "." + AnsiString(LS >> 16) + "." +
        AnsiString(LS & 0xFFFF) + ".";
    return true;
}
//---------------------------------------------------------------------------



