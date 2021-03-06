//---------------------------------------------------------------------------
#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include "rgb_Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWorkwithRGB *WorkwithRGB;
//---------------------------------------------------------------------------
__fastcall TWorkwithRGB::TWorkwithRGB(TComponent* Owner):TForm(Owner){}
//---------------------------------------------------------------------------
Graphics::TBitmap *colorusal = new Graphics::TBitmap();

//------------------------------------------------------------------------------
void __fastcall TWorkwithRGB::OverviewClick(TObject *Sender)
{
    if(OpenPictureDialog1->Execute())
    {
        colorusal->LoadFromFile( OpenPictureDialog1->FileName );
    }
    //---ochystka formy------------
    Canvas->Brush->Color = clBtnFace;
    Canvas->FillRect ( Canvas->ClipRect );
    Canvas->Draw(10,10,colorusal);  //leftup

    //---dilennja na shary-------------------------------------

    for( int y = 0; y < colorusal->Height; y++ )
    {
        for( int x = 0; x < colorusal->Width; x++ )
        {
            Lr[x][y] = GetRValue(GetPixel(colorusal->Canvas->Handle, x, y));
            Lg[x][y] = GetGValue(GetPixel(colorusal->Canvas->Handle, x, y));
            Lb[x][y] = GetBValue(GetPixel(colorusal->Canvas->Handle, x, y));
        }
    }
    //-----------vyvid staryh shariv-------------------------
    int k = 0;
    for(int y = 0; y < colorusal->Height; y++)
    {
        for(int x = 0; x < colorusal->Width; x++)
        {
           Canvas->Pixels[colorusal->Width+20+x][10+y] = (TColor)RGB(Lr[x][y],k,k);
           Canvas->Pixels[2*colorusal->Width+30+x][10+y] = (TColor)RGB(k,Lg[x][y],k);
           Canvas->Pixels[3*colorusal->Width+40+x][10+y] = (TColor)RGB(k,k,Lb[x][y]);
        }
    }

    //-------------max_min------------------------------------
    rmax = Lr[0][0]; rmin = Lr[0][0];
    gmax = Lg[0][0]; gmin = Lg[0][0];
    bmax = Lb[0][0]; bmin = Lb[0][0];

    for(int y = 0; y < colorusal->Height; y++)
    {
        for(int x = 0; x < colorusal->Width; x++)
        {
            if(Lr[x][y] < rmin) rmin = Lr[x][y];
            if(Lg[x][y] < gmin) gmin = Lg[x][y];
            if(Lb[x][y] < bmin) bmin = Lb[x][y];

            if(Lr[x][y] > rmax) rmax = Lr[x][y];
            if(Lg[x][y] > gmax) gmax = Lg[x][y];
            if(Lb[x][y] > bmax) bmax = Lb[x][y];
        }
    }

    ShowMessage("Old diapasons\nrmax "+IntToStr(rmax)+" rmin "+IntToStr(rmin)+"\n"+
                "gmax "+IntToStr(gmax)+" gmin "+IntToStr(gmin)+"\n"+
                "bmax "+IntToStr(bmax)+" bmin "+IntToStr(bmin));
    //--->>>v Edits
    DiapazonRedMAX->Text = rmax; DiapazonRedMIN->Text = rmin;
    DiapazonGreenMAX->Text = gmax; DiapazonGreenMIN->Text = gmin;
    DiapazonBlueMAX->Text = bmax; DiapazonBlueMIN->Text = bmin;
}
//------------------------------------------------------------------------------
//--------diapazons------------------------------
void TWorkwithRGB::diapasons()
{
    //perevirka na vvedenu velychynu 0 <= d <= 255
    //--------- red ---------------------------------
    drmax = StrToInt(DiapazonRedMAX->Text); if(drmax < 1 || drmax > 255) drmax = 255;
    drmin = StrToInt(DiapazonRedMIN->Text); if(drmin < 0 || drmin > 254) drmin = 0;
    if(drmax < drmin){ int tmp = drmax; drmax = drmin; drmin = tmp; }
    if(drmax == drmin)
    {
        if(drmin == 0)drmax +=1;
        if(drmax == 255)drmin -=1;
    }
    DiapazonRedMAX->Text = drmax; DiapazonRedMIN->Text = drmin;

    //-------- green --------------------------------
    dgmax = StrToInt(DiapazonGreenMAX->Text); if(dgmax < 1 || dgmax > 255) dgmax = 255;
    dgmin = StrToInt(DiapazonGreenMIN->Text); if(dgmin < 0 || dgmin > 254) dgmin = 0;
    if(dgmax < dgmin){ int tmp = dgmax; dgmax = dgmin; dgmin = tmp; }
    if(dgmax == dgmin)
    {
        if(dgmin == 0)dgmax +=1;
        if(dgmax == 255)dgmin -=1;
    }
    DiapazonGreenMAX->Text = dgmax; DiapazonGreenMIN->Text = dgmin;

    //-------- blue ---------------------------------
    dbmax = StrToInt(DiapazonBlueMAX->Text); if(dbmax < 1 || dbmax > 255) dbmax = 255;
    dbmin = StrToInt(DiapazonBlueMIN->Text); if(dbmin < 0 || dbmin > 254) dbmin = 0;
    if(dbmax < dbmin){ int tmp = dbmax; dbmax = dbmin; dbmin = tmp; }
    if(dbmax == dbmin)
    {
        if(dbmin == 0)dbmax +=1;
        if(dbmax == 255)dbmin -=1;
    }
    DiapazonBlueMAX->Text = dbmax; DiapazonBlueMIN->Text = dbmin;
}
//------------------------------------------------------------------------------
void __fastcall TWorkwithRGB::DoClick(TObject *Sender)
{
    diapasons();

    ShowMessage("New diapasons\nrmax "+IntToStr(drmax)+" rmin "+IntToStr(drmin)+"\n"+
                "gmax "+IntToStr(dgmax)+" gmin "+IntToStr(dgmin)+"\n"+
                "bmax "+IntToStr(dbmax)+" bmin "+IntToStr(dbmin));
    //--------pererahunok--------------------------
    for(int y = 0; y < colorusal->Height; y++)
    {
        for(int x = 0; x < colorusal->Width; x++)
        {
            Lr[x][y] = (Lr[x][y]-rmin)*(drmax-drmin)/(rmax-rmin) + drmin;
            Lg[x][y] = (Lg[x][y]-gmin)*(dgmax-dgmin)/(gmax-gmin) + dgmin;
            Lb[x][y] = (Lb[x][y]-bmin)*(dbmax-dbmin)/(bmax-bmin) + dbmin;
        }
    }
    //------------vyvid novyh shariv------------------
    int k = 0;
    for(int y = 0; y < colorusal->Height; y++)
    {
        for(int x = 0; x < colorusal->Width; x++)
        {
            Canvas->Pixels[colorusal->Width+20+x][colorusal->Height+20+y] = (TColor)RGB(Lr[x][y],k,k);
            Canvas->Pixels[2*colorusal->Width+30+x][colorusal->Height+20+y] = (TColor)RGB(k,Lg[x][y],k);
            Canvas->Pixels[3*colorusal->Width+40+x][colorusal->Height+20+y] = (TColor)RGB(k,k,Lb[x][y]);
        }
    }

    //----perezapys pikseliv--------------------------------------------------------
    RGBTRIPLE *stroky;
    for(int y = 0; y < colorusal->Height; y++)
    {
        stroky = (RGBTRIPLE*)colorusal->ScanLine[y];
        for(int x = 0; x < colorusal->Width; x++)
        {
            stroky[x].rgbtRed = Lr[x][y];
            stroky[x].rgbtGreen = Lg[x][y];
            stroky[x].rgbtBlue = Lb[x][y];
        }
    }

    //---draw_end--------
    Canvas->Draw(10,colorusal->Height+20,colorusal);
}

//---------------------------------------------------------------------------
void __fastcall TWorkwithRGB::SaveClick(TObject *Sender)
{
    if(SavePictureDialog1->Execute())
    {
        colorusal->SaveToFile(SavePictureDialog1->FileName);
    }
}
//---------------------------------------------------------------------------


