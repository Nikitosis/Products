object Form2: TForm2
  Left = 0
  Top = 0
  VertScrollBar.Tracking = True
  BorderStyle = bsSingle
  Caption = #1055#1088#1086#1076#1091#1082#1090#1099
  ClientHeight = 540
  ClientWidth = 942
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 40
    Top = 8
    Width = 75
    Height = 21
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNone
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 314
    Top = 8
    Width = 105
    Height = 21
    Caption = #1048#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 441
    Top = 11
    Width = 75
    Height = 16
    Caption = #1041#1077#1083#1082#1086#1074'('#1084#1075'/'#1075')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 539
    Top = 11
    Width = 73
    Height = 16
    Caption = #1046#1080#1088#1086#1074'('#1084#1075'/'#1075')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 728
    Top = 8
    Width = 99
    Height = 21
    Caption = #1050#1050#1072#1083#1083#1086#1088#1080#1081'/'#1075
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 624
    Top = 11
    Width = 94
    Height = 16
    Caption = #1059#1075#1083#1077#1074#1086#1076#1086#1074'('#1084#1075'/'#1075')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Image1: TImage
    Left = 126
    Top = 8
    Width = 33
    Height = 25
  end
  object Button1: TButton
    Tag = -1
    Left = 8
    Top = 447
    Width = 928
    Height = 81
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object ScrollBox1: TScrollBox
    Left = 8
    Top = 40
    Width = 928
    Height = 401
    HorzScrollBar.Visible = False
    VertScrollBar.Smooth = True
    VertScrollBar.Tracking = True
    TabOrder = 1
  end
  object MainMenu1: TMainMenu
    object File1: TMenuItem
      Caption = 'File'
      object Save1: TMenuItem
        Caption = 'Save'
        OnClick = Save1Click
      end
      object Load1: TMenuItem
        Caption = 'Load'
        OnClick = Load1Click
      end
    end
  end
end
