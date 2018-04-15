//---------------------------------------------------------------------------

#ifndef ProdFormH
#define ProdFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <Buttons.hpp>
#include <string>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TOpenPictureDialog *OpenPictureDialog1;
	TImage *Image2;
	TBitBtn *BitBtn1;
	TBitBtn *Button2;
	TBitBtn *Button3;
	TBitBtn *Button4;
	TBitBtn *Button1;
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
	TButton *Button27;
	TButton *Button26;
	TButton *Button25;
	TButton *Button24;
	TButton *Button23;
	TButton *Button22;
	TButton *Button21;
	TButton *Button20;
	TButton *Button18;
	TButton *Button17;
	TButton *Button19;
	TButton *Button16;
	TButton *Button38;
	TButton *Button37;
	TButton *Button36;
	TButton *Button35;
	TButton *Button34;
	TButton *Button33;
	TButton *Button32;
	TButton *Button31;
	TButton *Button30;
	TButton *Button29;
	TButton *Button28;
	TButton *Button48;
	TButton *Button47;
	TButton *Button46;
	TButton *Button45;
	TButton *Button44;
	TButton *Button42;
	TButton *Button43;
	TButton *Button41;
	TButton *Button40;
	TButton *Button53;
	TButton *Button52;
	TBitBtn *Backspace;
	TBitBtn *BitBtn2;
	TBitBtn *Button51;
	TBitBtn *Button50;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button6MouseEnter(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ShiftClick(TObject *Sender);
	void __fastcall Button53Click(TObject *Sender);
	void __fastcall Edit2Click(TObject *Sender);
	void __fastcall Edit1Click(TObject *Sender);
	void __fastcall BackspaceClick(TObject *Sender);
	void __fastcall Button52Click(TObject *Sender);
	void __fastcall Button51Click(TObject *Sender);
	void __fastcall Button50Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	AnsiString Masses[600];
	int FocusIndex;
	bool IsNew;
	__fastcall TForm5(TComponent* Owner);
	void __fastcall TForm5::SettingsEnter(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
