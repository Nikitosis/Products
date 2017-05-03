//---------------------------------------------------------------------------

#ifndef ProductsH
#define ProductsH
#include <Buttons.hpp>
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <pngimage.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TScrollBox *ScrollBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Save1;
	TMenuItem *Load1;
	TImage *Button1;
	TLabel *Label3;
	TTimer *Timer1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall PropClick(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall Load1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormMouseEnter(TObject *Sender);
private:	// User declarations
public:	 int ProductsA;
TPanel *Panels[100];
int PanelH;	// User declarations
TImage *Images[100];
TLabel *Labeles[300];
TBitBtn *Buttons[100];
bool IsDel[100];
int PropNum,ProductsDel;
int SettingsNum,PictureNum;
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
