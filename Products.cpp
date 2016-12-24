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
}
//---------------------------------------------------------------------------

void __fastcall TForm2::PropClick(TObject *Sender)                //��� ����� �� ������ ���������
{
	TButton *btn = dynamic_cast<TButton *>(Sender);       //��������� Sender � TButton
	int num=btn->Tag;
	Form5->Image1->Picture=Images[num]->Picture;
	Form5->Edit1->Text=Labeles[(num)*4]->Caption;
	Form5->Edit2->Text=Labeles[(num)*4+1]->Caption;
	Form5->Edit3->Text=Labeles[(num)*4+2]->Caption;
	Form5->Edit4->Text=Labeles[(num)*4+3]->Caption;
	Form5->Edit5->Text=Edits[num]->Text;
	PropNum=num;
	Form5->Button4->Visible=true;
    Form5->Show();
}
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	Form5->Edit1->Text="";
	Form5->Edit2->Text="0";
	Form5->Edit3->Text="0";
	Form5->Edit4->Text="0";
	Form5->Edit5->Text="";
	Form5->Image1->Picture=Form5->Image2->Picture;
	Form5->Button4->Visible=false;
	Form5->Show();
}
//---------------------------------------------------------------------------

