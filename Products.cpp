//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Products.h"
#include "Main.h"
#include "Meals.h"
#include "Recommend.h"
#include "ProdForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;


const int PanelH=100;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	PanelH=100;
	memset(IsDel,false,200*sizeof(bool));
}
//---------------------------------------------------------------------------

void __fastcall TForm2::PropClick(TObject *Sender)                //при клике на кнопку настройки
{
	TBitBtn *btn = dynamic_cast<TBitBtn *>(Sender);       //переводим Sender в TButton
	int num=btn->Tag;
	Form5->Image1->Picture=Images[num]->Picture;
	Form5->Edit1->Text=Labeles[(num)*5]->Caption;
	Form5->Edit2->Text=Labeles[(num)*5+1]->Caption;
	Form5->Edit3->Text=Labeles[(num)*5+2]->Caption;
	Form5->Edit4->Text=Labeles[(num)*5+3]->Caption;
	PropNum=num;
	Form5->Button4->Visible=true;

	Form5->Edit2->Text=Form5->Masses[num*3];
	Form5->Edit3->Text=Form5->Masses[num*3+1];
	Form5->Edit4->Text=Form5->Masses[num*3+2];
    Form5->Show();
}
void __fastcall TForm2::Button1Click(TObject *Sender)
{

	Form5->Edit1->Text="";
	Form5->Edit2->Text="0";
	Form5->Edit3->Text="0";
	Form5->Edit4->Text="0";
	Form5->Image1->Picture=Form5->Image2->Picture;
	Form5->Button4->Visible=false;
	Form5->Show();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm2::Save1Click(TObject *Sender)
{
Form1->Save1Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Load1Click(TObject *Sender)
{
Form1->Load1Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
memset(Form2->IsDel,false,200*sizeof(bool));
ProductsA=0;
ProductsDel=0;
SettingsNum=-1;
PictureNum=0;
}
//---------------------------------------------------------------------------



void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
//Form1->Visible=true;
Form5->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
	if(SettingsNum>=0)
	{
	   AnsiString s=ExtractFilePath(Application->ExeName);
	   s+="/SettingButtons/"+IntToStr(PictureNum)+".bmp";
	   Form2->Buttons[SettingsNum]->Glyph->LoadFromFile(s);
	   PictureNum++;
	   PictureNum%=3;
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm2::FormMouseEnter(TObject *Sender)
{
	SettingsNum=-1;
	PictureNum=0;
	AnsiString s=ExtractFilePath(Application->ExeName);
	s+="/MenuButtons/Button.png";
	Button1->Picture->LoadFromFile(s);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button1MouseEnter(TObject *Sender)
{
	AnsiString s=ExtractFilePath(Application->ExeName);
	s+="/MenuButtons/MouseEnter.png";
	Button1->Picture->LoadFromFile(s);
}
//---------------------------------------------------------------------------

