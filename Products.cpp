//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Products.h"
#include "ProdForm.h"
#include "Main.h"
#include "Meals.h"
#include "Recommend.h"
#include "ProdForm.h"
#include <math.h>
#include "Math.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;



//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	PanelH=100;
	isExpantion=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::PropClick(TObject *Sender)                //��� ����� �� ������ ���������
{
	TBitBtn *btn = dynamic_cast<TBitBtn *>(Sender);       //��������� Sender � TButton
	int num=btn->Tag;
	Form5->Image1->Picture=Product[num].Image->Picture;
	Form5->Edit1->Text=Product[num].Name->Caption;
	Form5->Edit2->Text=FloatToStr(StrToFloat(Product[num].Protein->Caption)/10);
	Form5->Edit3->Text=FloatToStr(StrToFloat(Product[num].Fat->Caption)/10);
	Form5->Edit4->Text=FloatToStr(StrToFloat(Product[num].Carbon->Caption)/10);
	PropNum=num;
	Form5->Button4->Visible=true;

	Form5->IsNew=false;
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
	Form5->IsNew=true;
	Form5->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::CreateNewProduct()
{
	Form5->IsNew=true;
    double sum=100;
	int n=Form2->Product.size();
	int k;
	k=Form2->ScrollBox1->VertScrollBar->Position;  //����� �����������,����� �����. ��������
	Form2->ScrollBox1->VertScrollBar->Position=0;

	TForm2::Prod TemporProd;   //��������� ����������
	Form2->Product.push_back(TemporProd);

	Form2->Product[n].Panel=new TPanel(Form2);
	Form2->Product[n].Panel->Parent=Form2->ScrollBox1;
	Form2->Product[n].Panel->Top=(n)*Form2->PanelH;
	Form2->Product[n].Panel->Left=0;
	Form2->Product[n].Panel->Width=Form2->ScrollBox1->Width-4;
	Form2->Product[n].Panel->Height=Form2->PanelH;
	Form2->Product[n].Panel->OnMouseEnter=Form2->OnMouseEnter;
	Form2->Product[n].Panel->Visible=true;

	Form2->ScrollBox1->VertScrollBar->Position=k;


	Form2->Product[n].Image=new TImage(Form2);
	Form2->Product[n].Image->Parent=Form2->Product[n].Panel;
	Form2->Product[n].Image->Left=300;
	Form2->Product[n].Image->Height=Form2->PanelH-1;
	Form2->Product[n].Image->Width=125;
	Form2->Product[n].Image->Picture=Form5->Image1->Picture;
	Form2->Product[n].Image->Stretch=true;

	Form2->Product[n].Name=new TLabel(Form2);
	Form2->Product[n].Name->Parent=Form2->Product[n].Panel;
	Form2->Product[n].Name->Top=20;
	Form2->Product[n].Name->Left=10;
	Form2->Product[n].Name->WordWrap=true;
	Form2->Product[n].Name->AutoSize=false;
	Form2->Product[n].Name->Height=80;
	Form2->Product[n].Name->Width=270;
	Form2->Product[n].Name->Font->Size=14;
	Form2->Product[n].Name->Caption=Form5->Edit1->Text;

	Form2->Product[n].Protein=new TLabel(Form2);
	Form2->Product[n].Protein->Parent=Form2->Product[n].Panel;
	Form2->Product[n].Protein->Top=20;
	Form2->Product[n].Protein->Left=440;
	Form2->Product[n].Protein->WordWrap=true;
	Form2->Product[n].Protein->AutoSize=false;
	Form2->Product[n].Protein->Height=40;
	Form2->Product[n].Protein->Width=50;
	Form2->Product[n].Protein->Font->Size=10;
	Form2->Product[n].Protein->Caption=FloatToStr(SimpleRoundTo(StrToFloat(Form5->Edit2->Text)/sum*1000,0));

	Form2->Product[n].Fat=new TLabel(Form2);
	Form2->Product[n].Fat->Parent=Form2->Product[n].Panel;
	Form2->Product[n].Fat->Top=20;
	Form2->Product[n].Fat->Left=533;
	Form2->Product[n].Fat->WordWrap=true;
	Form2->Product[n].Fat->AutoSize=false;
	Form2->Product[n].Fat->Height=20;
	Form2->Product[n].Fat->Width=50;
	Form2->Product[n].Fat->Font->Size=10;
	Form2->Product[n].Fat->Caption=FloatToStr(SimpleRoundTo(StrToFloat(Form5->Edit3->Text)/sum*1000,0));

	Form2->Product[n].Carbon=new TLabel(Form2);
	Form2->Product[n].Carbon->Parent=Form2->Product[n].Panel;
	Form2->Product[n].Carbon->Top=20;
	Form2->Product[n].Carbon->Left=625;
	Form2->Product[n].Carbon->WordWrap=true;
	Form2->Product[n].Carbon->AutoSize=false;
	Form2->Product[n].Carbon->Height=20;
	Form2->Product[n].Carbon->Width=50;
	Form2->Product[n].Carbon->Font->Size=10;
	Form2->Product[n].Carbon->Caption=FloatToStr(SimpleRoundTo(StrToFloat(Form5->Edit4->Text)/sum*1000,0));

	Form2->Product[n].Calories=new TLabel(Form2);
	Form2->Product[n].Calories->Parent=Form2->Product[n].Panel;
	Form2->Product[n].Calories->Top=20;
	Form2->Product[n].Calories->Left=719;
	Form2->Product[n].Calories->WordWrap=true;
	Form2->Product[n].Calories->AutoSize=false;
	Form2->Product[n].Calories->Height=20;
	Form2->Product[n].Calories->Width=50;
	Form2->Product[n].Calories->Font->Size=10;
	double n1=StrToInt(Form2->Product[n].Protein->Caption)*0.004;
	double n2=StrToInt(Form2->Product[n].Fat->Caption)*0.009;
	double n3=StrToInt(Form2->Product[n].Carbon->Caption)*0.004;
	Form2->Product[n].Calories->Caption=FloatToStr(SimpleRoundTo(n1+n2+n3,-2));
   //	Form2->Labeles[n*5+4]->Caption=Edit;

	Form2->Product[n].SettingButton=new TBitBtn(Form2);
	Form2->Product[n].SettingButton->Parent=Form2->Product[n].Panel;
	Form2->Product[n].SettingButton->Left=820;
	Form2->Product[n].SettingButton->Height=Form2->PanelH-1;
	Form2->Product[n].SettingButton->Width=100;
	Form2->Product[n].SettingButton->Tag=n;
	Form2->Product[n].SettingButton->OnClick=Form2->PropClick;
	Form2->Product[n].SettingButton->Glyph=Form5->BitBtn1->Glyph;
	Form2->Product[n].SettingButton->OnMouseEnter=Form5->SettingsEnter;


	TImage *line=new TImage(Form2);               //������ �����
	line->Parent=Form2->Product[n].Panel;
	line->Left=300;
	line->Width=2;
	line->Height=Form2->PanelH-1;
	line->Picture->Bitmap->Width=2;
	line->Picture->Bitmap->Height=Form2->PanelH-1;
	line->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

	TImage *line2=new TImage(Form2);
	line2->Parent=Form2->Product[n].Panel;
	line2->Left=427;
	line2->Width=2;
	line2->Height=Form2->PanelH-1;
	line2->Picture->Bitmap->Width=2;
	line2->Picture->Bitmap->Height=Form2->PanelH-1;
	line2->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line2->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

	TImage *line3=new TImage(Form2);
	line3->Parent=Form2->Product[n].Panel;
	line3->Left=520;
	line3->Width=2;
	line3->Height=Form2->PanelH-1;
	line3->Picture->Bitmap->Width=2;
	line3->Picture->Bitmap->Height=Form2->PanelH-1;
	line3->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line3->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

	TImage *line4=new TImage(Form2);
	line4->Parent=Form2->Product[n].Panel;
	line4->Left=613;
	line4->Width=2;
	line4->Height=Form2->PanelH-1;
	line4->Picture->Bitmap->Width=2;
	line4->Picture->Bitmap->Height=Form2->PanelH-1;
	line4->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line4->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

	TImage *line5=new TImage(Form2);
	line5->Parent=Form2->Product[n].Panel;
	line5->Left=706;
	line5->Width=2;
	line5->Height=Form2->PanelH-1;
	line5->Picture->Bitmap->Width=2;
	line5->Picture->Bitmap->Height=Form2->PanelH-1;
	line5->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line5->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

	TImage *line6=new TImage(Form2);
	line6->Parent=Form2->Product[n].Panel;
	line6->Left=819;
	line6->Width=2;
	line6->Height=Form2->PanelH-1;
	line6->Picture->Bitmap->Width=2;
	line6->Picture->Bitmap->Height=Form2->PanelH-1;
	line6->Picture->Bitmap->Canvas->Brush->Color=clBlack;
	line6->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

	for(int i=0;i<Form3->Meal.size();i++)   //��������� ���� �� ��� �����(���� �� ���� ������ ��� �������� ����)
		Form3->Meal[i].Weight[n]='0';

	Form3->AddLeft(n);
}
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
SettingsNum=-1;
PictureNum=0;
}
//---------------------------------------------------------------------------



