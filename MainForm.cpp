//---------------------------------------------------------------------------

#include <vcl.h>
#include <FileCtrl.hpp>
#include <IniFiles.hpp>
#include <stdio.h>
#include <vector>
#pragma hdrstop

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner),acad(NULL)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	//Форма готова к приему файлов
	DragAcceptFiles(Handle,true);
	//Определяем путь по умолчанию для сохранения файлов
	EDestinationFolder->Text = GetCurrentDir()+"\\Result";
	EDestinationFolder->Hint = EDestinationFolder->Text;
	//Загружаем установки
	LoadOptions();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
	//Снятие формы с регистрации приемника файлов
	DragAcceptFiles(Handle,false);

	//Сохраняем установки
	SaveOptions();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::WMDROPFILES(TMessage &Msg)
{
	//Проверяем существует ли директория для сохранения файлов
	if(!DirectoryExists(EDestinationFolder->Text))
		if(!CreateDir(EDestinationFolder->Text))
		{
			ShowMessage("Невозможно создать каталог для размещения файлов");
			return;
		}	

	//формируем список перетащенных в главную форму файлов
	char Filename[256];
	list<string> list_file;
	int count;							//число перетащенных файлов

	count = DragQueryFile((void*)Msg.WParam,0xFFFFFFFF,Filename,sizeof(Filename));

	for(int i=0; i<count;i++)
	{
		//Запрос имени файла
		DragQueryFile((void*)Msg.WParam,i,Filename,sizeof(Filename));
		list_file.push_back(Filename);
	}
	//Завершение перетаскивания
	DragFinish((void*)Msg.WParam);

	AnsiString oldCaption = Caption;

	Caption = "Запускается Excel, подождите...";
	//Создаем Excel
	if(!CreateExcel())
	{
		Caption = oldCaption;
		return;
	}

	if(CBACADDrawing->Checked)
	{
		//Создаем автокад
		Caption = "Загружается AutoCAD, подождите...";
		try
		{
			acad = new cACAD;
		}
		catch(...)
		{
			Application->MessageBox("Невозможно открыть AutoCAD! Возможно "
			"AutoCAD не установлен на компьютере.","Ошибка",MB_OK+MB_ICONERROR);
			acad = NULL;
		}
	}

    Caption = "Выполняются расчеты, подождите...";
	Progress->Position = 1;
	Progress->Max = count+1;
	Progress->Visible = true;
	//Производим расчеты для всех перетащенных файлов
	for(list<string>::const_iterator i = list_file.begin(); i != list_file.end();
		i++)
	{
		Calculate(*i);
		Progress->Position++;
	}
	Caption = oldCaption;
	Progress->Visible = false;

	if(acad)
	{
		delete acad;
		acad = NULL;
	}
	DestroyExcel();
}
//---------------------------------------------------------------------------
void TForm1::Calculate(string file_name)
{
	// устанавливаем путь к файлу шаблона
	AnsiString file_template_name = ExtractFileDir(Application->ExeName)+"\\Шаблон.xlt";
	//открываем файл шаблона
	try
	{
		Excel.OlePropertyGet("WorkBooks").OleProcedure("Open",file_template_name.c_str(),0,false,1);
	}catch(...)
	{
		Application->MessageBox("Ошибка открытия книги Microsoft Excel!","Ошибка",MB_OK+MB_ICONERROR);
		return;
	}

	//загружаем точки из файла
	list<CPoint> list_point;
	if(RGCoord->ItemIndex==0)
		LoadPointFromFile(file_name,list_point);
	else //Если в исходном файле даны математические координаты, то меняем их местами
	{
		list<CPoint> list1;
		LoadPointFromFile(file_name,list1);
		for(list<CPoint>::const_iterator i_sour = list1.begin();i_sour != list1.end();i_sour++)
		{
			CPoint temp(i_sour->GetName(),i_sour->GetEast(),i_sour->GetNord());
			list_point.push_back(temp);
		}
	}

	//Формируем файл Excel с результатами вычислений
	WriteGeoData(list_point);
	WriteOpisanie2(list_point);
	WriteAreaSheet(list_point);
	WriteOpisanie1(list_point);

	//Формируем файл DWG с чертежом
	if(acad)
		WriteDrawing(list_point);

	//Формируем имя файла для сохранения результатов расчетов
	AnsiString res_file_name=EDestinationFolder->Text;
	if(*(res_file_name.AnsiLastChar())!='\\')
		res_file_name += '\\';
	//Получаем имя исходного файла и удаляем из него расширение
	res_file_name += ChangeFileExt(ExtractFileName(file_name.c_str()),"") + "-op";

	//Сохраняем результат расчетов в файл
	Excel.OlePropertyGet("WorkBooks",1).OleProcedure("SaveAs",res_file_name.c_str());
	//Закрываем файл
	Excel.OlePropertyGet("WorkBooks",1).OleProcedure("Close");

	//Сохраняем чертеж в файл
	if(acad)
		acad->SaveDrawingAndClose(res_file_name.c_str());
}
//---------------------------------------------------------------------------
void TForm1::WriteGeoData(const list<CPoint>& list_point)
{
	const int number_geo_data_sheet = 3;

	Variant Sheet=Excel.OlePropertyGet("WorkSheets",number_geo_data_sheet);

	int row = 2;     					//Номер строки для вставки данных
	//Создаем строки необходимые для помещения геоданных
	InsertExcelRow(number_geo_data_sheet,row,list_point.size()+1);

	list<CPoint>::const_iterator sled = list_point.begin();
	sled++;
	for(list<CPoint>::const_iterator tek = list_point.begin();tek != list_point.end();tek++)
	{
		if(sled == list_point.end())
		{
			sled = list_point.begin();
			toExcelCell(Sheet,row+1,1,sled->GetName());
		}

		toExcelCell(Sheet,row,1,tek->GetName());
		toExcelCell(Sheet,row,2,CalculateDirectAngle(*tek,*sled).GetValue(af_TO_MINUTE));
		toExcelCell(Sheet,row,3,FloatToStr(CalculateLength(*tek,*sled)));

		row++;
		sled++;
	}
	//Очищаем ссылку на лист
	Sheet.Clear();
}
//------------------------------------------------------------------------
void TForm1::WriteOpisanie1(const list<CPoint>& list_point)
{
	const int number_geo_data_sheet = 1;
	Variant Sheet=Excel.OlePropertyGet("WorkSheets",number_geo_data_sheet);
	//определяем СКП положения МЗ
	float rms;
	switch (RGRMS->ItemIndex)
	{
	case 0:
		rms=0.1;
		break;
	case 1:
		rms = 0.2;
		break;
	case 2:
		rms = 0.5;
		break;
	case 3:
		rms = 2.5;
		break;
	case 4:
		rms = 5.0;
		break;
	}
	//Формируем список с новыми точками
	list<CPoint> new_point;
	for(list<CPoint>::const_iterator i = list_point.begin();i != list_point.end();i++)
		if(i->GetType() == tp_NEW)
			new_point.push_back(*i);
    new_point.sort();
	int row = 9;                       	//Номер строки для вставки данных
	//Создаем строки необходимые для помещения сведений о новых точках
	InsertExcelRow(number_geo_data_sheet,row,new_point.size());

	//Помещаем сведения в файл
	for(list<CPoint>::const_iterator tek = new_point.begin();tek != new_point.end();tek++)
	{
		toExcelCell(Sheet,row,1,tek->GetName());
		toExcelCell(Sheet,row,2,Variant(tek->GetNord()));
		toExcelCell(Sheet,row,3,Variant(tek->GetEast()));
		toExcelCell(Sheet,row,4,Variant(rms));
		toExcelCell(Sheet,row,5,EPointZakr->Text);
		row++;
	}
	//Очищаем ссылку на лист
	Sheet.Clear();

}
//------------------------------------------------------------------------
void TForm1::WriteOpisanie2(const list<CPoint>& list_point)
{
	const int number_geo_data_sheet = 2;
	Variant Sheet=Excel.OlePropertyGet("WorkSheets",number_geo_data_sheet);
	//Определяем допустимое расхождении при контрольном измерении линии
	float rms = 2;
	switch (RGRMS->ItemIndex)
	{
	case 0:
		rms *= 0.1;
		break;
	case 1:
		rms *= 0.2;
		break;
	case 2:
		rms *= 0.5;
		break;
	case 3:
		rms *= 2.5;
		break;
	case 4:
		rms *= 5.0;
		break;
	}
	//Формируем список линий
	list<CKadastrLine> list_lines;
	list<CPoint>::const_iterator sled = list_point.begin();
	sled++;
	for(list<CPoint>::const_iterator tek = list_point.begin();tek != list_point.end();tek++,sled++)
	{
		if(sled == list_point.end())
			sled = list_point.begin();
		list_lines.push_back(CKadastrLine(*tek,*sled));
	}
	//Формируем список новых и уточненных линий,а также если необходимо список существующих участков
	list<CKadastrLine> list_new_lines,list_uto4_lines,list_exist_lines;
	for(list<CKadastrLine>::const_iterator i = list_lines.begin();i !=list_lines.end();i++)
		if(i->GetType() == tl_NEW)
			list_new_lines.push_back(*i);
		else if(i->GetType() == tl_Uto4n)
			list_uto4_lines.push_back(*i);
		else if(CHBExistGranic->Checked)  //i->GetType() == tl_EXIST && CHBExistGranic->Checked
			list_exist_lines.push_back(*i);
	list_new_lines.sort();
	list_uto4_lines.sort();
	list_exist_lines.sort();

	int row = 8;                       	//Номер строки для вставки данных
	//Создаем строки необходимые для помещения сведений о новых точках
	InsertExcelRow(number_geo_data_sheet,row,list_new_lines.size()+list_uto4_lines.size()+list_exist_lines.size());

	//Помещаем сведения об участках границ образованных существующими точками в файл,
	//Необходимо вручную удалить существующие участки границ
	for(list<CKadastrLine>::const_iterator i = list_exist_lines.begin();i != list_exist_lines.end();i++)
	{
		toExcelCell(Sheet,row,1,(i->GetBeginPoint().GetName() + " - " + i->GetEndPoint().GetName()));
		toExcelCell(Sheet,row,2,FloatToStr(i->GetLength()));
		toExcelCell(Sheet,row,3,Variant(rms));
		toExcelCell(Sheet,row,4,i->GetDirectAngle());
		toExcelCell(Sheet,row,5,AnsiString("-"));
		row++;
	}
	//Помещаем сведения о вновь образованных участках границ в файл
	for(list<CKadastrLine>::const_iterator i = list_new_lines.begin();i != list_new_lines.end();i++)
	{
		toExcelCell(Sheet,row,1,(i->GetBeginPoint().GetName() + " - " + i->GetEndPoint().GetName()));
		toExcelCell(Sheet,row,2,FloatToStr(i->GetLength()));
		toExcelCell(Sheet,row,3,Variant(rms));
		toExcelCell(Sheet,row,4,i->GetDirectAngle());
		toExcelCell(Sheet,row,5,AnsiString("-"));
		row++;
	}
	//Помещаем сведения об уточненных участках границ в файл
	for(list<CKadastrLine>::const_iterator i = list_uto4_lines.begin();i != list_uto4_lines.end();i++)
	{
		toExcelCell(Sheet,row,1,(i->GetBeginPoint().GetName() + " - " + i->GetEndPoint().GetName()));
		toExcelCell(Sheet,row,2,FloatToStr(i->GetLength()));
		toExcelCell(Sheet,row,3,Variant(rms));
		toExcelCell(Sheet,row,4,i->GetDirectAngle());
		toExcelCell(Sheet,row,5,AnsiString("-"));
		row++;
	}
	//Очищаем ссылку на лист
	Sheet.Clear();

}
//---------------------------------------------------------------------------
void TForm1::WriteAreaSheet(const list<CPoint>& list_point)
{
	const int number_geo_data_sheet = 4;
	Variant Sheet=Excel.OlePropertyGet("WorkSheets",number_geo_data_sheet);

	int row = 6;                       	//Номер строки для вставки данных
	//Создаем строки необходимые для помещения сведений о новых точках
	InsertExcelRow(number_geo_data_sheet,row,list_point.size());

	//Помещаем сведения в файл
	double col4 = 0, col5 = 0, col6 = 0, col7 = 0;
	double sum4 = 0, sum5 = 0, sum6 = 0, sum7 = 0;

	list<CPoint>::const_iterator Ci = list_point.begin();
	//Создаем вектор и переносим в него данные
	int v_size = list_point.size()+2;
	vector<CPoint> Vec(v_size);
	for(int i = 1;i < v_size-1; i++,Ci++)
	{
		if(i == 1)
			Vec[v_size-1] = *Ci;
		else if(i == v_size-2)
			Vec[0] = *Ci;
		Vec[i] = *Ci;
	}

	for(int pred = 0, tek = 1,sled = 2;tek < v_size-1;pred++,tek++,sled++,row++)
	{
		col4 = Vec[pred].GetNord() - Vec[sled].GetNord();
		col5 = Vec[sled].GetEast() - Vec[pred].GetEast();
		col6 = col4*Vec[tek].GetEast();
		col7 = col5*Vec[tek].GetNord();

		sum4 += col4,sum5 += col5,sum6 += col6,sum7 += col7;

		toExcelCell(Sheet,row,1,Vec[tek].GetName());
		toExcelCell(Sheet,row,2,Variant(Vec[tek].GetNord()));
		toExcelCell(Sheet,row,3,Variant(Vec[tek].GetEast()));
		toExcelCell(Sheet,row,4,Variant(col4));
		toExcelCell(Sheet,row,5,Variant(col5));
		toExcelCell(Sheet,row,6,Variant(col6));
		toExcelCell(Sheet,row,7,Variant(col7));
	}
	toExcelCell(Sheet,row,4,Variant(sum4));
	toExcelCell(Sheet,row,5,Variant(sum5));
	toExcelCell(Sheet,row,6,Variant(sum6));
	toExcelCell(Sheet,row,7,Variant(sum7));
	row++;

	double S6 = fabs(sum6/2);
	double S7 = fabs(sum7/2);
	toExcelCell(Sheet,row,6,Variant(S6));
	toExcelCell(Sheet,row,7,Variant(S7));
	row++;

	double s = (S6+S7)/2;
	toExcelCell(Sheet,row,6,Variant(s));
	row++;
	//Очищаем ссылку на лист
	Sheet.Clear();
}
//---------------------------------------------------------------------------
void TForm1::WriteDrawing(const list<CPoint>& list_point)
{
	//Формируем список линий
	list<CKadastrLine> list_lines;
	list<CPoint>::const_iterator sled = list_point.begin();
	sled++;
	for(list<CPoint>::const_iterator tek = list_point.begin();tek != list_point.end();tek++,sled++)
	{
		if(sled == list_point.end())
			sled = list_point.begin();
		list_lines.push_back(CKadastrLine(*tek,*sled));
	}
	acad->NewDrawing((ExtractFileDir(Application->ExeName)+"\\Шаблон.dwt").c_str());
	acad->WriteKadastrLines(list_lines);
	acad->WriteKadastrPoints(list_point);
	acad->BuildLayout();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::toExcelCell(Variant Sheet,int Row,int Column, AnsiString data)
{
	Variant  cur = Sheet.OlePropertyGet("Cells", Row,Column);
	cur.OlePropertySet("Value", data.c_str());
}
//------------------------------------------------------------------------
void __fastcall TForm1::toExcelCell(Variant Sheet, int Row,int Column, Variant data)
{
	Variant  cur = Sheet.OlePropertyGet("Cells", Row,Column);
    cur.OlePropertySet("Value", data);
}
//------------------------------------------------------------------------
void __fastcall TForm1::InsertExcelRow(int Sheet,int sRow,int count)
{
	//Вставляем дополнительные строки
	Variant C;
	Excel.OlePropertyGet("WorkSheets",Sheet).OleProcedure("Select");
	C=Excel.OlePropertyGet("Range",(IntToStr(sRow)+":"+IntToStr(sRow)).c_str());
	C=Excel.OlePropertyGet("Rows",(int)C.OlePropertyGet("Row")+1);
	for(int i=1;i<count-1;i++)
		C.OleProcedure("Insert");
}
//------------------------------------------------------------------------
void __fastcall TForm1::BSelectFolderClick(TObject *Sender)
{
	AnsiString Directory;
	//Проверяем существует ли текущая директория
	if(DirectoryExists(EDestinationFolder->Text))
		Directory = EDestinationFolder->Text;
	else
		Directory = GetCurrentDir();
	if(SelectDirectory("Укажите каталог для сохранения результатов вычисления",
						"",Directory))
	{
		EDestinationFolder->Hint = Directory;
		EDestinationFolder->Text = Directory;
    }
}
//---------------------------------------------------------------------------
void TForm1::SaveOptions()
{
	const AnsiString ini_file_name = ExtractFileDir(Application->ExeName)+"\\options.ini";
	//Проверяем наличие файла с настройками приложения
	if ((!FileExists(ini_file_name)))
	{
		FILE* F;
		//Создаем файл .ini
		if((F=fopen(ini_file_name.c_str(),"w+")) == NULL)
			return;
		fclose(F);
	}
	TIniFile* Ini = new TIniFile(ini_file_name);
	Ini->WriteInteger("Default val",RGRMS->Name,RGRMS->ItemIndex);
	Ini->WriteInteger("Default val",RGCoord->Name,RGCoord->ItemIndex);
	Ini->WriteString("Default val",EPointZakr->Name,EPointZakr->Text);
	Ini->WriteString("Default val",EDestinationFolder->Name,EDestinationFolder->Text);
	Ini->WriteBool("Default val",CHBExistGranic->Name,CHBExistGranic->Checked);
	Ini->WriteBool("Default val",CBACADDrawing->Name,CBACADDrawing->Checked);
	Ini->UpdateFile();
	delete Ini;
}
//---------------------------------------------------------------------------
void TForm1::LoadOptions()
{
	const AnsiString ini_file_name = ExtractFileDir(Application->ExeName)+"\\options.ini";
	//Проверяем наличие файла с настройками приложения
	if ((!FileExists(ini_file_name)))
		return;
    TIniFile* Ini = new TIniFile(ini_file_name);
	RGRMS->ItemIndex = Ini->ReadInteger("Default val",RGRMS->Name,0);
	RGCoord->ItemIndex = Ini->ReadInteger("Default val",RGCoord->Name,0);
	EPointZakr->Text = Ini->ReadString("Default val",EPointZakr->Name,0);
	EDestinationFolder->Text = Ini->ReadString("Default val",EDestinationFolder->Name,0);
	EDestinationFolder->Hint = EDestinationFolder->Text;
	CHBExistGranic->Checked = Ini->ReadBool("Default val",CHBExistGranic->Name,false);  
	CBACADDrawing->Checked = Ini->ReadBool("Default val",CBACADDrawing->Name,true);
	delete Ini;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BACADClick(TObject *Sender)
{
	Visible=false;
	FNumer->ShowModal();
	Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BAboutClick(TObject *Sender)
{
	FAboutBox->ShowModal();
}
//---------------------------------------------------------------------------
bool TForm1::CreateExcel()
{
	//Создание сервера автоматизации Excel
	try
	{
		Excel = CreateOleObject("Excel.Application");
		Excel.OlePropertySet("DisplayAlerts", false);
	}catch(...)
	{
		Application->MessageBox("Невозможно открыть Microsoft Excel! Возможно "
		"Excel не установлен на компьютере.","Ошибка",MB_OK+MB_ICONERROR);
		return false;
	}
	return true;
}
//---------------------------------------------------------------------------
void TForm1::DestroyExcel()
{
	//Закрытие сервера автоматизации Excel
	Excel.OleProcedure("Quit");
	Excel.Clear();
}
//---------------------------------------------------------------------------
