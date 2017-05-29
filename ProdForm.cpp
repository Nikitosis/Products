﻿//---------------------------------------------------------------------------

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
#include "Main.h"
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
if(Edit2->Text=="")     //если пустое место в едите
Edit2->Text='0';
if(Edit3->Text=="")
Edit2->Text='0';
if(Edit4->Text=="")
Edit4->Text='0';
while(Edit2->Text[1]=='0')           //удаляем первые нули в массах
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
if(Edit2->Text[Edit2->Text.Length()]==',')                 //удаляем последнюю кому
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
//sum=Edit2->Text.ToDouble()+Edit3->Text.ToDouble()+Edit4->Text.ToDouble();
//if(sum==0)           //чтоб не было деления на ноль
 //	sum=1;
sum=100;
if(StrToFloat(Edit2->Text)+StrToFloat(Edit3->Text)+StrToFloat(Edit4->Text)>100)   //если сумма бжу > массы продукта
{
	ShowMessage("Максимальная сумма белков,жиров и углеводов-100г");
	return;
}
if(Button4->Visible==false)     //если кнопка удалить невидима(мы зашли через кнопку добавить)
{

	Form2->ProductsA++;
	n=Form2->ProductsA-1;
	int k;
	k=Form2->ScrollBox1->VertScrollBar->Position;  //нужно обязательно,иначе появл. пропуски
	Form2->ScrollBox1->VertScrollBar->Position=0;

	Form2->Panels[n]=new TPanel(Form2);
	Form2->Panels[n]->Parent=Form2->ScrollBox1;
	Form2->Panels[n]->Top=(Form2->ProductsA-1-Form2->ProductsDel)*Form2->PanelH;
	Form2->Panels[n]->Left=0;
	Form2->Panels[n]->Width=Form2->ScrollBox1->Width-4;
	Form2->Panels[n]->Height=Form2->PanelH;
	Form2->Panels[n]->OnMouseEnter=Form2->OnMouseEnter;

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
	Form2->Labeles[n*5+1]->Left=440;
	Form2->Labeles[n*5+1]->WordWrap=true;
	Form2->Labeles[n*5+1]->AutoSize=false;
	Form2->Labeles[n*5+1]->Height=40;
	Form2->Labeles[n*5+1]->Width=50;
	Form2->Labeles[n*5+1]->Font->Size=10;
	Form2->Labeles[n*5+1]->Caption=FloatToStr(SimpleRoundTo(StrToFloat(Edit2->Text)/sum*1000,0));

	Form2->Labeles[n*5+2]=new TLabel(Form2);
	Form2->Labeles[n*5+2]->Parent=Form2->Panels[n];
	Form2->Labeles[n*5+2]->Top=20;
	Form2->Labeles[n*5+2]->Left=533;
	Form2->Labeles[n*5+2]->WordWrap=true;
	Form2->Labeles[n*5+2]->AutoSize=false;
	Form2->Labeles[n*5+2]->Height=20;
	Form2->Labeles[n*5+2]->Width=50;
	Form2->Labeles[n*5+2]->Font->Size=10;
	Form2->Labeles[n*5+2]->Caption=FloatToStr(SimpleRoundTo(StrToFloat(Edit3->Text)/sum*1000,0));

	Form2->Labeles[n*5+3]=new TLabel(Form2);
	Form2->Labeles[n*5+3]->Parent=Form2->Panels[n];
	Form2->Labeles[n*5+3]->Top=20;
	Form2->Labeles[n*5+3]->Left=625;
	Form2->Labeles[n*5+3]->WordWrap=true;
	Form2->Labeles[n*5+3]->AutoSize=false;
	Form2->Labeles[n*5+3]->Height=20;
	Form2->Labeles[n*5+3]->Width=50;
	Form2->Labeles[n*5+3]->Font->Size=10;
	Form2->Labeles[n*5+3]->Caption=FloatToStr(SimpleRoundTo(StrToFloat(Edit4->Text)/sum*1000,0));

	Form2->Labeles[n*5+4]=new TLabel(Form2);
	Form2->Labeles[n*5+4]->Parent=Form2->Panels[n];
	Form2->Labeles[n*5+4]->Top=20;
	Form2->Labeles[n*5+4]->Left=719;
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

	Form2->Buttons[n]=new TBitBtn(Form2);
	Form2->Buttons[n]->Parent=Form2->Panels[n];
	Form2->Buttons[n]->Left=820;
	Form2->Buttons[n]->Height=Form2->PanelH-1;
	Form2->Buttons[n]->Width=100;
	Form2->Buttons[n]->Tag=n;
	Form2->Buttons[n]->OnClick=Form2->PropClick;
	Form2->Buttons[n]->Glyph=BitBtn1->Glyph;
	Form2->Buttons[n]->OnMouseEnter=SettingsEnter;

	TImage *line=new TImage(Form2);               //рисуем линии
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
	line3->Left=520;
	line3->Width=2;
	line3->Height=Form2->PanelH-1;
	line3->Picture->Bitmap->Width=2;
	line3->Picture->Bitmap->Height=Form2->PanelH-1;
	line3->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line3->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

	TImage *line4=new TImage(Form2);
	line4->Parent=Form2->Panels[n];
	line4->Left=613;
	line4->Width=2;
	line4->Height=Form2->PanelH-1;
	line4->Picture->Bitmap->Width=2;
	line4->Picture->Bitmap->Height=Form2->PanelH-1;
	line4->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line4->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

	TImage *line5=new TImage(Form2);
	line5->Parent=Form2->Panels[n];
	line5->Left=706;
	line5->Width=2;
	line5->Height=Form2->PanelH-1;
	line5->Picture->Bitmap->Width=2;
	line5->Picture->Bitmap->Height=Form2->PanelH-1;
	line5->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line5->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

	TImage *line6=new TImage(Form2);
	line6->Parent=Form2->Panels[n];
	line6->Left=819;
	line6->Width=2;
	line6->Height=Form2->PanelH-1;
	line6->Picture->Bitmap->Width=2;
	line6->Picture->Bitmap->Height=Form2->PanelH-1;
	line6->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line6->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));
	Masses[n*3]=Edit2->Text;        //массы белков углеводов запоминаем
	Masses[n*3+1]=Edit3->Text;
   	Masses[n*3+2]=Edit4->Text;
}
	else
	{

        n=Form2->PropNum;
		Form2->Images[n]->Picture=Image1->Picture;
		Form2->Labeles[n*5]->Caption=Edit1->Text;

		Masses[n*3]=Edit2->Text;        //массы белков углеводов запоминаем
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
Form3->WasDeleted=num;

for(int i=0;i<Form3->ProductsHave+Form3->ProductsUse;i++)
if(Form3->PanelsHave[i]->Tag==num)
{
	for(int j=0;j<Form2->ProductsA;j++)
	{
		Form3->IsLeft[j][num]=false;
		Form3->IsRight[j][num]=false;
	}
}
/*for(int i=0;i<Form2->ProductsA;i++)
	if(Form2->Panels[i]->Tag==num)
		Form2->Panels[i]->Free();  */
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

Form3->WasDeleted=-1;
Form3->Close();
Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm5::Edit2Change(TObject *Sender)
{
TEdit *Edit = dynamic_cast<TEdit *>(Sender);
bool flag=false;
for(int i=1;i<=Edit->Text.Length();i++)
{
	if(Edit->Text[i]==',' && flag)        //проверяем на наличие второй точки
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

void __fastcall TForm5::FormClose(TObject *Sender, TCloseAction &Action)
{
Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::SettingsEnter(TObject *Sender)
{
	TBitBtn *btn = dynamic_cast<TBitBtn *>(Sender);
	if(Form2->SettingsNum>=0)
	{
	   AnsiString s=ExtractFilePath(Application->ExeName);
	   s+="/SettingButtons/"+IntToStr(0)+".bmp";
	   Form2->Buttons[Form2->SettingsNum]->Glyph->LoadFromFile(s);
	   Form2->PictureNum=0;
	}
	Form2->SettingsNum=btn->Tag;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button6MouseEnter(TObject *Sender)
{
for(int i=0;i<Form5->ComponentCount-1;i++)
	{
	   if(Form5->ActiveControl==Form5->Components[i] && Form5->Components[i]->ClassName()=="TEdit")
		FocusIndex=i;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button6Click(TObject *Sender)
{
TButton *button = dynamic_cast<TButton *>(Sender);         //буквы+цифры
AnsiString s=Form5->Components[FocusIndex]->ClassName();
if(Form5->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form5->Components[FocusIndex];
	  int start=edit->SelStart;
	  AnsiString s=edit->Text;
	  s.Delete(start+1,edit->SelLength);    //если выделено,то заменяем
	  s.Insert(button->Caption,start+1);    //вставляем букву
	  edit->SetFocus();
	  edit->Text=s;
	  edit->SelStart=start+1;
	  edit->SelLength=0;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm5::FormShow(TObject *Sender)
{
FocusIndex=6;
Edit1->OnClick(Sender);
if(Button53->Caption=="ABC")
	Button53->OnClick(Sender);
if(Form1->IsKeyboard)
	{
	Panel4->Visible=true;
	Height=597;
	}
	else
	{
	Panel4->Visible=false;
	Height=387;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm5::ShiftClick(TObject *Sender)
{
for(int i=0;i<Form5->ComponentCount-1;i++)
{
  if(Form5->Components[i]->ClassName()=="TButton")
  {
	TButton *button = (TButton*)Form5->Components[i];
	if(button->Parent!=Panel4)
		continue;
	if(button->Caption.Length()==1)
		if(button->Caption==button->Caption.UpperCase())
			button->Caption=button->Caption.LowerCase();
			else
			button->Caption=button->Caption.UpperCase();
  }
}
TEdit *edit = (TEdit*)Form5->Components[FocusIndex];
edit->SetFocus();
edit->SelLength=0;
edit->SelStart=100;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button53Click(TObject *Sender)
{
if(Button53->Caption=="Sym")
	Button53->Caption="ABC";
	else
	Button53->Caption="Sym";
int foc=FocusIndex;
setlocale(LC_ALL,"rus");
char capt[]={'й','ц','у','к','е','н','г','ш','щ','з','х','ї',
'ф','і','в','а','п','р','о','л','д','ж','є','я','ч','с','м','и','т','ь','б','ю'};
char symb[]={'+','x','÷','=','%','_','/','\\','{','}','#','$',
'/','|','^','~','*','(',')','-','\"','\'',':',';','!','?',',','.','[',']','<','>'};

for(int i=0;i<Form5->ComponentCount-1;i++)
{
	if(Components[i]->ClassName()=="TButton")
		{
			TButton *btn= (TButton*)Components[i];
			int charnum=-1,symnum=-1;
			AnsiString s=btn->Caption;
			for(int i=0;i<32;i++)
			{
				AnsiString c=capt[i];
				if(btn->Caption.LowerCase()==c)
					charnum=i;
				if(btn->Caption.LowerCase()==symb[i])
					symnum=i;
			}
			if(charnum!=-1)
			{
				btn->Caption=symb[charnum];
			}
			if(symnum!=-1)
			{
				AnsiString c=capt[symnum];
				btn->Caption=c;
			}
        }
}
FocusIndex=foc;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Edit2Click(TObject *Sender)
{
TEdit *edt = dynamic_cast<TEdit *>(Sender);
for(int i=0;i<Form5->ComponentCount-1;i++)
{
	if(Form5->Components[i]->ClassName()=="TButton")
	{
		TButton *btn =(TButton *) Form5->Components[i];
		if(!(btn->Name=="Backspace"
		|| btn->Caption=="0" || btn->Caption=="1" || btn->Caption=="2"
		|| btn->Caption=="3" || btn->Caption=="4" || btn->Caption=="5"
		|| btn->Caption=="6" || btn->Caption=="7" || btn->Caption=="8"
		|| btn->Caption=="9"))
			btn->Enabled=false;
	}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Edit1Click(TObject *Sender)
{
for(int i=0;i<Form5->ComponentCount-1;i++)
{
	if(Components[i]->ClassName()=="TButton")
	{
		TButton *btn=(TButton*)Components[i];
		if(btn->Parent==Panel4 && btn->Enabled==false)
			{
                btn->Enabled=true;
            }
    }
}
}
//---------------------------------------------------------------------------

void __fastcall TForm5::BackspaceClick(TObject *Sender)
{
  TButton *button = dynamic_cast<TButton *>(Sender);         //backspace
  AnsiString s=Form5->Components[FocusIndex]->ClassName();
if(Form5->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form5->Components[FocusIndex];
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

void __fastcall TForm5::Button52Click(TObject *Sender)
{
TButton *button = dynamic_cast<TButton *>(Sender);         //буквы+цифры
AnsiString s=Form5->Components[FocusIndex]->ClassName();
if(Form6->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form5->Components[FocusIndex];
	  int start=edit->SelStart;
	  AnsiString s=edit->Text;
	  s.Delete(start+1,edit->SelLength);    //если выделено,то заменяем
	  s.Insert(button->Caption,start+1);    //вставляем букву
	  edit->SetFocus();
	  edit->Text=s;
	  edit->SelStart=start+1;
	  edit->SelLength=0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button51Click(TObject *Sender)
{
TButton *button = dynamic_cast<TButton *>(Sender);         //буквы+цифры
AnsiString s=Form5->Components[FocusIndex]->ClassName();
if(Form5->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form5->Components[FocusIndex];
	  int start=edit->SelStart;
	  edit->SetFocus();
	  if(start!=0)
	 	 edit->SelStart=start-1;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button50Click(TObject *Sender)
{
TButton *button = dynamic_cast<TButton *>(Sender);         //буквы+цифры
AnsiString s=Form5->Components[FocusIndex]->ClassName();
if(Form5->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form5->Components[FocusIndex];
	  int start=edit->SelStart;
	  edit->SetFocus();
	  edit->SelStart=start+1;
	}
}
//---------------------------------------------------------------------------

