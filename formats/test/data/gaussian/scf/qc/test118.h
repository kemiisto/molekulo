std::string gaussian_scf_qc_test118 = R"(
 (Enter c:\g09w\l508.exe)
 Tight linear equation convergence will be used.
 UHF wavefunction.
 Quadratic Convergence SCF Method.
 Line search only if initial step raises energy.
 Integral symmetry usage will be decided dynamically.
 ReadGW:  IGet=1 IStart=           2 Next=           2 LGW=           0.
 Iteration   1 EE= -38.8883792043103                                    Grad=3.105D-01
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-3.888837920431D+01 DE= 0.00D+00
     ILin= 2 X=3.000D-01 Y=-3.890418408072D+01 DE=-1.58D-02
     ILin= 3 X=4.243D-01 Y=-3.890900217511D+01 DE=-2.06D-02
     ILin= 4 X=6.000D-01 Y=-3.891408018594D+01 DE=-2.57D-02
     ILin= 5 X=8.485D-01 Y=-3.891778121214D+01 DE=-2.94D-02
     ILin= 6 X=1.200D+00 Y=-3.891604359415D+01 DE=-2.77D-02
     An  expanding polynomial of degree  6 produced  0.9495
 Iteration   2 EE= -38.9181183630418     Delta-E=       -0.029739158732 Grad=6.383D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-3.891811836304D+01 DE= 0.00D+00
     ILin= 2 X=9.495D-01 Y=-3.892029777071D+01 DE=-2.18D-03
     ILin= 3 X=1.343D+00 Y=-3.892051477624D+01 DE=-2.40D-03
     ILin= 4 X=1.899D+00 Y=-3.892013502327D+01 DE=-2.02D-03
     An  expanding polynomial of degree  4 produced  1.3584
 Iteration   3 EE= -38.9205150926903     Delta-E=       -0.002396729648 Grad=2.742D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-3.892051509269D+01 DE= 0.00D+00
     ILin= 2 X=1.358D+00 Y=-3.892091374683D+01 DE=-3.99D-04
     ILin= 3 X=1.921D+00 Y=-3.892071375382D+01 DE=-1.99D-04
     An  expanding polynomial of degree  3 produced  1.1136
 Iteration   4 EE= -38.9209340072834     Delta-E=       -0.000418914593 Grad=1.016D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-3.892093400728D+01 DE= 0.00D+00
     ILin= 2 X=1.114D+00 Y=-3.892102924892D+01 DE=-9.52D-05
     ILin= 3 X=1.575D+00 Y=-3.892103120120D+01 DE=-9.72D-05
     ILin= 4 X=2.227D+00 Y=-3.892099645760D+01 DE=-6.25D-05
     An  expanding polynomial of degree  4 produced  1.3852
 Iteration   5 EE= -38.9210330578734     Delta-E=       -0.000099050590 Grad=5.887D-03
 QCNR:  CnvC1=1.09D-09 CnvC2=1.09D-08
 LinEq1:  Iter=  0 NonCon=     1 RMS=3.87D-04 Max=2.26D-03
 AX will form     1 AO Fock derivatives at one time.
 LinEq1:  Iter=  1 NonCon=     1 RMS=1.62D-04 Max=9.19D-04
 LinEq1:  Iter=  2 NonCon=     1 RMS=9.71D-06 Max=6.94D-05
 LinEq1:  Iter=  3 NonCon=     1 RMS=3.75D-07 Max=2.00D-06
 LinEq1:  Iter=  4 NonCon=     1 RMS=5.32D-08 Max=2.03D-07
 LinEq1:  Iter=  5 NonCon=     1 RMS=3.63D-09 Max=1.62D-08
 LinEq1:  Iter=  6 NonCon=     0 RMS=4.98D-10 Max=1.84D-09
 Linear equations converged to 1.086D-09 1.086D-08 after     6 iterations.
 Angle between quadratic step and gradient=  41.61 degrees.
     ILin= 1 X=0.000D+00 Y=-3.892103305787D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-3.892106756037D+01 DE=-3.45D-05
     ILin= 3 X=1.414D+00 Y=-3.892106162654D+01 DE=-2.86D-05
     An  expanding polynomial of degree  3 produced  0.9997
 Iteration   6 EE= -38.9210675603767     Delta-E=       -0.000034502503 Grad=6.151D-06
 QCNR:  CnvC1=6.15D-11 CnvC2=6.15D-10
 LinEq1:  Iter=  0 NonCon=     1 RMS=3.48D-07 Max=1.46D-06
 LinEq1:  Iter=  1 NonCon=     1 RMS=6.61D-08 Max=3.89D-07
 LinEq1:  Iter=  2 NonCon=     1 RMS=1.62D-08 Max=8.84D-08
 LinEq1:  Iter=  3 NonCon=     1 RMS=3.94D-09 Max=2.76D-08
 LinEq1:  Iter=  4 NonCon=     1 RMS=6.70D-10 Max=3.43D-09
 LinEq1:  Iter=  5 NonCon=     1 RMS=1.00D-10 Max=3.79D-10
 LinEq1:  Iter=  6 NonCon=     0 RMS=1.22D-11 Max=5.45D-11
 Linear equations converged to 6.151D-11 6.151D-10 after     6 iterations.
 Angle between quadratic step and gradient=  37.72 degrees.
     ILin= 1 X=0.000D+00 Y=-3.892106756038D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-3.892106756040D+01 DE=-2.55D-11
 Iteration   7 EE= -38.9210675604022     Delta-E=       -0.000000000025 Grad=2.090D-09
 Rotation gradient small -- convergence achieved.
 Orbital symmetries in SymMO:
    1=1    2=1    3=4    4=1    5=3    6=1    7=4    8=1    9=3   10=4
   11=1   12=1   13=4   14=2   15=1   16=3   17=4   18=1   19=1
 Orbital symmetries in SymMO:
    1=1    2=1    3=4    4=1    5=3    6=1    7=4    8=1    9=4   10=3
   11=1   12=1   13=4   14=2   15=1   16=3   17=4   18=1   19=1
 SCF Done:  E(UHF) =  -38.9210675604     a.u. after    7 cycles
            Convg  =    0.2090D-08                    34 Fock formations.
              S**2 =  2.0167                  -V/T =  2.0007
 <Sx>= 0.0000 <Sy>= 0.0000 <Sz>= 1.0000 <S**2>= 2.0167 S= 1.0055
 <L.S>= 0.000000000000E+00
 Annihilation of the first spin contaminant:
 S**2 before annihilation     2.0167,   after     2.0001
 Leave Link  508 at Thu Nov 05 20:23:04 2015, MaxMem=   33554432 cpu:       0.0
)";