//---------------------------------------------------------------------------

#ifndef RecipeH
#define RecipeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <pngimage.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TLabel *Label1;
	TImage *Image1;
	TImage *Button2;
	TImage *Button1;
	TLabel *Label2;
	TLabel *Label4;
	TLabel *Label3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1MouseEnter(TObject *Sender);
	void __fastcall Image1MouseEnter(TObject *Sender);
	void __fastcall Button2MouseEnter(TObject *Sender);
private:	// User declarations
public:		// User declarations
AnsiString text;
	__fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
