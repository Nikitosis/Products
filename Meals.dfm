object Form3: TForm3
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1041#1083#1102#1076#1072
  ClientHeight = 541
  ClientWidth = 924
  Color = clBtnFace
  TransparentColorValue = cl3DLight
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label6: TLabel
    Left = 691
    Top = 12
    Width = 101
    Height = 24
    Caption = #1050#1050#1072#1083#1083#1086#1088#1080#1081
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 604
    Top = 18
    Width = 76
    Height = 16
    Caption = #1059#1075#1083#1077#1074#1086#1076#1086#1074'('#1075')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 536
    Top = 18
    Width = 55
    Height = 16
    Caption = #1046#1080#1088#1086#1074'('#1075')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 464
    Top = 18
    Width = 57
    Height = 16
    Caption = #1041#1077#1083#1082#1086#1074'('#1075')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 341
    Top = 18
    Width = 93
    Height = 18
    Caption = #1048#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 144
    Top = 12
    Width = 88
    Height = 24
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 834
    Top = 15
    Width = 60
    Height = 21
    Caption = #1052#1072#1089#1072'('#1075')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label8: TLabel
    Left = 72
    Top = 458
    Width = 291
    Height = 13
    Caption = #1041#1083#1102#1076#1086','#1074' '#1082#1086#1090#1086#1088#1086#1084' '#1084#1077#1085#1100#1096#1077' '#1082#1082#1072#1083','#1095#1077#1084' '#1074#1072#1096#1072' '#1089#1091#1090#1086#1095#1085#1072#1103' '#1085#1086#1088#1084#1072
  end
  object Label9: TLabel
    Left = 72
    Top = 483
    Width = 265
    Height = 13
    Caption = #1041#1083#1102#1076#1086','#1074' '#1082#1086#1090#1086#1088#1086#1084' '#1088#1077#1082#1086#1084#1084#1077#1085#1076#1091#1077#1084#1086#1077' '#1082#1086#1083'-'#1074#1086' '#1082#1082#1072#1083#1086#1088#1080#1081
  end
  object Label10: TLabel
    Left = 72
    Top = 508
    Width = 291
    Height = 13
    Caption = #1041#1083#1102#1076#1086','#1074' '#1082#1086#1090#1086#1088#1086#1084' '#1073#1086#1083#1100#1096#1077' '#1082#1082#1072#1083','#1095#1077#1084' '#1074#1072#1096#1072' '#1089#1091#1090#1086#1095#1085#1072#1103' '#1085#1086#1088#1084#1072
  end
  object ScrollBox1: TScrollBox
    Left = 8
    Top = 48
    Width = 910
    Height = 401
    HorzScrollBar.Visible = False
    VertScrollBar.Smooth = True
    VertScrollBar.Tracking = True
    TabOrder = 0
  end
  object Button1: TButton
    Tag = -1
    Left = 6
    Top = 455
    Width = 910
    Height = 81
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object Panel1: TPanel
    Left = 32
    Top = 457
    Width = 17
    Height = 15
    Color = clHighlight
    ParentBackground = False
    TabOrder = 2
  end
  object Panel2: TPanel
    Left = 32
    Top = 482
    Width = 17
    Height = 15
    Color = 5502745
    Ctl3D = False
    ParentBackground = False
    ParentCtl3D = False
    TabOrder = 3
  end
  object Panel3: TPanel
    Left = 32
    Top = 507
    Width = 17
    Height = 15
    Color = 1687799
    ParentBackground = False
    TabOrder = 4
  end
  object MainMenu1: TMainMenu
    Left = 128
    Top = 65528
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
