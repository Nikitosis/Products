// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RecommendMeals.h"
#include "RecommendDialog.h"
#include "Products.h"
#include "Meals.h"
#include "Main.h"
#include <math.h>
#include "Math.hpp"
#include <Comobj.hpp>
#include <olectrls.hpp>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm11 *Form11;

// ---------------------------------------------------------------------------
__fastcall TForm11::TForm11(TComponent* Owner) : TForm(Owner) {
	PanelH = 100;
}

// ---------------------------------------------------------------------------
void __fastcall TForm11::CreateNewRecomMeal(int num) {
	int k = Form11->ScrollBox1->VertScrollBar->Position;
	// ����� �����������,����� �����. ��������
	Form11->ScrollBox1->VertScrollBar->Position = 0;

	TForm11::RecomT TemporRecomMeal;
	Form11->RecomMeal.push_back(TemporRecomMeal);
	int n = Form11->RecomMeal.size() - 1;

	Form11->RecomMeal[n].Panel = new TPanel(Form11);
	Form11->RecomMeal[n].Panel->Parent = Form11->ScrollBox1;
	Form11->RecomMeal[n].Panel->Top = (n) * Form11->PanelH;
	Form11->RecomMeal[n].Panel->Left = 0;
	Form11->RecomMeal[n].Panel->Width = Form11->ScrollBox1->Width - 4;
	Form11->RecomMeal[n].Panel->Height = Form11->PanelH;

	Form11->RecomMeal[n].Image = new TImage(Form11);
	Form11->RecomMeal[n].Image->Parent = Form11->RecomMeal[n].Panel;
	Form11->RecomMeal[n].Image->Left = 327;
	Form11->RecomMeal[n].Image->Height = Form11->PanelH - 1;
	Form11->RecomMeal[n].Image->Width = 125;
	Form11->RecomMeal[n].Image->Stretch = true;
	Form11->RecomMeal[n].Image->Picture = Form3->Meal[n].Image->Picture;

	Form11->RecomMeal[n].Name = new TLabel(Form11);
	Form11->RecomMeal[n].Name->Parent = Form11->RecomMeal[n].Panel;
	Form11->RecomMeal[n].Name->Top = 20;
	Form11->RecomMeal[n].Name->Left = 10;
	Form11->RecomMeal[n].Name->WordWrap = true;
	Form11->RecomMeal[n].Name->AutoSize = false;
	Form11->RecomMeal[n].Name->Height = 70;
	Form11->RecomMeal[n].Name->Width = 300;
	Form11->RecomMeal[n].Name->Font->Size = 14;
	Form11->RecomMeal[n].Name->Caption = Form3->Meal[n].Name->Caption;

	Form11->RecomMeal[n].Protein = new TLabel(Form11);
	Form11->RecomMeal[n].Protein->Parent = Form11->RecomMeal[n].Panel;
	Form11->RecomMeal[n].Protein->Top = 40;
	Form11->RecomMeal[n].Protein->Left = 460;
	Form11->RecomMeal[n].Protein->WordWrap = true;
	Form11->RecomMeal[n].Protein->AutoSize = false;
	Form11->RecomMeal[n].Protein->Height = 20;
	Form11->RecomMeal[n].Protein->Width = 70;
	Form11->RecomMeal[n].Protein->Font->Size = 10;
	Form11->RecomMeal[n].Protein->Caption = "0";

	Form11->RecomMeal[n].Fat = new TLabel(Form11);
	Form11->RecomMeal[n].Fat->Parent = Form11->RecomMeal[n].Panel;
	Form11->RecomMeal[n].Fat->Top = 40;
	Form11->RecomMeal[n].Fat->Left = 533;
	Form11->RecomMeal[n].Fat->WordWrap = true;
	Form11->RecomMeal[n].Fat->AutoSize = false;
	Form11->RecomMeal[n].Fat->Height = 20;
	Form11->RecomMeal[n].Fat->Width = 70;
	Form11->RecomMeal[n].Fat->Font->Size = 10;
	Form11->RecomMeal[n].Fat->Caption = "0";

	Form11->RecomMeal[n].Carbon = new TLabel(Form11);
	Form11->RecomMeal[n].Carbon->Parent = Form11->RecomMeal[n].Panel;
	Form11->RecomMeal[n].Carbon->Top = 40;
	Form11->RecomMeal[n].Carbon->Left = 606;
	Form11->RecomMeal[n].Carbon->WordWrap = true;
	Form11->RecomMeal[n].Carbon->AutoSize = false;
	Form11->RecomMeal[n].Carbon->Height = 20;
	Form11->RecomMeal[n].Carbon->Width = 70;
	Form11->RecomMeal[n].Carbon->Font->Size = 10;
	Form11->RecomMeal[n].Carbon->Caption = "0";

	Form11->RecomMeal[n].Calories = new TLabel(Form11);
	Form11->RecomMeal[n].Calories->Parent = Form11->RecomMeal[n].Panel;
	Form11->RecomMeal[n].Calories->Top = 40;
	Form11->RecomMeal[n].Calories->Left = 679;
	Form11->RecomMeal[n].Calories->WordWrap = true;
	Form11->RecomMeal[n].Calories->AutoSize = false;
	Form11->RecomMeal[n].Calories->Height = 20;
	Form11->RecomMeal[n].Calories->Width = 70;
	Form11->RecomMeal[n].Calories->Font->Size = 10;
	Form11->RecomMeal[n].Calories->Caption = "0";

	Form11->RecomMeal[n].Weight = new TEdit(Form11); // ���� �����
	Form11->RecomMeal[n].Weight->Parent = Form11->RecomMeal[n].Panel;
	Form11->RecomMeal[n].Weight->Left = 803;
	Form11->RecomMeal[n].Weight->Top = 40;
	Form11->RecomMeal[n].Weight->NumbersOnly = true;
	Form11->RecomMeal[n].Weight->MaxLength = 9;
	Form11->RecomMeal[n].Weight->Font->Size = 10;
	Form11->RecomMeal[n].Weight->AutoSize = false;
	Form11->RecomMeal[n].Weight->Width = 50;
	Form11->RecomMeal[n].Weight->Text = "0";
	Form11->RecomMeal[n].Weight->Tag = n;
	Form11->RecomMeal[n].Weight->OnChange = MassChange;
	Form11->RecomMeal[n].Weight->MaxLength=5;

	Form11->RecomMeal[n].Check=new TCheckBox(Form11);
	Form11->RecomMeal[n].Check->Parent=Form11->RecomMeal[n].Panel;
	Form11->RecomMeal[n].Check->Left=870;
	Form11->RecomMeal[n].Check->Top = 43;
	Form11->RecomMeal[n].Check->Tag=n;
	Form11->RecomMeal[n].Check->Visible=false;
	Form11->RecomMeal[n].Check->OnClick=CheckClick;

	TImage *line2 = new TImage(Form11);
	line2->Parent = Form11->RecomMeal[n].Panel;
	line2->Left = 327;
	line2->Width = 2;
	line2->Height = Form11->PanelH - 1;
	line2->Picture->Bitmap->Width = 2;
	line2->Picture->Bitmap->Height = Form11->PanelH - 1;
	line2->Picture->Bitmap->Canvas->Brush->Color = clBlack;
	line2->Picture->Bitmap->Canvas->FillRect(Rect(0, 0, 2, 100));

	TImage *line3 = new TImage(Form11);
	line3->Parent = Form11->RecomMeal[n].Panel;
	line3->Left = 450;
	line3->Width = 2;
	line3->Height = Form11->PanelH - 1;
	line3->Picture->Bitmap->Width = 2;
	line3->Picture->Bitmap->Height = Form11->PanelH - 1;
	line3->Picture->Bitmap->Canvas->Brush->Color = clBlack;
	line3->Picture->Bitmap->Canvas->FillRect(Rect(0, 0, 2, 100));

	TImage *line4 = new TImage(Form11);
	line4->Parent = Form11->RecomMeal[n].Panel;
	line4->Left = 523;
	line4->Width = 2;
	line4->Height = Form11->PanelH - 1;
	line4->Picture->Bitmap->Width = 2;
	line4->Picture->Bitmap->Height = Form11->PanelH - 1;
	line4->Picture->Bitmap->Canvas->Brush->Color = clBlack;
	line4->Picture->Bitmap->Canvas->FillRect(Rect(0, 0, 2, 100));

	TImage *line5 = new TImage(Form11);
	line5->Parent = Form11->RecomMeal[n].Panel;
	line5->Left = 596;
	line5->Width = 2;
	line5->Height = Form11->PanelH - 1;
	line5->Picture->Bitmap->Width = 2;
	line5->Picture->Bitmap->Height = Form11->PanelH - 1;
	line5->Picture->Bitmap->Canvas->Brush->Color = clBlack;
	line5->Picture->Bitmap->Canvas->FillRect(Rect(0, 0, 2, 100));

	TImage *line6 = new TImage(Form11);
	line6->Parent = Form11->RecomMeal[n].Panel;
	line6->Left = 669;
	line6->Width = 2;
	line6->Height = Form11->PanelH - 1;
	line6->Picture->Bitmap->Width = 2;
	line6->Picture->Bitmap->Height = Form11->PanelH - 1;
	line6->Picture->Bitmap->Canvas->Brush->Color = clBlack;
	line6->Picture->Bitmap->Canvas->FillRect(Rect(0, 0, 2, 100));

	TImage *line7 = new TImage(Form11);
	line7->Parent = Form11->RecomMeal[n].Panel;
	line7->Left = 792;
	line7->Width = 2;
	line7->Height = Form11->PanelH - 1;
	line7->Picture->Bitmap->Width = 2;
	line7->Picture->Bitmap->Height = Form11->PanelH - 1;
	line7->Picture->Bitmap->Canvas->Brush->Color = clBlack;
	line7->Picture->Bitmap->Canvas->FillRect(Rect(0, 0, 2, 100));

	Form11->ScrollBox1->VertScrollBar->Position = k;
}

