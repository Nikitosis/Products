//---------------------------------------------------------------------------

#ifndef MealsH
#define MealsH

#include <Buttons.hpp>

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <pngimage.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TScrollBox *ScrollBox1;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label5;
	TLabel *Label4;
	TLabel *Label2;
	TLabel *Label1;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Save1;
	TMenuItem *Load1;
	TLabel *Label3;
	TPanel *RecomPanel;
	TLabel *Label11;
	TImage *Button1;
	TLabel *Label8;
	TTimer *Timer1;
	TPanel *Panel4;
	TButton *Button10;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Backspace;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall Load1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormMouseEnter(TObject *Sender);
	void __fastcall Button1MouseEnter(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button6MouseEnter(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BackspaceClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
TPanel *Panels[200];                   //для каждой Meals
TImage *Images[200];
TMemo *Memos[200];
TLabel *Labeles[600];
TBitBtn *Buttons[200];
int MealsA,MealsDel,PanelH,PanelHaveH;          //колво прод. колво удаленных, высота панели в Meals,высота панели в MealsForm
int ProductsHave,ProductsUse;           //кол-во продуктов слева и справа соотв.
int PropNum;    //номер нажатой кнопки настроек
TPanel *PanelsHave[200];       //для каждой MealsForm
//TPanel *RecomPanel[100];
TLabel *LabelesHave[200];
TImage *ImagesHave[200];
TEdit *EditsHave[200];
TBitBtn *ButtonsHave[200];

bool IsRecommend;
bool IsLeft[200][200];
bool IsRight[200][200];       //сохраняют,с какой стороны находится продукт
bool LeftWas[200];
bool RightWas[200];
bool IsDelMeal[200];
AnsiString Weights[200][200];
int SettingsNum,PictureNum;
int WasDeleted;
bool NeedToDelete[200];
int FocusIndex;
	__fastcall TForm3(TComponent* Owner);
	void __fastcall TForm3::AddClick(TObject *Sender);
	void __fastcall TForm3::AddClickF(int num);
	void __fastcall TForm3::PropClick(TObject *Sender);
		void __fastcall TForm3::PropClickNum(int num);
	void __fastcall TForm3::EditsHaveChange(TObject *Sender);
	void __fastcall TForm3::EditsClick(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
