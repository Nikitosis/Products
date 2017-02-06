//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <fstream.h>
#include <iostream.h>
#include <string>
#include <windows.h>

#include "Main.h"
#include "Products.h"
#include "Meals.h"
#include "Recommend.h"
#include "MealsForm.h"
#include "ProdForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
setlocale(LC_ALL, "Russian");
SetConsoleCP(1251);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Form4->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Save1Click(TObject *Sender)
{
	  if(SaveDialog1->Execute())
	  {
		   ofstream fout(SaveDialog1->FileName.c_str());
		   fout<<Form3->MealsA-Form3->MealsDel<<endl;
		   for(int i=0;i<Form3->MealsA;i++)
		   if(Form3->IsDelMeal[i]==false)
		   {
			 AnsiString s;

			 s=Form3->Labeles[i*5]->Caption.c_str();
			 fout<<s.c_str()<<endl;

			 s=Form3->Labeles[i*5+1]->Caption.c_str();
			 fout<<s.c_str()<<endl;

			 s=Form3->Labeles[i*5+2]->Caption.c_str();
			 fout<<s.c_str()<<endl;

			 s=Form3->Labeles[i*5+3]->Caption.c_str();
			 fout<<s.c_str()<<endl;

			 s=Form3->Labeles[i*5+4]->Caption.c_str();
			 fout<<s.c_str()<<endl;

			 s=Form3->Memos[i]->Lines->Text.c_str();
			 fout<<s.c_str()<<endl;
		   }

		   for(int i=0;i<99;i++)
		   for(int j=0;j<99;j++)
		   fout<<Form3->IsLeft[i][j]<<" ";
		   fout<<endl;

		   for(int i=0;i<99;i++)
		   for(int j=0;j<99;j++)
		   fout<<Form3->IsRight[i][j]<<" ";
		   fout<<endl;

		   for(int i=0;i<99;i++)
		   for(int j=0;j<99;j++)
		   {
			 AnsiString s;
			 s=Form3->Weights[i][j].c_str();
		     fout<<s.c_str()<<" ";
		   }
		   fout<<endl;
		   //////////////////////////////////////////

		   fout<<Form2->ProductsA-Form2->ProductsDel<<endl;

		   for(int i=0;i<Form2->ProductsA;i++)
			 if(Form2->IsDel[i]==false)
			   {
				   AnsiString s;

				   s=Form2->Labeles[i*5]->Caption.c_str();
				   fout<<s.c_str()<<endl;

				   s=Form2->Labeles[i*5+1]->Caption.c_str();
				   fout<<s.c_str()<<endl;

				   s=Form2->Labeles[i*5+2]->Caption.c_str();
				   fout<<s.c_str()<<endl;

				   s=Form2->Labeles[i*5+3]->Caption.c_str();
				   fout<<s.c_str()<<endl;

				   s=Form2->Labeles[i*5+4]->Caption.c_str();
				   fout<<s.c_str()<<endl;

			   }

	  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Load1Click(TObject *Sender)
{
	if(OpenDialog1->Execute())
	{
	ifstream fin(OpenDialog1->FileName.c_str());

		for(int i=0;i<Form2->ProductsA;i++)                      //открываем Products
		if(Form2->IsDel[i]==false)
		 Form2->Panels[i]->Free();

        for(int i=0;i<Form3->MealsA;i++)
		if(Form3->IsDelMeal[i]==false)
		 Form3->Panels[i]->Free();

		 memset(Form2->IsDel,false,100*sizeof(bool));
		 memset(Form3->IsDelMeal,false,100*sizeof(bool));


		int n;
		fin>>n;
		Form3->PropNum=99;
		Form2->ProductsA=0;
		Form3->MealsA=0;
		Form2->ProductsDel=0;
		Form3->MealsDel=0;

		string s;
	    getline(fin,s);
		for(int i=0;i<n;i++)
		{
		  Form6->Button2Click(this);
		  getline(fin,s);
		  Form3->Labeles[i*5]->Caption=s.c_str();

          getline(fin,s);
		  Form3->Labeles[i*5+1]->Caption=s.c_str();

		  getline(fin,s);
		  Form3->Labeles[i*5+2]->Caption=s.c_str();

		  getline(fin,s);
		  Form3->Labeles[i*5+3]->Caption=s.c_str();

		  getline(fin,s);
		  Form3->Labeles[i*5+4]->Caption=s.c_str();

		  getline(fin,s);
		  Form3->Memos[i]->Lines->Text=s.c_str();
		}

	  for(int i=0;i<99;i++)
		for(int j=0;j<99;j++)
		  fin>>Form3->IsLeft[i][j];

	  for(int i=0;i<99;i++)
		for(int j=0;j<99;j++)
		  fin>>Form3->IsRight[i][j];

      for(int i=0;i<99;i++)
		for(int j=0;j<99;j++)
		{
			fin>>s;
            Form3->Weights[i][j]=s.c_str();
		}
		/////////////////////////////////////////////////////////     открываем Meals
	    n;
		fin>>n;
		Form5->Button4->Visible=false;
		getline(fin,s);
		for(int i=0;i<n;i++)
		{
		  Form5->Button2Click(this);
		  getline(fin,s);
		  Form2->Labeles[i*5]->Caption=s.c_str();

          getline(fin,s);
		  Form2->Labeles[i*5+1]->Caption=s.c_str();

		  getline(fin,s);
		  Form2->Labeles[i*5+2]->Caption=s.c_str();

		  getline(fin,s);
		  Form2->Labeles[i*5+3]->Caption=s.c_str();

		  getline(fin,s);
		  Form2->Labeles[i*5+4]->Caption=s.c_str();

        }

    }
}
//---------------------------------------------------------------------------

