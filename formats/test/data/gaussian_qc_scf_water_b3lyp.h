std::string gaussian_qc_scf_cycles_water_b3lyp = R"(
 (Enter c:\g09w\l508.exe)
 Direct SCF.
 Tight linear equation convergence will be used.
 RB3LYP wavefunction.
 Quadratic Convergence SCF Method.
 Line search only if initial step raises energy.
 Integral symmetry usage will be decided dynamically.
 ReadGW:  IGet=1 IStart=           2 Next=       23754 LGW=       23752.
 Pruned (  75, 302) grid will be used in CalDFT.
 Keep R1 ints in memory in canonical form, NReq=884065.
 Symmetry not used in FoFDir.
 MinBra= 0 MaxBra= 1 Meth= 1.
 IRaf=       0 NMat=   1 IRICut=       1 DoRegI=T DoRafI=F ISym2E= 0 JSym2E=0.
 Iteration   1 EE= -75.9104461620061                                    Grad=4.126D-01
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-7.591044616201D+01 DE= 0.00D+00
     ILin= 2 X=3.000D-01 Y=-7.596499356582D+01 DE=-5.45D-02
     ILin= 3 X=4.243D-01 Y=-7.597098733895D+01 DE=-6.05D-02
     ILin= 4 X=6.000D-01 Y=-7.596248571654D+01 DE=-5.20D-02
     An  expanding polynomial of degree  4 produced  0.4374
 Iteration   2 EE= -75.9710420695432     Delta-E=       -0.060595907537 Grad=4.519D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-7.597104206954D+01 DE= 0.00D+00
     ILin= 2 X=4.374D-01 Y=-7.597135856919D+01 DE=-3.16D-04
     ILin= 3 X=6.186D-01 Y=-7.597143554023D+01 DE=-3.93D-04
     ILin= 4 X=8.749D-01 Y=-7.597149027078D+01 DE=-4.48D-04
     ILin= 5 X=1.237D+00 Y=-7.597145943604D+01 DE=-4.17D-04
     An  expanding polynomial of degree  5 produced  0.9680
 Iteration   3 EE= -75.9714944525492     Delta-E=       -0.000452383006 Grad=4.341D-03
 QCNR:  CnvC1=1.00D-09 CnvC2=1.00D-08
 LinEq1:  Iter=  0 NonCon=     1 RMS=3.88D-04 Max=1.87D-03
 AX will form     1 AO Fock derivatives at one time.
 LinEq1:  Iter=  1 NonCon=     1 RMS=2.17D-04 Max=1.15D-03
 LinEq1:  Iter=  2 NonCon=     1 RMS=1.59D-05 Max=6.59D-05
 LinEq1:  Iter=  3 NonCon=     1 RMS=1.19D-06 Max=3.62D-06
 LinEq1:  Iter=  4 NonCon=     1 RMS=2.92D-08 Max=9.22D-08
 LinEq1:  Iter=  5 NonCon=     1 RMS=1.08D-09 Max=3.53D-09
 LinEq1:  Iter=  6 NonCon=     0 RMS=2.84D-11 Max=1.10D-10
 Linear equations converged to 1.000D-09 1.000D-08 after     6 iterations.
 Angle between quadratic step and gradient=  36.34 degrees.
     ILin= 1 X=0.000D+00 Y=-7.597149445255D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-7.597150186463D+01 DE=-7.41D-06
     ILin= 3 X=1.414D+00 Y=-7.597150059187D+01 DE=-6.14D-06
     An  expanding polynomial of degree  3 produced  0.9999
 Iteration   4 EE= -75.9715018646291     Delta-E=       -0.000007412080 Grad=1.980D-06
 QCNR:  CnvC1=1.98D-11 CnvC2=1.98D-10
 LinEq1:  Iter=  0 NonCon=     1 RMS=2.27D-07 Max=1.23D-06
 LinEq1:  Iter=  1 NonCon=     1 RMS=8.42D-08 Max=4.02D-07
 LinEq1:  Iter=  2 NonCon=     1 RMS=1.58D-08 Max=7.57D-08
 LinEq1:  Iter=  3 NonCon=     1 RMS=1.03D-09 Max=5.06D-09
 LinEq1:  Iter=  4 NonCon=     1 RMS=6.70D-11 Max=2.36D-10
 LinEq1:  Iter=  5 NonCon=     0 RMS=1.77D-12 Max=7.12D-12
 Linear equations converged to 1.980D-11 1.980D-10 after     5 iterations.
 Angle between quadratic step and gradient=  42.81 degrees.
     ILin= 1 X=0.000D+00 Y=-7.597150186463D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-7.597150186463D+01 DE=-2.98D-12
 Iteration   5 EE= -75.9715018646321     Delta-E=       -0.000000000003 Grad=2.728D-11
 Rotation gradient small -- convergence achieved.
 Orbital symmetries in SymMO:
    1=1    2=1    3=4    4=1    5=3    6=1    7=4    8=4    9=1   10=3
   11=1   12=4   13=1
 SCF Done:  E(RB3LYP) =  -75.9715018646     a.u. after    5 cycles
)";