// ------------------------------------------------------------------------------
void __fastcall TForm11::MassChange(TObject *Sender) {
	TEdit *btn = dynamic_cast<TEdit*>(Sender);
	int num = btn->Tag;

	UpdateWeights(num);

	if(RecomMeal[num].Check->Checked==false)
		for(int i=0;i<RecomMeal.size();i++)
			if(RecomMeal[i].Check->Checked==true)
			{
				CheckClick(RecomMeal[i].Check);
				break;
			}

	UpdateWeights(num);



}

void __fastcall TForm11::UpdateWeights(int num)
{
	double sum = 0;
	double cal = 0;
	double prot = 0;
	double fat = 0;
	double carbon = 0;
	for (int i = 0; i < Form2->Product.size(); i++) {
		if (Form3->Meal[num].IsRight[i]) {
			sum += StrToInt(Form3->Meal[num].Weight[i]);
			cal += StrToFloat(Form3->Meal[num].Weight[i]) * StrToFloat(Form2->Product[i].Calories->Caption);
			prot += StrToFloat(Form3->Meal[num].Weight[i]) * StrToFloat(Form2->Product[i].Protein->Caption) / 1000;
			fat += StrToFloat(Form3->Meal[num].Weight[i]) * StrToFloat(Form2->Product[i].Fat->Caption) / 1000;
			carbon += StrToFloat(Form3->Meal[num].Weight[i]) * StrToFloat(Form2->Product[i].Carbon->Caption) / 1000;
		}
	}
	double kpergramm;
	double bpergramm;
	double zpergramm;
	double upergramm;
	if (sum != 0) {
		kpergramm = cal / sum;
		bpergramm = prot / sum;
		zpergramm = fat / sum;
		upergramm = carbon / sum;
	}
	else {
		kpergramm = 0;
		bpergramm = 0;
		zpergramm = 0;
		upergramm = 0;
	}

	double gramm = 0;
	if (RecomMeal[num].Weight->Text != "")
		gramm = StrToFloat(RecomMeal[num].Weight->Text);

	kpergramm = ceil(kpergramm * gramm * 100) / 100;
	bpergramm = ceil(bpergramm * 100 * gramm) / 100;
	zpergramm = ceil(zpergramm * 100 * gramm) / 100;
	upergramm = ceil(upergramm * 100 * gramm) / 100;

	RecomMeal[num].Protein->Caption = FloatToStr(ceil(bpergramm));
	RecomMeal[num].Fat->Caption = FloatToStr(ceil(zpergramm));
	RecomMeal[num].Carbon->Caption = FloatToStr(ceil(upergramm));
	RecomMeal[num].Calories->Caption = FloatToStr(ceil(kpergramm));

	int allcal = 0;
	int allprot = 0;
	int allcarbon = 0;
	int allfat = 0;
	for (int j = 0; j < Form3->Meal.size(); j++)
		if (RecomMeal[j].Weight->Text != "") {
			allcal += StrToInt(RecomMeal[j].Calories->Caption);
			allprot += StrToInt(RecomMeal[j].Protein->Caption);
			allfat += StrToInt(RecomMeal[j].Fat->Caption);
			allcarbon += StrToInt(RecomMeal[j].Carbon->Caption);
		}
	Label9->Caption = IntToStr(allprot);
	Label10->Caption = IntToStr(allfat);
	Label12->Caption = IntToStr(allcarbon);
	Label13->Caption = IntToStr(allcal);

	if (Form8->BMR - allcal > 400) // ���� ������
	{
		Form11->RecomPanel->Color = clHighlight;
		Form11->Label11->Caption =
			"� ��� ������ ����,�� ���� ����� ����� (" + IntToStr(allcal)
			+ "����)";
		Form11->Label11->Font->Color = clWhite;
	}
	else if (Form8->BMR - allcal < -400) // ���� ������
	{
		Form11->RecomPanel->Color = RGB(247, 192, 25);
		Form11->Label11->Caption =
			"� ��� ����� ����,�� ���� ����� ����� (" + IntToStr(allcal)
			+ "����)";
		Form11->Label11->Font->Color = clWhite;
	}
	else {
		Form11->RecomPanel->Color = RGB(25, 247, 83); // ���� ��������
		Form11->Label11->Caption =
			"� ��� ������������� ������� ������� (" + IntToStr(allcal)
			+ "����)";
		Form11->Label11->Font->Color = clBlack;
	}
}

