object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1055#1077#1088#1077#1090#1072#1097#1080#1090#1077' '#1092#1072#1081#1083' '#1089' '#1082#1086#1086#1088#1076#1080#1085#1072#1090#1072#1084#1080
  ClientHeight = 216
  ClientWidth = 428
  Color = clBtnFace
  DragMode = dmAutomatic
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 225
    Top = 79
    Width = 114
    Height = 16
    Caption = #1058#1086#1095#1082#1080' '#1079#1072#1082#1088#1077#1087#1083#1077#1085#1099':'
  end
  object BSelectFolder: TButton
    Left = 343
    Top = 176
    Width = 75
    Height = 25
    Caption = #1042#1099#1073#1088#1072#1090#1100
    TabOrder = 3
    OnClick = BSelectFolderClick
  end
  object RGCoord: TRadioGroup
    Left = 225
    Top = 8
    Width = 152
    Height = 73
    Caption = #1050#1086#1086#1088#1076#1080#1085#1072#1090#1099' '#1074' '#1092#1072#1081#1083#1077':'
    ItemIndex = 1
    Items.Strings = (
      #1089#1077#1074#1077#1088','#1074#1086#1089#1090#1086#1082
      #1074#1086#1089#1090#1086#1082','#1089#1077#1074#1077#1088)
    TabOrder = 0
  end
  object RGRMS: TRadioGroup
    Left = 8
    Top = 8
    Width = 201
    Height = 153
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
    Left = 8
    Top = 176
    Width = 331
    Height = 24
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    Text = 'EDestinationFolder'
  end
  object EPointZakr: TEdit
    Left = 227
    Top = 101
    Width = 193
    Height = 24
    TabOrder = 4
    Text = #1052#1077#1090#1072#1083#1083#1080#1095#1077#1089#1082#1072#1103' '#1072#1088#1084#1072#1090#1091#1088#1072
  end
  object Progress: TProgressBar
    Left = 0
    Top = 200
    Width = 428
    Height = 16
    Align = alBottom
    TabOrder = 5
    Visible = False
  end
  object CHBExistGranic: TCheckBox
    Left = 225
    Top = 131
    Width = 195
    Height = 17
    Caption = #1057#1091#1097#1077#1089#1090#1074#1091#1102#1097#1080#1077' '#1091#1095'. '#1075#1088#1072#1085#1080#1094
    TabOrder = 6
  end
  object CBACADDrawing: TCheckBox
    Left = 225
    Top = 154
    Width = 195
    Height = 17
    Caption = #1042#1099#1095#1077#1088#1090#1080#1090#1100' '#1095#1077#1088#1090#1077#1078
    Checked = True
    State = cbChecked
    TabOrder = 7
  end
  object BAbout: TButton
    Left = 383
    Top = 16
    Width = 35
    Height = 25
    Caption = '?'
    TabOrder = 8
    OnClick = BAboutClick
  end
  object BACAD: TButton
    Left = 383
    Top = 56
    Width = 37
    Height = 25
    Caption = 'DWG'
    TabOrder = 9
    OnClick = BACADClick
  end
end
