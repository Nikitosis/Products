//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "math.h"


#include "RecommendDialog.h"
#include "Meals.h"
#include "MealsForm.h"
#include "Products.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button2Click(TObject *Sender)
{
if(Form1->IsKeyboard)     //����������
	Form3->Panel4->Visible=true;
	else
	Form3->Panel4->Visible=false;

WatchedRecom=true;
Form3->IsRecommend=true;
Form3->Button1->Visible=false;
Form3->Label8->Visible=false;
Form3->RecomPanel->Visible=true;
Form3->RecomPanel->Color=clHighlight;
for(int i=0;i<Form3->MealsA;i++)
	{
		if(Form3->IsDelMeal[i]==false)
		{


			LWeights[i]=new TEdit(Form3);             //���� �����
			LWeights[i]->Parent=Form3->Panels[i];
			LWeights[i]->Left = 803;
			LWeights[i]->Top=40;
			LWeights[i]->Width=40;
			LWeights[i]->NumbersOnly=true;
			LWeights[i]->MaxLength=9;
			LWeights[i]->Font->Size=10;
			LWeights[i]->AutoSize=false;
			LWeights[i]->Width=50;
			LWeights[i]->Text="0";
			LWeights[i]->Tag=i;
			LWeights[i]->OnChange=MassChange;

			LBel[i] = new TLabel(Form3);
			LBel[i]->Parent = Form3->Panels[i];
			LBel[i]->Top = 40;
			LBel[i]->Left = 460;
			LBel[i]->WordWrap = true;
			LBel[i]->AutoSize = false;
			LBel[i]->Height = 20;
			LBel[i]->Width = 70;
			LBel[i]->Font->Size = 10;
			LBel[i]->Caption = "0";

			LZh[i] = new TLabel(Form3);
			LZh[i]->Parent = Form3->Panels[i];
			LZh[i]->Top = 40;
			LZh[i]->Left = 533;
			LZh[i]->WordWrap = true;
			LZh[i]->AutoSize = false;
			LZh[i]->Height = 20;
			LZh[i]->Width = 70;
			LZh[i]->Font->Size = 10;
			LZh[i]->Caption = "0";

			LUgl[i] = new TLabel(Form3);
			LUgl[i]->Parent = Form3->Panels[i];
			LUgl[i]->Top = 40;
			LUgl[i]->Left = 606;
			LUgl[i]->WordWrap = true;
			LUgl[i]->AutoSize = false;
			LUgl[i]->Height = 20;
			LUgl[i]->Width = 70;
			LUgl[i]->Font->Size = 10;
			LUgl[i]->Caption = "0";

			LKal[i] = new TLabel(Form3);
			LKal[i]->Parent = Form3->Panels[i];
			LKal[i]->Top = 40;
			LKal[i]->Left = 679;
			LKal[i]->WordWrap = true;
			LKal[i]->AutoSize = false;
			LKal[i]->Height = 20;
			LKal[i]->Width = 70;
			LKal[i]->Font->Size = 10;
			LKal[i]->Caption = "0";

			Form3->Label3->Visible=true;  //����� ����
			Form3->Buttons[i]->Visible=false;
			Form3->Labeles[i*5+1]->Visible=false;
			Form3->Labeles[i*5+2]->Visible=false;
			Form3->Labeles[i*5+3]->Visible=false;
			Form3->Labeles[i*5+4]->Visible=false;

			Form3->Label11->Visible=true;  //���������
			Form3->Label11->Caption="� ��� ������ ����,�� ���� ����� �����";




		}
	}
Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::FormClose(TObject *Sender, TCloseAction &Action)
{
	if(WatchedRecom)   //���� �������� � ���������� ����������������
	for(int i=0;i<Form3->MealsA;i++)
		if(Form3->IsDelMeal[i]==false)
		{
			LWeights[i]->Free();
			LBel[i]->Free();
			LZh[i]->Free();
			LUgl[i]->Free();
			LKal[i]->Free();

			Form3->Labeles[i*5+1]->Visible=true;
			Form3->Labeles[i*5+2]->Visible=true;
			Form3->Labeles[i*5+3]->Visible=true;
			Form3->Labeles[i*5+4]->Visible=true;

			Form3->Buttons[i]->Visible=true;
		}
	Form3->Label3->Visible=false;
	Form3->Button1->Visible=true;
	Form3->Label8->Visible=true;
	Form3->Label11->Visible=false;
	Form3->IsRecommend=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm8::MassChange(TObject *Sender)
{
	TEdit *btn = dynamic_cast<TEdit *>(Sender);

	int num=btn->Tag;

	double sum=0;
	for(int i=0;i<Form2->ProductsA;i++)
	{
		if(!Form2->IsDel[i] && Form3->IsRight[num][i])
            sum+=StrToInt(Form3->Weights[num][i]);
	}
	double kpergramm;
	double bpergramm;
	double zpergramm;
	double upergramm;
	if(sum!=0)
	{
		kpergramm=StrToFloat(Form3->Labeles[num*5+4]->Caption)/sum;
		bpergramm=StrToFloat(Form3->Labeles[num*5+1]->Caption)/sum;
		zpergramm=StrToFloat(Form3->Labeles[num*5+2]->Caption)/sum;
		upergramm=StrToFloat(Form3->Labeles[num*5+3]->Caption)/sum;
	}
	else
	{
		kpergramm=0;
		bpergramm=0;
		zpergramm=0;
		upergramm=0;
    }

	double gramm=0;
	if(LWeights[num]->Text!="")
		gramm=StrToFloat(LWeights[num]->Text);

	kpergramm=ceil(kpergramm*gramm*100)/100;
	bpergramm=ceil(bpergramm*100*gramm)/100;
	zpergramm=ceil(zpergramm*100*gramm)/100;
	upergramm=ceil(upergramm*100*gramm)/100;

	LBel[num]->Caption=FloatToStr(ceil(bpergramm));
	LZh[num]->Caption=FloatToStr(ceil(zpergramm));
	LUgl[num]->Caption=FloatToStr(ceil(upergramm));
	LKal[num]->Caption=FloatToStr(ceil(kpergramm));

		int kal=0;
			for(int j=0;j<Form3->MealsA;j++)
				if(!Form3->IsDelMeal[j] && LWeights[j]->Text!="")
					kal+=StrToInt(LKal[j]->Caption);

			if(BMR-kal>400)   //���� ������
			{
				Form3->RecomPanel->Color=clHighlight;
				Form3->Label11->Caption="� ��� ������ ����,�� ���� ����� ����� ("+IntToStr(kal) + "����)";
				Form3->Label11->Font->Color=clWhite;
			}
				else
				if(BMR-kal<-400)  //���� ������
				{
					Form3->RecomPanel->Color=RGB(247,192,25);
					Form3->Label11->Caption="� ��� ����� ����,�� ���� ����� ����� ("+IntToStr(kal) + "����)";
					Form3->Label11->Font->Color=clWhite;
				}
					else
					{
					Form3->RecomPanel->Color=RGB(25,247,83);     //���� ��������
					Form3->Label11->Caption="� ��� ������������� ������� ������� (" +IntToStr(kal) + "����)";
					Form3->Label11->Font->Color=clBlack;
					}

}

