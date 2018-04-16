// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>

#include "Products.h"
#include "Main.h"
#include "Meals.h"
#include "Recommend.h"
#include "RecommendDialog.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

// ---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender) {
	if (Edit1->Text == "" || Edit2->Text == "" || Edit3->Text == "") {
		ShowMessage("�������� ���� ������,���� �� ���");
	}
	else if (ComboBox1->ItemIndex < 0 || ComboBox2->ItemIndex < 0)
		ShowMessage("������ ���� ����� �� ����� ���������");
	else {
		double weight = StrToInt(Edit2->Text);
		double height = StrToInt(Edit1->Text);
		double age = StrToInt(Edit3->Text);
		if (ComboBox1->ItemIndex == 0)
			BMR =(10 * weight) + (6.25 * height) - (5 * age)+5;
		else
			BMR = (10 * weight) + (6.25 * height) - (5 * age)-161;
		if (ComboBox2->ItemIndex == 0)
			BMR *= 1.2;
		if (ComboBox2->ItemIndex == 1)
			BMR *= 1.375;
		if (ComboBox2->ItemIndex == 2)
			BMR *= 1.55;
		if (ComboBox2->ItemIndex == 3)
			BMR *= 1.725;
		if (ComboBox2->ItemIndex == 4)
			BMR *= 1.9;
		BMR = ceil(BMR);
		Form8->Label1->Caption =
			"���� ������������� ������� ������ �� ����: " + FloatToStr(BMR);
		Form8->BMR = BMR;
		Form8->ShowModal();
	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action) {
	Form1->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm4::Button1MouseEnter(TObject *Sender)
{
	AnsiString s=ExtractFilePath(Application->ExeName);
	Button1->Picture->LoadFromFile(s+"/RecomButton/MouseEnter.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormMouseEnter(TObject *Sender)
{
	AnsiString s=ExtractFilePath(Application->ExeName);
	Button1->Picture->LoadFromFile(s+"/RecomButton/Button.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button6Click(TObject *Sender)
{
TButton *button = dynamic_cast<TButton *>(Sender);         //�����+�����
AnsiString s=Form4->Components[FocusIndex]->ClassName();
if(Form4->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form4->Components[FocusIndex];
	  int start=edit->SelStart;
	  AnsiString s=edit->Text;
	  s.Delete(start+1,edit->SelLength);    //���� ��������,�� ��������
	  s.Insert(button->Caption,start+1);    //��������� �����
	  edit->SetFocus();
	  edit->Text=s;
	  edit->SelStart=start+1;
	  edit->SelLength=0;
	}
}

//---------------------------------------------------------------------------


void __fastcall TForm4::FormShow(TObject *Sender)
{
FocusIndex=1;
if(Form1->IsKeyboard)
	{
	Height=476;
	Panel4->Visible=true;
	}
	else
	{
	Height=390;
	Panel4->Visible=false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button6MouseEnter(TObject *Sender)
{
for(int i=0;i<Form4->ComponentCount-1;i++)
	{
	   if(Form4->ActiveControl==Form4->Components[i] && Form4->Components[i]->ClassName()=="TEdit")
		FocusIndex=i;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm4::BackspaceClick(TObject *Sender)
{
 TButton *button = dynamic_cast<TButton *>(Sender);         //backspace
  AnsiString s=Form4->Components[FocusIndex]->ClassName();
if(Form4->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form4->Components[FocusIndex];
	  int start=edit->SelStart;
	  if(edit->SelLength!=0)
		start++;
	  AnsiString s=edit->Text;
	  int length=edit->SelLength;
	  if(length==0)
		length=1;
	  s.Delete(start,length);
	  edit->SetFocus();
	  edit->Text=s;
	  if(start!=0)
		 edit->SelStart=start-1;
	  edit->SelLength=0;
	}
}
//---------------------------------------------------------------------------

