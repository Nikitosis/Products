//---------------------------------------------------------------------------

#ifndef MealsH
#define MealsH

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TScrollBox *ScrollBox1;
	TButton *Button1;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label5;
	TLabel *Label4;
	TLabel *Label3;
	TLabel *Label2;
	TLabel *Label1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
TPanel *Panels[100];                   //��� ������ Meals
TImage *Images[100];
TMemo *Memos[100];
TLabel *Labeles[300];
TButton *Buttons[100];
int ProductsA,ProductsDel,PanelH,PanelHaveH;          //����� ����. ����� ���������, ������ ������ � Meals,������ ������ � MealsForm
int ProductsHave,ProductsUse;           //���-�� ��������� ����� � ������ �����.
int PropNum;    //����� ������� ������ ��������
TPanel *PanelsHave[100];       //��� ������ MealsForm
TLabel *LabelesHave[100];
TImage *ImagesHave[100];
TEdit *EditsHave[100];
TButton *ButtonsHave[100];
bool IsLeft[100][100];
bool IsRight[100][100];       //���������,� ����� ������� ��������� �������
bool LeftWas[100];
bool RightWas[100];
AnsiString Weights[100][100];
	__fastcall TForm3(TComponent* Owner);
	void __fastcall TForm3::AddClick(TObject *Sender);
	void __fastcall TForm3::AddClickF(int num);
	void __fastcall TForm3::PropClick(TObject *Sender);
	void __fastcall TForm3::EditsHaveChange(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
