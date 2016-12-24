//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#ifndef _MYINCL1_H
#define _MYINCL1_H

#include "ProdForm.h"
#include "Products.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
if (OpenPictureDialog1->Execute())
	{
		 Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button2Click(TObject *Sender)
{
int n=Form2->ProductsA-1;
if(Button4->Visible==false)     //���� ������ ������� ��������(�� ����� ����� ������ ��������)
{
	Form2->ProductsA++;
	n=Form2->ProductsA-1;
	int k;
	k=Form2->ScrollBox1->VertScrollBar->Position;  //����� �����������,����� �����. ��������
	Form2->ScrollBox1->VertScrollBar->Position=0;

	Form2->Panels[n]=new TPanel(Form2);
	Form2->Panels[n]->Parent=Form2->ScrollBox1;
	Form2->Panels[n]->Top=(Form2->ProductsA-1-Form2->ProductsDel)*Form2->PanelH;
	Form2->Panels[n]->Left=0;
	Form2->Panels[n]->Width=Form2->ScrollBox1->Width-4;
	Form2->Panels[n]->Height=Form2->PanelH;

	Form2->ScrollBox1->VertScrollBar->Position=k;


	Form2->Images[n]=new TImage(Form2);
	Form2->Images[n]->Parent=Form2->Panels[n];
	Form2->Images[n]->Left=150;
	Form2->Images[n]->Height=Form2->PanelH-1;
	Form2->Images[n]->Width=125;
	Form2->Images[n]->Picture=Image1->Picture;
	Form2->Images[n]->Stretch=true;


	Form2->Edits[n]=new TMemo(Form2);
	Form2->Edits[n]->Parent=Form2->Panels[n];
	Form2->Edits[n]->Left=277;
	Form2->Edits[n]->Height=Form2->PanelH-1;
	Form2->Edits[n]->Width=150;
	Form2->Edits[n]->Lines->Text=Edit5->Lines->Text;
	Form2->Edits[n]->ReadOnly=true;
	Form2->Edits[n]->ScrollBars=ssBoth;

	Form2->Labeles[n*4]=new TLabel(Form2);
	Form2->Labeles[n*4]->Parent=Form2->Panels[n];
	Form2->Labeles[n*4]->Top=40;
	Form2->Labeles[n*4]->Left=10;
	Form2->Labeles[n*4]->WordWrap=true;
	Form2->Labeles[n*4]->AutoSize=false;
	Form2->Labeles[n*4]->Height=50;
	Form2->Labeles[n*4]->Width=130;
	Form2->Labeles[n*4]->Font->Size=14;
	Form2->Labeles[n*4]->Caption=Edit1->Text;

	Form2->Labeles[n*4+1]=new TLabel(Form2);
	Form2->Labeles[n*4+1]->Parent=Form2->Panels[n];
	Form2->Labeles[n*4+1]->Top=40;
	Form2->Labeles[n*4+1]->Left=450;
	Form2->Labeles[n*4+1]->WordWrap=true;
	Form2->Labeles[n*4+1]->AutoSize=false;
	Form2->Labeles[n*4+1]->Height=20;
	Form2->Labeles[n*4+1]->Width=50;
	Form2->Labeles[n*4+1]->Font->Size=10;
	Form2->Labeles[n*4+1]->Caption=Edit2->Text;

	Form2->Labeles[n*4+2]=new TLabel(Form2);
	Form2->Labeles[n*4+2]->Parent=Form2->Panels[n];
	Form2->Labeles[n*4+2]->Top=40;
	Form2->Labeles[n*4+2]->Left=573;
	Form2->Labeles[n*4+2]->WordWrap=true;
	Form2->Labeles[n*4+2]->AutoSize=false;
	Form2->Labeles[n*4+2]->Height=20;
	Form2->Labeles[n*4+2]->Width=50;
	Form2->Labeles[n*4+2]->Font->Size=10;
	Form2->Labeles[n*4+2]->Caption=Edit3->Text;

	Form2->Labeles[n*4+3]=new TLabel(Form2);
	Form2->Labeles[n*4+3]->Parent=Form2->Panels[n];
	Form2->Labeles[n*4+3]->Top=40;
	Form2->Labeles[n*4+3]->Left=696;
	Form2->Labeles[n*4+3]->WordWrap=true;
	Form2->Labeles[n*4+3]->AutoSize=false;
	Form2->Labeles[n*4+3]->Height=20;
	Form2->Labeles[n*4+3]->Width=50;
	Form2->Labeles[n*4+3]->Font->Size=10;
	Form2->Labeles[n*4+3]->Caption=Edit4->Text;

	Form2->Buttons[n]=new TButton(Form2);
	Form2->Buttons[n]->Parent=Form2->Panels[n];
	Form2->Buttons[n]->Left=797;
	Form2->Buttons[n]->Height=Form2->PanelH-1;
	Form2->Buttons[n]->Width=100;
	Form2->Buttons[n]->Tag=n;
	Form2->Buttons[n]->OnClick=Form2->PropClick;

	TImage *line=new TImage(Form2);               //������ �����
	line->Parent=Form2->Panels[n];
	line->Left=150;
	line->Width=2;
	line->Height=Form2->PanelH-1;
	line->Picture->Bitmap->Width=2;
	line->Picture->Bitmap->Height=Form2->PanelH-1;
	line->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

	TImage *line1=new TImage(Form2);
	line1->Parent=Form2->Panels[n];
	line1->Left=275;
	line1->Width=2;
	line1->Height=Form2->PanelH-1;
	line1->Picture->Bitmap->Width=2;
	line1->Picture->Bitmap->Height=Form2->PanelH-1;
	line1->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line1->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

	TImage *line2=new TImage(Form2);
	line2->Parent=Form2->Panels[n];
	line2->Left=427;
	line2->Width=2;
	line2->Height=Form2->PanelH-1;
	line2->Picture->Bitmap->Width=2;
	line2->Picture->Bitmap->Height=Form2->PanelH-1;
	line2->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line2->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

	TImage *line3=new TImage(Form2);
	line3->Parent=Form2->Panels[n];
	line3->Left=550;
	line3->Width=2;
	line3->Height=Form2->PanelH-1;
	line3->Picture->Bitmap->Width=2;
	line3->Picture->Bitmap->Height=Form2->PanelH-1;
	line3->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line3->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

	TImage *line4=new TImage(Form2);
	line4->Parent=Form2->Panels[n];
	line4->Left=673;
	line4->Width=2;
	line4->Height=Form2->PanelH-1;
	line4->Picture->Bitmap->Width=2;
	line4->Picture->Bitmap->Height=Form2->PanelH-1;
	line4->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line4->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

	TImage *line5=new TImage(Form2);
	line5->Parent=Form2->Panels[n];
	line5->Left=796;
	line5->Width=2;
	line5->Height=Form2->PanelH-1;
	line5->Picture->Bitmap->Width=2;
	line5->Picture->Bitmap->Height=Form2->PanelH-1;
	line5->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line5->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));
}
	else
	{
		Form2->Images[n]->Picture=Image1->Picture;
		Form2->Edits[n]->Lines->Text=Edit5->Lines->Text;
		Form2->Labeles[n*4]->Caption=Edit1->Text;
		Form2->Labeles[n*4+1]->Caption=Edit2->Text;
		Form2->Labeles[n*4+2]->Caption=Edit3->Text;
		Form2->Labeles[n*4+3]->Caption=Edit4->Text;
    }

Close();
}
void __fastcall TForm5::Button3Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
#endif


//---------------------------------------------------------------------------



void __fastcall TForm5::Button4Click(TObject *Sender)
{
int num=Form2->PropNum;
int n=Form2->ProductsA-1;
for(int i=num+1;i<n+1;i++)
{
	Form2->Panels[i]->Top-=Form2->PanelH;
}
Form2->Panels[num]->Free();
Form2->ProductsDel++;

Close();
}
//---------------------------------------------------------------------------

