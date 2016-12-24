//---------------------------------------------------------------------------

#ifndef ProductsH
#define ProductsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TScrollBox *ScrollBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall PropClick(TObject *Sender);
private:	// User declarations
public:	 int ProductsA;
TPanel *Panels[100];
int PanelH;	// User declarations
TImage *Images[100];
TLabel *Labeles[300];
TMemo *Edits[100];
TButton *Buttons[100];
int PropNum,ProductsDel;
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
