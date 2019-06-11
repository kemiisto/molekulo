std::string gaussian_scf_diis_water_hf_nodiis = R"(
 (Enter c:\g09w\l502.exe)
 Closed shell SCF:
 Requested convergence on RMS density matrix=1.00D-08 within 128 cycles.
 Requested convergence on MAX density matrix=1.00D-06.
 Requested convergence on             energy=1.00D-06.
 No special actions if energy rises.
 Integral symmetry usage will be decided dynamically.
 Keep R1 ints in memory in canonical form, NReq=807239.
 IEnd=        3039 IEndB=        3039 NGot=    33554432 MDV=    33547641
 LenX=    33547641 LenY=    33547179
 Symmetry not used in FoFDir.
 MinBra= 0 MaxBra= 1 Meth= 1.
 IRaf=       0 NMat=   1 IRICut=       1 DoRegI=T DoRafI=F ISym2E= 0 JSym2E=0.

 Cycle   1  Pass 1  IDiag  1:
 E= -75.5170109481120    
 Gap=     0.631 Goal=   None    Shift=    0.000
 RMSDP=1.78D-02 MaxDP=8.02D-02              OVMax= 1.13D-01

 Cycle   2  Pass 1  IDiag  1:
 E= -75.5701757793356     Delta-E=       -0.053164831224 Rises=F Damp=F
 Gap=     0.782 Goal=   None    Shift=    0.000
 RMSDP=9.04D-03 MaxDP=4.89D-02 DE=-5.32D-02 OVMax= 3.72D-02

 Cycle   3  Pass 1  IDiag  1:
 E= -75.5818453955312     Delta-E=       -0.011669616196 Rises=F Damp=F
 Gap=     0.713 Goal=   None    Shift=    0.000
 RMSDP=4.61D-03 MaxDP=2.12D-02 DE=-1.17D-02 OVMax= 2.40D-02

 Cycle   4  Pass 1  IDiag  1:
 E= -75.5847998977749     Delta-E=       -0.002954502244 Rises=F Damp=F
 Gap=     0.752 Goal=   None    Shift=    0.000
 4-Point extrapolation.
 RMSDP=2.30D-03 MaxDP=1.21D-02 DE=-2.95D-03 OVMax= 1.07D-02

 Cycle   5  Pass 1  IDiag  1:
 E=   (Non-Variational)  
 Gap=     0.739 Goal=   None    Shift=    0.000
 RMSDP=2.30D-03 MaxDP=1.21D-02 DE=-6.59D-04 OVMax= 3.91D-03

 Cycle   6  Pass 1  IDiag  1:
 E= -75.5858096651021     Delta-E=       -0.001009767327 Rises=F Damp=F
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=3.53D-05 MaxDP=1.82D-04 DE=-1.01D-03 OVMax= 1.99D-04

 Cycle   7  Pass 1  IDiag  1:
 E= -75.5858099236921     Delta-E=       -0.000000258590 Rises=F Damp=F
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=1.78D-05 MaxDP=9.09D-05 DE=-2.59D-07 OVMax= 1.20D-04

 Cycle   8  Pass 1  IDiag  1:
 E= -75.5858099670474     Delta-E=       -0.000000043355 Rises=F Damp=F
 Gap=     0.740 Goal=   None    Shift=    0.000
 4-Point extrapolation.
 RMSDP=6.64D-06 MaxDP=3.19D-05 DE=-4.34D-08 OVMax= 3.76D-05

 Cycle   9  Pass 1  IDiag  1:
 E=   (Non-Variational)  
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=6.64D-06 MaxDP=3.19D-05 DE=-1.92D-08 OVMax= 5.42D-05

 Cycle  10  Pass 1  IDiag  1:
 E= -75.5858099750818     Delta-E=       -0.000000008034 Rises=F Damp=F
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=3.58D-06 MaxDP=1.50D-05 DE=-8.03D-09 OVMax= 1.81D-05

 Cycle  11  Pass 1  IDiag  1:
 E= -75.5858099767686     Delta-E=       -0.000000001687 Rises=F Damp=F
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=1.70D-06 MaxDP=9.36D-06 DE=-1.69D-09 OVMax= 8.04D-06

 Cycle  12  Pass 1  IDiag  1:
 E= -75.5858099771966     Delta-E=       -0.000000000428 Rises=F Damp=F
 Gap=     0.740 Goal=   None    Shift=    0.000
 4-Point extrapolation.
 RMSDP=9.07D-07 MaxDP=4.12D-06 DE=-4.28D-10 OVMax= 4.35D-06

 Cycle  13  Pass 1  IDiag  1:
 E=   (Non-Variational)  
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=9.07D-07 MaxDP=4.12D-06 DE=-9.61D-11 OVMax= 1.39D-06

 Cycle  14  Pass 1  IDiag  1:
 E= -75.5858099773432     Delta-E=       -0.000000000147 Rises=F Damp=F
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=2.53D-08 MaxDP=1.18D-07 DE=-1.47D-10 OVMax= 1.43D-07

 Cycle  15  Pass 1  IDiag  1:
 E= -75.5858099773434     Delta-E=        0.000000000000 Rises=F Damp=F
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=1.45D-08 MaxDP=7.82D-08 DE=-2.27D-13 OVMax= 9.90D-08

 Cycle  16  Pass 1  IDiag  1:
 E= -75.5858099773435     Delta-E=        0.000000000000 Rises=F Damp=F
 Gap=     0.740 Goal=   None    Shift=    0.000
 RMSDP=5.50D-09 MaxDP=2.40D-08 DE=-4.26D-14 OVMax= 2.87D-08

 SCF Done:  E(RHF) =  -75.5858099773     A.U. after   16 cycles
             Convg  =    0.5496D-08             -V/T =  2.0018
 KE= 7.544716213235D+01 PE=-1.980498358461D+02 EE= 3.785974774638D+01
 Leave Link  502 at Thu Nov 05 21:08:49 2015, MaxMem=   33554432 cpu:       0.0
)";
