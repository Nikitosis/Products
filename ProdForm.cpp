//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#ifndef _MYINCL1_H
#define _MYINCL1_H

#include "ProdForm.h"
#include "Products.h"
#include "MealsForm.h"
#include "Meals.h"
#include <math.h>
#include "Math.hpp"
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
int n;

///////////
while(Edit2->Text[1]=='0')           //������� ������ ���� � ������
{
	if(Edit2->Text.Length()>1)
	{
		if(Edit2->Text[2]!=',')
			Edit2->Text=Edit2->Text.Delete(1,1);
		   else
		   break;
	}
	else break;
}
if(Edit2->Text[Edit2->Text.Length()]==',')                 //������� ��������� ����
	Edit2->Text=Edit2->Text.Delete(Edit2->Text.Length(),1);

while(Edit3->Text[1]=='0')
{
	if(Edit3->Text.Length()>1)
	{
		if(Edit3->Text[2]!=',')
			Edit3->Text=Edit3->Text.Delete(1,1);
		   else
		   break;
	}
	else break;
}
if(Edit3->Text[Edit3->Text.Length()]==',')
	Edit3->Text=Edit3->Text.Delete(Edit3->Text.Length(),1);

while(Edit4->Text[1]=='0')
{
	if(Edit4->Text.Length()>1)
	{
		if(Edit4->Text[2]!=',')
			Edit4->Text=Edit4->Text.Delete(1,1);
		   else
		   break;
	}
	else break;
}
if(Edit4->Text[Edit4->Text.Length()]==',')
	Edit4->Text=Edit4->Text.Delete(Edit4->Text.Length(),1);
////////////


