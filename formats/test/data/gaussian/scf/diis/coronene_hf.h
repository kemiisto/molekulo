std::string gaussian_scf_diis_coronene_hf = R"(
 (Enter c:\g09w\l502.exe)
 Closed shell SCF:
 Requested convergence on RMS density matrix=1.00D-08 within 128 cycles.
 Requested convergence on MAX density matrix=1.00D-06.
 Requested convergence on             energy=1.00D-06.
 No special actions if energy rises.
 Using DIIS extrapolation, IDIIS=  1040.
 Integral symmetry usage will be decided dynamically.
 IEnd=       72058 IEndB=       72058 NGot=    33554432 MDV=    33516571
 LenX=    33516571 LenY=    33498706
 Fock matrices will be formed incrementally for  20 cycles.
 Integral accuracy reduced to 1.0D-05 until final iterations.

 Cycle   1  Pass 0  IDiag  1:
 FoFCou: FMM=F IPFlag=           0 FMFlag=      100000 FMFlg1=           0
         NFxFlg=           0 DoJE=F BraDBF=F KetDBF=F FulRan=T
         Omega=  0.000000  0.000000  1.000000  0.000000  0.000000 ICntrl=       0 IOpCl=  0
         NMat0=    1 NMatS0=    1 NMatT0=    0 NMatD0=    1 NMtDS0=    0 NMtDT0=    0
         I1Cent=           0 NGrid=           0.
 Symmetry not used in FoFCou.
 E= -904.629006880920    
 DIIS: error= 5.84D-02 at cycle   1 NSaved=   1.
 NSaved= 1 IEnMin= 1 EnMin= -904.629006880920     IErMin= 1 ErrMin= 5.84D-02
 ErrMax= 5.84D-02 EMaxC= 1.00D-01 BMatC= 3.01D-01 BMatP= 3.01D-01
 IDIUse=3 WtCom= 4.16D-01 WtEn= 5.84D-01
 Coeff-Com:  0.100D+01
 Coeff-En:   0.100D+01
 Coeff:      0.100D+01
 Gap=     0.354 Goal=   None    Shift=    0.000
 GapD=    0.354 DampG=1.000 DampE=0.500 DampFc=0.5000 IDamp=-1.
 Damping current iteration by 5.00D-01
 RMSDP=3.87D-03 MaxDP=8.04D-02              OVMax= 0.00D+00

 Cycle   2  Pass 0  IDiag  1:
 RMSU=  1.37D-03    CP:  9.99D-01
 E= -904.718616198498     Delta-E=       -0.089609317578 Rises=F Damp=T
 DIIS: error= 3.09D-02 at cycle   2 NSaved=   2.
 NSaved= 2 IEnMin= 2 EnMin= -904.718616198498     IErMin= 2 ErrMin= 3.09D-02
 ErrMax= 3.09D-02 EMaxC= 1.00D-01 BMatC= 8.37D-02 BMatP= 3.01D-01
 IDIUse=3 WtCom= 6.91D-01 WtEn= 3.09D-01
 Coeff-Com: -0.110D+01 0.210D+01
 Coeff-En:   0.000D+00 0.100D+01
 Coeff:     -0.759D+00 0.176D+01
 Gap=     0.358 Goal=   None    Shift=    0.000
 RMSDP=2.09D-03 MaxDP=4.14D-02 DE=-8.96D-02 OVMax= 0.00D+00

 Cycle   3  Pass 0  IDiag  1:
 RMSU=  3.55D-04    CP:  9.98D-01  2.05D+00
 E= -904.814405084983     Delta-E=       -0.095788886485 Rises=F Damp=F
 DIIS: error= 2.72D-03 at cycle   3 NSaved=   3.
 NSaved= 3 IEnMin= 3 EnMin= -904.814405084983     IErMin= 3 ErrMin= 2.72D-03
 ErrMax= 2.72D-03 EMaxC= 1.00D-01 BMatC= 2.58D-04 BMatP= 8.37D-02
 IDIUse=3 WtCom= 9.73D-01 WtEn= 2.72D-02
 Coeff-Com: -0.118D+00 0.203D+00 0.915D+00
 Coeff-En:   0.000D+00 0.000D+00 0.100D+01
 Coeff:     -0.115D+00 0.198D+00 0.917D+00
 Gap=     0.360 Goal=   None    Shift=    0.000
 RMSDP=2.54D-04 MaxDP=3.46D-03 DE=-9.58D-02 OVMax= 0.00D+00

 Cycle   4  Pass 0  IDiag  1:
 RMSU=  1.70D-04    CP:  9.98D-01  2.09D+00  1.05D+00
 E= -904.814991783521     Delta-E=       -0.000586698538 Rises=F Damp=F
 DIIS: error= 1.27D-03 at cycle   4 NSaved=   4.
 NSaved= 4 IEnMin= 4 EnMin= -904.814991783521     IErMin= 4 ErrMin= 1.27D-03
 ErrMax= 1.27D-03 EMaxC= 1.00D-01 BMatC= 5.10D-05 BMatP= 2.58D-04
 IDIUse=3 WtCom= 9.87D-01 WtEn= 1.27D-02
 Coeff-Com:  0.138D+00-0.267D+00 0.145D+00 0.983D+00
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.100D+01
 Coeff:      0.136D+00-0.263D+00 0.144D+00 0.983D+00
 Gap=     0.361 Goal=   None    Shift=    0.000
 RMSDP=1.24D-04 MaxDP=2.23D-03 DE=-5.87D-04 OVMax= 0.00D+00

 Cycle   5  Pass 0  IDiag  1:
 RMSU=  4.14D-05    CP:  9.98D-01  2.10D+00  1.25D+00  1.14D+00
 E= -904.815147098348     Delta-E=       -0.000155314827 Rises=F Damp=F
 DIIS: error= 3.78D-04 at cycle   5 NSaved=   5.
 NSaved= 5 IEnMin= 5 EnMin= -904.815147098348     IErMin= 5 ErrMin= 3.78D-04
 ErrMax= 3.78D-04 EMaxC= 1.00D-01 BMatC= 4.63D-06 BMatP= 5.10D-05
 IDIUse=3 WtCom= 9.96D-01 WtEn= 3.78D-03
 Coeff-Com:  0.330D-02-0.419D-02-0.965D-01-0.653D-01 0.116D+01
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.000D+00 0.100D+01
 Coeff:      0.328D-02-0.417D-02-0.961D-01-0.650D-01 0.116D+01
 Gap=     0.362 Goal=   None    Shift=    0.000
 RMSDP=5.88D-05 MaxDP=1.24D-03 DE=-1.55D-04 OVMax= 0.00D+00

 Cycle   6  Pass 0  IDiag  1:
 RMSU=  1.48D-05    CP:  9.98D-01  2.11D+00  1.31D+00  1.30D+00  1.41D+00
 E= -904.815172361011     Delta-E=       -0.000025262664 Rises=F Damp=F
 DIIS: error= 1.28D-04 at cycle   6 NSaved=   6.
 NSaved= 6 IEnMin= 6 EnMin= -904.815172361011     IErMin= 6 ErrMin= 1.28D-04
 ErrMax= 1.28D-04 EMaxC= 1.00D-01 BMatC= 5.52D-07 BMatP= 4.63D-06
 IDIUse=3 WtCom= 9.99D-01 WtEn= 1.28D-03
 Coeff-Com: -0.233D-01 0.448D-01-0.230D-01-0.157D+00 0.188D-02 0.116D+01
 Coeff-En:   0.000D+00 0.000D+00 0.000D+00 0.000D+00 0.000D+00 0.100D+01
 Coeff:     -0.232D-01 0.448D-01-0.230D-01-0.157D+00 0.188D-02 0.116D+01
 Gap=     0.362 Goal=   None    Shift=    0.000
 RMSDP=2.40D-05 MaxDP=5.16D-04 DE=-2.53D-05 OVMax= 0.00D+00

 Cycle   7  Pass 0  IDiag  1:
 RMSU=  1.92D-06    CP:  9.98D-01  2.11D+00  1.33D+00  1.36D+00  1.68D+00
                    CP:  1.17D+00
 E= -904.815176045933     Delta-E=       -0.000003684921 Rises=F Damp=F
 DIIS: error= 1.68D-05 at cycle   7 NSaved=   7.
 NSaved= 7 IEnMin= 7 EnMin= -904.815176045933     IErMin= 7 ErrMin= 1.68D-05
 ErrMax= 1.68D-05 EMaxC= 1.00D-01 BMatC= 1.05D-08 BMatP= 5.52D-07
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.135D-02-0.270D-02 0.670D-02 0.144D-01-0.664D-01-0.768D-01
 Coeff-Com:  0.112D+01
 Coeff:      0.135D-02-0.270D-02 0.670D-02 0.144D-01-0.664D-01-0.768D-01
 Coeff:      0.112D+01
 Gap=     0.362 Goal=   None    Shift=    0.000
 RMSDP=3.21D-06 MaxDP=6.77D-05 DE=-3.68D-06 OVMax= 0.00D+00

 Initial convergence to 1.0D-05 achieved.  Increase integral accuracy.
 Cycle   8  Pass 1  IDiag  1:
 E= -904.815192237424     Delta-E=       -0.000016191491 Rises=F Damp=F
 DIIS: error= 9.88D-06 at cycle   1 NSaved=   1.
 NSaved= 1 IEnMin= 1 EnMin= -904.815192237424     IErMin= 1 ErrMin= 9.88D-06
 ErrMax= 9.88D-06 EMaxC= 1.00D-01 BMatC= 5.07D-09 BMatP= 5.07D-09
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.100D+01
 Coeff:      0.100D+01
 Gap=     0.362 Goal=   None    Shift=    0.000
 RMSDP=3.21D-06 MaxDP=6.77D-05 DE=-1.62D-05 OVMax= 0.00D+00

 Cycle   9  Pass 1  IDiag  1:
 RMSU=  6.01D-07    CP:  1.00D+00
 E= -904.815192245049     Delta-E=       -0.000000007625 Rises=F Damp=F
 DIIS: error= 1.00D-06 at cycle   2 NSaved=   2.
 NSaved= 2 IEnMin= 2 EnMin= -904.815192245049     IErMin= 2 ErrMin= 1.00D-06
 ErrMax= 1.00D-06 EMaxC= 1.00D-01 BMatC= 5.35D-11 BMatP= 5.07D-09
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.690D-01 0.107D+01
 Coeff:     -0.690D-01 0.107D+01
 Gap=     0.362 Goal=   None    Shift=    0.000
 RMSDP=1.31D-07 MaxDP=2.30D-06 DE=-7.62D-09 OVMax= 0.00D+00

 Cycle  10  Pass 1  IDiag  1:
 RMSU=  7.71D-08    CP:  1.00D+00  1.09D+00
 E= -904.815192245232     Delta-E=       -0.000000000183 Rises=F Damp=F
 DIIS: error= 3.70D-07 at cycle   3 NSaved=   3.
 NSaved= 3 IEnMin= 3 EnMin= -904.815192245232     IErMin= 3 ErrMin= 3.70D-07
 ErrMax= 3.70D-07 EMaxC= 1.00D-01 BMatC= 2.12D-11 BMatP= 5.35D-11
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.378D-01 0.459D+00 0.579D+00
 Coeff:     -0.378D-01 0.459D+00 0.579D+00
 Gap=     0.362 Goal=   None    Shift=    0.000
 RMSDP=4.10D-08 MaxDP=6.59D-07 DE=-1.83D-10 OVMax= 0.00D+00

 Cycle  11  Pass 1  IDiag  1:
 RMSU=  2.17D-08    CP:  1.00D+00  1.10D+00  7.62D-01
 E= -904.815192245423     Delta-E=       -0.000000000191 Rises=F Damp=F
 DIIS: error= 1.34D-07 at cycle   4 NSaved=   4.
 NSaved= 4 IEnMin= 4 EnMin= -904.815192245423     IErMin= 4 ErrMin= 1.34D-07
 ErrMax= 1.34D-07 EMaxC= 1.00D-01 BMatC= 1.03D-12 BMatP= 2.12D-11
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.144D-01-0.203D+00-0.315D+00 0.150D+01
 Coeff:      0.144D-01-0.203D+00-0.315D+00 0.150D+01
 Gap=     0.362 Goal=   None    Shift=    0.000
 RMSDP=2.31D-08 MaxDP=2.89D-07 DE=-1.91D-10 OVMax= 0.00D+00

 Cycle  12  Pass 1  IDiag  1:
 RMSU=  4.57D-09    CP:  1.00D+00  1.10D+00  8.65D-01  1.61D+00
 E= -904.815192245431     Delta-E=       -0.000000000008 Rises=F Damp=F
 DIIS: error= 2.18D-08 at cycle   5 NSaved=   5.
 NSaved= 5 IEnMin= 5 EnMin= -904.815192245431     IErMin= 5 ErrMin= 2.18D-08
 ErrMax= 2.18D-08 EMaxC= 1.00D-01 BMatC= 6.06D-14 BMatP= 1.03D-12
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.189D-03 0.124D-02-0.357D-01-0.873D-01 0.112D+01
 Coeff:      0.189D-03 0.124D-02-0.357D-01-0.873D-01 0.112D+01
 Gap=     0.362 Goal=   None    Shift=    0.000
 RMSDP=4.60D-09 MaxDP=6.79D-08 DE=-8.19D-12 OVMax= 0.00D+00

 SCF Done:  E(RHF) =  -904.815192245     A.U. after   12 cycles
             Convg  =    0.4599D-08             -V/T =  2.0093
 KE= 8.964687340196D+02 PE=-5.774014759237D+03 EE= 2.140055590111D+03
 Leave Link  502 at Wed Mar 19 19:03:12 2014, MaxMem=   33554432 cpu:      25.0
)";
