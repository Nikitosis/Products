//---------------------------------------------------------------------------

#ifndef LoadingH
#define LoadingH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm12 : public TForm
{
__published:	// IDE-managed Components
	TProgressBar *ProgressBar1;
	TLabel *Label1;
private:	// User declarations
public:		// User declarations
	__fastcall TForm12(TComponent* Owner);
	void __fastcall OpenLoading(int maximum);
	void __fastcall AddProgress();
	void __fastcall OpenSaving(int maximum);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm12 *Form12;
//---------------------------------------------------------------------------
#endif
