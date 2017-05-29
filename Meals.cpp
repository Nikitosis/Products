// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include <Buttons.hpp>

#include "RecommendDialog.h"
#include "Products.h"
#include "Main.h"
#include "Meals.h"
#include "Recommend.h"
#include "MealsForm.h"
#include "Recipe.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

// ---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner) : TForm(Owner) {
	memset(IsLeft, false, 40000 * sizeof(bool));
	memset(IsRight, false, 40000 * sizeof(bool));
	memset(IsDelMeal,false,200*sizeof(bool));
	PanelH = 100;
	PanelHaveH = 50;
	for(int i=0;i<200;i++)
	for(int j=0;j<200;j++)
	Weights[i][j]="0";
}

// ---------------------------------------------------------------------------
void AddLeft(int num) {      //������� ����� ������ � ����� �����
	Form3->ProductsHave++;
	int n = Form3->ProductsHave+Form3->ProductsUse - 1;
	int k = Form6->ScrollBox1->VertScrollBar->Position;
	Form6->ScrollBox1->VertScrollBar->Position = 0;

	int w = Form6->ScrollBox1->Width / 4;
	// w=round(w);

	Form3->PanelsHave[n] = new TPanel(Form6);
	Form3->PanelsHave[n]->Parent = Form6->ScrollBox1;
	Form3->PanelsHave[n]->Top = Form3->PanelHaveH * (Form3->ProductsHave-1);
	Form3->PanelsHave[n]->Height = Form3->PanelHaveH;
	Form3->PanelsHave[n]->Width = Form6->ScrollBox1->Width - 4;
	Form3->PanelsHave[n]->Tag=num;    //��������� �������� � Products(num-����� ��������)
	Form3->PanelsHave[n]->ParentBackground=false;
	Form3->PanelsHave[n]->DoubleBuffered=true;

	Form3->LabelesHave[n*4] = new TLabel(Form6);
	Form3->LabelesHave[n*4]->Parent = Form3->PanelsHave[n];
	Form3->LabelesHave[n*4]->Top = 5;
	Form3->LabelesHave[n*4]->Left = 15;
	Form3->LabelesHave[n*4]->Caption = Form2->Labeles[num * 5]->Caption;
	Form3->LabelesHave[n*4]->Width = w;
	Form3->LabelesHave[n*4]->Height = 20;
	Form3->LabelesHave[n*4]->WordWrap = true;


	Form3->LabelesHave[n*4+1]=new TLabel(Form6);                     //������ ������ �����,����,�����.
	Form3->LabelesHave[n*4+1]->Parent=Form3->PanelsHave[n];
	Form3->LabelesHave[n*4+1]->Caption=Form2->Labeles[num*5+1]->Caption;
	Form3->LabelesHave[n*4+1]->Visible=false;

	Form3->LabelesHave[n*4+2]=new TLabel(Form6);
	Form3->LabelesHave[n*4+2]->Parent=Form3->PanelsHave[n];
	Form3->LabelesHave[n*4+2]->Caption=Form2->Labeles[num*5+2]->Caption;
	Form3->LabelesHave[n*4+2]->Visible=false;

	Form3->LabelesHave[n*4+3]=new TLabel(Form6);
	Form3->LabelesHave[n*4+3]->Parent=Form3->PanelsHave[n];
	Form3->LabelesHave[n*4+3]->Caption=Form2->Labeles[num*5+3]->Caption;
	Form3->LabelesHave[n*4+3]->Visible=false;

	Form3->ImagesHave[n] = new TImage(Form6);
	Form3->ImagesHave[n]->Parent = Form3->PanelsHave[n];
	Form3->ImagesHave[n]->Left = 40 + w;
	Form3->ImagesHave[n]->Width = w;
	Form3->ImagesHave[n]->Height = 46;
	Form3->ImagesHave[n]->Stretch = true;
	Form3->ImagesHave[n]->Picture = Form2->Images[num]->Picture;

	Form3->EditsHave[n] = new TEdit(Form6);
	Form3->EditsHave[n]->Parent = Form3->PanelsHave[n];
	Form3->EditsHave[n]->Left = 45 + 2 * w;
	Form3->EditsHave[n]->Top = 15;
	Form3->EditsHave[n]->Width = w-30;
	Form3->EditsHave[n]->NumbersOnly=true;
	Form3->EditsHave[n]->Text="0";
	Form3->EditsHave[n]->MaxLength=6;
	Form3->EditsHave[n]->OnChange=Form3->EditsHaveChange;
    Form3->EditsHave[n]->OnClick=Form3->EditsClick;

	Form3->ButtonsHave[n] = new TBitBtn(Form6);
	Form3->ButtonsHave[n]->Parent = Form3->PanelsHave[n];
	Form3->ButtonsHave[n]->Left = 15 + 3 * w;
	Form3->ButtonsHave[n]->Width = w - 36;
	Form3->ButtonsHave[n]->Height = Form3->PanelHaveH;
	Form3->ButtonsHave[n]->Tag = n;
	Form3->ButtonsHave[n]->OnClick=Form3->AddClick;
	//Form3->ButtonsHave[n]->Caption=12;
   //	Form3->ButtonsHave[n]->Visible=false;
	Form3->ButtonsHave[n]->Glyph=Form6->BitBtn2->Glyph;

	Form6->ScrollBox1->VertScrollBar->Position = k;
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender) {     //������ ��������

  memset(LeftWas,false,200*sizeof(bool));                 //�����,���� ��� ������ �������� ���������
  memset(RightWas,false,200*sizeof(bool));

	WasDeleted=-1;
	int num=199;
	PropNum=199;
	ProductsHave = 0;
	ProductsUse = 0;

	  for(int i=0;i<200;i++)
	{
		IsRight[num][i]=false;
		IsLeft[num][i]=true;
	}

   for(int i=0;i<Form2->ProductsA;i++)
	{
		if(NeedToDelete[i])
		{
			PanelsHave[i]->Free();
			NeedToDelete[i]=false;
		}
	}

	int n=0;
	for (int i = 0; i < Form2->ProductsA; i++)
		if (Form2->IsDel[i] == false)
		{
			AddLeft(i);
			NeedToDelete[n]=true;
			if(IsRight[num][i])
			{
				IsRight[num][i]==false;
				IsLeft[num][i]=true;
				AddClickF(n);
			}
			n++;
		}
	//PanelsHave[1]->Visible=false;
	Form6->Label5->Caption="0";              //������,�������� �� MealsForm
	Form6->Label6->Caption="0";
	Form6->Label7->Caption="0";
	Form6->Label8->Caption="0";
	Form6->Label9->Caption="0";
	Form6->Label10->Caption="0";
	Form6->Label11->Caption="0";
	Form6->Label12->Caption="0";
	Form6->Edit1->Text="";
	Form7->Memo1->Lines->Clear();


	Form6->Show();
	Form6->Edit1->SetFocus();
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::AddClickF(int num)
{
   int i;            //i- meals num-������ �������
	i=PropNum;
	int prodnum=PanelsHave[num]->Tag;            //��� ��������� ���� ���� ���������� � ���������
	int k = Form6->ScrollBox1->VertScrollBar->Position;
	Form6->ScrollBox1->VertScrollBar->Position = 0;
	int k1 = Form6->ScrollBox2->VertScrollBar->Position;
	Form6->ScrollBox2->VertScrollBar->Position = 0;

	Form6->Edit2->Text="";

	if(IsLeft[i][prodnum]==true)
	{
		int amount=StrToInt(Form3->EditsHave[num]->Text);
		Form6->Label5->Caption=FloatToStr(StrToFloat(Form6->Label5->Caption)+StrToFloat(Form2->Labeles[prodnum*5+1]->Caption)*amount);          //�����,������� ���������
		Form6->Label6->Caption=FloatToStr(StrToFloat(Form6->Label6->Caption)+StrToFloat(Form2->Labeles[prodnum*5+1]->Caption)*amount);
		Form6->Label7->Caption=FloatToStr(StrToFloat(Form6->Label7->Caption)+StrToFloat(Form2->Labeles[prodnum*5+1]->Caption)*amount);
		Form6->Label8->Caption=FloatToStr(StrToFloat(Form6->Label5->Caption)*4+StrToFloat(Form6->Label6->Caption)*9+StrToFloat(Form6->Label7->Caption)*4);

		int n1=ceil(StrToFloat(Form6->Label5->Caption)/1000);
		Form6->Label9->Caption=IntToStr(n1);

		n1=ceil(StrToFloat(Form6->Label6->Caption)/1000);
		Form6->Label10->Caption=IntToStr(n1);

		n1=ceil(StrToFloat(Form6->Label7->Caption)/1000);
		Form6->Label11->Caption=IntToStr(n1);

		n1=ceil(StrToFloat(Form6->Label8->Caption)/1000);
		Form6->Label12->Caption=IntToStr(n1);

		ProductsUse++;
		ProductsHave--;
		IsLeft[i][prodnum] = false;
		IsRight[i][prodnum] = true;
		PanelsHave[num]->Parent=Form6->ScrollBox2;
		for(int j=0;j<ProductsUse+ProductsHave;j++)
		if(IsLeft[i][PanelsHave[j]->Tag] && PanelsHave[j]->Top > PanelsHave[num]->Top)
			PanelsHave[j]->Top-=PanelHaveH;
		PanelsHave[num]->Top=(ProductsUse-1)*PanelHaveH;

		ButtonsHave[num]->Glyph=Form6->BitBtn3->Glyph;
	}
	else
	{
		Form3->EditsHave[num]->Text="0";
		int amount=StrToInt(Form3->EditsHave[num]->Text);
		Form6->Label5->Caption=FloatToStr(StrToFloat(Form6->Label5->Caption)-StrToFloat(Form2->Labeles[prodnum*5+1]->Caption)*amount);          //�����,������� ���������
		Form6->Label6->Caption=FloatToStr(StrToFloat(Form6->Label6->Caption)-StrToFloat(Form2->Labeles[prodnum*5+1]->Caption)*amount);
		Form6->Label7->Caption=FloatToStr(StrToFloat(Form6->Label7->Caption)-StrToFloat(Form2->Labeles[prodnum*5+1]->Caption)*amount);
		Form6->Label8->Caption=FloatToStr(StrToFloat(Form6->Label5->Caption)*4+StrToFloat(Form6->Label6->Caption)*9+StrToFloat(Form6->Label7->Caption)*4);

		int n1=ceil(StrToFloat(Form6->Label5->Caption)/1000);
		Form6->Label9->Caption=IntToStr(n1);

		n1=ceil(StrToFloat(Form6->Label6->Caption)/1000);
		Form6->Label10->Caption=IntToStr(n1);

		n1=ceil(StrToFloat(Form6->Label7->Caption)/1000);
		Form6->Label11->Caption=IntToStr(n1);

		n1=ceil(StrToFloat(Form6->Label8->Caption)/1000);
		Form6->Label12->Caption=IntToStr(n1);

		ProductsUse--;
		ProductsHave++;
		IsLeft[i][prodnum] = true;
		IsRight[i][prodnum] = false;
		PanelsHave[num]->Parent=Form6->ScrollBox1;
		for(int j=0;j<ProductsUse+ProductsHave;j++)
		if(IsRight[i][PanelsHave[j]->Tag] && PanelsHave[j]->Top>PanelsHave[num]->Top)
			PanelsHave[j]->Top-=PanelHaveH;
		PanelsHave[num]->Top=(ProductsHave-1)*PanelHaveH;

		ButtonsHave[num]->Glyph=Form6->BitBtn2->Glyph;
	}

	Form6->ScrollBox1->VertScrollBar->Position = k;
	Form6->ScrollBox2->VertScrollBar->Position = k1;
}
void __fastcall TForm3::AddClick(TObject *Sender)
{
TBitBtn *btn = dynamic_cast<TBitBtn *>(Sender);
int num=btn->Tag;
AddClickF(num);
}
//------------------------------------------------------------------------------
void __fastcall TForm3::PropClick(TObject *Sender)
{
  TBitBtn *btn = dynamic_cast<TBitBtn *>(Sender);
  int num=btn->Tag;
  PropClickNum(num);

}
//--------------------------------------------------------------------------------------
void __fastcall TForm3::PropClickNum(int num)
{
  Form6->Button4->Visible=true;    //������ �������


  memset(LeftWas,false,200*sizeof(bool));                 //�����,���� ��� ������ �������� ���������
  memset(RightWas,false,200*sizeof(bool));

  Form6->Edit1->Text=Form3->Labeles[num*5]->Caption;
  Form6->Image1->Picture=Images[num]->Picture;
  Form7->Memo1->Lines->Text=Form3->Memos[num]->Lines->Text;

  for(int i=0;i<Form2->ProductsA;i++)
  {
	  if(IsLeft[num][i])
	  LeftWas[i]=true;
	  if(IsRight[num][i])
	  RightWas[i]=true;
  }
	int n=0;

	for(int i=0;i<Form2->ProductsA;i++)
	{
		if(NeedToDelete[i])
		{
			PanelsHave[i]->Free();
			NeedToDelete[i]=false;
		}
	}
	WasDeleted=-1;
	PropNum=num;
	ProductsHave = 0;
	ProductsUse = 0;

	for(int i=0;i<Form2->ProductsA;i++)
	if(!IsRight[num][i])
	IsLeft[num][i]=true;

	n=0;
	for (int i = 0; i < Form2->ProductsA; i++)
		if (Form2->IsDel[i] == false)
		{
			AddLeft(i);
			NeedToDelete[n]=true;
			if(IsRight[num][i])
			{
				IsRight[num][i]==false;
				IsLeft[num][i]=true;
				AddClickF(n);
			}
			n++;
		}
	//PanelsHave[1]->Visible=false;
	Form6->Label5->Caption="0";              //������,�������� �� MealsForm
	Form6->Label6->Caption="0";
	Form6->Label7->Caption="0";
	Form6->Label8->Caption="0";
	Form6->Label9->Caption="0";
	Form6->Label10->Caption="0";
	Form6->Label11->Caption="0";
	Form6->Label12->Caption="0";

    n=0;
	for(int i=0;i<Form2->ProductsA;i++)
		if(NeedToDelete[i])
		{
			//EditsHave[n]->Text=Weights[num][i];
			//n++;
			EditsHave[i]->Text=Weights[num][PanelsHave[i]->Tag];
			int f;
		}

	/*n=0;

	while(Form2->IsDel[n]==false)
	{
		n++;
	}
	Form3->EditsHave[n]=Form3->EditsHave[n];   */

	for(int i=0;i<Form2->ProductsA;i++)
	if(Form2->IsDel[i]==false)
	{
	//EditsHave[n]->Text=Weights[num][n];
	//ButtonsHave[i]->Caption="";        //���� �����,�� ����������
	//n++;
	}


	Form6->Show();
	Form6->Edit1->SetFocus();
}

void __fastcall TForm3::EditsHaveChange(TObject *Sender)
{
TEdit *btn = dynamic_cast<TEdit *>(Sender);
bool flag=btn->Text.IsEmpty();

int num=PropNum;
double sum1=0,sum2=0,sum3=0;
if(btn->Parent->Parent==Form6->ScrollBox2)
{
	int n=0;
	for(int i=0;i<Form2->ProductsA;i++)
	{
		if(NeedToDelete[i])
			{
				if(IsRight[num][PanelsHave[i]->Tag] && !EditsHave[i]->Text.IsEmpty())
					{
					  int k=PanelsHave[i]->Tag;
					  sum1+=StrToInt(Form2->Labeles[k*5+1]->Caption)*StrToInt(Form3->EditsHave[i]->Text);
					  sum2+=StrToInt(Form2->Labeles[k*5+2]->Caption)*StrToInt(Form3->EditsHave[i]->Text);
					  sum3+=StrToInt(Form2->Labeles[k*5+3]->Caption)*StrToInt(Form3->EditsHave[i]->Text);
                    }
            }
	}

Form6->Label5->Caption=FloatToStr(sum1);
Form6->Label6->Caption=FloatToStr(sum2);
Form6->Label7->Caption=FloatToStr(sum3);
Form6->Label8->Caption=FloatToStr(sum1*4+sum2*9+sum3*4);

int n1=ceil(StrToFloat(Form6->Label5->Caption)/1000);
		Form6->Label9->Caption=IntToStr(n1);

		n1=ceil(StrToFloat(Form6->Label6->Caption)/1000);
		Form6->Label10->Caption=IntToStr(n1);

		n1=ceil(StrToFloat(Form6->Label7->Caption)/1000);
		Form6->Label11->Caption=IntToStr(n1);

		n1=ceil(StrToFloat(Form6->Label8->Caption)/1000);
		Form6->Label12->Caption=IntToStr(n1);

Form3->Labeles[num*5+1]->Caption=Form6->Label9->Caption;
Form3->Labeles[num*5+2]->Caption=Form6->Label10->Caption;
Form3->Labeles[num*5+3]->Caption=Form6->Label11->Caption;
Form3->Labeles[num*5+4]->Caption=Form6->Label12->Caption;
    }
}

//------------------------------------------------------------------------------

void __fastcall TForm3::Save1Click(TObject *Sender)
{
Form1->Save1Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Load1Click(TObject *Sender)
{
Form1->Load1Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender)
{
//memset(Form2->IsDel,false,100*sizeof(bool));
//memset(Form3->IsDelMeal,false,100*sizeof(bool));
MealsA=0;
MealsDel=0;
IsRecommend=false;
SettingsNum=-1;
PictureNum=0;
memset(NeedToDelete,0,200*sizeof(bool));
}
//---------------------------------------------------------------------------


void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
if(IsRecommend==false)
{
	Form1->Show();
	Form6->Hide();
}
else
{
	Form8->Close();
	Form3->Label11->Font->Color=clWhite;
}

}
//---------------------------------------------------------------------------


void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
if(SettingsNum>=0)
	{
	   AnsiString s=ExtractFilePath(Application->ExeName);
	   s+="/SettingButtons/"+IntToStr(PictureNum)+".bmp";
	   Form3->Buttons[SettingsNum]->Glyph->LoadFromFile(s);
	   PictureNum++;
	   PictureNum%=3;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormMouseEnter(TObject *Sender)
{
	SettingsNum=-1;
	PictureNum=0;
	AnsiString s=ExtractFilePath(Application->ExeName);
	s+="/MenuButtons/Button.png";
	Button1->Picture->LoadFromFile(s);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1MouseEnter(TObject *Sender)
{
	AnsiString s=ExtractFilePath(Application->ExeName);
	s+="/MenuButtons/MouseEnter.png";
	Button1->Picture->LoadFromFile(s);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::EditsClick(TObject *Sender)
{
TEdit *edt = dynamic_cast<TEdit *>(Sender);
for(int i=0;i<Form6->ComponentCount-1;i++)
{
	if(Form6->Components[i]->ClassName()=="TButton")
	{
		TButton *btn =(TButton *) Form6->Components[i];
		if(!(btn->Name=="Backspace"
		|| btn->Caption=="0" || btn->Caption=="1" || btn->Caption=="2"
		|| btn->Caption=="3" || btn->Caption=="4" || btn->Caption=="5"
		|| btn->Caption=="6" || btn->Caption=="7" || btn->Caption=="8"
		|| btn->Caption=="9"))
			btn->Enabled=false;
	}
}
}

void __fastcall TForm3::Button6Click(TObject *Sender)
{
TButton *button = dynamic_cast<TButton *>(Sender);         //�����+�����
AnsiString s=Form3->Components[FocusIndex]->ClassName();
if(Form3->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form3->Components[FocusIndex];
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

void __fastcall TForm3::Button6MouseEnter(TObject *Sender)
{
for(int i=0;i<Form3->ComponentCount-1;i++)
	{
	   if(Form3->ActiveControl==Form3->Components[i] && Form3->Components[i]->ClassName()=="TEdit")
		FocusIndex=i;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormShow(TObject *Sender)
{
FocusIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::BackspaceClick(TObject *Sender)
{
  TButton *button = dynamic_cast<TButton *>(Sender);         //backspace
  AnsiString s=Form3->Components[FocusIndex]->ClassName();
if(Form3->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form3->Components[FocusIndex];
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

