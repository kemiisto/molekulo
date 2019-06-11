std::string gaussian_scf_diis_water_hf_not_converged = R"(
 (Enter c:\g09w\l502.exe)
 Closed shell SCF:
 Requested convergence on RMS density matrix=1.00D-08 within   3 cycles.
 Requested convergence on MAX density matrix=1.00D-06.
 Requested convergence on             energy=1.00D-06.
 No special actions if energy rises.
 Using DIIS extrapolation, IDIIS=  1040.
 Integral symmetry usage will be decided dynamically.
 Keep R1 ints in memory in canonical form, NReq=805979.
 IEnd=        1779 IEndB=        1779 NGot=    33554432 MDV=    33548637
 LenX=    33548637 LenY=    33548452
 Symmetry not used in FoFDir.
 MinBra= 0 MaxBra= 1 Meth= 1.
 IRaf=       0 NMat=   1 IRICut=       1 DoRegI=T DoRafI=F ISym2E= 0 JSym2E=0.

 Cycle   1  Pass 1  IDiag  1:
 E= -75.5170109481120    
 DIIS: error= 9.32D-02 at cycle   1 NSaved=   1.
 NSaved= 1 IEnMin= 1 EnMin= -75.5170109481120     IErMin= 1 ErrMin= 9.32D-02
 ErrMax= 9.32D-02 EMaxC= 1.00D-01 BMatC= 1.15D-01 BMatP= 1.15D-01
 IDIUse=3 WtCom= 6.79D-02 WtEn= 9.32D-01
 Coeff-Com:  0.100D+01
 Coeff-En:   0.100D+01
 Coeff:      0.100D+01
 Gap=     0.631 Goal=   None    Shift=    0.000
 GapD=    0.631 DampG=2.000 DampE=0.500 DampFc=1.0000 IDamp=-1.
 RMSDP=1.78D-02 MaxDP=8.02D-02              OVMax= 1.13D-01

 Cycle   2  Pass 1  IDiag  1:
 E= -75.5701757793356     Delta-E=       -0.053164831224 Rises=F Damp=F
 DIIS: error= 4.48D-02 at cycle   2 NSaved=   2.
 NSaved= 2 IEnMin= 2 EnMin= -75.5701757793356     IErMin= 2 ErrMin= 4.48D-02
 ErrMax= 4.48D-02 EMaxC= 1.00D-01 BMatC= 2.84D-02 BMatP= 1.15D-01
 IDIUse=3 WtCom= 5.52D-01 WtEn= 4.48D-01
 Coeff-Com:  0.309D+00 0.691D+00
 Coeff-En:   0.000D+00 0.100D+01
 Coeff:      0.171D+00 0.829D+00
 Gap=     0.756 Goal=   None    Shift=    0.000
 RMSDP=7.52D-03 MaxDP=4.06D-02 DE=-5.32D-02 OVMax= 3.10D-02

 Cycle   3  Pass 1  IDiag  1:
 E= -75.5847903860537     Delta-E=       -0.014614606718 Rises=F Damp=F
 DIIS: error= 1.14D-02 at cycle   3 NSaved=   3.
 NSaved= 3 IEnMin= 3 EnMin= -75.5847903860537     IErMin= 3 ErrMin= 1.14D-02
 ErrMax= 1.14D-02 EMaxC= 1.00D-01 BMatC= 1.50D-03 BMatP= 2.84D-02
 IDIUse=3 WtCom= 8.86D-01 WtEn= 1.14D-01
 Coeff-Com: -0.289D-01 0.151D+00 0.878D+00
 Coeff-En:   0.000D+00 0.000D+00 0.100D+01
 Coeff:     -0.256D-01 0.134D+00 0.892D+00
 Gap=     0.736 Goal=   None    Shift=    0.000
 RMSDP=1.70D-03 MaxDP=6.90D-03 DE=-1.46D-02 OVMax= 1.02D-02

 Cycle   4  Pass 1  IDiag  1:
 E= -75.5857941194611     Delta-E=       -0.001003733407 Rises=F Damp=F
 DIIS: error= 1.46D-03 at cycle   4 NSaved=   4.
 NSaved= 4 IEnMin= 4 EnMin= -75.5857941194611     IErMin= 4 ErrMin= 1.46D-03
 ErrMax= 1.46D-03 EMaxC= 1.00D-01 BMatC= 1.84D-05 BMatP= 1.50D-03
 IDIUse=3 WtCom= 9.85D-01 WtEn= 1.46D-02
 Coeff-Com:  0.798D-02-0.771D-01-0.269D+00 0.134D+01
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.100D+01
 Coeff:      0.787D-02-0.760D-01-0.265D+00 0.133D+01
 Gap=     0.739 Goal=   None    Shift=    0.000
 RMSDP=2.83D-04 MaxDP=1.57D-03 DE=-1.00D-03 OVMax= 1.36D-03

 Cycle   5  Pass 1  IDiag  1:
 E= -75.5858097383584     Delta-E=       -0.000015618897 Rises=F Damp=F
 DIIS: error= 9.83D-05 at cycle   5 NSaved=   5.
 NSaved= 5 IEnMin= 5 EnMin= -75.5858097383584     IErMin= 5 ErrMin= 9.83D-05
 ErrMax= 9.83D-05 EMaxC= 1.00D-01 BMatC= 8.76D-08 BMatP= 1.84D-05
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.199D-02 0.218D-01 0.717D-01-0.437D+00 0.135D+01
 Coeff:     -0.199D-02 0.218D-01 0.717D-01-0.437D+00 0.135D+01
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=5.54D-05 MaxDP=2.77D-04 DE=-1.56D-05 OVMax= 3.56D-04

 >>>>>>>>>> Convergence criterion not met.
 SCF Done:  E(RHF) =  -75.5847903861     A.U. after    4 cycles
             Convg  =    0.1704D-02             -V/T =  2.0021
 KE= 7.542441369909D+01 PE=-1.982407324303D+02 EE= 3.807441235515D+01
 Convergence failure -- run terminated.
 Error termination via Lnk1e in c:\g09w\l502.exe at Mon Nov 02 21:07:02 2015.
)";
