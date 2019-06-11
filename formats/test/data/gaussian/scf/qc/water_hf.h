std::string gaussian_scf_qc_water_hf = R"(
 (Enter c:\g09w\l508.exe)
 Direct SCF.
 Tight linear equation convergence will be used.
 RHF wavefunction.
 Quadratic Convergence SCF Method.
 Line search only if initial step raises energy.
 Integral symmetry usage will be decided dynamically.
 ReadGW:  IGet=1 IStart=           2 Next=           2 LGW=           0.
 Keep R1 ints in memory in canonical form, NReq=805658.
 Symmetry not used in FoFDir.
 MinBra= 0 MaxBra= 1 Meth= 1.
 IRaf=       0 NMat=   1 IRICut=       1 DoRegI=T DoRafI=F ISym2E= 0 JSym2E=0.
 Iteration   1 EE= -75.5170109481120                                    Grad=4.796D-01
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-7.551701094811D+01 DE= 0.00D+00
     ILin= 2 X=3.000D-01 Y=-7.556302723391D+01 DE=-4.60D-02
     ILin= 3 X=4.243D-01 Y=-7.557446651030D+01 DE=-5.75D-02
     ILin= 4 X=6.000D-01 Y=-7.558299831588D+01 DE=-6.60D-02
     ILin= 5 X=8.485D-01 Y=-7.557978782023D+01 DE=-6.28D-02
     An  expanding polynomial of degree  5 produced  0.6796
 Iteration   2 EE= -75.5839156860635     Delta-E=       -0.066904737952 Grad=1.166D-01
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-7.558391568606D+01 DE= 0.00D+00
     ILin= 2 X=6.796D-01 Y=-7.558539450929D+01 DE=-1.48D-03
     ILin= 3 X=9.611D-01 Y=-7.558565147417D+01 DE=-1.74D-03
     ILin= 4 X=1.359D+00 Y=-7.558565932874D+01 DE=-1.74D-03
     ILin= 5 X=1.922D+00 Y=-7.558495947285D+01 DE=-1.04D-03
     An  expanding polynomial of degree  5 produced  1.1676
 Iteration   3 EE= -75.5857075413510     Delta-E=       -0.001791855287 Grad=1.863D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-7.558570754135D+01 DE= 0.00D+00
     ILin= 2 X=1.168D+00 Y=-7.558577943398D+01 DE=-7.19D-05
     ILin= 3 X=1.651D+00 Y=-7.558570346045D+01 DE= 4.08D-06
     An  expanding polynomial of degree  3 produced  0.8163
 Iteration   4 EE= -75.5857957676848     Delta-E=       -0.000088226334 Grad=5.350D-03
 QCNR:  CnvC1=1.00D-09 CnvC2=1.00D-08
 LinEq1:  Iter=  0 NonCon=     1 RMS=2.75D-04 Max=1.10D-03
 AX will form     1 AO Fock derivatives at one time.
 LinEq1:  Iter=  1 NonCon=     1 RMS=1.35D-04 Max=4.95D-04
 LinEq1:  Iter=  2 NonCon=     1 RMS=1.48D-05 Max=6.79D-05
 LinEq1:  Iter=  3 NonCon=     1 RMS=1.08D-06 Max=4.53D-06
 LinEq1:  Iter=  4 NonCon=     1 RMS=9.53D-08 Max=3.10D-07
 LinEq1:  Iter=  5 NonCon=     1 RMS=5.60D-09 Max=1.65D-08
 LinEq1:  Iter=  6 NonCon=     0 RMS=1.36D-10 Max=5.79D-10
 Linear equations converged to 1.000D-09 1.000D-08 after     6 iterations.
 Angle between quadratic step and gradient=  46.63 degrees.
     ILin= 1 X=0.000D+00 Y=-7.558579576768D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-7.558580997730D+01 DE=-1.42D-05
     ILin= 3 X=1.414D+00 Y=-7.558580754389D+01 DE=-1.18D-05
     An  expanding polynomial of degree  3 produced  1.0003
 Iteration   5 EE= -75.5858099773009     Delta-E=       -0.000014209616 Grad=2.647D-06
 QCNR:  CnvC1=2.65D-11 CnvC2=2.65D-10
 LinEq1:  Iter=  0 NonCon=     1 RMS=1.65D-07 Max=7.90D-07
 LinEq1:  Iter=  1 NonCon=     1 RMS=6.09D-08 Max=2.34D-07
 LinEq1:  Iter=  2 NonCon=     1 RMS=9.20D-09 Max=3.09D-08
 LinEq1:  Iter=  3 NonCon=     1 RMS=1.13D-09 Max=4.32D-09
 LinEq1:  Iter=  4 NonCon=     1 RMS=7.57D-11 Max=2.57D-10
 LinEq1:  Iter=  5 NonCon=     0 RMS=5.92D-12 Max=1.87D-11
 Linear equations converged to 2.647D-11 2.647D-10 after     5 iterations.
 Angle between quadratic step and gradient=  39.03 degrees.
     ILin= 1 X=0.000D+00 Y=-7.558580997730D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-7.558580997730D+01 DE=-3.57D-12
 Iteration   6 EE= -75.5858099773044     Delta-E=       -0.000000000004 Grad=2.040D-09
 Rotation gradient small -- convergence achieved.
 Orbital symmetries in SymMO:
    1=1    2=1    3=4    4=1    5=3    6=1    7=4    8=4    9=1   10=3
   11=1   12=4   13=1
 SCF Done:  E(RHF) =  -75.5858099773     a.u. after    6 cycles
            Convg  =    0.2040D-08                    29 Fock formations.
              S**2 =  0.0000                  -V/T =  2.0018
 Leave Link  508 at Wed Jul 08 16:04:21 2015, MaxMem=   33554432 cpu:       0.0
)";