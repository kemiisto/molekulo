std::string gaussian_scf_diis_test005 = R"(
 (Enter c:\g09w\l502.exe)
 Closed shell SCF:
 Requested convergence on RMS density matrix=1.00D-08 within 128 cycles.
 Requested convergence on MAX density matrix=1.00D-06.
 Requested convergence on             energy=1.00D-06.
 No special actions if energy rises.
 Using DIIS extrapolation, IDIIS=  1040.
 Unsorted integral processing.
 Integral symmetry usage will be decided dynamically.
 Two-electron integrals will be kept in memory, NGetB=      289067.
 IEnd=      289067 IEndB=      289067 NGot=    33554432 MDV=    33527509
 LenX=    33265365 LenY=    33543759

 Cycle   1  Pass 1  IDiag  1:
 E= -76.7159525365055    
 DIIS: error= 7.79D-02 at cycle   1 NSaved=   1.
 NSaved= 1 IEnMin= 1 EnMin= -76.7159525365055     IErMin= 1 ErrMin= 7.79D-02
 ErrMax= 7.79D-02 EMaxC= 1.00D-01 BMatC= 1.93D-01 BMatP= 1.93D-01
 IDIUse=3 WtCom= 2.21D-01 WtEn= 7.79D-01
 Coeff-Com:  0.100D+01
 Coeff-En:   0.100D+01
 Coeff:      0.100D+01
 Gap=     0.517 Goal=   None    Shift=    0.000
 GapD=    0.517 DampG=2.000 DampE=0.500 DampFc=1.0000 IDamp=-1.
 RMSDP=6.16D-03 MaxDP=8.50D-02              OVMax= 1.33D-01

 Cycle   2  Pass 1  IDiag  1:
 E= -76.8288683133668     Delta-E=       -0.112915776861 Rises=F Damp=F
 DIIS: error= 2.19D-02 at cycle   2 NSaved=   2.
 NSaved= 2 IEnMin= 2 EnMin= -76.8288683133668     IErMin= 2 ErrMin= 2.19D-02
 ErrMax= 2.19D-02 EMaxC= 1.00D-01 BMatC= 1.39D-02 BMatP= 1.93D-01
 IDIUse=3 WtCom= 7.81D-01 WtEn= 2.19D-01
 Coeff-Com:  0.151D+00 0.849D+00
 Coeff-En:   0.000D+00 0.100D+01
 Coeff:      0.118D+00 0.882D+00
 Gap=     0.601 Goal=   None    Shift=    0.000
 RMSDP=1.96D-03 MaxDP=2.85D-02 DE=-1.13D-01 OVMax= 3.79D-02

 Cycle   3  Pass 1  IDiag  1:
 E= -76.8407722569881     Delta-E=       -0.011903943621 Rises=F Damp=F
 DIIS: error= 4.75D-03 at cycle   3 NSaved=   3.
 NSaved= 3 IEnMin= 3 EnMin= -76.8407722569881     IErMin= 3 ErrMin= 4.75D-03
 ErrMax= 4.75D-03 EMaxC= 1.00D-01 BMatC= 4.54D-04 BMatP= 1.39D-02
 IDIUse=3 WtCom= 9.53D-01 WtEn= 4.75D-02
 Coeff-Com: -0.180D-01 0.114D+00 0.903D+00
 Coeff-En:   0.000D+00 0.000D+00 0.100D+01
 Coeff:     -0.171D-01 0.109D+00 0.908D+00
 Gap=     0.580 Goal=   None    Shift=    0.000
 RMSDP=3.26D-04 MaxDP=3.31D-03 DE=-1.19D-02 OVMax= 6.13D-03

 Cycle   4  Pass 1  IDiag  1:
 E= -76.8412101048244     Delta-E=       -0.000437847836 Rises=F Damp=F
 DIIS: error= 2.33D-04 at cycle   4 NSaved=   4.
 NSaved= 4 IEnMin= 4 EnMin= -76.8412101048244     IErMin= 4 ErrMin= 2.33D-04
 ErrMax= 2.33D-04 EMaxC= 1.00D-01 BMatC= 1.38D-06 BMatP= 4.54D-04
 IDIUse=3 WtCom= 9.98D-01 WtEn= 2.33D-03
 Coeff-Com:  0.239D-02-0.245D-01-0.147D+00 0.117D+01
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.100D+01
 Coeff:      0.238D-02-0.244D-01-0.147D+00 0.117D+01
 Gap=     0.580 Goal=   None    Shift=    0.000
 RMSDP=7.03D-05 MaxDP=1.22D-03 DE=-4.38D-04 OVMax= 4.77D-04

 Cycle   5  Pass 1  IDiag  1:
 E= -76.8412121344604     Delta-E=       -0.000002029636 Rises=F Damp=F
 DIIS: error= 3.07D-05 at cycle   5 NSaved=   5.
 NSaved= 5 IEnMin= 5 EnMin= -76.8412121344604     IErMin= 5 ErrMin= 3.07D-05
 ErrMax= 3.07D-05 EMaxC= 1.00D-01 BMatC= 2.63D-08 BMatP= 1.38D-06
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.199D-03 0.230D-02 0.153D-01-0.215D+00 0.120D+01
 Coeff:     -0.199D-03 0.230D-02 0.153D-01-0.215D+00 0.120D+01
 Gap=     0.580 Goal=   None    Shift=    0.000
 RMSDP=7.72D-06 MaxDP=1.28D-04 DE=-2.03D-06 OVMax= 9.58D-05

 Cycle   6  Pass 1  IDiag  1:
 E= -76.8412121775719     Delta-E=       -0.000000043111 Rises=F Damp=F
 DIIS: error= 3.49D-06 at cycle   6 NSaved=   6.
 NSaved= 6 IEnMin= 6 EnMin= -76.8412121775719     IErMin= 6 ErrMin= 3.49D-06
 ErrMax= 3.49D-06 EMaxC= 1.00D-01 BMatC= 2.45D-10 BMatP= 2.63D-08
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.546D-05 0.544D-04 0.207D-03 0.129D-01-0.170D+00 0.116D+01
 Coeff:     -0.546D-05 0.544D-04 0.207D-03 0.129D-01-0.170D+00 0.116D+01
 Gap=     0.580 Goal=   None    Shift=    0.000
 RMSDP=5.61D-07 MaxDP=4.91D-06 DE=-4.31D-08 OVMax= 1.05D-05

 Cycle   7  Pass 1  IDiag  1:
 E= -76.8412121779833     Delta-E=       -0.000000000411 Rises=F Damp=F
 DIIS: error= 3.46D-07 at cycle   7 NSaved=   7.
 NSaved= 7 IEnMin= 7 EnMin= -76.8412121779833     IErMin= 7 ErrMin= 3.46D-07
 ErrMax= 3.46D-07 EMaxC= 1.00D-01 BMatC= 2.76D-12 BMatP= 2.45D-10
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.586D-06-0.187D-04-0.117D-03 0.429D-03 0.951D-02-0.169D+00
 Coeff-Com:  0.116D+01
 Coeff:      0.586D-06-0.187D-04-0.117D-03 0.429D-03 0.951D-02-0.169D+00
 Coeff:      0.116D+01
 Gap=     0.580 Goal=   None    Shift=    0.000
 RMSDP=1.06D-07 MaxDP=1.62D-06 DE=-4.11D-10 OVMax= 1.03D-06

 Cycle   8  Pass 1  IDiag  1:
 E= -76.8412121779879     Delta-E=       -0.000000000005 Rises=F Damp=F
 DIIS: error= 1.78D-08 at cycle   8 NSaved=   8.
 NSaved= 8 IEnMin= 8 EnMin= -76.8412121779879     IErMin= 8 ErrMin= 1.78D-08
 ErrMax= 1.78D-08 EMaxC= 1.00D-01 BMatC= 9.15D-15 BMatP= 2.76D-12
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.230D-06 0.377D-05 0.245D-04-0.214D-03 0.117D-04 0.153D-01
 Coeff-Com: -0.151D+00 0.114D+01
 Coeff:     -0.230D-06 0.377D-05 0.245D-04-0.214D-03 0.117D-04 0.153D-01
 Coeff:     -0.151D+00 0.114D+01
 Gap=     0.580 Goal=   None    Shift=    0.000
 RMSDP=4.04D-09 MaxDP=6.04D-08 DE=-4.63D-12 OVMax= 5.04D-08

 SCF Done:  E(RHF) =  -76.8412121780     A.U. after    8 cycles
             Convg  =    0.4039D-08             -V/T =  2.0001
 KE= 7.683370366615D+01 PE=-2.291221812877D+02 EE= 5.037755117588D+01
 Leave Link  502 at Thu Nov 05 16:53:39 2015, MaxMem=   33554432 cpu:       0.0
)";