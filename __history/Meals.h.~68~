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
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall Load1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormMouseEnter(TObject *Sender);
private:	// User declarations
public:		// User declarations
TPanel *Panels[100];                   //для каждой Meals
TImage *Images[100];
TMemo *Memos[100];
TLabel *Labeles[300];
TBitBtn *Buttons[100];
int MealsA,MealsDel,PanelH,PanelHaveH;          //колво прод. колво удаленных, высота панели в Meals,высота панели в MealsForm
int ProductsHave,ProductsUse;           //кол-во продуктов слева и справа соотв.
int PropNum;    //номер нажатой кнопки настроек
TPanel *PanelsHave[100];       //для каждой MealsForm
//TPanel *RecomPanel[100];
TLabel *LabelesHave[100];
TImage *ImagesHave[100];
TEdit *EditsHave[100];
TBitBtn *ButtonsHave[100];

bool IsRecommend;
bool IsLeft[100][100];
bool IsRight[100][100];       //сохраняют,с какой стороны находится продукт
bool LeftWas[100];
bool RightWas[100];
bool IsDelMeal[100];
AnsiString Weights[100][100];
int SettingsNum,PictureNum;
	__fastcall TForm3(TComponent* Owner);
	void __fastcall TForm3::AddClick(TObject *Sender);
	void __fastcall TForm3::AddClickF(int num);
	void __fastcall TForm3::PropClick(TObject *Sender);
		void __fastcall TForm3::PropClickNum(int num);
	void __fastcall TForm3::EditsHaveChange(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
