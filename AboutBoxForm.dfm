object FAboutBox: TFAboutBox
  Left = 313
  Top = 240
  BorderStyle = bsDialog
  Caption = #1054' '#1055#1088#1086#1075#1088#1072#1084#1084#1077' '#1054#1087#1080#1089#1072#1085#1080#1077
  ClientHeight = 356
  ClientWidth = 468
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object LVersion: TLabel
    Left = 223
    Top = 68
    Width = 50
    Height = 16
    Caption = #1042#1077#1088#1089#1080#1103':'
  end
  object LProductVer: TLabel
    Left = 279
    Top = 68
    Width = 74
    Height = 16
    Caption = 'LProductVer'
  end
  object LProductName: TLabel
    Left = 222
    Top = 12
    Width = 216
    Height = 37
    Hint = #1053#1072#1079#1074#1072#1085#1080#1077' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
    AutoSize = False
    Caption = #1054#1087#1080#1089#1072#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = 33
    Font.Name = 'Courier New Cyr'
    Font.Pitch = fpVariable
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object LCopyright: TLabel
    Left = 222
    Top = 98
    Width = 239
    Height = 16
    Caption = #1040#1074#1090#1086#1088#1089#1082#1086#1077' '#1087#1088#1072#1074#1086':(C) 2003-2008 FFFFF'
  end
  object Label1: TLabel
    Left = 6
    Top = 159
    Width = 455
    Height = 16
    Caption = 
      '________________________________________________________________' +
      '_'
  end
  object LAuthor: TLabel
    Left = 223
    Top = 136
    Width = 89
    Height = 16
    Caption = #1040#1074#1090#1086#1088':  FFFFF'
  end
  object LEmail: TLabel
    Left = 347
    Top = 136
    Width = 92
    Height = 17
    Cursor = crHandPoint
    Hint = #1055#1086#1095#1090#1086#1074#1099#1081' '#1103#1097#1080#1082' '#1072#1074#1090#1086#1088#1072
    Alignment = taRightJustify
    Caption = 'FFFFF@bk.ru'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -15
    Font.Name = 'Courier New Cyr'
    Font.Pitch = fpVariable
    Font.Style = [fsUnderline]
    ParentColor = False
    ParentFont = False
    OnClick = LEmailClick
  end
  object ILogotip: TImage
    Left = 6
    Top = 12
    Width = 211
    Height = 140
    Hint = #1051#1086#1075#1086#1090#1080#1087' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
    Stretch = True
  end
  object BOK: TButton
    Left = 178
    Top = 320
    Width = 93
    Height = 31
    Hint = #1047#1072#1082#1088#1099#1090#1100' '#1086#1082#1085#1086' '#1080' '#1074#1077#1088#1085#1091#1090#1100#1089#1103' '#1074' '#1087#1088#1086#1075#1088#1072#1084#1084#1091
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 0
  end
  object MComment: TMemo
    Left = 6
    Top = 181
    Width = 438
    Height = 132
    Hint = #1059#1089#1083#1086#1074#1080#1103' '#1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1085#1080#1077
    Lines.Strings = (
      #1056#1072#1073#1086#1090#1072' '#1089' '#1087#1088#1086#1075#1088#1072#1084#1084#1086#1081' '#1054#1087#1080#1089#1072#1085#1080#1077' '#1088#1072#1079#1088#1077#1096#1077#1085#1072' '
      #1090#1086#1083#1100#1082#1086', '#1077#1089#1083#1080' '#1042#1099' '#1089#1086#1075#1083#1072#1089#1085#1099' '#1089' '#1091#1089#1083#1086#1074#1080#1103#1084#1080' '#1043#1077#1085#1077#1088#1072#1083#1100#1085#1086#1081' '
      #1086#1073#1097#1077#1076#1086#1089#1090#1091#1087#1085#1086#1081' '#1083#1080#1094#1077#1085#1079#1080#1080' (GPL). '#1045#1089#1083#1080' '#1042#1099' '#1085#1077' '#1089#1086#1075#1083#1072#1089#1085#1099' '#1089' '
      #1091#1083#1086#1074#1080#1103#1084#1080' '#1083#1080#1094#1077#1085#1079#1080#1080' '#1087#1086#1078#1072#1083#1091#1081#1089#1090#1072' '#1091#1076#1072#1083#1080#1090#1077' '#1087#1088#1086#1075#1088#1072#1084#1084#1091' '#1089' '#1042#1072#1096#1077#1075#1086' '
      #1082#1086#1084#1087#1100#1102#1090#1077#1088#1072'! '
      #1051#1080#1094#1077#1085#1079#1080#1103' '#1087#1086#1089#1090#1072#1074#1083#1103#1077#1090#1089#1103' '#1089' '#1076#1080#1089#1090#1088#1080#1073#1091#1090#1080#1074#1086#1084' '#1087#1088#1086#1075#1088#1072#1084#1084#1099'.')
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 1
  end
end
