std::string gaussian_scf_diis_test001 = R"(
 (Enter c:\g09w\l502.exe)
 Complex closed shell SCF:
 Requested convergence on RMS density matrix=1.00D-08 within 128 cycles.
 Requested convergence on MAX density matrix=1.00D-06.
 Requested convergence on             energy=1.00D-06.
 No special actions if energy rises.
 Using DIIS extrapolation, IDIIS=  1040.
 Integral symmetry usage will be decided dynamically.
 Keep R1 and R3 ints in memory in canonical form, NReq=824394.
 IEnd=       21293 IEndB=       21293 NGot=    33554432 MDV=    33547596
 LenX=    33547596 LenY=    33546273
 Symmetry not used in FoFDir.
 MinBra= 0 MaxBra= 1 Meth= 1.
 IRaf=       0 NMat=   1 IRICut=       1 DoRegI=T DoRafI=F ISym2E= 0 JSym2E=0.
 An orbital has undefined symmetry, so N**3 symmetry is turned off.

 Cycle   1  Pass 1  IDiag  1:
 Density matrix breaks symmetry, PCut= 1.00D-04
 Density matrix has no symmetry -- integrals replicated.
 E= -147.577024369843    
 DIIS: error= 2.69D-02 at cycle   1 NSaved=   1.
 NSaved= 1 IEnMin= 1 EnMin= -147.577024369843     IErMin= 1 ErrMin= 2.69D-02
 ErrMax= 2.69D-02 EMaxC= 1.00D-01 BMatC= 7.12D-03 BMatP= 7.12D-03
 IDIUse=3 WtCom= 7.31D-01 WtEn= 2.69D-01
 Coeff-Com:  0.100D+01
 Coeff-En:   0.100D+01
 Coeff:      0.100D+01
 Gap=     0.572 Goal=   None    Shift=    0.000
 GapD=    0.572 DampG=2.000 DampE=0.500 DampFc=1.0000 IDamp=-1.
 RMSDP=4.50D-03 MaxDP=1.44D-02              OVMax= 0.00D+00

 Cycle   2  Pass 1  IDiag  1:
 Density matrix breaks symmetry, PCut= 1.00D-07
 Density matrix has no symmetry -- integrals replicated.
 E= -147.578440324672     Delta-E=       -0.001415954830 Rises=F Damp=F
 DIIS: error= 3.59D-03 at cycle   2 NSaved=   2.
 NSaved= 2 IEnMin= 2 EnMin= -147.578440324672     IErMin= 2 ErrMin= 3.59D-03
 ErrMax= 3.59D-03 EMaxC= 1.00D-01 BMatC= 1.12D-04 BMatP= 7.12D-03
 IDIUse=3 WtCom= 9.64D-01 WtEn= 3.59D-02
 Coeff-Com: -0.105D+00 0.110D+01
 Coeff-En:   0.000D+00 0.100D+01
 Coeff:     -0.101D+00 0.110D+01
 Gap=     0.572 Goal=   None    Shift=    0.000
 RMSDP=1.17D-03 MaxDP=3.81D-03 DE=-1.42D-03 OVMax= 0.00D+00

 Cycle   3  Pass 1  IDiag  1:
 Density matrix breaks symmetry, PCut= 1.00D-07
 Density matrix has no symmetry -- integrals replicated.
 E= -147.578509304061     Delta-E=       -0.000068979389 Rises=F Damp=F
 DIIS: error= 4.50D-04 at cycle   3 NSaved=   3.
 NSaved= 3 IEnMin= 3 EnMin= -147.578509304061     IErMin= 3 ErrMin= 4.50D-04
 ErrMax= 4.50D-04 EMaxC= 1.00D-01 BMatC= 2.30D-06 BMatP= 1.12D-04
 IDIUse=3 WtCom= 9.95D-01 WtEn= 4.50D-03
 Coeff-Com:  0.120D-01-0.244D+00 0.123D+01
 Coeff-En:   0.000D+00 0.000D+00 0.100D+01
 Coeff:      0.119D-01-0.243D+00 0.123D+01
 Gap=     0.572 Goal=   None    Shift=    0.000
 RMSDP=2.17D-04 MaxDP=7.10D-04 DE=-6.90D-05 OVMax= 0.00D+00

 Cycle   4  Pass 1  IDiag  1:
 Density matrix breaks symmetry, PCut= 1.00D-07
 Density matrix has no symmetry -- integrals replicated.
 E= -147.578511032137     Delta-E=       -0.000001728076 Rises=F Damp=F
 DIIS: error= 4.98D-07 at cycle   4 NSaved=   4.
 NSaved= 4 IEnMin= 4 EnMin= -147.578511032137     IErMin= 4 ErrMin= 4.98D-07
 ErrMax= 4.98D-07 EMaxC= 1.00D-01 BMatC= 2.57D-12 BMatP= 2.30D-06
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.878D-06-0.556D-04-0.717D-03 0.100D+01
 Coeff:      0.878D-06-0.556D-04-0.717D-03 0.100D+01
 Gap=     0.572 Goal=   None    Shift=    0.000
 RMSDP=2.27D-07 MaxDP=7.43D-07 DE=-1.73D-06 OVMax= 0.00D+00

 Cycle   5  Pass 1  IDiag  1:
 Density matrix breaks symmetry, PCut= 1.00D-07
 Density matrix has no symmetry -- integrals replicated.
 E= -147.578511032139     Delta-E=       -0.000000000002 Rises=F Damp=F
 DIIS: error= 6.75D-11 at cycle   5 NSaved=   5.
 NSaved= 5 IEnMin= 5 EnMin= -147.578511032139     IErMin= 5 ErrMin= 6.75D-11
 ErrMax= 6.75D-11 EMaxC= 1.00D-01 BMatC= 6.25D-20 BMatP= 2.57D-12
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Large coefficients: NSaved=  5 BigCof=    0.00 CofMax=   10.00 Det= 8.38D-28
 Inversion failed.  Reducing to  4 matrices.
 Coeff-Com: -0.535D-08 0.754D-06-0.534D-03 0.100D+01
 Coeff:     -0.535D-08 0.754D-06-0.534D-03 0.100D+01
 Gap=     0.572 Goal=   None    Shift=    0.000
 RMSDP=3.50D-11 MaxDP=1.15D-10 DE=-1.93D-12 OVMax= 0.00D+00

 Density matrix breaks symmetry, PCut= 1.00D-07
 Density matrix has no symmetry -- integrals replicated.
 SCF Done:  E(CRHF) =  -147.578511032     A.U. after    5 cycles
             Convg  =    0.3498D-10             -V/T =  2.0109
 KE= 1.459836914369D+02 PE=-4.057231402774D+02 EE= 8.440082194797D+01
 Leave Link  502 at Thu Nov 05 16:53:20 2015, MaxMem=   33554432 cpu:       0.0
)";