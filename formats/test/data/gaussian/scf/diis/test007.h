std::string gaussian_scf_diis_test007 = R"(
 (Enter c:\g09w\l502.exe)
 Closed shell SCF:
 Requested convergence on RMS density matrix=1.00D-07 within 128 cycles.
 Requested convergence on MAX density matrix=1.00D-05.
 Requested convergence on             energy=1.00D-05.
 No special actions if energy rises.
 Using DIIS extrapolation, IDIIS=  1040.
 Unsorted integral processing.
 Two-electron integral symmetry not used.
 Two-electron integrals will be kept in memory, NGetB=      150775.
 IEnd=      264744 IEndB=      150775 NGot=    33554432 MDV=    33534729
 LenX=    33272585 LenY=    33550950

 Cycle   1  Pass 1  IDiag  1:
 E= -75.9337104522472    
 DIIS: error= 7.96D-02 at cycle   1 NSaved=   1.
 NSaved= 1 IEnMin= 1 EnMin= -75.9337104522472     IErMin= 1 ErrMin= 7.96D-02
 ErrMax= 7.96D-02 EMaxC= 1.00D-01 BMatC= 1.22D-01 BMatP= 1.22D-01
 IDIUse=3 WtCom= 2.04D-01 WtEn= 7.96D-01
 Coeff-Com:  0.100D+01
 Coeff-En:   0.100D+01
 Coeff:      0.100D+01
 Gap=     0.592 Goal=   None    Shift=    0.000
 GapD=    0.592 DampG=2.000 DampE=0.500 DampFc=1.0000 IDamp=-1.
 RMSDP=1.48D-02 MaxDP=1.16D-01              OVMax= 1.20D-01

 Cycle   2  Pass 1  IDiag  1:
 E= -75.9857362423962     Delta-E=       -0.052025790149 Rises=F Damp=F
 DIIS: error= 4.88D-02 at cycle   2 NSaved=   2.
 NSaved= 2 IEnMin= 2 EnMin= -75.9857362423962     IErMin= 2 ErrMin= 4.88D-02
 ErrMax= 4.88D-02 EMaxC= 1.00D-01 BMatC= 3.70D-02 BMatP= 1.22D-01
 IDIUse=3 WtCom= 5.12D-01 WtEn= 4.88D-01
 Coeff-Com:  0.335D+00 0.665D+00
 Coeff-En:   0.852D-01 0.915D+00
 Coeff:      0.213D+00 0.787D+00
 Gap=     0.728 Goal=   None    Shift=    0.000
 RMSDP=7.15D-03 MaxDP=5.60D-02 DE=-5.20D-02 OVMax= 4.61D-02

 Cycle   3  Pass 1  IDiag  1:
 E= -76.0082732231612     Delta-E=       -0.022536980765 Rises=F Damp=F
 DIIS: error= 1.23D-02 at cycle   3 NSaved=   3.
 NSaved= 3 IEnMin= 3 EnMin= -76.0082732231612     IErMin= 3 ErrMin= 1.23D-02
 ErrMax= 1.23D-02 EMaxC= 1.00D-01 BMatC= 2.17D-03 BMatP= 3.70D-02
 IDIUse=3 WtCom= 8.77D-01 WtEn= 1.23D-01
 Coeff-Com: -0.257D-01 0.168D+00 0.858D+00
 Coeff-En:   0.000D+00 0.000D+00 0.100D+01
 Coeff:     -0.226D-01 0.147D+00 0.875D+00
 Gap=     0.702 Goal=   None    Shift=    0.000
 RMSDP=1.47D-03 MaxDP=1.19D-02 DE=-2.25D-02 OVMax= 1.27D-02

 Cycle   4  Pass 1  IDiag  1:
 E= -76.0098450825981     Delta-E=       -0.001571859437 Rises=F Damp=F
 DIIS: error= 1.56D-03 at cycle   4 NSaved=   4.
 NSaved= 4 IEnMin= 4 EnMin= -76.0098450825981     IErMin= 4 ErrMin= 1.56D-03
 ErrMax= 1.56D-03 EMaxC= 1.00D-01 BMatC= 2.43D-05 BMatP= 2.17D-03
 IDIUse=3 WtCom= 9.84D-01 WtEn= 1.56D-02
 Coeff-Com:  0.613D-02-0.803D-01-0.249D+00 0.132D+01
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.100D+01
 Coeff:      0.604D-02-0.791D-01-0.245D+00 0.132D+01
 Gap=     0.706 Goal=   None    Shift=    0.000
 RMSDP=2.28D-04 MaxDP=2.10D-03 DE=-1.57D-03 OVMax= 1.73D-03

 Cycle   5  Pass 1  IDiag  1:
 E= -76.0098681926951     Delta-E=       -0.000023110097 Rises=F Damp=F
 DIIS: error= 1.48D-04 at cycle   5 NSaved=   5.
 NSaved= 5 IEnMin= 5 EnMin= -76.0098681926951     IErMin= 5 ErrMin= 1.48D-04
 ErrMax= 1.48D-04 EMaxC= 1.00D-01 BMatC= 1.79D-07 BMatP= 2.43D-05
 IDIUse=3 WtCom= 9.99D-01 WtEn= 1.48D-03
 Coeff-Com: -0.527D-04 0.718D-02 0.131D-01-0.217D+00 0.120D+01
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.000D+00 0.100D+01
 Coeff:     -0.526D-04 0.717D-02 0.131D-01-0.217D+00 0.120D+01
 Gap=     0.706 Goal=   None    Shift=    0.000
 RMSDP=4.92D-05 MaxDP=2.88D-04 DE=-2.31D-05 OVMax= 4.47D-04

 Cycle   6  Pass 1  IDiag  1:
 E= -76.0098686699877     Delta-E=       -0.000000477293 Rises=F Damp=F
 DIIS: error= 2.67D-05 at cycle   6 NSaved=   6.
 NSaved= 6 IEnMin= 6 EnMin= -76.0098686699877     IErMin= 6 ErrMin= 2.67D-05
 ErrMax= 2.67D-05 EMaxC= 1.00D-01 BMatC= 8.26D-09 BMatP= 1.79D-07
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.249D-03 0.189D-02 0.804D-02-0.108D-01-0.289D+00 0.129D+01
 Coeff:     -0.249D-03 0.189D-02 0.804D-02-0.108D-01-0.289D+00 0.129D+01
 Gap=     0.706 Goal=   None    Shift=    0.000
 RMSDP=1.35D-05 MaxDP=7.13D-05 DE=-4.77D-07 OVMax= 1.19D-04

 Cycle   7  Pass 1  IDiag  1:
 E= -76.0098686937119     Delta-E=       -0.000000023724 Rises=F Damp=F
 DIIS: error= 6.02D-06 at cycle   7 NSaved=   7.
 NSaved= 7 IEnMin= 7 EnMin= -76.0098686937119     IErMin= 7 ErrMin= 6.02D-06
 ErrMax= 6.02D-06 EMaxC= 1.00D-01 BMatC= 3.15D-10 BMatP= 8.26D-09
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.108D-03-0.105D-02-0.395D-02 0.115D-01 0.100D+00-0.585D+00
 Coeff-Com:  0.148D+01
 Coeff:      0.108D-03-0.105D-02-0.395D-02 0.115D-01 0.100D+00-0.585D+00
 Coeff:      0.148D+01
 Gap=     0.706 Goal=   None    Shift=    0.000
 RMSDP=1.94D-06 MaxDP=1.55D-05 DE=-2.37D-08 OVMax= 1.77D-05

 Cycle   8  Pass 1  IDiag  1:
 E= -76.0098686945344     Delta-E=       -0.000000000822 Rises=F Damp=F
 DIIS: error= 8.48D-07 at cycle   8 NSaved=   8.
 NSaved= 8 IEnMin= 8 EnMin= -76.0098686945344     IErMin= 8 ErrMin= 8.48D-07
 ErrMax= 8.48D-07 EMaxC= 1.00D-01 BMatC= 5.71D-12 BMatP= 3.15D-10
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.135D-04 0.164D-03 0.565D-03-0.250D-02-0.815D-02 0.709D-01
 Coeff-Com: -0.289D+00 0.123D+01
 Coeff:     -0.135D-04 0.164D-03 0.565D-03-0.250D-02-0.815D-02 0.709D-01
 Coeff:     -0.289D+00 0.123D+01
 Gap=     0.706 Goal=   None    Shift=    0.000
 RMSDP=2.45D-07 MaxDP=1.37D-06 DE=-8.22D-10 OVMax= 2.24D-06

 Cycle   9  Pass 1  IDiag  1:
 E= -76.0098686945479     Delta-E=       -0.000000000014 Rises=F Damp=F
 DIIS: error= 9.38D-08 at cycle   9 NSaved=   9.
 NSaved= 9 IEnMin= 9 EnMin= -76.0098686945479     IErMin= 9 ErrMin= 9.38D-08
 ErrMax= 9.38D-08 EMaxC= 1.00D-01 BMatC= 1.19D-13 BMatP= 5.71D-12
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.996D-06-0.196D-04-0.593D-04 0.413D-03-0.113D-03-0.605D-02
 Coeff-Com:  0.466D-01-0.355D+00 0.131D+01
 Coeff:      0.996D-06-0.196D-04-0.593D-04 0.413D-03-0.113D-03-0.605D-02
 Coeff:      0.466D-01-0.355D+00 0.131D+01
 Gap=     0.706 Goal=   None    Shift=    0.000
 RMSDP=4.75D-08 MaxDP=2.55D-07 DE=-1.35D-11 OVMax= 4.29D-07

 SCF Done:  E(RHF) =  -76.0098686945     A.U. after    9 cycles
             Convg  =    0.4755D-07             -V/T =  2.0028
 KE= 7.580134774557D+01 PE=-1.988071109906D+02 EE= 3.783872121176D+01
 Leave Link  502 at Thu Nov 05 16:53:40 2015, MaxMem=   33554432 cpu:       0.0
)";