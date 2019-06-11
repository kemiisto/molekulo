std::string gaussian_scf_diis_test009 = R"(
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
 E= -74.9104425342548    
 DIIS: error= 7.55D-02 at cycle   1 NSaved=   1.
 NSaved= 1 IEnMin= 1 EnMin= -74.9104425342548     IErMin= 1 ErrMin= 7.55D-02
 ErrMax= 7.55D-02 EMaxC= 1.00D-01 BMatC= 3.74D-02 BMatP= 3.74D-02
 IDIUse=3 WtCom= 2.45D-01 WtEn= 7.55D-01
 Coeff-Com:  0.100D+01
 Coeff-En:   0.100D+01
 Coeff:      0.100D+01
 Gap=     0.883 Goal=   None    Shift=    0.000
 GapD=    0.883 DampG=2.000 DampE=0.500 DampFc=1.0000 IDamp=-1.
 RMSDP=3.93D-02 MaxDP=1.40D-01              OVMax= 0.00D+00

 Cycle   2  Pass 1  IDiag  1:
 E= -74.9603587989136     Delta-E=       -0.049916264659 Rises=F Damp=F
 DIIS: error= 6.37D-03 at cycle   2 NSaved=   2.
 NSaved= 2 IEnMin= 2 EnMin= -74.9603587989136     IErMin= 2 ErrMin= 6.37D-03
 ErrMax= 6.37D-03 EMaxC= 1.00D-01 BMatC= 3.39D-04 BMatP= 3.74D-02
 IDIUse=3 WtCom= 9.36D-01 WtEn= 6.37D-02
 Coeff-Com:  0.499D-01 0.950D+00
 Coeff-En:   0.000D+00 0.100D+01
 Coeff:      0.467D-01 0.953D+00
 Gap=     0.980 Goal=   None    Shift=    0.000
 RMSDP=2.77D-03 MaxDP=1.16D-02 DE=-4.99D-02 OVMax= 0.00D+00

 Cycle   3  Pass 1  IDiag  1:
 E= -74.9607058086476     Delta-E=       -0.000347009734 Rises=F Damp=F
 DIIS: error= 1.21D-03 at cycle   3 NSaved=   3.
 NSaved= 3 IEnMin= 3 EnMin= -74.9607058086476     IErMin= 3 ErrMin= 1.21D-03
 ErrMax= 1.21D-03 EMaxC= 1.00D-01 BMatC= 9.58D-06 BMatP= 3.39D-04
 IDIUse=3 WtCom= 9.88D-01 WtEn= 1.21D-02
 Coeff-Com: -0.108D-01-0.181D+00 0.119D+01
 Coeff-En:   0.000D+00 0.000D+00 0.100D+01
 Coeff:     -0.106D-01-0.179D+00 0.119D+01
 Gap=     0.980 Goal=   None    Shift=    0.000
 RMSDP=9.31D-04 MaxDP=4.02D-03 DE=-3.47D-04 OVMax= 0.00D+00

 Cycle   4  Pass 1  IDiag  1:
 E= -74.9607225781491     Delta-E=       -0.000016769501 Rises=F Damp=F
 DIIS: error= 1.78D-04 at cycle   4 NSaved=   4.
 NSaved= 4 IEnMin= 4 EnMin= -74.9607225781491     IErMin= 4 ErrMin= 1.78D-04
 ErrMax= 1.78D-04 EMaxC= 1.00D-01 BMatC= 2.68D-07 BMatP= 9.58D-06
 IDIUse=3 WtCom= 9.98D-01 WtEn= 1.78D-03
 Coeff-Com:  0.155D-02 0.141D-01-0.229D+00 0.121D+01
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.100D+01
 Coeff:      0.155D-02 0.141D-01-0.229D+00 0.121D+01
 Gap=     0.980 Goal=   None    Shift=    0.000
 RMSDP=2.07D-04 MaxDP=8.17D-04 DE=-1.68D-05 OVMax= 0.00D+00

 Cycle   5  Pass 1  IDiag  1:
 E= -74.9607232306619     Delta-E=       -0.000000652513 Rises=F Damp=F
 DIIS: error= 4.20D-05 at cycle   5 NSaved=   5.
 NSaved= 5 IEnMin= 5 EnMin= -74.9607232306619     IErMin= 5 ErrMin= 4.20D-05
 ErrMax= 4.20D-05 EMaxC= 1.00D-01 BMatC= 1.44D-08 BMatP= 2.68D-07
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.626D-03-0.491D-02 0.120D+00-0.788D+00 0.167D+01
 Coeff:     -0.626D-03-0.491D-02 0.120D+00-0.788D+00 0.167D+01
 Gap=     0.980 Goal=   None    Shift=    0.000
 RMSDP=6.29D-05 MaxDP=1.92D-04 DE=-6.53D-07 OVMax= 0.00D+00

 Cycle   6  Pass 1  IDiag  1:
 E= -74.9607232756392     Delta-E=       -0.000000044977 Rises=F Damp=F
 DIIS: error= 2.22D-07 at cycle   6 NSaved=   6.
 NSaved= 6 IEnMin= 6 EnMin= -74.9607232756392     IErMin= 6 ErrMin= 2.22D-07
 ErrMax= 2.22D-07 EMaxC= 1.00D-01 BMatC= 3.84D-13 BMatP= 1.44D-08
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.234D-07-0.157D-04 0.397D-03-0.296D-02 0.107D-01 0.992D+00
 Coeff:     -0.234D-07-0.157D-04 0.397D-03-0.296D-02 0.107D-01 0.992D+00
 Gap=     0.980 Goal=   None    Shift=    0.000
 RMSDP=2.72D-07 MaxDP=9.46D-07 DE=-4.50D-08 OVMax= 0.00D+00

 Cycle   7  Pass 1  IDiag  1:
 E= -74.9607232756403     Delta-E=       -0.000000000001 Rises=F Damp=F
 DIIS: error= 2.23D-10 at cycle   7 NSaved=   7.
 NSaved= 7 IEnMin= 7 EnMin= -74.9607232756403     IErMin= 7 ErrMin= 2.23D-10
 ErrMax= 2.23D-10 EMaxC= 1.00D-01 BMatC= 3.31D-19 BMatP= 3.84D-13
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.778D-10 0.101D-07 0.405D-06-0.483D-05 0.167D-04 0.161D-02
 Coeff-Com:  0.998D+00
 Coeff:      0.778D-10 0.101D-07 0.405D-06-0.483D-05 0.167D-04 0.161D-02
 Coeff:      0.998D+00
 Gap=     0.980 Goal=   None    Shift=    0.000
 RMSDP=2.38D-10 MaxDP=7.50D-10 DE=-1.01D-12 OVMax= 0.00D+00

 SCF Done:  E(RHF) =  -74.9607232756     A.U. after    7 cycles
             Convg  =    0.2381D-09             -V/T =  2.0051
 KE= 7.458406050809D+01 PE=-1.969263791019D+02 EE= 3.822441940824D+01
 Leave Link  502 at Thu Nov 05 16:53:42 2015, MaxMem=   33554432 cpu:       0.0
)";