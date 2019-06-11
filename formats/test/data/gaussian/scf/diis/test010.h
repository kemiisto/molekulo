std::string gaussian_scf_diis_test010 = R"(
 (Enter c:\g09w\l502.exe)
 Closed shell SCF:
 Requested convergence on RMS density matrix=1.00D-08 within 128 cycles.
 Requested convergence on MAX density matrix=1.00D-06.
 Requested convergence on             energy=1.00D-06.
 No special actions if energy rises.
 Using DIIS extrapolation, IDIIS=  1040.
 Unsorted integral processing.
 Integral symmetry usage will be decided dynamically.
 Two-electron integrals will be kept in memory, NGetB=      150804.
 IEnd=      264773 IEndB=      150804 NGot=    33554432 MDV=    33534700
 LenX=    33272556 LenY=    33550921

 Cycle   1  Pass 1  IDiag  1:
 E= -74.9127604222906    
 DIIS: error= 7.48D-02 at cycle   1 NSaved=   1.
 NSaved= 1 IEnMin= 1 EnMin= -74.9127604222906     IErMin= 1 ErrMin= 7.48D-02
 ErrMax= 7.48D-02 EMaxC= 1.00D-01 BMatC= 3.75D-02 BMatP= 3.75D-02
 IDIUse=3 WtCom= 2.52D-01 WtEn= 7.48D-01
 Coeff-Com:  0.100D+01
 Coeff-En:   0.100D+01
 Coeff:      0.100D+01
 Gap=     0.897 Goal=   None    Shift=    0.000
 GapD=    0.897 DampG=2.000 DampE=0.500 DampFc=1.0000 IDamp=-1.
 RMSDP=4.00D-02 MaxDP=1.41D-01              OVMax= 0.00D+00

 Cycle   2  Pass 1  IDiag  1:
 E= -74.9630777284393     Delta-E=       -0.050317306149 Rises=F Damp=F
 DIIS: error= 6.06D-03 at cycle   2 NSaved=   2.
 NSaved= 2 IEnMin= 2 EnMin= -74.9630777284393     IErMin= 2 ErrMin= 6.06D-03
 ErrMax= 6.06D-03 EMaxC= 1.00D-01 BMatC= 3.72D-04 BMatP= 3.75D-02
 IDIUse=3 WtCom= 9.39D-01 WtEn= 6.06D-02
 Coeff-Com:  0.586D-01 0.941D+00
 Coeff-En:   0.000D+00 0.100D+01
 Coeff:      0.551D-01 0.945D+00
 Gap=     0.995 Goal=   None    Shift=    0.000
 RMSDP=2.82D-03 MaxDP=9.97D-03 DE=-5.03D-02 OVMax= 0.00D+00

 Cycle   3  Pass 1  IDiag  1:
 E= -74.9634538239620     Delta-E=       -0.000376095523 Rises=F Damp=F
 DIIS: error= 1.10D-03 at cycle   3 NSaved=   3.
 NSaved= 3 IEnMin= 3 EnMin= -74.9634538239620     IErMin= 3 ErrMin= 1.10D-03
 ErrMax= 1.10D-03 EMaxC= 1.00D-01 BMatC= 7.77D-06 BMatP= 3.72D-04
 IDIUse=3 WtCom= 9.89D-01 WtEn= 1.10D-02
 Coeff-Com: -0.112D-01-0.158D+00 0.117D+01
 Coeff-En:   0.000D+00 0.000D+00 0.100D+01
 Coeff:     -0.110D-01-0.156D+00 0.117D+01
 Gap=     0.995 Goal=   None    Shift=    0.000
 RMSDP=7.95D-04 MaxDP=3.43D-03 DE=-3.76D-04 OVMax= 0.00D+00

 Cycle   4  Pass 1  IDiag  1:
 E= -74.9634666597301     Delta-E=       -0.000012835768 Rises=F Damp=F
 DIIS: error= 1.60D-04 at cycle   4 NSaved=   4.
 NSaved= 4 IEnMin= 4 EnMin= -74.9634666597301     IErMin= 4 ErrMin= 1.60D-04
 ErrMax= 1.60D-04 EMaxC= 1.00D-01 BMatC= 2.01D-07 BMatP= 7.77D-06
 IDIUse=3 WtCom= 9.98D-01 WtEn= 1.60D-03
 Coeff-Com:  0.141D-02 0.108D-01-0.218D+00 0.121D+01
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.100D+01
 Coeff:      0.141D-02 0.107D-01-0.218D+00 0.121D+01
 Gap=     0.995 Goal=   None    Shift=    0.000
 RMSDP=1.69D-04 MaxDP=6.91D-04 DE=-1.28D-05 OVMax= 0.00D+00

 Cycle   5  Pass 1  IDiag  1:
 E= -74.9634671046978     Delta-E=       -0.000000444968 Rises=F Damp=F
 DIIS: error= 3.26D-05 at cycle   5 NSaved=   5.
 NSaved= 5 IEnMin= 5 EnMin= -74.9634671046978     IErMin= 5 ErrMin= 3.26D-05
 ErrMax= 3.26D-05 EMaxC= 1.00D-01 BMatC= 8.97D-09 BMatP= 2.01D-07
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.693D-03-0.476D-02 0.129D+00-0.826D+00 0.170D+01
 Coeff:     -0.693D-03-0.476D-02 0.129D+00-0.826D+00 0.170D+01
 Gap=     0.995 Goal=   None    Shift=    0.000
 RMSDP=4.86D-05 MaxDP=1.50D-04 DE=-4.45D-07 OVMax= 0.00D+00

 Cycle   6  Pass 1  IDiag  1:
 E= -74.9634671322859     Delta-E=       -0.000000027588 Rises=F Damp=F
 DIIS: error= 2.21D-07 at cycle   6 NSaved=   6.
 NSaved= 6 IEnMin= 6 EnMin= -74.9634671322859     IErMin= 6 ErrMin= 2.21D-07
 ErrMax= 2.21D-07 EMaxC= 1.00D-01 BMatC= 3.99D-13 BMatP= 8.97D-09
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.368D-07-0.155D-04 0.435D-03-0.306D-02 0.116D-01 0.991D+00
 Coeff:     -0.368D-07-0.155D-04 0.435D-03-0.306D-02 0.116D-01 0.991D+00
 Gap=     0.995 Goal=   None    Shift=    0.000
 RMSDP=2.62D-07 MaxDP=9.36D-07 DE=-2.76D-08 OVMax= 0.00D+00

 Cycle   7  Pass 1  IDiag  1:
 E= -74.9634671322869     Delta-E=       -0.000000000001 Rises=F Damp=F
 DIIS: error= 2.01D-10 at cycle   7 NSaved=   7.
 NSaved= 7 IEnMin= 7 EnMin= -74.9634671322869     IErMin= 7 ErrMin= 2.01D-10
 ErrMax= 2.01D-10 EMaxC= 1.00D-01 BMatC= 2.72D-19 BMatP= 3.99D-13
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.582D-10 0.710D-08 0.442D-06-0.476D-05 0.161D-04 0.139D-02
 Coeff-Com:  0.999D+00
 Coeff:      0.582D-10 0.710D-08 0.442D-06-0.476D-05 0.161D-04 0.139D-02
 Coeff:      0.999D+00
 Gap=     0.995 Goal=   None    Shift=    0.000
 RMSDP=2.11D-10 MaxDP=6.90D-10 DE=-9.38D-13 OVMax= 0.00D+00

 SCF Done:  E(RHF) =  -74.9634671323     A.U. after    7 cycles
             Convg  =    0.2112D-09             -V/T =  2.0051
 KE= 7.458240965248D+01 PE=-1.969053717141D+02 EE= 3.819011670457D+01
 Leave Link  502 at Thu Nov 05 16:53:45 2015, MaxMem=   33554432 cpu:       0.0
)";