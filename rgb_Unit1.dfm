object WorkwithRGB: TWorkwithRGB
  Left = 80
  Top = 48
  Width = 1271
  Height = 668
  Caption = 'Laboratorna 3'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 384
    Top = 600
    Width = 23
    Height = 12
    Caption = 'Red'
    Color = clRed
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Broadway'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label2: TLabel
    Left = 584
    Top = 600
    Width = 36
    Height = 12
    Caption = 'Green'
    Color = clGreen
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Broadway'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label3: TLabel
    Left = 808
    Top = 600
    Width = 27
    Height = 12
    Caption = 'Blue'
    Color = clBlue
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Broadway'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object DiapazonRedMAX: TEdit
    Left = 352
    Top = 568
    Width = 41
    Height = 21
    TabOrder = 0
    Text = '255'
  end
  object DiapazonRedMIN: TEdit
    Left = 408
    Top = 568
    Width = 41
    Height = 21
    TabOrder = 1
    Text = '0'
  end
  object DiapazonGreenMAX: TEdit
    Left = 552
    Top = 568
    Width = 41
    Height = 21
    TabOrder = 2
    Text = '255'
  end
  object DiapazonGreenMIN: TEdit
    Left = 608
    Top = 568
    Width = 41
    Height = 21
    TabOrder = 3
    Text = '0'
  end
  object DiapazonBlueMAX: TEdit
    Left = 768
    Top = 568
    Width = 41
    Height = 21
    TabOrder = 4
    Text = '255'
  end
  object DiapazonBlueMIN: TEdit
    Left = 832
    Top = 568
    Width = 41
    Height = 21
    TabOrder = 5
    Text = '0'
  end
  object Do: TButton
    Left = 1144
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Do'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Anselmo Font4You'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = DoClick
  end
  object Overview: TButton
    Left = 1144
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Overview'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Anselmo Font4You'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    OnClick = OverviewClick
  end
  object Save: TButton
    Left = 1144
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Save'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Anselmo Font4You'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 8
    OnClick = SaveClick
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 1224
    Top = 40
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 1224
    Top = 104
  end
end
