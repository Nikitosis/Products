//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "math.h"


#include "RecommendDialog.h"
#include "RecommendMeals.h"
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

for(int i=0;i<Form3->Meal.size();i++)
	Form11->CreateNewRecomMeal(i);


Form11->ShowModal();
}
//---------------------------------------------------------------------------


