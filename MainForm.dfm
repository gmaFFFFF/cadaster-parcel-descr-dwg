object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1055#1077#1088#1077#1090#1072#1097#1080#1090#1077' '#1092#1072#1081#1083' '#1089' '#1082#1086#1086#1088#1076#1080#1085#1072#1090#1072#1084#1080
  ClientHeight = 164
  ClientWidth = 319
  Color = clBtnFace
  DragMode = dmAutomatic
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 169
    Top = 59
    Width = 93
    Height = 12
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1058#1086#1095#1082#1080' '#1079#1072#1082#1088#1077#1087#1083#1077#1085#1099':'
  end
  object BSelectFolder: TButton
    Left = 257
    Top = 132
    Width = 57
    Height = 19
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1042#1099#1073#1088#1072#1090#1100
    TabOrder = 3
    OnClick = BSelectFolderClick
  end
  object RGCoord: TRadioGroup
    Left = 169
    Top = 6
    Width = 114
    Height = 55
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1050#1086#1086#1088#1076#1080#1085#1072#1090#1099' '#1074' '#1092#1072#1081#1083#1077':'
    ItemIndex = 1
    Items.Strings = (
      #1089#1077#1074#1077#1088','#1074#1086#1089#1090#1086#1082
      #1074#1086#1089#1090#1086#1082','#1089#1077#1074#1077#1088)
    TabOrder = 0
  end
  object RGRMS: TRadioGroup
    Left = 6
    Top = 6
    Width = 151
    Height = 115
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1058#1086#1095#1085#1086#1089#1090#1100' '#1084#1077#1078#1077#1074#1072#1085#1080#1103':'
    ItemIndex = 1
    Items.Strings = (
      #1043#1086#1088#1086#1076'                  - 0.1'
      #1089'.'#1085'.'#1087'.                   - 0.2'
      #1087#1088#1086#1084#1099#1096#1083#1077#1085#1085#1086#1089#1090#1080' - 0.5'
      #1089'.'#1093'.,'#1054#1054#1055#1058'            - 2.5'
      #1051#1060','#1042#1060','#1047#1072#1087#1072#1089#1072'     - 5.0')
    TabOrder = 1
  end
  object EDestinationFolder: TEdit
    Left = 6
    Top = 132
    Width = 248
    Height = 20
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    Text = 'EDestinationFolder'
  end
  object EPointZakr: TEdit
    Left = 170
    Top = 76
    Width = 145
    Height = 20
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    TabOrder = 4
    Text = #1052#1077#1090#1072#1083#1083#1080#1095#1077#1089#1082#1072#1103' '#1072#1088#1084#1072#1090#1091#1088#1072
  end
  object Progress: TProgressBar
    Left = 0
    Top = 152
    Width = 319
    Height = 12
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Align = alBottom
    TabOrder = 5
    Visible = False
  end
  object CHBExistGranic: TCheckBox
    Left = 169
    Top = 98
    Width = 146
    Height = 13
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1057#1091#1097#1077#1089#1090#1074#1091#1102#1097#1080#1077' '#1091#1095'. '#1075#1088#1072#1085#1080#1094
    TabOrder = 6
  end
  object CBACADDrawing: TCheckBox
    Left = 169
    Top = 116
    Width = 146
    Height = 12
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1042#1099#1095#1077#1088#1090#1080#1090#1100' '#1095#1077#1088#1090#1077#1078
    Checked = True
    State = cbChecked
    TabOrder = 7
  end
  object BAbout: TButton
    Left = 287
    Top = 7
    Width = 27
    Height = 19
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = '?'
    TabOrder = 8
    OnClick = BAboutClick
  end
  object BACAD: TButton
    Left = 287
    Top = 30
    Width = 28
    Height = 19
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = 'DWG'
    TabOrder = 9
    OnClick = BACADClick
  end
  object BBKadSetka: TBitBtn
    Left = 287
    Top = 53
    Width = 28
    Height = 19
    DoubleBuffered = True
    Glyph.Data = {
      86000000424D86000000000000003E000000280000000D000000120000000100
      010000000000480000000000000000000000020000000000000000000000FFFF
      FF00FFF80000EFB80000EFB80000EFB80000EFB80000EFB8000080080000EFB8
      0000EFB80000EFB80000EFB80000EFB8000080080000EFB80000EFB80000EFB8
      0000EFB80000FFF80000}
    ParentDoubleBuffered = False
    TabOrder = 10
    OnClick = BBKadSetkaClick
  end
end
