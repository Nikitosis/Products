//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RecommendDialog.h"
#include "Meals.h"
#include "MealsForm.h"
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
Form3->IsRecommend=true;
Form3->Button1->Visible=false;
for(int i=0;i<Form3->MealsA;i++)
	{
		if(Form3->IsDelMeal[i]==false)
		{
			Form3->RecomPanel[i]->Visible=true;
			int kal=StrToInt(Form3->Labeles[i*5+4]->Caption);
			if(BMR-kal>400)   //���� ������
				Form3->RecomPanel[i]->Color=clHighlight;
				else
				if(BMR-kal<-400)  //���� ������
					Form3->RecomPanel[i]->Color=RGB(247,192,25);
					else
					Form3->RecomPanel[i]->Color=RGB(25,247,83);     //���� ��������

			LWeights[i]=new TLabel(Form3);             //���� �����
			LWeights[i]->Parent=Form3->Panels[i];
			LWeights[i]->Left = 803;
			LWeights[i]->Top=40;
			LWeights[i]->Font->Size=10;
			LWeights[i]->AutoSize=false;
			LWeights[i]->Width=50;
			LWeights[i]->Caption="aaaa";

			Form3->Label3->Visible=true;  //����� ����
			Form3->Buttons[i]->Visible=false;

			Form3->Panel1->Visible=true; //���������
			Form3->Panel2->Visible=true;
			Form3->Panel3->Visible=true;
			Form3->Label8->Visible=true;
			Form3->Label9->Visible=true;
			Form3->Label10->Visible=true;


            int weight=0;
			for(int j=0;j<100;j++)
			{
				if(Form3->IsRight[i][j])
                weight+=StrToInt(Form3->Weights[i][j]);
			}

			LWeights[i]->Caption=IntToStr(weight);
		}
	}
Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::FormClose(TObject *Sender, TCloseAction &Action)
{
	for(int i=0;i<Form3->MealsA;i++)
		if(Form3->IsDelMeal[i]==false)
		{
			LWeights[i]->Free();
			Form3->Buttons[i]->Visible=true;
			Form3->Label3->Visible=false;
			Form3->Button1->Visible=true;
		}
}
//---------------------------------------------------------------------------

