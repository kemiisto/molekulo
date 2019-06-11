std::string gaussian_scf_qc_test131 = R"(
 (Enter c:\g09w\l508.exe)
 Direct SCF.
 Tight linear equation convergence will be used.
 UHF wavefunction.
 Quadratic Convergence SCF Method.
 Line search only if initial step raises energy.
 Two-electron integral symmetry not used.
 ReadGW:  IGet=1 IStart=           2 Next=           2 LGW=           0.
 FoFCou: FMM=F IPFlag=           0 FMFlag=      100000 FMFlg1=           0
         NFxFlg=           0 DoJE=F BraDBF=F KetDBF=F FulRan=T
         Omega=  0.000000  0.000000  1.000000  0.000000  0.000000 ICntrl=       0 IOpCl=  1
         NMat0=    1 NMatS0=    1 NMatT0=    0 NMatD0=    1 NMtDS0=    0 NMtDT0=    0
         I1Cent=           0 NGrid=           0.
 Symmetry not used in FoFCou.
 Iteration   1 EE= -38.6838836361115                                    Grad=2.307D-01
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-3.868388363611D+01 DE= 0.00D+00
     ILin= 2 X=3.000D-01 Y=-3.869560007435D+01 DE=-1.17D-02
     ILin= 3 X=4.243D-01 Y=-3.869917892300D+01 DE=-1.53D-02
     ILin= 4 X=6.000D-01 Y=-3.870296242950D+01 DE=-1.91D-02
     ILin= 5 X=8.485D-01 Y=-3.870575422018D+01 DE=-2.19D-02
     ILin= 6 X=1.200D+00 Y=-3.870458397892D+01 DE=-2.07D-02
     An  expanding polynomial of degree  6 produced  0.9556
 Iteration   2 EE= -38.7060325981253     Delta-E=       -0.022148962014 Grad=5.287D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-3.870603259813D+01 DE= 0.00D+00
     ILin= 2 X=9.556D-01 Y=-3.870792559404D+01 DE=-1.89D-03
     ILin= 3 X=1.351D+00 Y=-3.870817671304D+01 DE=-2.14D-03
     ILin= 4 X=1.911D+00 Y=-3.870799858295D+01 DE=-1.97D-03
     An  expanding polynomial of degree  4 produced  1.4718
 Iteration   3 EE= -38.7081911416456     Delta-E=       -0.002158543520 Grad=2.689D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-3.870819114165D+01 DE= 0.00D+00
     ILin= 2 X=1.472D+00 Y=-3.870853890223D+01 DE=-3.48D-04
     ILin= 3 X=2.081D+00 Y=-3.870825794657D+01 DE=-6.68D-05
     An  expanding polynomial of degree  3 produced  1.0886
 Iteration   4 EE= -38.7085881635871     Delta-E=       -0.000397021942 Grad=9.614D-03
 QCNR:  CnvC1=1.00D-09 CnvC2=1.00D-08
 LinEq1:  Iter=  0 NonCon=     1 RMS=8.60D-04 Max=4.12D-03
 AX will form     1 AO Fock derivatives at one time.
 LinEq1:  Iter=  1 NonCon=     1 RMS=3.33D-04 Max=1.52D-03
 LinEq1:  Iter=  2 NonCon=     1 RMS=2.87D-05 Max=1.76D-04
 LinEq1:  Iter=  3 NonCon=     1 RMS=1.12D-06 Max=5.29D-06
 LinEq1:  Iter=  4 NonCon=     1 RMS=1.23D-07 Max=3.73D-07
 LinEq1:  Iter=  5 NonCon=     1 RMS=9.32D-09 Max=2.99D-08
 LinEq1:  Iter=  6 NonCon=     0 RMS=9.03D-10 Max=2.98D-09
 Linear equations converged to 1.000D-09 1.000D-08 after     6 iterations.
 Angle between quadratic step and gradient=  34.46 degrees.
     ILin= 1 X=0.000D+00 Y=-3.870858816359D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-3.870871855328D+01 DE=-1.30D-04
     ILin= 3 X=1.414D+00 Y=-3.870869616114D+01 DE=-1.08D-04
     An  expanding polynomial of degree  3 produced  0.9999
 Iteration   5 EE= -38.7087185532786     Delta-E=       -0.000130389691 Grad=2.935D-05
 QCNR:  CnvC1=2.94D-10 CnvC2=2.94D-09
 LinEq1:  Iter=  0 NonCon=     1 RMS=2.29D-06 Max=9.34D-06
 LinEq1:  Iter=  1 NonCon=     1 RMS=2.99D-07 Max=1.26D-06
 LinEq1:  Iter=  2 NonCon=     1 RMS=7.90D-08 Max=4.05D-07
 LinEq1:  Iter=  3 NonCon=     1 RMS=1.35D-08 Max=4.70D-08
 LinEq1:  Iter=  4 NonCon=     1 RMS=2.16D-09 Max=1.03D-08
 LinEq1:  Iter=  5 NonCon=     0 RMS=2.37D-10 Max=9.99D-10
 Linear equations converged to 2.935D-10 2.935D-09 after     5 iterations.
 Angle between quadratic step and gradient=  23.30 degrees.
     ILin= 1 X=0.000D+00 Y=-3.870871855328D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-3.870871855401D+01 DE=-7.34D-10
 Iteration   6 EE= -38.7087185540121     Delta-E=       -0.000000000734 Grad=4.077D-08
 Rotation gradient small -- convergence achieved.
 Orbital symmetries in SymMO:
    1=1    2=1    3=4    4=1    5=3    6=1    7=4    8=1    9=3   10=4
   11=1   12=4   13=1
 Orbital symmetries in SymMO:
    1=1    2=1    3=4    4=1    5=3    6=1    7=4    8=1    9=4   10=3
   11=1   12=4   13=1
 SCF Done:  E(UHF) =  -38.7087185540     a.u. after    6 cycles
            Convg  =    0.4077D-07                    29 Fock formations.
              S**2 =  2.0179                  -V/T =  2.0035
 <Sx>= 0.0000 <Sy>= 0.0000 <Sz>= 1.0000 <S**2>= 2.0179 S= 1.0059
 <L.S>= 0.000000000000E+00
 Annihilation of the first spin contaminant:
 S**2 before annihilation     2.0179,   after     2.0001
 Leave Link  508 at Thu Nov 05 20:23:17 2015, MaxMem=   33554432 cpu:       2.0
)";