void __fastcall TForm11::FormClose(TObject *Sender, TCloseAction &Action) {
	while (!RecomMeal.empty()) {
		RecomMeal.back().Image->Free();
		RecomMeal.back().Weight->Free();
		RecomMeal.back().Name->Free();
		RecomMeal.back().Protein->Free();
		RecomMeal.back().Fat->Free();
		RecomMeal.back().Carbon->Free();
		RecomMeal.back().Calories->Free();
		RecomMeal.back().Panel->Free();
		RecomMeal.pop_back();
	}
	Label11->Caption = "� ��� ������ ����,�� ���� ����� �����";
}

// ---------------------------------------------------------------------------������ � Excel
void __fastcall TForm11::ExcelInit(AnsiString File) {
	App = CreateOleObject("Excel.Application");
	Wb = App.OlePropertyGet("WorkBooks");
	App.OlePropertySet("SheetsInNewWorkbook", 3);
	Wb.OleProcedure("add");
	Sh = App.OlePropertyGet("WorkSheets", 1);
}

void __fastcall TForm11::toExcelCell(int Row, int Column, AnsiString data) {
	Variant Cur = Sh.OlePropertyGet("Cells", Row, Column);
	Cur.OlePropertySet("Value", data.c_str());
}

void __fastcall TForm11::Excel1Click(TObject *Sender) {
	ExcelInit("");
	Sh.OlePropertySet("Name","������");
	toExcelCell(2, 4, "������� �� �������");
	toExcelCell(4,1,"����� ������");
	toExcelCell(4, 2, "����(�)");
	toExcelCell(4, 3, "�����(�)");
	toExcelCell(4, 4, "����(�)");
	toExcelCell(4, 5, "���������(�)");
	toExcelCell(4, 6, "�������");

	Variant VarCell=Sh.OlePropertyGet("Range","A2:F3");
	VarCell.OleProcedure("Merge");  //����������
	VarCell.OlePropertySet("HorizontalAlignment", -4108);//������������ �� ������
	VarCell.OlePropertySet("VerticalAlignment",-4108);
	VarCell.OlePropertyGet("Font").OlePropertySet("Size",15);
	VarCell.OlePropertyGet("Interior").OlePropertySet("ColorIndex",34);

	VarCell=Sh.OlePropertyGet("Range","B4:F4");
	VarCell.OlePropertySet("ColumnWidth",17);

	VarCell=Sh.OlePropertyGet("Range","A4:F4");
	VarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);

	VarCell=Sh.OlePropertyGet("Cells",4,1);
	VarCell.OlePropertySet("ColumnWidth",30);
	//VarCell=
	int CurRow=6;
	for(int i=0;i<RecomMeal.size();i++)
			if(RecomMeal[i].Weight->Text!="" && RecomMeal[i].Weight->Text!="0")
				{
					toExcelCell(CurRow,1,RecomMeal[i].Name->Caption);
					toExcelCell(CurRow,2,RecomMeal[i].Weight->Text);
					toExcelCell(CurRow,3,RecomMeal[i].Protein->Caption);
					toExcelCell(CurRow,4,RecomMeal[i].Fat->Caption);
					toExcelCell(CurRow,5,RecomMeal[i].Carbon->Caption);
					toExcelCell(CurRow,6,RecomMeal[i].Calories->Caption);
					CurRow++;
				}
	CurRow++;
	int sumweight=0;
	for(int i=0;i<RecomMeal.size();i++)
		if(RecomMeal[i].Weight->Text!="")
	     	sumweight+=StrToInt(RecomMeal[i].Weight->Text);

	toExcelCell(CurRow,1,"������");
	VarCell=Sh.OlePropertyGet("Cells",CurRow,1);
	VarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);

	toExcelCell(CurRow,2,IntToStr(sumweight));
	VarCell=Sh.OlePropertyGet("Cells",CurRow,2);
	VarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);

	toExcelCell(CurRow,3,Label9->Caption);
	VarCell=Sh.OlePropertyGet("Cells",CurRow,3);
	VarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);

	toExcelCell(CurRow,4,Label10->Caption);
	VarCell=Sh.OlePropertyGet("Cells",CurRow,4);
	VarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);

	toExcelCell(CurRow,5,Label12->Caption);
	VarCell=Sh.OlePropertyGet("Cells",CurRow,5);
	VarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);

	toExcelCell(CurRow,6,Label13->Caption);
	VarCell=Sh.OlePropertyGet("Cells",CurRow,6);
	VarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);

	VarCell=Sh.OlePropertyGet("Range",Sh.OlePropertyGet("Cells",5,1),Sh.OlePropertyGet("Cells",CurRow-1,6)); //������������ ������
	VarCell.OlePropertySet("HorizontalAlignment",-4152);
	VarCell=Sh.OlePropertyGet("Range",Sh.OlePropertyGet("Cells",4,1),Sh.OlePropertyGet("Cells",CurRow-1,1));
	VarCell.OlePropertySet("HorizontalAlignment",-4131);


	VarCell=Sh.OlePropertyGet("Range",Sh.OlePropertyGet("Cells",4,1),Sh.OlePropertyGet("Cells",CurRow-1,6)); //������� ����
	VarCell.OlePropertyGet("Borders",11).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",11).OlePropertySet("Weight",2);
	VarCell.OlePropertyGet("Borders",12).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",12).OlePropertySet("Weight",2);
	VarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",2);
	VarCell.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",9).OlePropertySet("Weight",2);

	VarCell=Sh.OlePropertyGet("Range",Sh.OlePropertyGet("Cells",CurRow,1),Sh.OlePropertyGet("Cells",CurRow,6)); //������� ������������
	VarCell.OlePropertyGet("Borders",11).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",11).OlePropertySet("Weight",3);
	VarCell.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",9).OlePropertySet("Weight",3);
	VarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",3);
	VarCell.OlePropertyGet("Borders",8).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",8).OlePropertySet("Weight",3);
	///////////////////////////////////////////////////////////////////////////// ���� �����
	Sh=App.OlePropertyGet("WorkSheets", 2);
	Sh.OlePropertySet("Name","���� �����");
	toExcelCell(2,1,"���� ����� ������");
	VarCell=Sh.OlePropertyGet("Range","A2:B2");
	VarCell.OleProcedure("Merge");
	VarCell.OlePropertySet("HorizontalAlignment", -4108);//������������ �� ������
	VarCell.OlePropertySet("VerticalAlignment",-4108);
	VarCell.OlePropertyGet("Font").OlePropertySet("Size",15);
	VarCell.OlePropertyGet("Interior").OlePropertySet("ColorIndex",34);

	VarCell=Sh.OlePropertyGet("Cells",3,1);
	VarCell.OlePropertySet("ColumnWidth",40);
	VarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);

	VarCell=Sh.OlePropertyGet("Cells",3,2);
	VarCell.OlePropertySet("ColumnWidth",17);
	VarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);

	VarCell=Sh.OlePropertyGet("Range","A3:B3");
	VarCell.OlePropertyGet("Borders",11).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",11).OlePropertySet("Weight",2);
	VarCell.OlePropertyGet("Borders",12).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",12).OlePropertySet("Weight",2);
	VarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",2);
	VarCell.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",9).OlePropertySet("Weight",2);
	VarCell.OlePropertyGet("Borders",8).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",8).OlePropertySet("Weight",2);


	toExcelCell(3,1,"����� ��������");
	toExcelCell(3,2,"����(�)");


	int *Weights=new int[Form2->Product.size()];
	memset(Weights,0,Form2->Product.size()*sizeof(int));
	CurRow=4;
	for(int i=0;i<RecomMeal.size();i++)
	{
		if(RecomMeal[i].Weight->Text=="" || RecomMeal[i].Weight->Text=="0")
			continue;
	   VarCell=Sh.OlePropertyGet("Range",Sh.OlePropertyGet("Cells",CurRow,1),Sh.OlePropertyGet("Cells",CurRow,2));
	   VarCell.OleProcedure("Merge");
       VarCell.OlePropertySet("HorizontalAlignment", -4108);//������������ �� ������
	   VarCell.OlePropertySet("VerticalAlignment",-4108);
	   VarCell.OlePropertyGet("Font").OlePropertySet("Size",13);
	   VarCell.OlePropertyGet("Interior").OlePropertySet("ColorIndex",45);
	   toExcelCell(CurRow,1,RecomMeal[i].Name->Caption);

	   CurRow++;
	   int FirstRow=CurRow;


	   double mas=0;
	   for(int j=0;j<Form2->Product.size();j++)
		if(Form3->Meal[i].IsRight[j])
			mas+=StrToFloat(Form3->Meal[i].Weight[j]);

	   double koef;
	   if(mas!=0)
			koef=StrToFloat(RecomMeal[i].Weight->Text)/mas;
			else
			koef=0;

	   for(int j=0;j<Form2->Product.size();j++)
			if(Form3->Meal[i].IsRight[j])
				{
					toExcelCell(CurRow,1,Form2->Product[j].Name->Caption);
					int w=SimpleRoundTo(koef*StrToFloat(Form3->Meal[i].Weight[j]),0);
					toExcelCell(CurRow,2,w);
					Weights[j]+=w;
					CurRow++;
				}
	   VarCell=Sh.OlePropertyGet("Range",Sh.OlePropertyGet("Cells",FirstRow,1),Sh.OlePropertyGet("Cells",CurRow-1,2)); //�������
	   VarCell.OlePropertyGet("Borders",11).OlePropertySet("LineStyle",1);
	   VarCell.OlePropertyGet("Borders",11).OlePropertySet("Weight",2);
	   VarCell.OlePropertyGet("Borders",12).OlePropertySet("LineStyle",1);
	   VarCell.OlePropertyGet("Borders",12).OlePropertySet("Weight",2);
	   VarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
	   VarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",2);
	   VarCell.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
	   VarCell.OlePropertyGet("Borders",9).OlePropertySet("Weight",2);
	   VarCell.OlePropertyGet("Borders",8).OlePropertySet("LineStyle",1);
	   VarCell.OlePropertyGet("Borders",8).OlePropertySet("Weight",2);
    }
