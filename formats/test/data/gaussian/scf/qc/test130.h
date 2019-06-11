std::string gaussian_scf_qc_test130 = R"(
 (Enter c:\g09w\l508.exe)
 Direct SCF.
 Tight linear equation convergence will be used.
 RHF wavefunction.
 Quadratic Convergence SCF Method.
 Line search only if initial step raises energy.
 Two-electron integral symmetry not used.
 ReadGW:  IGet=1 IStart=           2 Next=           2 LGW=           0.
 FoFCou: FMM=F IPFlag=           0 FMFlag=      100000 FMFlg1=           0
         NFxFlg=           0 DoJE=F BraDBF=F KetDBF=F FulRan=T
         Omega=  0.000000  0.000000  1.000000  0.000000  0.000000 ICntrl=       0 IOpCl=  0
         NMat0=    1 NMatS0=    1 NMatT0=    0 NMatD0=    1 NMtDS0=    0 NMtDT0=    0
         I1Cent=           0 NGrid=           0.
 Symmetry not used in FoFCou.
 Iteration   1 EE= -55.7810163353527                                    Grad=5.020D-01
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-5.578101633535D+01 DE= 0.00D+00
     ILin= 2 X=3.000D-01 Y=-5.584302312076D+01 DE=-6.20D-02
     ILin= 3 X=4.243D-01 Y=-5.585838804937D+01 DE=-7.74D-02
     ILin= 4 X=6.000D-01 Y=-5.586979908122D+01 DE=-8.88D-02
     ILin= 5 X=8.485D-01 Y=-5.586540669119D+01 DE=-8.44D-02
     An  expanding polynomial of degree  5 produced  0.6786
 Iteration   2 EE= -55.8710015038621     Delta-E=       -0.089985168509 Grad=1.017D-01
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-5.587100150386D+01 DE= 0.00D+00
     ILin= 2 X=6.786D-01 Y=-5.587197134617D+01 DE=-9.70D-04
     ILin= 3 X=9.597D-01 Y=-5.587213270421D+01 DE=-1.13D-03
     ILin= 4 X=1.357D+00 Y=-5.587212059854D+01 DE=-1.12D-03
     An  expanding polynomial of degree  4 produced  1.1414
 Iteration   3 EE= -55.8721620992791     Delta-E=       -0.001160595417 Grad=1.135D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-5.587216209928D+01 DE= 0.00D+00
     ILin= 2 X=1.141D+00 Y=-5.587219528009D+01 DE=-3.32D-05
     ILin= 3 X=1.614D+00 Y=-5.587217443769D+01 DE=-1.23D-05
     An  expanding polynomial of degree  3 produced  0.8914
 Iteration   4 EE= -55.8721981132516     Delta-E=       -0.000036013972 Grad=3.123D-03
 QCNR:  CnvC1=1.00D-09 CnvC2=1.00D-08
 LinEq1:  Iter=  0 NonCon=     1 RMS=1.62D-04 Max=8.80D-04
 AX will form     1 AO Fock derivatives at one time.
 LinEq1:  Iter=  1 NonCon=     1 RMS=7.94D-05 Max=3.39D-04
 LinEq1:  Iter=  2 NonCon=     1 RMS=3.11D-06 Max=1.24D-05
 LinEq1:  Iter=  3 NonCon=     1 RMS=3.65D-07 Max=1.65D-06
 LinEq1:  Iter=  4 NonCon=     1 RMS=5.67D-08 Max=2.03D-07
 LinEq1:  Iter=  5 NonCon=     1 RMS=3.82D-09 Max=1.57D-08
 LinEq1:  Iter=  6 NonCon=     0 RMS=1.12D-10 Max=3.91D-10
 Linear equations converged to 1.000D-09 1.000D-08 after     6 iterations.
 Angle between quadratic step and gradient=  33.79 degrees.
     ILin= 1 X=0.000D+00 Y=-5.587219811325D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-5.587220347275D+01 DE=-5.36D-06
     ILin= 3 X=1.414D+00 Y=-5.587220255352D+01 DE=-4.44D-06
     An  expanding polynomial of degree  3 produced  1.0001
 Iteration   5 EE= -55.8722034727483     Delta-E=       -0.000005359497 Grad=4.430D-07
 QCNR:  CnvC1=4.43D-12 CnvC2=4.43D-11
 LinEq1:  Iter=  0 NonCon=     1 RMS=2.86D-08 Max=1.37D-07
 LinEq1:  Iter=  1 NonCon=     1 RMS=4.75D-09 Max=2.18D-08
 LinEq1:  Iter=  2 NonCon=     1 RMS=9.26D-10 Max=3.89D-09
 LinEq1:  Iter=  3 NonCon=     1 RMS=1.85D-10 Max=6.88D-10
 LinEq1:  Iter=  4 NonCon=     1 RMS=1.20D-11 Max=4.56D-11
 LinEq1:  Iter=  5 NonCon=     0 RMS=9.33D-13 Max=3.80D-12
 Linear equations converged to 4.430D-12 4.430D-11 after     5 iterations.
 Angle between quadratic step and gradient=  90.00 degrees.
     ILin= 1 X=0.000D+00 Y=-5.587220347275D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-5.587220347275D+01 DE=-3.41D-13
 Iteration   6 EE= -55.8722034727486     Delta-E=        0.000000000000 Grad=2.565D-10
 Rotation gradient small -- convergence achieved.
 Orbital symmetries in SymMO:
    1=1    2=1    3=2    4=1    5=1    6=1    7=1    8=2    9=2   10=1
   11=1   12=1   13=1   14=2   15=1
 SCF Done:  E(RHF) =  -55.8722034727     a.u. after    6 cycles
            Convg  =    0.2565D-09                    28 Fock formations.
              S**2 =  0.0000                  -V/T =  2.0020
 Leave Link  508 at Thu Nov 05 20:23:09 2015, MaxMem=   33554432 cpu:       2.0
)";