// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>

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
	memset(IsLeft, false, 10000 * sizeof(bool));
	memset(IsRight, false, 10000 * sizeof(bool));
	memset(IsDelMeal,false,100*sizeof(bool));
	PanelH = 100;
	PanelHaveH = 50;
	for(int i=0;i<100;i++)
	for(int j=0;j<100;j++)
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
	Form3->PanelsHave[n]->Top = Form3->PanelHaveH * (Form3->ProductsHave - 1);
	Form3->PanelsHave[n]->Height = Form3->PanelHaveH;
	Form3->PanelsHave[n]->Width = Form6->ScrollBox1->Width - 4;
	Form3->PanelsHave[n]->Tag=num;    //��������� �������� � Products(num-����� ��������)

	Form3->LabelesHave[n*4] = new TLabel(Form6);
	Form3->LabelesHave[n*4]->Parent = Form3->PanelsHave[n];
	Form3->LabelesHave[n*4]->Top = 15;
	Form3->LabelesHave[n*4]->Left = 15;
	Form3->LabelesHave[n*4]->Caption = Form2->Labeles[num * 5]->Caption;
	Form3->LabelesHave[n*4]->Width = w;

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
	Form3->ImagesHave[n]->Left = 10 + w;
	Form3->ImagesHave[n]->Width = w;
	Form3->ImagesHave[n]->Height = 46;
	Form3->ImagesHave[n]->Stretch = true;
	Form3->ImagesHave[n]->Picture = Form2->Images[num]->Picture;

	Form3->EditsHave[n] = new TEdit(Form6);
	Form3->EditsHave[n]->Parent = Form3->PanelsHave[n];
	Form3->EditsHave[n]->Left = 15 + 2 * w;
	Form3->EditsHave[n]->Top = 15;
	Form3->EditsHave[n]->Width = w;
	Form3->EditsHave[n]->NumbersOnly=true;
	Form3->EditsHave[n]->Text="0";
	Form3->EditsHave[n]->MaxLength=6;
	Form3->EditsHave[n]->OnChange=Form3->EditsHaveChange;

	Form3->ButtonsHave[n] = new TButton(Form6);
	Form3->ButtonsHave[n]->Parent = Form3->PanelsHave[n];
	Form3->ButtonsHave[n]->Left = 15 + 3 * w;
	Form3->ButtonsHave[n]->Width = w - 20;
	Form3->ButtonsHave[n]->Height = Form3->PanelHaveH;
	Form3->ButtonsHave[n]->Tag = n;
	Form3->ButtonsHave[n]->OnClick=Form3->AddClick;
    Form3->ButtonsHave[n]->Caption=n;

	Form6->ScrollBox1->VertScrollBar->Position = k;
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender) {     //������ ��������
	Form6->Label5->Caption="0";        //�����. ��������
	Form6->Label6->Caption="0";
	Form6->Label7->Caption="0";
	Form6->Label8->Caption="0";
	Form6->Label9->Caption="0";
	Form6->Label10->Caption="0";
	Form6->Label11->Caption="0";
	Form6->Label12->Caption="0";

	Form6->Edit1->Text="";
	Form7->Memo1->Lines->Text="";
	Form6->Button4->Visible=false;       //������ �������

	for (int i = 0; i < ProductsHave+ProductsUse; i++)
		PanelsHave[i]->Free();

	ProductsHave = 0;
	ProductsUse = 0;
	PropNum=99;             //99-�����,���� ������ �� ��������
	Form6->Show();

	int m = Form2->ProductsA;
	for(int i=0;i<Form2->ProductsA;i++)
	{
		IsLeft[99][i]=false;
		IsRight[99][i]=false;
	}

	int n=0;
	for (int i = 0; i < Form2->ProductsA; i++)
		if (Form2->IsDel[i] == false) {
			AddLeft(i);
			IsLeft[99][n]=true;
			n++;
		}

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

	if(IsLeft[i][num]==true)
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
		IsLeft[i][num] = false;
		IsRight[i][num] = true;
		PanelsHave[num]->Parent=Form6->ScrollBox2;
		for(int j=0;j<ProductsUse+ProductsHave;j++)
		if(IsLeft[i][j] && PanelsHave[j]->Top > PanelsHave[num]->Top)
			PanelsHave[j]->Top-=PanelHaveH;
		PanelsHave[num]->Top=(ProductsUse-1)*PanelHaveH;
	}
	else
	{
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
		IsLeft[i][num] = true;
		IsRight[i][num] = false;
		PanelsHave[num]->Parent=Form6->ScrollBox1;
		for(int j=0;j<ProductsUse+ProductsHave;j++)
		if(IsRight[i][j] && PanelsHave[j]->Top>PanelsHave[num]->Top)
			PanelsHave[j]->Top-=PanelHaveH;
		PanelsHave[num]->Top=(ProductsHave-1)*PanelHaveH;
	}

	Form6->ScrollBox1->VertScrollBar->Position = k;
    Form6->ScrollBox2->VertScrollBar->Position = k1;
}
void __fastcall TForm3::AddClick(TObject *Sender)
{
TButton *btn = dynamic_cast<TButton *>(Sender);
int num=btn->Tag;
AddClickF(num);
}
//------------------------------------------------------------------------------
void __fastcall TForm3::PropClick(TObject *Sender)
{
  TButton *btn = dynamic_cast<TButton *>(Sender);
  int num=btn->Tag;
  PropClickNum(num);

}
//--------------------------------------------------------------------------------------
void __fastcall TForm3::PropClickNum(int num)
{
  Form6->Button4->Visible=true;    //������ �������


  memset(LeftWas,false,100*sizeof(bool));                 //�����,���� ��� ������ �������� ���������
  memset(RightWas,false,100*sizeof(bool));

  Form6->Edit1->Text=Form3->Labeles[num*5]->Caption;
  Form7->Memo1->Lines->Text=Form3->Memos[num]->Lines->Text;

  for(int i=0;i<ProductsUse+ProductsHave;i++)
  {
	  if(IsLeft[num][i])
	  LeftWas[i]=true;
	  if(IsRight[num][i])
	  RightWas[i]=true;
  }
	for (int i = 0; i < ProductsHave+ProductsUse; i++)
		PanelsHave[i]->Free();

	PropNum=num;
	ProductsHave = 0;
	ProductsUse = 0;

	for(int i=0;i<Form2->ProductsA;i++)
	if(!IsRight[num][i])
	IsLeft[num][i]=true;

	int n=0;
	for (int i = 0; i < Form2->ProductsA; i++)
		if (Form2->IsDel[i] == false)
		{
			AddLeft(i);
			if(IsRight[num][n])
			{
                IsRight[num][n]==false;
				IsLeft[num][n]=true;
				AddClickF(n);
			}
			n++;
		}

	Form6->Label5->Caption="0";              //������,�������� �� MealsForm
	Form6->Label6->Caption="0";
	Form6->Label7->Caption="0";
	Form6->Label8->Caption="0";
	Form6->Label9->Caption="0";
	Form6->Label10->Caption="0";
	Form6->Label11->Caption="0";
	Form6->Label12->Caption="0";

	for(int i=0;i<Form2->ProductsA;i++)
		if(Form2->IsDel[i]==false)
			EditsHave[i]->Text=Weights[num][i];

	n=0;

	while(Form2->IsDel[n]==false)
	{
        n++;
	}
	Form3->EditsHave[n]=Form3->EditsHave[n];

	for(int i=0;i<Form2->ProductsA;i++)
	if(Form2->IsDel[i]==false)
	{
	EditsHave[n]->Text=Weights[num][n];
	n++;
	}



	Form6->Show();
}

void __fastcall TForm3::EditsHaveChange(TObject *Sender)          //��������(����������� �������� ����� ��� ��������� ����)
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
		if(Form2->IsDel[i]==false)
		{
			   if(i==btn->Parent->Tag && flag)
					int a=1;
			   else
			   if(IsRight[num][n]==true)
				  {
				  int k=PanelsHave[n]->Tag;
					  sum1+=StrToInt(Form2->Labeles[k*5+1]->Caption)*StrToInt(Form3->EditsHave[n]->Text);
					  sum2+=StrToInt(Form2->Labeles[k*5+2]->Caption)*StrToInt(Form3->EditsHave[n]->Text);
					  sum3+=StrToInt(Form2->Labeles[k*5+3]->Caption)*StrToInt(Form3->EditsHave[n]->Text);
				  }
			n++;
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