//////////////////////////////////////////////////////////////////////////////// �������� ��������
	Sh=App.OlePropertyGet("WorkSheets",3);
	Sh.OlePropertySet("Name","�������� ��������");
	toExcelCell(2,1,"�������� �������� ��� ������� ������������");
	VarCell=Sh.OlePropertyGet("Range","A2:B2");
	VarCell.OleProcedure("Merge");
	VarCell.OlePropertySet("HorizontalAlignment", -4108);//������������ �� ������
	VarCell.OlePropertySet("VerticalAlignment",-4108);
	VarCell.OlePropertyGet("Font").OlePropertySet("Size",15);
	VarCell.OlePropertyGet("Interior").OlePropertySet("ColorIndex",34);

	VarCell=Sh.OlePropertyGet("Cells",3,1);
	VarCell.OlePropertySet("ColumnWidth",40);
	VarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);

	VarCell=Sh.OlePropertyGet("Cells",3,2);
	VarCell.OlePropertySet("ColumnWidth",17);
	VarCell.OlePropertyGet("Font").OlePropertySet("Bold",true);

	toExcelCell(3,1,"����� ��������");
	toExcelCell(3,2,"����(�)");
	CurRow=4;
	for(int i=0;i<Form2->Product.size();i++)
	{
		if(Weights[i]>0)
		{
			toExcelCell(CurRow,1,Form2->Product[i].Name->Caption);
			toExcelCell(CurRow,2,IntToStr(Weights[i]));
			CurRow++;
        }
	}
    VarCell=Sh.OlePropertyGet("Range",Sh.OlePropertyGet("Cells",3,1),Sh.OlePropertyGet("Cells",CurRow-1,2)); //�������
	VarCell.OlePropertyGet("Borders",11).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",11).OlePropertySet("Weight",2);
	VarCell.OlePropertyGet("Borders",12).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",12).OlePropertySet("Weight",2);
	VarCell.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",10).OlePropertySet("Weight",2);
	VarCell.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",9).OlePropertySet("Weight",2);
	VarCell.OlePropertyGet("Borders",8).OlePropertySet("LineStyle",1);
	VarCell.OlePropertyGet("Borders",8).OlePropertySet("Weight",2);

	App.OlePropertySet("Visible",true);
}
// ---------------------------------------------------------------------------
void __fastcall TForm11::Button6Click(TObject *Sender)
{
TButton *button = dynamic_cast<TButton *>(Sender);         //�����+�����
AnsiString s=Form11->Components[FocusIndex]->ClassName();
if(Form11->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form11->Components[FocusIndex];
	  int start=edit->SelStart;
	  AnsiString s=edit->Text;
	  s.Delete(start+1,edit->SelLength);    //���� ��������,�� ��������
	  s.Insert(button->Caption,start+1);    //��������� �����
	  edit->SetFocus();
	  edit->Text=s;
	  edit->SelStart=start+1;
	  edit->SelLength=0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button6MouseEnter(TObject *Sender)
{
for(int i=0;i<Form11->ComponentCount-1;i++)
	{
	   if(Form11->ActiveControl==Form11->Components[i] && Form11->Components[i]->ClassName()=="TEdit")
		FocusIndex=i;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm11::BackspaceClick(TObject *Sender)
{
 TButton *button = dynamic_cast<TButton *>(Sender);         //backspace
  AnsiString s=Form11->Components[FocusIndex]->ClassName();
if(Form11->Components[FocusIndex]->ClassName()=="TEdit")
	{
	  TEdit *edit = (TEdit*)Form11->Components[FocusIndex];
	  int start=edit->SelStart;
	  if(edit->SelLength!=0)
		start++;
	  AnsiString s=edit->Text;
	  int length=edit->SelLength;
	  if(length==0)
		length=1;
	  s.Delete(start,length);
	  edit->SetFocus();
	  edit->Text=s;
	  if(start!=0)
		 edit->SelStart=start-1;
	  edit->SelLength=0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm11::FormShow(TObject *Sender)
{
FocusIndex=0;
isExpantion=false;
if(Form1->IsKeyboard)
{
	Panel4->Visible=true;
	Form11->Height=614;
}
else
{
	Panel4->Visible=false;
	Form11->Height=546;
}
}
//---------------------------------------------------------------------------


void __fastcall TForm11::BitBtn4Click(TObject *Sender)
{
if(!isExpantion)
{
	Edit1->Left=211;
}
isExpantion=! isExpantion;
Timer2->Enabled=true;
Edit1->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Timer2Timer(TObject *Sender)
{
if(isExpantion)
	{
		if(Edit1->Width<100)
			{
			Edit1->Width+=3;
			Edit1->Left=111;
			}
			else
			{
			Timer2->Enabled=false;
			Edit1->Width=100;
			}
	}
	else
	{
		if(Edit1->Width>0)
		{
			Edit1->Width-=3;
			Edit1->Left=111;
		}
			else
			{
			Timer2->Enabled=false;
			Edit1->Width=0;
			}
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Edit1Change(TObject *Sender)
{
ScrollBox1->VertScrollBar->Position=0;
AnsiString WordToFind=Edit1->Text.LowerCase();
int SearchAmount=0;
for(int i=0;i<Form3->Meal.size();i++)
	{
	AnsiString Name=RecomMeal[i].Name->Caption.LowerCase();
	int pos=Name.Pos(WordToFind);
	if(pos!=0 || WordToFind=="")
		{
		RecomMeal[i].Panel->Top=Form3->PanelH*SearchAmount;
		RecomMeal[i].Panel->Visible=true;
		SearchAmount++;
		}
	else
		{
		RecomMeal[i].Panel->Visible=false;
		}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm11::AutoOffClick(TObject *Sender)
{
AutoOff->Checked=true;
AutoOn->Checked=false;
for(int i=0;i<RecomMeal.size();i++)
{
	RecomMeal[i].Check->Visible=false;
	if(RecomMeal[i].Check->Checked==true)
	{
		RecomMeal[i].Check->Checked=false;
		CheckClick(RecomMeal[i].Check);
    }
}
}
//---------------------------------------------------------------------------

void __fastcall TForm11::AutoOnClick(TObject *Sender)
{
AutoOn->Checked=true;
AutoOff->Checked=false;
for(int i=0;i<RecomMeal.size();i++)
{
    RecomMeal[i].Check->Visible=true;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm11::CheckClick(TObject *Sender)
{
	TCheckBox *btn = dynamic_cast<TCheckBox*>(Sender);

	int num=btn->Tag;
	RecomMeal[num].Weight->Text="";

	if(RecomMeal[num].Check->Checked==true)
	{
		RecomMeal[num].Weight->Enabled=false;
	}
	else
	{
		RecomMeal[num].Weight->Enabled=true;
    }


	int CheckedAm=0;
	for(int i=0;i<RecomMeal.size();i++)
		if(RecomMeal[i].Check->Checked==true)
			CheckedAm++;

	int LastCalor=Form8->BMR;
	for(int i=0;i<RecomMeal.size();i++)
		if(RecomMeal[i].Check->Checked==false && RecomMeal[i].Calories->Caption!="")
		{
			LastCalor-=StrToInt(RecomMeal[i].Calories->Caption);
		}
	if(LastCalor<0)
		LastCalor=0;
	if(CheckedAm>0)
	{
		int CalorPerMeal=LastCalor/CheckedAm;

		for(int i=0;i<RecomMeal.size();i++)
			if(RecomMeal[i].Check->Checked==true)
			{
				int calor=StrToInt(Form3->Meal[i].Calories->Caption);
				int weight=0;
				for (int j = 0; j < Form2->Product.size(); j++)
					if (Form3->Meal[i].IsRight[j])
						{
							weight += StrToInt(Form3->Meal[i].Weight[j]);
						}

				double CalorPerGramm=double(calor)/weight;
				int gramm=CalorPerMeal/CalorPerGramm;
				RecomMeal[i].Weight->Text=IntToStr(gramm);
            }
	}
}



