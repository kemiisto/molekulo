std::string gaussian_scf_diis_test004 = R"(
 (Enter c:\g09w\l502.exe)
 UHF open shell SCF:
 Requested convergence on RMS density matrix=1.00D-08 within 128 cycles.
 Requested convergence on MAX density matrix=1.00D-06.
 Requested convergence on             energy=1.00D-06.
 No special actions if energy rises.
 Using DIIS extrapolation, IDIIS=  1040.
 Unsorted integral processing.
 Integral symmetry usage will be decided dynamically.
 IEnd=      267734 IEndB=      267734 NGot=    33554432 MDV=    33548842
 LenX=    33286698 LenY=    33546801

 Cycle   1  Pass 1  IDiag  1:
 E= -78.4539379445890    
 DIIS: error= 6.73D-02 at cycle   1 NSaved=   1.
 NSaved= 1 IEnMin= 1 EnMin= -78.4539379445890     IErMin= 1 ErrMin= 6.73D-02
 ErrMax= 6.73D-02 EMaxC= 1.00D-01 BMatC= 6.74D-01 BMatP= 6.74D-01
 IDIUse=3 WtCom= 3.27D-01 WtEn= 6.73D-01
 Coeff-Com:  0.100D+01
 Coeff-En:   0.100D+01
 Coeff:      0.100D+01
 Gap=     0.541 Goal=   None    Shift=    0.000
 Gap=     0.705 Goal=   None    Shift=    0.000
 GapD=    0.541 DampG=2.000 DampE=0.500 DampFc=1.0000 IDamp=-1.
 RMSDP=1.01D-02 MaxDP=1.19D-01              OVMax= 1.49D-01

 Cycle   2  Pass 1  IDiag  1:
 E= -78.5767128468840     Delta-E=       -0.122774902295 Rises=F Damp=F
 DIIS: error= 2.20D-02 at cycle   2 NSaved=   2.
 NSaved= 2 IEnMin= 2 EnMin= -78.5767128468840     IErMin= 2 ErrMin= 2.20D-02
 ErrMax= 2.20D-02 EMaxC= 1.00D-01 BMatC= 8.25D-02 BMatP= 6.74D-01
 IDIUse=3 WtCom= 7.80D-01 WtEn= 2.20D-01
 Coeff-Com:  0.201D+00 0.799D+00
 Coeff-En:   0.000D+00 0.100D+01
 Coeff:      0.156D+00 0.844D+00
 Gap=     0.604 Goal=   None    Shift=    0.000
 Gap=     0.701 Goal=   None    Shift=    0.000
 RMSDP=3.28D-03 MaxDP=4.40D-02 DE=-1.23D-01 OVMax= 4.31D-02

 Cycle   3  Pass 1  IDiag  1:
 E= -78.5954502783332     Delta-E=       -0.018737431449 Rises=F Damp=F
 DIIS: error= 4.78D-03 at cycle   3 NSaved=   3.
 NSaved= 3 IEnMin= 3 EnMin= -78.5954502783332     IErMin= 3 ErrMin= 4.78D-03
 ErrMax= 4.78D-03 EMaxC= 1.00D-01 BMatC= 3.27D-03 BMatP= 8.25D-02
 IDIUse=3 WtCom= 9.52D-01 WtEn= 4.78D-02
 Coeff-Com: -0.284D-01 0.964D-01 0.932D+00
 Coeff-En:   0.000D+00 0.000D+00 0.100D+01
 Coeff:     -0.270D-01 0.918D-01 0.935D+00
 Gap=     0.600 Goal=   None    Shift=    0.000
 Gap=     0.662 Goal=   None    Shift=    0.000
 RMSDP=6.96D-04 MaxDP=7.99D-03 DE=-1.87D-02 OVMax= 1.45D-02

 Cycle   4  Pass 1  IDiag  1:
 E= -78.5966285706626     Delta-E=       -0.001178292329 Rises=F Damp=F
 DIIS: error= 2.01D-03 at cycle   4 NSaved=   4.
 NSaved= 4 IEnMin= 4 EnMin= -78.5966285706626     IErMin= 4 ErrMin= 2.01D-03
 ErrMax= 2.01D-03 EMaxC= 1.00D-01 BMatC= 2.59D-04 BMatP= 3.27D-03
 IDIUse=3 WtCom= 9.80D-01 WtEn= 2.01D-02
 Coeff-Com:  0.808D-02-0.583D-01-0.359D+00 0.141D+01
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.100D+01
 Coeff:      0.791D-02-0.571D-01-0.352D+00 0.140D+01
 Gap=     0.602 Goal=   None    Shift=    0.000
 Gap=     0.666 Goal=   None    Shift=    0.000
 RMSDP=3.69D-04 MaxDP=4.23D-03 DE=-1.18D-03 OVMax= 7.95D-03

 Cycle   5  Pass 1  IDiag  1:
 E= -78.5968233694575     Delta-E=       -0.000194798795 Rises=F Damp=F
 DIIS: error= 5.35D-04 at cycle   5 NSaved=   5.
 NSaved= 5 IEnMin= 5 EnMin= -78.5968233694575     IErMin= 5 ErrMin= 5.35D-04
 ErrMax= 5.35D-04 EMaxC= 1.00D-01 BMatC= 5.14D-05 BMatP= 2.59D-04
 IDIUse=3 WtCom= 9.95D-01 WtEn= 5.35D-03
 Coeff-Com:  0.372D-02-0.128D-01-0.129D+00-0.557D-01 0.119D+01
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.000D+00 0.100D+01
 Coeff:      0.370D-02-0.128D-01-0.129D+00-0.554D-01 0.119D+01
 Gap=     0.604 Goal=   None    Shift=    0.000
 Gap=     0.666 Goal=   None    Shift=    0.000
 RMSDP=1.90D-04 MaxDP=2.50D-03 DE=-1.95D-04 OVMax= 2.73D-03

 Cycle   6  Pass 1  IDiag  1:
 E= -78.5968641388540     Delta-E=       -0.000040769397 Rises=F Damp=F
 DIIS: error= 2.57D-04 at cycle   6 NSaved=   6.
 NSaved= 6 IEnMin= 6 EnMin= -78.5968641388540     IErMin= 6 ErrMin= 2.57D-04
 ErrMax= 2.57D-04 EMaxC= 1.00D-01 BMatC= 1.00D-05 BMatP= 5.14D-05
 IDIUse=3 WtCom= 9.97D-01 WtEn= 2.57D-03
 Coeff-Com: -0.270D-02 0.172D-01 0.115D+00-0.288D+00-0.360D+00 0.152D+01
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.000D+00 0.000D+00 0.100D+01
 Coeff:     -0.269D-02 0.172D-01 0.115D+00-0.287D+00-0.359D+00 0.152D+01
 Gap=     0.604 Goal=   None    Shift=    0.000
 Gap=     0.667 Goal=   None    Shift=    0.000
 RMSDP=1.13D-04 MaxDP=1.35D-03 DE=-4.08D-05 OVMax= 1.64D-03

 Cycle   7  Pass 1  IDiag  1:
 E= -78.5968738397351     Delta-E=       -0.000009700881 Rises=F Damp=F
 DIIS: error= 1.25D-04 at cycle   7 NSaved=   7.
 NSaved= 7 IEnMin= 7 EnMin= -78.5968738397351     IErMin= 7 ErrMin= 1.25D-04
 ErrMax= 1.25D-04 EMaxC= 1.00D-01 BMatC= 7.57D-07 BMatP= 1.00D-05
 IDIUse=3 WtCom= 9.99D-01 WtEn= 1.25D-03
 Coeff-Com:  0.864D-04-0.161D-02-0.696D-02 0.621D-01-0.729D-01-0.306D+00
 Coeff-Com:  0.133D+01
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.000D+00 0.000D+00 0.000D+00
 Coeff-En:   0.100D+01
 Coeff:      0.863D-04-0.161D-02-0.695D-02 0.620D-01-0.728D-01-0.305D+00
 Coeff:      0.132D+01
 Gap=     0.604 Goal=   None    Shift=    0.000
 Gap=     0.667 Goal=   None    Shift=    0.000
 RMSDP=3.37D-05 MaxDP=3.98D-04 DE=-9.70D-06 OVMax= 4.63D-04

 Cycle   8  Pass 1  IDiag  1:
 E= -78.5968746281882     Delta-E=       -0.000000788453 Rises=F Damp=F
 DIIS: error= 2.94D-05 at cycle   8 NSaved=   8.
 NSaved= 8 IEnMin= 8 EnMin= -78.5968746281882     IErMin= 8 ErrMin= 2.94D-05
 ErrMax= 2.94D-05 EMaxC= 1.00D-01 BMatC= 7.54D-08 BMatP= 7.57D-07
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.173D-03-0.668D-03-0.612D-02-0.837D-02 0.666D-01 0.331D-01
 Coeff-Com: -0.675D+00 0.159D+01
 Coeff:      0.173D-03-0.668D-03-0.612D-02-0.837D-02 0.666D-01 0.331D-01
 Coeff:     -0.675D+00 0.159D+01
 Gap=     0.604 Goal=   None    Shift=    0.000
 Gap=     0.667 Goal=   None    Shift=    0.000
 RMSDP=1.01D-05 MaxDP=8.06D-05 DE=-7.88D-07 OVMax= 1.76D-04

 Cycle   9  Pass 1  IDiag  1:
 E= -78.5968747015779     Delta-E=       -0.000000073390 Rises=F Damp=F
 DIIS: error= 7.23D-06 at cycle   9 NSaved=   9.
 NSaved= 9 IEnMin= 9 EnMin= -78.5968747015779     IErMin= 9 ErrMin= 7.23D-06
 ErrMax= 7.23D-06 EMaxC= 1.00D-01 BMatC= 9.58D-09 BMatP= 7.54D-08
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.127D-03 0.638D-03 0.499D-02-0.643D-03-0.401D-01 0.914D-02
 Coeff-Com:  0.354D+00-0.114D+01 0.181D+01
 Coeff:     -0.127D-03 0.638D-03 0.499D-02-0.643D-03-0.401D-01 0.914D-02
 Coeff:      0.354D+00-0.114D+01 0.181D+01
 Gap=     0.604 Goal=   None    Shift=    0.000
 Gap=     0.667 Goal=   None    Shift=    0.000
 RMSDP=3.98D-06 MaxDP=4.12D-05 DE=-7.34D-08 OVMax= 5.24D-05

 Cycle  10  Pass 1  IDiag  1:
 E= -78.5968747116883     Delta-E=       -0.000000010110 Rises=F Damp=F
 DIIS: error= 3.53D-06 at cycle  10 NSaved=  10.
 NSaved=10 IEnMin=10 EnMin= -78.5968747116883     IErMin=10 ErrMin= 3.53D-06
 ErrMax= 3.53D-06 EMaxC= 1.00D-01 BMatC= 1.07D-09 BMatP= 9.58D-09
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.736D-04-0.395D-03-0.302D-02 0.139D-02 0.225D-01-0.106D-01
 Coeff-Com: -0.189D+00 0.678D+00-0.138D+01 0.188D+01
 Coeff:      0.736D-04-0.395D-03-0.302D-02 0.139D-02 0.225D-01-0.106D-01
 Coeff:     -0.189D+00 0.678D+00-0.138D+01 0.188D+01
 Gap=     0.604 Goal=   None    Shift=    0.000
 Gap=     0.667 Goal=   None    Shift=    0.000
 RMSDP=1.56D-06 MaxDP=1.66D-05 DE=-1.01D-08 OVMax= 2.22D-05

 Cycle  11  Pass 1  IDiag  1:
 E= -78.5968747129300     Delta-E=       -0.000000001242 Rises=F Damp=F
 DIIS: error= 5.95D-07 at cycle  11 NSaved=  11.
 NSaved=11 IEnMin=11 EnMin= -78.5968747129300     IErMin=11 ErrMin= 5.95D-07
 ErrMax= 5.95D-07 EMaxC= 1.00D-01 BMatC= 5.11D-11 BMatP= 1.07D-09
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.178D-04 0.982D-04 0.746D-03-0.506D-03-0.519D-02 0.342D-02
 Coeff-Com:  0.408D-01-0.161D+00 0.363D+00-0.678D+00 0.144D+01
 Coeff:     -0.178D-04 0.982D-04 0.746D-03-0.506D-03-0.519D-02 0.342D-02
 Coeff:      0.408D-01-0.161D+00 0.363D+00-0.678D+00 0.144D+01
 Gap=     0.604 Goal=   None    Shift=    0.000
 Gap=     0.667 Goal=   None    Shift=    0.000
 RMSDP=3.01D-07 MaxDP=2.85D-06 DE=-1.24D-09 OVMax= 3.87D-06

 Cycle  12  Pass 1  IDiag  1:
 E= -78.5968747129798     Delta-E=       -0.000000000050 Rises=F Damp=F
 DIIS: error= 1.86D-07 at cycle  12 NSaved=  12.
 NSaved=12 IEnMin=12 EnMin= -78.5968747129798     IErMin=12 ErrMin= 1.86D-07
 ErrMax= 1.86D-07 EMaxC= 1.00D-01 BMatC= 4.61D-12 BMatP= 5.11D-11
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.517D-05-0.290D-04-0.219D-03 0.179D-03 0.142D-02-0.110D-02
 Coeff-Com: -0.107D-01 0.455D-01-0.111D+00 0.248D+00-0.776D+00 0.160D+01
 Coeff:      0.517D-05-0.290D-04-0.219D-03 0.179D-03 0.142D-02-0.110D-02
 Coeff:     -0.107D-01 0.455D-01-0.111D+00 0.248D+00-0.776D+00 0.160D+01
 Gap=     0.604 Goal=   None    Shift=    0.000
 Gap=     0.667 Goal=   None    Shift=    0.000
 RMSDP=7.60D-08 MaxDP=8.77D-07 DE=-4.98D-11 OVMax= 1.18D-06

 Cycle  13  Pass 1  IDiag  1:
 E= -78.5968747129840     Delta-E=       -0.000000000004 Rises=F Damp=F
 DIIS: error= 5.84D-08 at cycle  13 NSaved=  13.
 NSaved=13 IEnMin=13 EnMin= -78.5968747129840     IErMin=13 ErrMin= 5.84D-08
 ErrMax= 5.84D-08 EMaxC= 1.00D-01 BMatC= 4.13D-13 BMatP= 4.61D-12
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.163D-06-0.934D-06-0.591D-05-0.667D-05 0.941D-04-0.283D-04
 Coeff-Com: -0.718D-03 0.181D-02-0.181D-02-0.830D-02 0.102D+00-0.523D+00
 Coeff-Com:  0.143D+01
 Coeff:      0.163D-06-0.934D-06-0.591D-05-0.667D-05 0.941D-04-0.283D-04
 Coeff:     -0.718D-03 0.181D-02-0.181D-02-0.830D-02 0.102D+00-0.523D+00
 Coeff:      0.143D+01
 Gap=     0.604 Goal=   None    Shift=    0.000
 Gap=     0.667 Goal=   None    Shift=    0.000
 RMSDP=2.41D-08 MaxDP=2.96D-07 DE=-4.21D-12 OVMax= 3.93D-07

 Cycle  14  Pass 1  IDiag  1:
 E= -78.5968747129844     Delta-E=        0.000000000000 Rises=F Damp=F
 DIIS: error= 1.25D-08 at cycle  14 NSaved=  14.
 NSaved=14 IEnMin=14 EnMin= -78.5968747129844     IErMin=14 ErrMin= 1.25D-08
 ErrMax= 1.25D-08 EMaxC= 1.00D-01 BMatC= 2.81D-14 BMatP= 4.13D-13
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.520D-06 0.290D-05 0.216D-04-0.159D-04-0.150D-03 0.111D-03
 Coeff-Com:  0.112D-02-0.447D-02 0.104D-01-0.206D-01 0.504D-01-0.397D-01
 Coeff-Com: -0.319D+00 0.132D+01
 Coeff:     -0.520D-06 0.290D-05 0.216D-04-0.159D-04-0.150D-03 0.111D-03
 Coeff:      0.112D-02-0.447D-02 0.104D-01-0.206D-01 0.504D-01-0.397D-01
 Coeff:     -0.319D+00 0.132D+01
 Gap=     0.604 Goal=   None    Shift=    0.000
 Gap=     0.667 Goal=   None    Shift=    0.000
 RMSDP=7.01D-09 MaxDP=8.18D-08 DE=-3.69D-13 OVMax= 1.02D-07

 SCF Done:  E(UHF) =  -78.5968747130     A.U. after   14 cycles
             Convg  =    0.7014D-08             -V/T =  2.0004
 <Sx>= 0.0000 <Sy>= 0.0000 <Sz>= 0.5000 <S**2>= 0.7630 S= 0.5065
 <L.S>= 0.000000000000E+00
 KE= 7.856895578823D+01 PE=-2.564519734274D+02 EE= 6.231120382667D+01
 Annihilation of the first spin contaminant:
 S**2 before annihilation     0.7630,   after     0.7501
 Leave Link  502 at Thu Nov 05 16:53:38 2015, MaxMem=   33554432 cpu:       1.0
)";