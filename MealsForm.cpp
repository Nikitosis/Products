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
void __fastcall TForm6::Button2Click(TObject *Sender) {
	if (Form3->PropNum == 199) {
		Form3->MealsA++;
		int n = Form3->MealsA - 1;
		int k;
		k = Form3->ScrollBox1->VertScrollBar->Position;
		// нужно обязательно,иначе появл. пропуски
		Form3->ScrollBox1->VertScrollBar->Position = 0;

		Form3->Panels[n] = new TPanel(Form3);
		Form3->Panels[n]->Parent = Form3->ScrollBox1;
		Form3->Panels[n]->Top = (Form3->MealsA - 1 - Form3->MealsDel)
		* Form3->PanelH;
		Form3->Panels[n]->Left = 0;
		Form3->Panels[n]->Width = Form3->ScrollBox1->Width - 4;
		Form3->Panels[n]->Height = Form3->PanelH;

		Form3->ScrollBox1->VertScrollBar->Position = k;

		Form3->Images[n] = new TImage(Form3);
		Form3->Images[n]->Parent = Form3->Panels[n];
		Form3->Images[n]->Left = 327;
		Form3->Images[n]->Height = Form3->PanelH - 1;
		Form3->Images[n]->Width = 125;
		Form3->Images[n]->Stretch = true;
		Form3->Images[n]->Picture = Image1->Picture;

		Form3->Memos[n] = new TMemo(Form3);
		Form3->Memos[n]->Parent = Form3->Panels[n];
		Form3->Memos[n]->Left = 277;
		Form3->Memos[n]->Height = Form3->PanelH - 1;
		Form3->Memos[n]->Width = 273;
		Form3->Memos[n]->ReadOnly = true;
		Form3->Memos[n]->ScrollBars = ssBoth;
		Form3->Memos[n]->Lines->Text = Form7->Memo1->Lines->Text;
		Form3->Memos[n]->Visible = false;

		Form3->Labeles[n * 5] = new TLabel(Form3);
		Form3->Labeles[n * 5]->Parent = Form3->Panels[n];
		Form3->Labeles[n * 5]->Top = 20;
		Form3->Labeles[n * 5]->Left = 10;
		Form3->Labeles[n * 5]->WordWrap = true;
		Form3->Labeles[n * 5]->AutoSize = false;
		Form3->Labeles[n * 5]->Height = 70;
		Form3->Labeles[n * 5]->Width = 300;
		Form3->Labeles[n * 5]->Font->Size = 14;
		Form3->Labeles[n * 5]->Caption = Form6->Edit1->Text;

		Form3->Labeles[n * 5 + 1] = new TLabel(Form3);
		Form3->Labeles[n * 5 + 1]->Parent = Form3->Panels[n];
		Form3->Labeles[n * 5 + 1]->Top = 40;
		Form3->Labeles[n * 5 + 1]->Left = 460;
		Form3->Labeles[n * 5 + 1]->WordWrap = true;
		Form3->Labeles[n * 5 + 1]->AutoSize = false;
		Form3->Labeles[n * 5 + 1]->Height = 20;
		Form3->Labeles[n * 5 + 1]->Width = 70;
		Form3->Labeles[n * 5 + 1]->Font->Size = 10;
		Form3->Labeles[n * 5 + 1]->Caption = Label9->Caption;

		Form3->Labeles[n * 5 + 2] = new TLabel(Form3);
		Form3->Labeles[n * 5 + 2]->Parent = Form3->Panels[n];
		Form3->Labeles[n * 5 + 2]->Top = 40;
		Form3->Labeles[n * 5 + 2]->Left = 533;
		Form3->Labeles[n * 5 + 2]->WordWrap = true;
		Form3->Labeles[n * 5 + 2]->AutoSize = false;
		Form3->Labeles[n * 5 + 2]->Height = 20;
		Form3->Labeles[n * 5 + 2]->Width = 70;
		Form3->Labeles[n * 5 + 2]->Font->Size = 10;
		Form3->Labeles[n * 5 + 2]->Caption = Label10->Caption;

		Form3->Labeles[n * 5 + 3] = new TLabel(Form3);
		Form3->Labeles[n * 5 + 3]->Parent = Form3->Panels[n];
		Form3->Labeles[n * 5 + 3]->Top = 40;
		Form3->Labeles[n * 5 + 3]->Left = 606;
		Form3->Labeles[n * 5 + 3]->WordWrap = true;
		Form3->Labeles[n * 5 + 3]->AutoSize = false;
		Form3->Labeles[n * 5 + 3]->Height = 20;
		Form3->Labeles[n * 5 + 3]->Width = 70;
		Form3->Labeles[n * 5 + 3]->Font->Size = 10;
		Form3->Labeles[n * 5 + 3]->Caption = Label11->Caption;

		Form3->Labeles[n * 5 + 4] = new TLabel(Form3);
		Form3->Labeles[n * 5 + 4]->Parent = Form3->Panels[n];
		Form3->Labeles[n * 5 + 4]->Top = 40;
		Form3->Labeles[n * 5 + 4]->Left = 679;
		Form3->Labeles[n * 5 + 4]->WordWrap = true;
		Form3->Labeles[n * 5 + 4]->AutoSize = false;
		Form3->Labeles[n * 5 + 4]->Height = 20;
		Form3->Labeles[n * 5 + 4]->Width = 70;
		Form3->Labeles[n * 5 + 4]->Font->Size = 10;
		Form3->Labeles[n * 5 + 4]->Caption = Label12->Caption;

		Form3->Buttons[n] = new TBitBtn(Form3);
		Form3->Buttons[n]->Parent = Form3->Panels[n];
		Form3->Buttons[n]->Left = 793;
		Form3->Buttons[n]->Height = Form3->PanelH - 1;
		Form3->Buttons[n]->Width = 110;
		Form3->Buttons[n]->Tag = n;
		Form3->Buttons[n]->OnClick = Form3->PropClick;
		Form3->Buttons[n]->Glyph=BitBtn1->Glyph;
		Form3->Buttons[n]->OnMouseEnter=SettingsEnter;


		/*Form3->RecomPanel[n] = new TPanel(Form3); // линия для обозначения,какое блюдо по каллорийности в реккомендациях
		Form3->RecomPanel[n]->Parent = Form3->Panels[n];
		Form3->RecomPanel[n]->Left = 0;
		Form3->RecomPanel[n]->Height = 10;
		Form3->RecomPanel[n]->Width = 327;
		Form3->RecomPanel[n]->Top = 0;
		Form3->RecomPanel[n]->Tag = n;
		Form3->RecomPanel[n]->Visible=false;
		Form3->RecomPanel[n]->Color = clLime;
		Form3->RecomPanel[n]->ParentBackground=false;   */

		TImage *line2 = new TImage(Form3);
		line2->Parent = Form3->Panels[n];
		line2->Left = 327;
		line2->Width = 2;
		line2->Height = Form3->PanelH - 1;
		line2->Picture->Bitmap->Width = 2;
		line2->Picture->Bitmap->Height = Form3->PanelH - 1;
		line2->Picture->Bitmap->Canvas->Brush->Color = clBlack;
		line2->Picture->Bitmap->Canvas->FillRect(Rect(0, 0, 2, 100));

		TImage *line3 = new TImage(Form3);
		line3->Parent = Form3->Panels[n];
		line3->Left = 450;
		line3->Width = 2;
		line3->Height = Form3->PanelH - 1;
		line3->Picture->Bitmap->Width = 2;
		line3->Picture->Bitmap->Height = Form3->PanelH - 1;
		line3->Picture->Bitmap->Canvas->Brush->Color = clBlack;
		line3->Picture->Bitmap->Canvas->FillRect(Rect(0, 0, 2, 100));

		TImage *line4 = new TImage(Form3);
		line4->Parent = Form3->Panels[n];
		line4->Left = 523;
		line4->Width = 2;
		line4->Height = Form3->PanelH - 1;
		line4->Picture->Bitmap->Width = 2;
		line4->Picture->Bitmap->Height = Form3->PanelH - 1;
		line4->Picture->Bitmap->Canvas->Brush->Color = clBlack;
		line4->Picture->Bitmap->Canvas->FillRect(Rect(0, 0, 2, 100));

		TImage *line5 = new TImage(Form3);
		line5->Parent = Form3->Panels[n];
		line5->Left = 596;
		line5->Width = 2;
		line5->Height = Form3->PanelH - 1;
		line5->Picture->Bitmap->Width = 2;
		line5->Picture->Bitmap->Height = Form3->PanelH - 1;
		line5->Picture->Bitmap->Canvas->Brush->Color = clBlack;
		line5->Picture->Bitmap->Canvas->FillRect(Rect(0, 0, 2, 100));

		TImage *line6 = new TImage(Form3);
		line6->Parent = Form3->Panels[n];
		line6->Left = 669;
		line6->Width = 2;
		line6->Height = Form3->PanelH - 1;
		line6->Picture->Bitmap->Width = 2;
		line6->Picture->Bitmap->Height = Form3->PanelH - 1;
		line6->Picture->Bitmap->Canvas->Brush->Color = clBlack;
		line6->Picture->Bitmap->Canvas->FillRect(Rect(0, 0, 2, 100));

		TImage *line7 = new TImage(Form3);
		line7->Parent = Form3->Panels[n];
		line7->Left = 792;
		line7->Width = 2;
		line7->Height = Form3->PanelH - 1;
		line7->Picture->Bitmap->Width = 2;
		line7->Picture->Bitmap->Height = Form3->PanelH - 1;
		line7->Picture->Bitmap->Canvas->Brush->Color = clBlack;
		line7->Picture->Bitmap->Canvas->FillRect(Rect(0, 0, 2, 100));

		for (int i = 0; i < Form2->ProductsA; i++) {
			Form3->IsLeft[n][i] = Form3->IsLeft[199][i];
			Form3->IsRight[n][i] = Form3->IsRight[199][i];
		}

		for (int i = 0; i < Form2->ProductsA; i++)
			Form3->Weights[n][i] = Form3->EditsHave[i]->Text;

		/*if (Form3->IsRecommend) // Если мы в рекомендациях ,то смотрим на ккалории и задаем панели цвет
		{
			Form3->RecomPanel[n]->Height=10;
			int kal=StrToInt(Label12->Caption);
			if(Form4->BMR-kal>400)   //если меньше
					Form3->RecomPanel[n]->Color=clHighlight;
					else
					if(Form4->BMR-kal<-400)  //если больше
						Form3->RecomPanel[n]->Color=RGB(247,192,25);
						else
						Form3->RecomPanel[n]->Color=RGB(25,247,83);     //если идеально
		}     */
	}
	else {
		int n = Form3->PropNum;
		Form3->Memos[n]->Text = Form7->Memo1->Text;
		Form3->Images[n]->Picture = Image1->Picture;
		Form3->Labeles[n * 5]->Caption = Edit1->Text;
		Form3->Labeles[n * 5 + 1]->Caption = Label9->Caption;
		Form3->Labeles[n * 5 + 2]->Caption = Label10->Caption;
		Form3->Labeles[n * 5 + 3]->Caption = Label11->Caption;
		Form3->Labeles[n * 5 + 4]->Caption = Label12->Caption;
		for (int i = 0; i < Form2->ProductsA; i++)
			if(Form3->NeedToDelete[i])
				Form3->Weights[n][Form3->PanelsHave[i]->Tag] = Form3->EditsHave[i]->Text;


		if (Form3->IsRecommend) // Если мы в рекомендациях ,то смотрим на ккалории и задаем панели цвет
		{
			int kal=StrToInt(Label12->Caption);
			if(Form4->BMR-kal>400)   //если меньше
					Form3->RecomPanel->Color=clHighlight;
					else
					if(Form4->BMR-kal<-400)  //если больше
						Form3->RecomPanel->Color=RGB(247,192,25);
						else
						Form3->RecomPanel->Color=RGB(25,247,83);     //если идеально
		}
	}

		Close();
}

