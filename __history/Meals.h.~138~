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
#include <vector>
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
	TImage *Button1;
	TLabel *Label8;
	TTimer *Timer1;
	TBitBtn *BitBtn4;
	TEdit *Edit1;
	TTimer *Timer2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall Load1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormMouseEnter(TObject *Sender);
	void __fastcall Button1MouseEnter(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button6MouseEnter(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BackspaceClick(TObject *Sender);
	void __fastcall BitBtn4Click(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
struct MealStr{
	TPanel* Panel;
	TImage* Image;
	TMemo* Memo;
	TLabel* Name;
	TLabel* Protein;
	TLabel* Fat;
	TLabel* Carbon;
	TLabel* Calories;
	TBitBtn* SettingButton;
	bool IsLeft[1000];
	bool IsRight[1000];
	AnsiString Weight[1000];
};
struct ProductHave{
	TPanel* Panel;
	TImage* Image;
	TLabel* Name;
	TLabel* Protein;
	TLabel* Fat;
	TLabel* Carbon;
	TEdit* Edit;
	TBitBtn* Button;
};
std::vector<MealStr> Meal;
std::vector<ProductHave> ProdHave;
int PanelH,PanelHaveH;          //колво прод. колво удаленных, высота панели в Meals,высота панели в MealsForm
int ProductsHave,ProductsUse;           //кол-во продуктов слева и справа соотв.
int PropNum;    //номер нажатой кнопки настроек

bool IsNew; //новое ли блюдо
bool LeftWas[1000];
bool RightWas[1000];
bool IsSaved;
bool IsDel;
int SettingsNum,PictureNum;
int WasDeleted;
bool isExpantion;
int FocusIndex;
	__fastcall TForm3(TComponent* Owner);
	void __fastcall TForm3::AddClick(TObject *Sender);
	void __fastcall TForm3::AddClickF(int num);
	void __fastcall TForm3::PropClick(TObject *Sender);
	void __fastcall TForm3::PropClickNum(int num);
	void __fastcall TForm3::EditsHaveChange(TObject *Sender);
	void __fastcall TForm3::EditsClick(TObject *Sender);
	void __fastcall TForm3::CreateNewMeal();
	void __fastcall TForm3::RecountCalFromProd(int num);
	void __fastcall TForm3::RecountCalFromMeal();
	void __fastcall TForm3::AddLeft(int num);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
