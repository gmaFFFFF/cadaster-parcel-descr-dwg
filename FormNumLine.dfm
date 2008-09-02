object FNumer: TFNumer
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = #1055#1088#1086#1085#1091#1084#1077#1088#1091#1081#1090#1077' '#1091#1095#1072#1089#1090#1086#1082
  ClientHeight = 142
  ClientWidth = 250
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 129
    Top = 48
    Width = 98
    Height = 16
    Caption = #1052#1072#1089#1096#1090#1072#1073' '#1073#1083#1086#1082#1086#1074
  end
  object BNumerate: TButton
    Left = 8
    Top = 8
    Width = 115
    Height = 25
    Caption = #1053#1091#1084#1077#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = BNumerateClick
  end
  object BSave: TButton
    Left = 8
    Top = 109
    Width = 115
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 3
    OnClick = BSaveClick
  end
  object LERMS: TLabeledEdit
    Left = 129
    Top = 23
    Width = 98
    Height = 24
    EditLabel.Width = 99
    EditLabel.Height = 16
    EditLabel.Caption = #1055#1086#1075#1088#1077#1096#1085#1086#1089#1090#1100', '#1089#1084
    TabOrder = 4
    Text = '1'
  end
  object UpDown1: TUpDown
    Left = 227
    Top = 23
    Width = 19
    Height = 24
    Associate = LERMS
    Max = 1000
    Position = 1
    TabOrder = 5
  end
  object BSpecifyNamesPointsOnDrawing: TButton
    Left = 8
    Top = 41
    Width = 115
    Height = 25
    Caption = #1059#1090#1086#1095#1085#1080#1090#1100' '#1080#1084#1077#1085#1072
    TabOrder = 1
    OnClick = BSpecifyNamesPointsOnDrawingClick
  end
  object MEScaleBlock: TMaskEdit
    Left = 129
    Top = 65
    Width = 98
    Height = 24
    EditMask = '999;0; '
    MaxLength = 3
    TabOrder = 6
    Text = '1'
  end
  object BReverse: TButton
    Left = 8
    Top = 75
    Width = 115
    Height = 25
    Caption = #1056#1077#1074#1077#1088#1089
    TabOrder = 2
    OnClick = BReverseClick
  end
  object LabeledEdit1: TLabeledEdit
    Left = 129
    Top = 110
    Width = 98
    Height = 24
    EditLabel.Width = 63
    EditLabel.Height = 16
    EditLabel.Caption = #1053#1072#1095#1072#1090#1100' '#1089' '#1085
    TabOrder = 7
    Text = '1'
  end
  object UDBeginNum: TUpDown
    Left = 227
    Top = 110
    Width = 19
    Height = 24
    Associate = LabeledEdit1
    Min = 1
    Max = 9999
    Position = 1
    TabOrder = 8
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'csv'
    Filter = #1050#1072#1090#1072#1083#1086#1075' '#1082#1086#1086#1088#1076#1080#1085#1072#1090'(*.csv)|*.csv|All(*.*)|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofNoValidate, ofEnableSizing]
    Left = 160
    Top = 65535
  end
end