// ---------------------------------------------------------------------------
void __fastcall TForm6::Button3Click(TObject *Sender) {
	if (Form3->PropNum != 199) {
		int num = Form3->PropNum;
		for (int i = 0; i < Form2->ProductsA; i++) {
			Form3->IsLeft[num][i] = Form3->LeftWas[i];
			Form3->IsRight[num][i] = Form3->RightWas[i];
		}
		Form3->PropClick(Form3->Buttons[num]);
		if(Form3->ProductsHave+Form3->ProductsUse>0)
			Form3->EditsHaveChange(Form3->EditsHave[0]);
	}
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
	Form3->Panels[Form3->PropNum]->Free();
	for (int i = 0; i < Form3->MealsA; i++)
		if (Form3->IsDelMeal[i] == false && Form3->Panels[i]
			->Top > Form3->Panels[Form3->PropNum]->Top)
			Form3->Panels[i]->Top -= Form3->PanelH;

	for (int i = 0; i < Form2->ProductsA; i++) {
		Form3->IsLeft[Form3->PropNum][i] = true;
		Form3->IsRight[Form3->PropNum][i] = false;
	}
	Form3->MealsDel++;
	Form3->IsDelMeal[Form3->PropNum] = true;
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
Form3->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::SettingsEnter(TObject *Sender)
{
	TBitBtn *btn = dynamic_cast<TBitBtn *>(Sender);
	if(Form3->SettingsNum>=0)
	{
	   AnsiString s=ExtractFilePath(Application->ExeName);
	   s+="/SettingButtons/"+IntToStr(0)+".bmp";
	   Form3->Buttons[Form3->SettingsNum]->Glyph->LoadFromFile(s);
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
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button10MouseEnter(TObject *Sender)
{
for(int i=0;i<Form6->ComponentCount-1;i++)
	{
	   if(Form6->ActiveControl==Form6->Components[i] && Form6->Components[i]->ClassName()=="TEdit")
		FocusIndex=i;
	}
AnsiString s=ExtractFilePath(Application->ExeName);
Button5->Picture->LoadFromFile(s+"/RecipeButton/ScrollActive.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button7Click(TObject *Sender)
{
  TButton *button = dynamic_cast<TButton *>(Sender);         //backspace
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





void __fastcall TForm6::Button6Click(TObject *Sender)
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
TButton *button = dynamic_cast<TButton *>(Sender);         //буквы+цифры
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
TButton *button = dynamic_cast<TButton *>(Sender);         //буквы+цифры
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

