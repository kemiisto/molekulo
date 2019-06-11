std::string gaussian_scf_diis_test002 = R"(
 (Enter c:\g09w\l502.exe)
 Restricted open shell SCF:
 Requested convergence on RMS density matrix=1.00D-08 within 128 cycles.
 Requested convergence on MAX density matrix=1.00D-06.
 Requested convergence on             energy=1.00D-06.
 No special actions if energy rises.
 Using DIIS extrapolation, IDIIS=  1040.
 Unsorted integral processing.
 Integral symmetry usage will be decided dynamically.
 Two-electron integrals will be kept in memory, NGetB=      150878.
 IEnd=      264847 IEndB=      150878 NGot=    33554432 MDV=    33534626
 LenX=    33272482 LenY=    33271600

 Cycle   1  Pass 1  IDiag  1:
 E= -39.4433685360849    
 DIIS: error= 6.41D-02 at cycle   1 NSaved=   1.
 NSaved= 1 IEnMin= 1 EnMin= -39.4433685360849     IErMin= 1 ErrMin= 6.41D-02
 ErrMax= 6.41D-02 EMaxC= 1.00D-01 BMatC= 6.30D-02 BMatP= 6.30D-02
 IDIUse=3 WtCom= 3.59D-01 WtEn= 6.41D-01
 Coeff-Com:  0.100D+01
 Coeff-En:   0.100D+01
 Coeff:      0.100D+01
 Gap=     0.298 Goal=   None    Shift=    0.000
 GapD=    0.298 DampG=1.000 DampE=0.500 DampFc=0.5000 IDamp=-1.
 Damping current iteration by 5.00D-01
 RMSDP=1.65D-02 MaxDP=1.35D-01              OVMax= 1.10D-01

 Cycle   2  Pass 1  IDiag  1:
 E= -39.4744989535336     Delta-E=       -0.031130417449 Rises=F Damp=T
 DIIS: error= 2.23D-02 at cycle   2 NSaved=   2.
 NSaved= 2 IEnMin= 2 EnMin= -39.4744989535336     IErMin= 2 ErrMin= 2.23D-02
 ErrMax= 2.23D-02 EMaxC= 1.00D-01 BMatC= 8.13D-03 BMatP= 6.30D-02
 IDIUse=3 WtCom= 7.77D-01 WtEn= 2.23D-01
 Coeff-Com: -0.412D+00 0.141D+01
 Coeff-En:   0.000D+00 0.100D+01
 Coeff:     -0.320D+00 0.132D+01
 Gap=     0.330 Goal=   None    Shift=    0.000
 RMSDP=4.64D-03 MaxDP=2.84D-02 DE=-3.11D-02 OVMax= 1.66D-02

 Cycle   3  Pass 1  IDiag  1:
 E= -39.5017140920356     Delta-E=       -0.027215138502 Rises=F Damp=F
 DIIS: error= 2.76D-03 at cycle   3 NSaved=   3.
 NSaved= 3 IEnMin= 3 EnMin= -39.5017140920356     IErMin= 3 ErrMin= 2.76D-03
 ErrMax= 2.76D-03 EMaxC= 1.00D-01 BMatC= 6.20D-05 BMatP= 8.13D-03
 IDIUse=3 WtCom= 9.72D-01 WtEn= 2.76D-02
 Coeff-Com: -0.225D-01 0.161D-01 0.101D+01
 Coeff-En:   0.000D+00 0.000D+00 0.100D+01
 Coeff:     -0.219D-01 0.156D-01 0.101D+01
 Gap=     0.330 Goal=   None    Shift=    0.000
 RMSDP=6.65D-04 MaxDP=5.91D-03 DE=-2.72D-02 OVMax= 1.89D-03

 Cycle   4  Pass 1  IDiag  1:
 E= -39.5017778293688     Delta-E=       -0.000063737333 Rises=F Damp=F
 DIIS: error= 6.08D-04 at cycle   4 NSaved=   4.
 NSaved= 4 IEnMin= 4 EnMin= -39.5017778293688     IErMin= 4 ErrMin= 6.08D-04
 ErrMax= 6.08D-04 EMaxC= 1.00D-01 BMatC= 2.67D-06 BMatP= 6.20D-05
 IDIUse=3 WtCom= 9.94D-01 WtEn= 6.08D-03
 Coeff-Com: -0.608D-03 0.163D-01-0.305D+00 0.129D+01
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.100D+01
 Coeff:     -0.604D-03 0.162D-01-0.303D+00 0.129D+01
 Gap=     0.330 Goal=   None    Shift=    0.000
 RMSDP=1.76D-04 MaxDP=1.81D-03 DE=-6.37D-05 OVMax= 5.72D-04

 Cycle   5  Pass 1  IDiag  1:
 E= -39.5017818414360     Delta-E=       -0.000004012067 Rises=F Damp=F
 DIIS: error= 1.07D-04 at cycle   5 NSaved=   5.
 NSaved= 5 IEnMin= 5 EnMin= -39.5017818414360     IErMin= 5 ErrMin= 1.07D-04
 ErrMax= 1.07D-04 EMaxC= 1.00D-01 BMatC= 5.15D-08 BMatP= 2.67D-06
 IDIUse=3 WtCom= 9.99D-01 WtEn= 1.07D-03
 Coeff-Com: -0.119D-02 0.140D-02 0.208D-01-0.199D+00 0.118D+01
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.000D+00 0.100D+01
 Coeff:     -0.118D-02 0.140D-02 0.208D-01-0.199D+00 0.118D+01
 Gap=     0.330 Goal=   None    Shift=    0.000
 RMSDP=2.43D-05 MaxDP=2.98D-04 DE=-4.01D-06 OVMax= 7.30D-05

 Cycle   6  Pass 1  IDiag  1:
 E= -39.5017819130889     Delta-E=       -0.000000071653 Rises=F Damp=F
 DIIS: error= 1.45D-05 at cycle   6 NSaved=   6.
 NSaved= 6 IEnMin= 6 EnMin= -39.5017819130889     IErMin= 6 ErrMin= 1.45D-05
 ErrMax= 1.45D-05 EMaxC= 1.00D-01 BMatC= 9.57D-10 BMatP= 5.15D-08
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.118D-03 0.449D-03-0.129D-01 0.837D-01-0.401D+00 0.133D+01
 Coeff:      0.118D-03 0.449D-03-0.129D-01 0.837D-01-0.401D+00 0.133D+01
 Gap=     0.330 Goal=   None    Shift=    0.000
 RMSDP=3.08D-06 MaxDP=3.73D-05 DE=-7.17D-08 OVMax= 6.43D-06

 Cycle   7  Pass 1  IDiag  1:
 E= -39.5017819143297     Delta-E=       -0.000000001241 Rises=F Damp=F
 DIIS: error= 3.37D-06 at cycle   7 NSaved=   7.
 NSaved= 7 IEnMin= 7 EnMin= -39.5017819143297     IErMin= 7 ErrMin= 3.37D-06
 ErrMax= 3.37D-06 EMaxC= 1.00D-01 BMatC= 4.64D-11 BMatP= 9.57D-10
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.214D-04 0.891D-04-0.986D-03 0.113D-02 0.170D-01-0.216D+00
 Coeff-Com:  0.120D+01
 Coeff:     -0.214D-04 0.891D-04-0.986D-03 0.113D-02 0.170D-01-0.216D+00
 Coeff:      0.120D+01
 Gap=     0.330 Goal=   None    Shift=    0.000
 RMSDP=6.77D-07 MaxDP=9.16D-06 DE=-1.24D-09 OVMax= 1.43D-06

 Cycle   8  Pass 1  IDiag  1:
 E= -39.5017819143907     Delta-E=       -0.000000000061 Rises=F Damp=F
 DIIS: error= 6.07D-07 at cycle   8 NSaved=   8.
 NSaved= 8 IEnMin= 8 EnMin= -39.5017819143907     IErMin= 8 ErrMin= 6.07D-07
 ErrMax= 6.07D-07 EMaxC= 1.00D-01 BMatC= 1.50D-12 BMatP= 4.64D-11
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.594D-05 0.610D-05 0.958D-04-0.143D-02 0.953D-02-0.547D-01
 Coeff-Com:  0.104D-01 0.104D+01
 Coeff:     -0.594D-05 0.610D-05 0.958D-04-0.143D-02 0.953D-02-0.547D-01
 Coeff:      0.104D-01 0.104D+01
 Gap=     0.330 Goal=   None    Shift=    0.000
 RMSDP=1.28D-07 MaxDP=1.88D-06 DE=-6.10D-11 OVMax= 1.69D-07

 Cycle   9  Pass 1  IDiag  1:
 E= -39.5017819143928     Delta-E=       -0.000000000002 Rises=F Damp=F
 DIIS: error= 3.79D-08 at cycle   9 NSaved=   9.
 NSaved= 9 IEnMin= 9 EnMin= -39.5017819143928     IErMin= 9 ErrMin= 3.79D-08
 ErrMax= 3.79D-08 EMaxC= 1.00D-01 BMatC= 6.33D-15 BMatP= 1.50D-12
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.105D-05-0.206D-05 0.296D-05 0.164D-03-0.156D-02 0.101D-01
 Coeff-Com: -0.247D-01-0.157D+00 0.117D+01
 Coeff:      0.105D-05-0.206D-05 0.296D-05 0.164D-03-0.156D-02 0.101D-01
 Coeff:     -0.247D-01-0.157D+00 0.117D+01
 Gap=     0.330 Goal=   None    Shift=    0.000
 RMSDP=1.35D-08 MaxDP=1.69D-07 DE=-2.05D-12 OVMax= 4.82D-08

 Cycle  10  Pass 1  IDiag  1:
 E= -39.5017819143928     Delta-E=        0.000000000000 Rises=F Damp=F
 DIIS: error= 1.34D-08 at cycle  10 NSaved=  10.
 NSaved=10 IEnMin= 9 EnMin= -39.5017819143928     IErMin=10 ErrMin= 1.34D-08
 ErrMax= 1.34D-08 EMaxC= 1.00D-01 BMatC= 7.43D-16 BMatP= 6.33D-15
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.292D-06 0.300D-06 0.419D-05-0.719D-04 0.568D-03-0.294D-02
 Coeff-Com:  0.101D-01 0.551D-01-0.525D+00 0.146D+01
 Coeff:     -0.292D-06 0.300D-06 0.419D-05-0.719D-04 0.568D-03-0.294D-02
 Coeff:      0.101D-01 0.551D-01-0.525D+00 0.146D+01
 Gap=     0.330 Goal=   None    Shift=    0.000
 RMSDP=3.60D-09 MaxDP=5.04D-08 DE= 1.42D-14 OVMax= 9.44D-09

 SCF Done:  E(ROHF) =  -39.5017819144     A.U. after   10 cycles
             Convg  =    0.3598D-08             -V/T =  1.9984
 <Sx>= 0.0000 <Sy>= 0.0000 <Sz>= 0.5000 <S**2>= 0.7500 S= 0.5000
 <L.S>= 0.000000000000E+00
 KE= 3.956469258765D+01 PE=-1.112335019413D+02 EE= 2.241257370224D+01
 Annihilation of the first spin contaminant:
 S**2 before annihilation     0.7500,   after     0.7500
 Leave Link  502 at Thu Nov 05 16:53:21 2015, MaxMem=   33554432 cpu:       0.0
)";