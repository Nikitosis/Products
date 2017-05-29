//---------------------------------------------------------------------------

#ifndef RecommendH
#define RecommendH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include <Graphics.hpp>
#include <Buttons.hpp>//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TComboBox *ComboBox1;
	TLabel *Label2;
	TEdit *Edit1;
	TLabel *Label3;
	TEdit *Edit2;
	TLabel *Label4;
	TEdit *Edit3;
	TLabel *Label5;
	TComboBox *ComboBox2;
	TImage *Button1;
	TLabel *Label6;
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
	TBitBtn *Backspace;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button1MouseEnter(TObject *Sender);
	void __fastcall FormMouseEnter(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button6MouseEnter(TObject *Sender);
	void __fastcall BackspaceClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
double BMR;
int FocusIndex;
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
