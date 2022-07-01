object FDrawKadSetka: TFDrawKadSetka
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = #1050#1072#1076#1072#1089#1090#1088#1086#1074#1072#1103' '#1089#1077#1090#1082#1072
  ClientHeight = 203
  ClientWidth = 184
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 4
    Top = 127
    Width = 61
    Height = 13
    Caption = #1052#1072#1089#1096#1090#1072#1073' 1 :'
  end
  object RGSourceCoord: TRadioGroup
    Left = 0
    Top = 8
    Width = 177
    Height = 57
    Caption = #1054#1087#1088#1077#1076#1077#1083#1080#1090#1100' '#1075#1088#1072#1085#1080#1094#1099' '#1091#1095#1072#1089#1090#1082#1072':'
    ItemIndex = 0
    Items.Strings = (
      #1087#1086' '#1090#1086#1095#1082#1072#1084
      #1087#1086' '#1087#1086#1083#1080#1083#1080#1085#1080#1080)
    TabOrder = 0
  end
  object RGScale: TRadioGroup
    Left = 0
    Top = 71
    Width = 178
    Height = 50
    Caption = #1052#1072#1089#1096#1090#1072#1073' '#1095#1077#1088#1090#1077#1078#1072
    ItemIndex = 0
    Items.Strings = (
      #1074#1099#1095#1080#1089#1083#1080#1090#1100' ('#1042#1069':230x180 '#1084#1084')'
      #1085#1072#1089#1090#1088#1072#1080#1074#1072#1077#1084#1099#1081)
    TabOrder = 1
  end
  object CSEScale: TCSpinEdit
    Left = 4
    Top = 146
    Width = 169
    Height = 22
    TabOrder = 2
    Value = 1000
  end
  object Button1: TButton
    Left = -1
    Top = 174
    Width = 178
    Height = 25
    Caption = #1063#1077#1088#1090#1080#1090#1100
    TabOrder = 3
    OnClick = Button1Click
  end
end
