std::string gaussian_scf_qc_test117 = R"(
 (Enter c:\g09w\l508.exe)
 Tight linear equation convergence will be used.
 RHF wavefunction.
 Quadratic Convergence SCF Method.
 Line search only if initial step raises energy.
 Integral symmetry usage will be decided dynamically.
 ReadGW:  IGet=1 IStart=           2 Next=           2 LGW=           0.
 Iteration   1 EE= -75.9337104479242                                    Grad=4.938D-01
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-7.593371044792D+01 DE= 0.00D+00
     ILin= 2 X=3.000D-01 Y=-7.598714251053D+01 DE=-5.34D-02
     ILin= 3 X=4.243D-01 Y=-7.599969729549D+01 DE=-6.60D-02
     ILin= 4 X=6.000D-01 Y=-7.600778571957D+01 DE=-7.41D-02
     ILin= 5 X=8.485D-01 Y=-7.599981894101D+01 DE=-6.61D-02
     An  expanding polynomial of degree  5 produced  0.6372
 Iteration   2 EE= -76.0080410955941     Delta-E=       -0.074330647670 Grad=1.288D-01
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-7.600804109559D+01 DE= 0.00D+00
     ILin= 2 X=6.372D-01 Y=-7.600942472240D+01 DE=-1.38D-03
     ILin= 3 X=9.012D-01 Y=-7.600968396073D+01 DE=-1.64D-03
     ILin= 4 X=1.274D+00 Y=-7.600973688542D+01 DE=-1.70D-03
     ILin= 5 X=1.802D+00 Y=-7.600918472510D+01 DE=-1.14D-03
     An  expanding polynomial of degree  5 produced  1.1416
 Iteration   3 EE= -76.0097601626042     Delta-E=       -0.001719067010 Grad=1.786D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-7.600976016260D+01 DE= 0.00D+00
     ILin= 2 X=1.142D+00 Y=-7.600983766663D+01 DE=-7.75D-05
     ILin= 3 X=1.614D+00 Y=-7.600977149568D+01 DE=-1.13D-05
     An  expanding polynomial of degree  3 produced  0.8345
 Iteration   4 EE= -76.0098497981911     Delta-E=       -0.000089635587 Grad=5.586D-03
 QCNR:  CnvC1=1.18D-09 CnvC2=1.18D-08
 LinEq1:  Iter=  0 NonCon=     1 RMS=2.60D-04 Max=1.46D-03
 AX will form     1 AO Fock derivatives at one time.
 LinEq1:  Iter=  1 NonCon=     1 RMS=1.47D-04 Max=7.65D-04
 LinEq1:  Iter=  2 NonCon=     1 RMS=1.15D-05 Max=4.17D-05
 LinEq1:  Iter=  3 NonCon=     1 RMS=1.71D-06 Max=7.31D-06
 LinEq1:  Iter=  4 NonCon=     1 RMS=2.81D-07 Max=1.20D-06
 LinEq1:  Iter=  5 NonCon=     1 RMS=2.93D-08 Max=1.19D-07
 LinEq1:  Iter=  6 NonCon=     1 RMS=3.40D-09 Max=1.85D-08
 LinEq1:  Iter=  7 NonCon=     0 RMS=1.43D-10 Max=6.02D-10
 Linear equations converged to 1.183D-09 1.183D-08 after     7 iterations.
 Angle between quadratic step and gradient=  42.70 degrees.
     ILin= 1 X=0.000D+00 Y=-7.600984979819D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-7.600986871213D+01 DE=-1.89D-05
     ILin= 3 X=1.414D+00 Y=-7.600986548446D+01 DE=-1.57D-05
     An  expanding polynomial of degree  3 produced  1.0008
 Iteration   5 EE= -76.0098687121347     Delta-E=       -0.000018913944 Grad=3.909D-06
 QCNR:  CnvC1=3.91D-11 CnvC2=3.91D-10
 LinEq1:  Iter=  0 NonCon=     1 RMS=1.77D-07 Max=7.91D-07
 LinEq1:  Iter=  1 NonCon=     1 RMS=6.11D-08 Max=3.27D-07
 LinEq1:  Iter=  2 NonCon=     1 RMS=1.49D-08 Max=7.01D-08
 LinEq1:  Iter=  3 NonCon=     1 RMS=2.87D-09 Max=1.07D-08
 LinEq1:  Iter=  4 NonCon=     1 RMS=4.15D-10 Max=2.27D-09
 LinEq1:  Iter=  5 NonCon=     0 RMS=3.37D-11 Max=1.76D-10
 Linear equations converged to 3.909D-11 3.909D-10 after     5 iterations.
 Angle between quadratic step and gradient=  41.04 degrees.
     ILin= 1 X=0.000D+00 Y=-7.600986871213D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-7.600986871214D+01 DE=-8.91D-12
 Iteration   6 EE= -76.0098687121436     Delta-E=       -0.000000000009 Grad=5.744D-09
 Rotation gradient small -- convergence achieved.
 Orbital symmetries in SymMO:
    1=1    2=1    3=4    4=1    5=3    6=1    7=4    8=4    9=1   10=1
   11=3   12=4   13=1   14=2   15=1   16=3   17=1   18=4   19=1
 SCF Done:  E(RHF) =  -76.0098687121     a.u. after    6 cycles
            Convg  =    0.5744D-08                    30 Fock formations.
              S**2 =  0.0000                  -V/T =  2.0028
 Leave Link  508 at Thu Nov 05 20:23:02 2015, MaxMem=   33554432 cpu:       0.0
)";