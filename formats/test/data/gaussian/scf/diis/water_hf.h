std::string gaussian_scf_diis_water_hf = R"(
 (Enter c:\g09w\l502.exe)
 Closed shell SCF:
 Requested convergence on RMS density matrix=1.00D-08 within 128 cycles.
 Requested convergence on MAX density matrix=1.00D-06.
 Requested convergence on             energy=1.00D-06.
 No special actions if energy rises.
 Using DIIS extrapolation, IDIIS=  1040.
 Integral symmetry usage will be decided dynamically.
 Keep R1 ints in memory in canonical form, NReq=823930.
 IEnd=       19730 IEndB=       19730 NGot=    33554432 MDV=    33547591
 LenX=    33547591 LenY=    33546709
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

 Cycle   6  Pass 1  IDiag  1:
 E= -75.5858099662530     Delta-E=       -0.000000227895 Rises=F Damp=F
 DIIS: error= 2.17D-05 at cycle   6 NSaved=   6.
 NSaved= 6 IEnMin= 6 EnMin= -75.5858099662530     IErMin= 6 ErrMin= 2.17D-05
 ErrMax= 2.17D-05 EMaxC= 1.00D-01 BMatC= 3.44D-09 BMatP= 8.76D-08
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.108D-02-0.122D-01-0.396D-01 0.252D+00-0.856D+00 0.166D+01
 Coeff:      0.108D-02-0.122D-01-0.396D-01 0.252D+00-0.856D+00 0.166D+01
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=1.23D-05 MaxDP=5.28D-05 DE=-2.28D-07 OVMax= 8.23D-05

 Cycle   7  Pass 1  IDiag  1:
 E= -75.5858099772537     Delta-E=       -0.000000011001 Rises=F Damp=F
 DIIS: error= 1.55D-06 at cycle   7 NSaved=   7.
 NSaved= 7 IEnMin= 7 EnMin= -75.5858099772537     IErMin= 7 ErrMin= 1.55D-06
 ErrMax= 1.55D-06 EMaxC= 1.00D-01 BMatC= 4.18D-11 BMatP= 3.44D-09
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.835D-04 0.987D-03 0.315D-02-0.220D-01 0.840D-01-0.237D+00
 Coeff-Com:  0.117D+01
 Coeff:     -0.835D-04 0.987D-03 0.315D-02-0.220D-01 0.840D-01-0.237D+00
 Coeff:      0.117D+01
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=1.09D-06 MaxDP=5.10D-06 DE=-1.10D-08 OVMax= 6.90D-06

 Cycle   8  Pass 1  IDiag  1:
 E= -75.5858099773422     Delta-E=       -0.000000000088 Rises=F Damp=F
 DIIS: error= 2.45D-07 at cycle   8 NSaved=   8.
 NSaved= 8 IEnMin= 8 EnMin= -75.5858099773422     IErMin= 8 ErrMin= 2.45D-07
 ErrMax= 2.45D-07 EMaxC= 1.00D-01 BMatC= 5.09D-13 BMatP= 4.18D-11
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.482D-06-0.811D-05-0.141D-04 0.580D-03-0.399D-02 0.217D-01
 Coeff-Com: -0.245D+00 0.123D+01
 Coeff:     -0.482D-06-0.811D-05-0.141D-04 0.580D-03-0.399D-02 0.217D-01
 Coeff:     -0.245D+00 0.123D+01
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=1.27D-07 MaxDP=8.38D-07 DE=-8.84D-11 OVMax= 6.91D-07

 Cycle   9  Pass 1  IDiag  1:
 E= -75.5858099773433     Delta-E=       -0.000000000001 Rises=F Damp=F
 DIIS: error= 2.33D-08 at cycle   9 NSaved=   9.
 NSaved= 9 IEnMin= 9 EnMin= -75.5858099773433     IErMin= 9 ErrMin= 2.33D-08
 ErrMax= 2.33D-08 EMaxC= 1.00D-01 BMatC= 5.99D-15 BMatP= 5.09D-13
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.118D-06 0.378D-05 0.109D-04-0.159D-03 0.874D-03-0.414D-02
 Coeff-Com:  0.419D-01-0.251D+00 0.121D+01
 Coeff:     -0.118D-06 0.378D-05 0.109D-04-0.159D-03 0.874D-03-0.414D-02
 Coeff:      0.419D-01-0.251D+00 0.121D+01
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=1.06D-08 MaxDP=4.58D-08 DE=-1.08D-12 OVMax= 6.66D-08

 Cycle  10  Pass 1  IDiag  1:
 E= -75.5858099773433     Delta-E=        0.000000000000 Rises=F Damp=F
 DIIS: error= 7.75D-10 at cycle  10 NSaved=  10.
 NSaved=10 IEnMin= 9 EnMin= -75.5858099773433     IErMin=10 ErrMin= 7.75D-10
 ErrMax= 7.75D-10 EMaxC= 1.00D-01 BMatC= 1.08D-17 BMatP= 5.99D-15
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.157D-07-0.347D-08 0.101D-06 0.583D-05-0.426D-04 0.237D-03
 Coeff-Com: -0.265D-02 0.191D-01-0.133D+00 0.112D+01
 Coeff:     -0.157D-07-0.347D-08 0.101D-06 0.583D-05-0.426D-04 0.237D-03
 Coeff:     -0.265D-02 0.191D-01-0.133D+00 0.112D+01
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=3.68D-10 MaxDP=1.22D-09 DE= 1.42D-14 OVMax= 2.06D-09

 SCF Done:  E(RHF) =  -75.5858099773     A.U. after   10 cycles
             Convg  =    0.3677D-09             -V/T =  2.0018
 KE= 7.544716224790D+01 PE=-1.980498357157D+02 EE= 3.785974750045D+01
 Leave Link  502 at Wed Jul 08 16:04:53 2015, MaxMem=   33554432 cpu:       0.0
)";
