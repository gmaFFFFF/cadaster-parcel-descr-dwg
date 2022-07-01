object FNumer: TFNumer
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = #1055#1088#1086#1085#1091#1084#1077#1088#1091#1081#1090#1077' '#1091#1095#1072#1089#1090#1086#1082
  ClientHeight = 107
  ClientWidth = 188
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 97
    Top = 36
    Width = 81
    Height = 12
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1052#1072#1089#1096#1090#1072#1073' '#1073#1083#1086#1082#1086#1074
  end
  object BNumerate: TButton
    Left = 6
    Top = 6
    Width = 86
    Height = 19
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1053#1091#1084#1077#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = BNumerateClick
  end
  object BSave: TButton
    Left = 6
    Top = 82
    Width = 86
    Height = 19
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 3
    OnClick = BSaveClick
  end
  object LERMS: TLabeledEdit
    Left = 97
    Top = 17
    Width = 73
    Height = 20
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    EditLabel.Width = 81
    EditLabel.Height = 12
    EditLabel.Margins.Left = 2
    EditLabel.Margins.Top = 2
    EditLabel.Margins.Right = 2
    EditLabel.Margins.Bottom = 2
    EditLabel.Caption = #1055#1086#1075#1088#1077#1096#1085#1086#1089#1090#1100', '#1089#1084
    TabOrder = 4
    Text = '1'
  end
  object UpDown1: TUpDown
    Left = 170
    Top = 17
    Width = 15
    Height = 20
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Associate = LERMS
    Max = 1000
    Position = 1
    TabOrder = 5
  end
  object BSpecifyNamesPointsOnDrawing: TButton
    Left = 6
    Top = 31
    Width = 86
    Height = 19
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1059#1090#1086#1095#1085#1080#1090#1100' '#1080#1084#1077#1085#1072
    TabOrder = 1
    OnClick = BSpecifyNamesPointsOnDrawingClick
  end
  object MEScaleBlock: TMaskEdit
    Left = 97
    Top = 49
    Width = 73
    Height = 20
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    EditMask = '999;0; '
    MaxLength = 3
    TabOrder = 6
    Text = '1'
  end
  object BReverse: TButton
    Left = 6
    Top = 56
    Width = 86
    Height = 19
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1056#1077#1074#1077#1088#1089
    TabOrder = 2
    OnClick = BReverseClick
  end
  object LabeledEdit1: TLabeledEdit
    Left = 97
    Top = 83
    Width = 73
    Height = 20
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    EditLabel.Width = 50
    EditLabel.Height = 12
    EditLabel.Margins.Left = 2
    EditLabel.Margins.Top = 2
    EditLabel.Margins.Right = 2
    EditLabel.Margins.Bottom = 2
    EditLabel.Caption = #1053#1072#1095#1072#1090#1100' '#1089' '#1085
    TabOrder = 7
    Text = '1'
  end
  object UDBeginNum: TUpDown
    Left = 170
    Top = 83
    Width = 15
    Height = 20
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
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
