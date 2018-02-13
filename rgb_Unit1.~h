//---------------------------------------------------------------------------

#ifndef rgb_Unit1H
#define rgb_Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TWorkwithRGB : public TForm
{
__published:	// IDE-managed Components
        TEdit *DiapazonRedMAX;
        TEdit *DiapazonRedMIN;
        TEdit *DiapazonGreenMAX;
        TEdit *DiapazonGreenMIN;
        TEdit *DiapazonBlueMAX;
        TEdit *DiapazonBlueMIN;
        TButton *Do;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TOpenPictureDialog *OpenPictureDialog1;
        TButton *Overview;
        TButton *Save;
        TSavePictureDialog *SavePictureDialog1;
        void __fastcall DoClick(TObject *Sender);
        void __fastcall OverviewClick(TObject *Sender);
        void __fastcall SaveClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TWorkwithRGB(TComponent* Owner);
        void diapasons();
        int Lr[260][260], Lg[260][260], Lb[260][260];
        int drmax, drmin, dgmax, dgmin, dbmax, dbmin;
        int rmax, rmin, gmax, gmin, bmax, bmin;
};
//---------------------------------------------------------------------------
extern PACKAGE TWorkwithRGB *WorkwithRGB;
//---------------------------------------------------------------------------
#endif
