//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Products.h"
#include "Main.h"
#include "Meals.h"
#include "Recommend.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int ProductsA;
TPanel *Panels[100];
const int PanelH=30;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button1Click(TObject *Sender)
{
ProductsA++;
Panels[ProductsA]=new TPanel(Form2);
Panels[ProductsA]->Parent=ScrollBox1;
Panels[ProductsA]->Top=(ProductsA-1)*PanelH;
Panels[ProductsA]->Left=0;
Panels[ProductsA]->Width=ScrollBox1->Width-4;
Panels[ProductsA]->Height=PanelH;
}
//---------------------------------------------------------------------------