double sum;
sum=Edit2->Text.ToDouble()+Edit3->Text.ToDouble()+Edit4->Text.ToDouble();
if(sum==0)           //���� �� ���� ������� �� ����
	sum=1;
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
	Form2->Images[n]->Left=300;
	Form2->Images[n]->Height=Form2->PanelH-1;
	Form2->Images[n]->Width=125;
	Form2->Images[n]->Picture=Image1->Picture;
	Form2->Images[n]->Stretch=true;

	Form2->Labeles[n*5]=new TLabel(Form2);
	Form2->Labeles[n*5]->Parent=Form2->Panels[n];
	Form2->Labeles[n*5]->Top=20;
	Form2->Labeles[n*5]->Left=10;
	Form2->Labeles[n*5]->WordWrap=true;
	Form2->Labeles[n*5]->AutoSize=false;
	Form2->Labeles[n*5]->Height=80;
	Form2->Labeles[n*5]->Width=270;
	Form2->Labeles[n*5]->Font->Size=14;
	Form2->Labeles[n*5]->Caption=Edit1->Text;

	Form2->Labeles[n*5+1]=new TLabel(Form2);
	Form2->Labeles[n*5+1]->Parent=Form2->Panels[n];
	Form2->Labeles[n*5+1]->Top=20;
	Form2->Labeles[n*5+1]->Left=450;
	Form2->Labeles[n*5+1]->WordWrap=true;
	Form2->Labeles[n*5+1]->AutoSize=false;
	Form2->Labeles[n*5+1]->Height=40;
	Form2->Labeles[n*5+1]->Width=50;
	Form2->Labeles[n*5+1]->Font->Size=10;
	Form2->Labeles[n*5+1]->Caption=FloatToStr(SimpleRoundTo(StrToFloat(Edit2->Text)/sum*1000,0));

	Form2->Labeles[n*5+2]=new TLabel(Form2);
	Form2->Labeles[n*5+2]->Parent=Form2->Panels[n];
	Form2->Labeles[n*5+2]->Top=20;
	Form2->Labeles[n*5+2]->Left=573;
	Form2->Labeles[n*5+2]->WordWrap=true;
	Form2->Labeles[n*5+2]->AutoSize=false;
	Form2->Labeles[n*5+2]->Height=20;
	Form2->Labeles[n*5+2]->Width=50;
	Form2->Labeles[n*5+2]->Font->Size=10;
	Form2->Labeles[n*5+2]->Caption=FloatToStr(SimpleRoundTo(StrToFloat(Edit3->Text)/sum*1000,0));

	Form2->Labeles[n*5+3]=new TLabel(Form2);
	Form2->Labeles[n*5+3]->Parent=Form2->Panels[n];
	Form2->Labeles[n*5+3]->Top=20;
	Form2->Labeles[n*5+3]->Left=696;
	Form2->Labeles[n*5+3]->WordWrap=true;
	Form2->Labeles[n*5+3]->AutoSize=false;
	Form2->Labeles[n*5+3]->Height=20;
	Form2->Labeles[n*5+3]->Width=50;
	Form2->Labeles[n*5+3]->Font->Size=10;
	Form2->Labeles[n*5+3]->Caption=FloatToStr(SimpleRoundTo(StrToFloat(Edit4->Text)/sum*1000,0));

	Form2->Labeles[n*5+4]=new TLabel(Form2);
	Form2->Labeles[n*5+4]->Parent=Form2->Panels[n];
	Form2->Labeles[n*5+4]->Top=20;
	Form2->Labeles[n*5+4]->Left=819;
	Form2->Labeles[n*5+4]->WordWrap=true;
	Form2->Labeles[n*5+4]->AutoSize=false;
	Form2->Labeles[n*5+4]->Height=20;
	Form2->Labeles[n*5+4]->Width=50;
	Form2->Labeles[n*5+4]->Font->Size=10;
	double n1=StrToInt(Form2->Labeles[n*5+1]->Caption)*0.004;
	double n2=StrToInt(Form2->Labeles[n*5+2]->Caption)*0.009;
	double n3=StrToInt(Form2->Labeles[n*5+3]->Caption)*0.004;
	Form2->Labeles[n*5+4]->Caption=FloatToStr(SimpleRoundTo(n1+n2+n3,-2));
   //	Form2->Labeles[n*5+4]->Caption=Edit;

	Form2->Buttons[n]=new TButton(Form2);
	Form2->Buttons[n]->Parent=Form2->Panels[n];
	Form2->Buttons[n]->Left=920;
	Form2->Buttons[n]->Height=Form2->PanelH-1;
	Form2->Buttons[n]->Width=100;
	Form2->Buttons[n]->Tag=n;
	Form2->Buttons[n]->OnClick=Form2->PropClick;

	TImage *line=new TImage(Form2);               //������ �����
	line->Parent=Form2->Panels[n];
	line->Left=300;
	line->Width=2;
	line->Height=Form2->PanelH-1;
	line->Picture->Bitmap->Width=2;
	line->Picture->Bitmap->Height=Form2->PanelH-1;
	line->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

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

	TImage *line6=new TImage(Form2);
	line6->Parent=Form2->Panels[n];
	line6->Left=919;
	line6->Width=2;
	line6->Height=Form2->PanelH-1;
	line6->Picture->Bitmap->Width=2;
	line6->Picture->Bitmap->Height=Form2->PanelH-1;
	line6->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line6->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));
	Masses[n*3]=Edit2->Text;        //����� ������ ��������� ����������
	Masses[n*3+1]=Edit3->Text;
   	Masses[n*3+2]=Edit4->Text;
}
	else
	{

        n=Form2->PropNum;
		Form2->Images[n]->Picture=Image1->Picture;
		Form2->Labeles[n*5]->Caption=Edit1->Text;

		Masses[n*3]=Edit2->Text;        //����� ������ ��������� ����������
		Masses[n*3+1]=Edit3->Text;
		Masses[n*3+2]=Edit4->Text;

		Form2->Labeles[n*5+1]->Caption=FloatToStr(SimpleRoundTo(StrToFloat(Edit2->Text)/sum*1000,0));
		Form2->Labeles[n*5+2]->Caption=FloatToStr(SimpleRoundTo(StrToFloat(Edit3->Text)/sum*1000,0));
		Form2->Labeles[n*5+3]->Caption=FloatToStr(SimpleRoundTo(StrToFloat(Edit4->Text)/sum*1000,0));
		double n1=StrToInt(Form2->Labeles[n*5+1]->Caption)*0.004;
		double n2=StrToInt(Form2->Labeles[n*5+2]->Caption)*0.009;
		double n3=StrToInt(Form2->Labeles[n*5+3]->Caption)*0.004;
		Form2->Labeles[n*5+4]->Caption=FloatToStr(SimpleRoundTo(n1+n2+n3,-2));
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
	if(Form2->IsDel[i]==false)
		Form2->Panels[i]->Top-=Form2->PanelH;
}
Form2->Panels[num]->Free();
Form2->IsDel[num]=true;
Form2->ProductsDel++;

for(int i=0;i<Form3->ProductsHave+Form3->ProductsUse;i++)
if(Form3->PanelsHave[i]->Tag==num)
	for(int j=0;j<Form2->ProductsA;j++)
	{
		Form3->IsLeft[j][num]=false;
		Form3->IsRight[j][num]=false;
	}

for(int i=0;i<Form3->MealsA;i++)
if(Form3->IsDelMeal[i]==false)
{
	Form3->Labeles[i*5+1]->Caption="0";
	Form3->Labeles[i*5+2]->Caption="0";
	Form3->Labeles[i*5+3]->Caption="0";
	Form3->Labeles[i*5+4]->Caption="0";
	Form3->PropClickNum(i);
	Form6->Close();
}

Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm5::Edit2Change(TObject *Sender)
{
TEdit *Edit = dynamic_cast<TEdit *>(Sender);
bool flag=false;
for(int i=1;i<=Edit->Text.Length();i++)
{
	if(Edit->Text[i]==',' && flag)        //��������� �� ������� ������ �����
	{
		Edit->Text=Edit->Text.Delete(i,1);
		continue;
	}
	if(Edit->Text[i]==',')
	{
		flag=true;
	}

	if(!((Edit->Text[i]>='0' && Edit->Text[i]<='9') || Edit->Text[i]==','))
	Edit->Text=Edit->Text.Delete(i,1);
}
}
//---------------------------------------------------------------------------

