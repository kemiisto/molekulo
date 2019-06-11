std::string gaussian_scf_diis_water_b3lyp = R"(
 (Enter c:\g09w\l502.exe)
 Closed shell SCF:
 Requested convergence on RMS density matrix=1.00D-08 within 128 cycles.
 Requested convergence on MAX density matrix=1.00D-06.
 Requested convergence on             energy=1.00D-06.
 No special actions if energy rises.
 Using DIIS extrapolation, IDIIS=  1040.
 Integral symmetry usage will be decided dynamically.
        23752 words used for storage of precomputed grid.
 Keep R1 ints in memory in canonical form, NReq=902311.
 IEnd=       43482 IEndB=       43482 NGot=    33554432 MDV=    33523839
 LenX=    33523839 LenY=    33522957
 Symmetry not used in FoFDir.
 MinBra= 0 MaxBra= 1 Meth= 1.
 IRaf=       0 NMat=   1 IRICut=       1 DoRegI=T DoRafI=F ISym2E= 0 JSym2E=0.
 Integral accuracy reduced to 1.0D-05 until final iterations.

 Cycle   1  Pass 0  IDiag  1:
 E= -75.9104639122239    
 DIIS: error= 8.43D-02 at cycle   1 NSaved=   1.
 NSaved= 1 IEnMin= 1 EnMin= -75.9104639122239     IErMin= 1 ErrMin= 8.43D-02
 ErrMax= 8.43D-02 EMaxC= 1.00D-01 BMatC= 8.51D-02 BMatP= 8.51D-02
 IDIUse=3 WtCom= 1.57D-01 WtEn= 8.43D-01
 Coeff-Com:  0.100D+01
 Coeff-En:   0.100D+01
 Coeff:      0.100D+01
 Gap=     0.236 Goal=   None    Shift=    0.000
 GapD=    0.236 DampG=1.000 DampE=0.500 DampFc=0.5000 IDamp=-1.
 Damping current iteration by 5.00D-01
 RMSDP=3.26D-02 MaxDP=1.23D-01              OVMax= 1.84D-01

 Cycle   2  Pass 0  IDiag  1:
 E= -75.9366483877627     Delta-E=       -0.026184475539 Rises=F Damp=T
 DIIS: error= 1.26D-02 at cycle   2 NSaved=   2.
 NSaved= 2 IEnMin= 2 EnMin= -75.9366483877627     IErMin= 2 ErrMin= 1.26D-02
 ErrMax= 1.26D-02 EMaxC= 1.00D-01 BMatC= 2.66D-03 BMatP= 8.51D-02
 IDIUse=3 WtCom= 8.74D-01 WtEn= 1.26D-01
 Coeff-Com:  0.122D+00 0.878D+00
 Coeff-En:   0.176D+00 0.824D+00
 Coeff:      0.129D+00 0.871D+00
 Gap=     0.345 Goal=   None    Shift=    0.000
 RMSDP=2.73D-03 MaxDP=1.61D-02 DE=-2.62D-02 OVMax= 8.59D-02

 Cycle   3  Pass 0  IDiag  1:
 E= -75.9714625981312     Delta-E=       -0.034814210369 Rises=F Damp=F
 DIIS: error= 2.51D-03 at cycle   3 NSaved=   3.
 NSaved= 3 IEnMin= 3 EnMin= -75.9714625981312     IErMin= 3 ErrMin= 2.51D-03
 ErrMax= 2.51D-03 EMaxC= 1.00D-01 BMatC= 9.53D-05 BMatP= 2.66D-03
 IDIUse=3 WtCom= 9.75D-01 WtEn= 2.51D-02
 Coeff-Com:  0.266D-01-0.529D-01 0.103D+01
 Coeff-En:   0.000D+00 0.000D+00 0.100D+01
 Coeff:      0.260D-01-0.516D-01 0.103D+01
 Gap=     0.356 Goal=   None    Shift=    0.000
 RMSDP=4.25D-04 MaxDP=2.37D-03 DE=-3.48D-02 OVMax= 1.90D-03

 Cycle   4  Pass 0  IDiag  1:
 E= -75.9715207604717     Delta-E=       -0.000058162341 Rises=F Damp=F
 DIIS: error= 6.38D-05 at cycle   4 NSaved=   4.
 NSaved= 4 IEnMin= 4 EnMin= -75.9715207604717     IErMin= 4 ErrMin= 6.38D-05
 ErrMax= 6.38D-05 EMaxC= 1.00D-01 BMatC= 4.34D-08 BMatP= 9.53D-05
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.797D-03-0.236D-02 0.155D-01 0.986D+00
 Coeff:      0.797D-03-0.236D-02 0.155D-01 0.986D+00
 Gap=     0.356 Goal=   None    Shift=    0.000
 RMSDP=9.94D-06 MaxDP=5.46D-05 DE=-5.82D-05 OVMax= 4.79D-05

 Initial convergence to 1.0D-05 achieved.  Increase integral accuracy.
 Cycle   5  Pass 1  IDiag  1:
 E= -75.9715018643415     Delta-E=        0.000018896130 Rises=F Damp=F
 DIIS: error= 5.40D-06 at cycle   1 NSaved=   1.
 NSaved= 1 IEnMin= 1 EnMin= -75.9715018643415     IErMin= 1 ErrMin= 5.40D-06
 ErrMax= 5.40D-06 EMaxC= 1.00D-01 BMatC= 4.69D-10 BMatP= 4.69D-10
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.100D+01
 Coeff:      0.100D+01
 Gap=     0.356 Goal=   None    Shift=    0.000
 RMSDP=9.94D-06 MaxDP=5.46D-05 DE= 1.89D-05 OVMax= 9.51D-06

 Cycle   6  Pass 1  IDiag  1:
 E= -75.9715018643321     Delta-E=        0.000000000009 Rises=F Damp=F
 DIIS: error= 5.60D-06 at cycle   2 NSaved=   2.
 NSaved= 2 IEnMin= 1 EnMin= -75.9715018643415     IErMin= 1 ErrMin= 5.40D-06
 ErrMax= 5.60D-06 EMaxC= 1.00D-01 BMatC= 4.71D-10 BMatP= 4.69D-10
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com:  0.501D+00 0.499D+00
 Coeff:      0.501D+00 0.499D+00
 Gap=     0.356 Goal=   None    Shift=    0.000
 RMSDP=1.06D-06 MaxDP=4.05D-06 DE= 9.35D-12 OVMax= 5.69D-06

 Cycle   7  Pass 1  IDiag  1:
 E= -75.9715018646264     Delta-E=       -0.000000000294 Rises=F Damp=F
 DIIS: error= 6.25D-07 at cycle   3 NSaved=   3.
 NSaved= 3 IEnMin= 3 EnMin= -75.9715018646264     IErMin= 3 ErrMin= 6.25D-07
 ErrMax= 6.25D-07 EMaxC= 1.00D-01 BMatC= 6.38D-12 BMatP= 4.69D-10
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.769D-02 0.996D-01 0.908D+00
 Coeff:     -0.769D-02 0.996D-01 0.908D+00
 Gap=     0.356 Goal=   None    Shift=    0.000
 RMSDP=9.52D-08 MaxDP=4.29D-07 DE=-2.94D-10 OVMax= 5.49D-07

 Cycle   8  Pass 1  IDiag  1:
 E= -75.9715018646305     Delta-E=       -0.000000000004 Rises=F Damp=F
 DIIS: error= 1.14D-08 at cycle   4 NSaved=   4.
 NSaved= 4 IEnMin= 4 EnMin= -75.9715018646305     IErMin= 4 ErrMin= 1.14D-08
 ErrMax= 1.14D-08 EMaxC= 1.00D-01 BMatC= 1.80D-15 BMatP= 6.38D-12
 IDIUse=1 WtCom= 1.00D+00 WtEn= 0.00D+00
 Coeff-Com: -0.775D-03 0.196D-02 0.685D-02 0.992D+00
 Coeff:     -0.775D-03 0.196D-02 0.685D-02 0.992D+00
 Gap=     0.356 Goal=   None    Shift=    0.000
 RMSDP=2.45D-09 MaxDP=1.06D-08 DE=-4.09D-12 OVMax= 1.83D-08

 SCF Done:  E(RB3LYP) =  -75.9715018646     A.U. after    8 cycles
             Convg  =    0.2450D-08             -V/T =  2.0056
 KE= 7.554600600222D+01 PE=-1.982527039602D+02 EE= 3.757808010340D+01
 Leave Link  502 at Mon Nov 02 21:04:58 2015, MaxMem=   33554432 cpu:       0.0
)";
