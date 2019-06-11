std::string gaussian_scf_qc_coronene_hf = R"(
 (Enter c:\g09w\l508.exe)
 Direct SCF.
 Tight linear equation convergence will be used.
 RHF wavefunction.
 Quadratic Convergence SCF Method.
 Line search only if initial step raises energy.
 Integral symmetry usage will be decided dynamically.
 ReadGW:  IGet=1 IStart=           2 Next=           2 LGW=           0.
 FoFCou: FMM=F IPFlag=           0 FMFlag=      100000 FMFlg1=           0
         NFxFlg=           0 DoJE=F BraDBF=F KetDBF=F FulRan=T
         Omega=  0.000000  0.000000  1.000000  0.000000  0.000000 ICntrl=       0 IOpCl=  0
         NMat0=    1 NMatS0=    1 NMatT0=    0 NMatD0=    1 NMtDS0=    0 NMtDT0=    0
         I1Cent=           0 NGrid=           0.
 Petite list used in FoFCou.
 Iteration   1 EE= -904.629017249843                                    Grad=7.764D-01
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-9.046290172498D+02 DE= 0.00D+00
     ILin= 2 X=3.000D-01 Y=-9.047196604515D+02 DE=-9.06D-02
     ILin= 3 X=4.243D-01 Y=-9.047482445432D+02 DE=-1.19D-01
     ILin= 4 X=6.000D-01 Y=-9.047796620574D+02 DE=-1.51D-01
     ILin= 5 X=8.485D-01 Y=-9.048060174766D+02 DE=-1.77D-01
     ILin= 6 X=1.200D+00 Y=-9.048070202557D+02 DE=-1.78D-01
     ILin= 7 X=1.697D+00 Y=-9.047358039515D+02 DE=-1.07D-01
     An  expanding polynomial of degree  7 produced  1.0326
 Iteration   2 EE= -904.811848578900     Delta-E=       -0.182831329056 Grad=5.821D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-9.048118485789D+02 DE= 0.00D+00
     ILin= 2 X=1.033D+00 Y=-9.048143780676D+02 DE=-2.53D-03
     ILin= 3 X=1.460D+00 Y=-9.048133291612D+02 DE=-1.48D-03
     An  expanding polynomial of degree  3 produced  0.8812
 Iteration   3 EE= -904.814454471148     Delta-E=       -0.002605892249 Grad=2.192D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-9.048144544711D+02 DE= 0.00D+00
     ILin= 2 X=8.812D-01 Y=-9.048149833220D+02 DE=-5.29D-04
     ILin= 3 X=1.246D+00 Y=-9.048148815884D+02 DE=-4.27D-04
     An  expanding polynomial of degree  3 produced  0.8661
 Iteration   4 EE= -904.814983472712     Delta-E=       -0.000529001563 Grad=1.101D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-9.048149834727D+02 DE= 0.00D+00
     ILin= 2 X=8.661D-01 Y=-9.048151277164D+02 DE=-1.44D-04
     ILin= 3 X=1.225D+00 Y=-9.048151117295D+02 DE=-1.28D-04
     An  expanding polynomial of degree  3 produced  0.9161
 Iteration   5 EE= -904.815128153528     Delta-E=       -0.000144680816 Grad=5.924D-03
 QCNR:  CnvC1=9.18D-09 CnvC2=9.18D-08
 LinEq1:  Iter=  0 NonCon=     1 RMS=9.98D-05 Max=2.82D-03
 AX will form     1 AO Fock derivatives at one time.
 LinEq1:  Iter=  1 NonCon=     1 RMS=6.13D-05 Max=1.87D-03
 LinEq1:  Iter=  2 NonCon=     1 RMS=2.36D-06 Max=3.73D-05
 LinEq1:  Iter=  3 NonCon=     1 RMS=4.04D-07 Max=6.65D-06
 LinEq1:  Iter=  4 NonCon=     1 RMS=7.64D-08 Max=1.07D-06
 LinEq1:  Iter=  5 NonCon=     0 RMS=7.07D-09 Max=8.57D-08
 Linear equations converged to 9.178D-09 9.178D-08 after     5 iterations.
 Angle between quadratic step and gradient=  40.71 degrees.
     ILin= 1 X=0.000D+00 Y=-9.048151281535D+02 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-9.048151922442D+02 DE=-6.41D-05
     ILin= 3 X=1.414D+00 Y=-9.048151811000D+02 DE=-5.29D-05
     An  expanding polynomial of degree  3 produced  0.9980
 Iteration   6 EE= -904.815192244407     Delta-E=       -0.000064090879 Grad=1.463D-05
 QCNR:  CnvC1=1.46D-10 CnvC2=1.46D-09
 LinEq1:  Iter=  0 NonCon=     1 RMS=2.14D-07 Max=5.16D-06
 LinEq1:  Iter=  1 NonCon=     1 RMS=7.77D-08 Max=1.43D-06
 LinEq1:  Iter=  2 NonCon=     1 RMS=2.71D-08 Max=8.06D-07
 LinEq1:  Iter=  3 NonCon=     1 RMS=1.09D-08 Max=2.57D-07
 LinEq1:  Iter=  4 NonCon=     1 RMS=1.11D-09 Max=2.95D-08
 LinEq1:  Iter=  5 NonCon=     1 RMS=1.65D-10 Max=3.38D-09
 LinEq1:  Iter=  6 NonCon=     0 RMS=2.45D-11 Max=4.19D-10
 Linear equations converged to 1.463D-10 1.463D-09 after     6 iterations.
 Angle between quadratic step and gradient=  28.03 degrees.
     ILin= 1 X=0.000D+00 Y=-9.048151922444D+02 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-9.048151922447D+02 DE=-3.14D-10
 Iteration   7 EE= -904.815192244721     Delta-E=       -0.000000000314 Grad=8.263D-09
 Rotation gradient small -- convergence achieved.
 SCF Done:  E(RHF) =  -904.815192245     a.u. after    7 cycles
            Convg  =    0.8263D-08                    32 Fock formations.
              S**2 =  0.0000                  -V/T =  2.0093
 Leave Link  508 at Thu Nov 05 18:34:49 2015, MaxMem=   33554432 cpu:     116.0
)";