void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
Form5->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
	if(SettingsNum>=0)
	{
	   AnsiString s=ExtractFilePath(Application->ExeName);
	   s+="/SettingButtons/"+IntToStr(PictureNum)+".bmp";
	   Form2->Product[SettingsNum].SettingButton->Glyph->LoadFromFile(s);
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


void __fastcall TForm2::BitBtn4Click(TObject *Sender)
{
if(!isExpantion)
{
	Edit1->Left=211;
}
isExpantion=! isExpantion;
Timer2->Enabled=true;
Edit1->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer2Timer(TObject *Sender)
{
if(isExpantion)
	{
		if(Edit1->Width<100)
			{
			Edit1->Width+=3;
			Edit1->Left=111;
			}
			else
			{
			Timer2->Enabled=false;
			Edit1->Width=100;
			}
	}
	else
	{
		if(Edit1->Width>0)
		{
			Edit1->Width-=3;
			Edit1->Left=111;
		}
			else
			{
			Timer2->Enabled=false;
			Edit1->Width=0;
			}
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit1Change(TObject *Sender)
{
ScrollBox1->VertScrollBar->Position=0;
AnsiString WordToFind=Edit1->Text.LowerCase();
int SearchAmount=0;
for(int i=0;i<Form2->Product.size();i++)
	{
	AnsiString Name=Form2->Product[i].Name->Caption.LowerCase();
	int pos=Name.Pos(WordToFind);
	if(pos!=0 || WordToFind=="")
		{
		Form2->Product[i].Panel->Top=Form2->PanelH*SearchAmount;
		Form2->Product[i].Panel->Visible=true;
		SearchAmount++;
		}
	else
		{
		Form2->Product[i].Panel->Visible=false;
		}
}

}
//---------------------------------------------------------------------------

