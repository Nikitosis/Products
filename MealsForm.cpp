// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Products.h"
#include "MealsForm.h"
#include "Meals.h"
#include "Recipe.h"
#include "Recommend.h"
#include "Main.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;

// ---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------
void __fastcall TForm6::SaveButtonClick()
{
	Form3->IsSaved=false;
	Form3->IsDel=false;

	Form3->IsSaved=true;

	int n=Form3->PropNum;
	Form3->Meal[n].Image->Picture = Form6->Image1->Picture;
	Form3->Meal[n].Memo->Lines->Text = Form7->Memo1->Lines->Text;
	Form3->Meal[n].Name->Caption = Form6->Edit1->Text;
	Form3->Meal[n].Protein->Caption = Form6->Label9->Caption;
	Form3->Meal[n].Fat->Caption = Form6->Label10->Caption;
	Form3->Meal[n].Carbon->Caption = Form6->Label11->Caption;
	Form3->Meal[n].Calories->Caption = Form6->Label12->Caption;

	Form3->Meal[Form3->Meal.size()-1].Panel->Visible=true;

	for (int i = 0; i < Form2->Product.size(); i++)
	{
		Form3->Meal[n].Weight[i] = Form3->ProdHave[i].Edit->Text;
    }
}
// ---------------------------------------------------------------------------
void __fastcall TForm6::Button2Click(TObject *Sender) {
	SaveButtonClick();

	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TForm6::Button3Click(TObject *Sender) { //отменить
	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender) {
	if (OpenPictureDialog1->Execute()) {
		Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm6::Button4Click(TObject *Sender) // удаляем meals
{
	Form3->IsDel=true;
	Form3->Meal[Form3->PropNum].Panel->Free();

	for(int i=Form3->PropNum+1;i<Form3->Meal.size();i++)
	{
		Form3->Meal[i].Panel->Top-=Form3->PanelH;
		Form3->Meal[i].SettingButton->Tag--;
	}

	Form3->Meal.erase(Form3->Meal.begin()+Form3->PropNum);

	Form6->Close();
}
// ---------------------------------------------------------------------------

void __fastcall TForm6::Button5Click(TObject *Sender) {
	Form7->text = Form7->Memo1->Text;
	Form7->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm6::Panel1MouseEnter(TObject *Sender) {
	onScroll1 = true;
	onScroll2 = false;
}
// ---------------------------------------------------------------------------

void __fastcall TForm6::Panel2MouseEnter(TObject *Sender) {
	onScroll2 = true;
	onScroll1 = false;
}
// ---------------------------------------------------------------------------

void __fastcall TForm6::FormMouseEnter(TObject *Sender) {
	onScroll1 = false;
	onScroll2 = false;
    AnsiString s=ExtractFilePath(Application->ExeName);
	Button5->Picture->LoadFromFile(s+"/RecipeButton/Scroll.bmp");
}
// ---------------------------------------------------------------------------

void __fastcall TForm6::FormMouseWheelDown(TObject *Sender, TShiftState Shift,
	TPoint &MousePos, bool &Handled) {
	if (onScroll1)
		ScrollBox1->VertScrollBar->Position += 10;
	else
		ScrollBox2->VertScrollBar->Position += 10;
}
// ---------------------------------------------------------------------------

void __fastcall TForm6::FormMouseWheelUp(TObject *Sender, TShiftState Shift,
	TPoint &MousePos, bool &Handled) {
	if (onScroll1)
		ScrollBox1->VertScrollBar->Position -= 10;
	else
		ScrollBox2->VertScrollBar->Position -= 10;
}
// ---------------------------------------------------------------------------
void __fastcall TForm6::FormClose(TObject *Sender, TCloseAction &Action)
{
if(Form3->IsSaved || Form3->IsDel)
{
	Form3->IsSaved=false;
	Form3->IsDel=false;
	return;
}

if (!Form3->IsNew) {
		int num = Form3->PropNum;
		for (int i = 0; i < Form2->Product.size(); i++) {
			Form3->Meal[num].IsLeft[i] = Form3->LeftWas[i];
			Form3->Meal[num].IsRight[i] = Form3->RightWas[i];
		}
		Form3->RecountCalFromProd(num);
	}
	else
	{
		Form3->Meal.pop_back();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm6::SettingsEnter(TObject *Sender)
{
	TBitBtn *btn = dynamic_cast<TBitBtn *>(Sender);
	if(Form3->SettingsNum>=0)
	{
	   AnsiString s=ExtractFilePath(Application->ExeName);
	   s+="/SettingButtons/"+IntToStr(0)+".bmp";
	   Form3->Meal[Form3->SettingsNum].SettingButton->Glyph->LoadFromFile(s);
	   Form3->PictureNum=0;
	}
	Form3->SettingsNum=btn->Tag;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button10Click(TObject *Sender)
{
TButton *button = dynamic_cast<TButton *>(Sender);         //буквы+цифры
AnsiString s=Form6->Components[FocusIndex]->ClassName();
if(Form6->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form6->Components[FocusIndex];
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




void __fastcall TForm6::FormShow(TObject *Sender)
{
Form3->Edit1->Text="";
Edit1->OnClick(Sender);
FocusIndex=22;

if(Form1->IsKeyboard)
	{
	Panel4->Visible=true;
	Height=747;
	}
	else
	{
	Panel4->Visible=false;
	Height=554;
	}
Edit2->Text="";
Edit2->Left=305;
Edit2->Width=0;
isExpantion=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button10MouseEnter(TObject *Sender)
{
for(int i=0;i<Form6->ComponentCount-1;i++)
	{
	   if(Form6->ActiveControl==Form6->Components[i] && Form6->Components[i]->ClassName()=="TEdit")
		FocusIndex=i;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button7Click(TObject *Sender)//backspace
{
  AnsiString s=Form6->Components[FocusIndex]->ClassName();
if(Form6->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form6->Components[FocusIndex];
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






void __fastcall TForm6::Button118Click(TObject *Sender)
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

for(int i=0;i<Form6->ComponentCount-1;i++)
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


void __fastcall TForm6::Button133Click(TObject *Sender)
{
AnsiString s=Form6->Components[FocusIndex]->ClassName();
if(Form6->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form6->Components[FocusIndex];
	  int start=edit->SelStart;
	  edit->SetFocus();
	  edit->SelStart=start+1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button134Click(TObject *Sender)
{
AnsiString s=Form6->Components[FocusIndex]->ClassName();
if(Form6->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form6->Components[FocusIndex];
	  int start=edit->SelStart;
	  edit->SetFocus();
	  if(start!=0)
	 	 edit->SelStart=start-1;
    }
}
//---------------------------------------------------------------------------




void __fastcall TForm6::Edit1Click(TObject *Sender)
{
for(int i=0;i<Form6->ComponentCount-1;i++)
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

void __fastcall TForm6::Edit2Change(TObject *Sender)     //Фильтр по названиям доступных блюд
{
ScrollBox1->VertScrollBar->Position=0;
int PropNum=Form3->PropNum;
AnsiString WordToFind=Edit2->Text.LowerCase();
int SearchAmount=0;
for(int i=0;i<Form2->Product.size();i++)
		if(Form3->Meal[PropNum].IsLeft[i])
			{
				AnsiString Name=Form3->ProdHave[i].Name->Caption.LowerCase();
				int pos=Name.Pos(WordToFind);
				if(pos!=0 || WordToFind=="")
					{
						Form3->ProdHave[i].Panel->Top=Form3->PanelHaveH*SearchAmount;
						Form3->ProdHave[i].Panel->Visible=true;
						SearchAmount++;
					}
					else
					{
						Form3->ProdHave[i].Panel->Visible=false;
					}
			}

}
//---------------------------------------------------------------------------

void __fastcall TForm6::BitBtn4Click(TObject *Sender)
{
if(!isExpantion)
{
    Edit2->Left=305-Edit2->Width;
}
isExpantion=! isExpantion;
Timer1->Enabled=true;
Edit2->Text="";
}
//---------------------------------------------------------------------------


void __fastcall TForm6::Timer1Timer(TObject *Sender)
{
if(isExpantion)
	{
		if(Edit2->Width<81)
			{
			Edit2->Width+=3;
			Edit2->Left-=3;
			}
			else
			{
			Timer1->Enabled=false;
			Edit2->Width=81;
			Edit2->Left=224;
			}
	}
	else
	{
       	if(Edit2->Width>0)
			Edit2->Width-=3;
			else
			{
			Timer1->Enabled=false;
			Edit2->Width=0;
			Edit2->Left=305;
			}
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm6::BackspaceClick(TObject *Sender)//backspace
{
  AnsiString s=Form6->Components[FocusIndex]->ClassName();
if(Form6->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form6->Components[FocusIndex];
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

void __fastcall TForm6::ShiftClick(TObject *Sender)
{
for(int i=0;i<Form6->ComponentCount-1;i++)
{
  if(Form6->Components[i]->ClassName()=="TButton")
  {
	TButton *button = (TButton*)Form6->Components[i];
	if(button->Caption.Length()==1)
		if(button->Caption==button->Caption.UpperCase())
			button->Caption=button->Caption.LowerCase();
			else
			button->Caption=button->Caption.UpperCase();
  }
}
TEdit *edit = (TEdit*)Form6->Components[FocusIndex];
edit->SetFocus();
edit->SelLength=0;
edit->SelStart=100;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button5MouseEnter(TObject *Sender)
{
AnsiString s=ExtractFilePath(Application->ExeName);
Button5->Picture->LoadFromFile(s+"/RecipeButton/ScrollActive.bmp");
}
//---------------------------------------------------------------------------


