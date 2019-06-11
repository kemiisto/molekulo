std::string gaussian_scf_qc_test045 = R"(
 (Enter c:\g09w\l508.exe)
 Direct SCF.
 Tight linear equation convergence will be used.
 RPBE-PBE wavefunction.
 Quadratic Convergence SCF Method.
 Line search only if initial step raises energy.
 Integral symmetry usage will be decided dynamically.
 ReadGW:  IGet=1 IStart=           2 Next=       24497 LGW=       24495.
 Pruned (  75, 302) grid will be used in CalDFT.
 FoFCou: FMM=F IPFlag=           0 FMFlag=      100000 FMFlg1=           0
         NFxFlg=           0 DoJE=T BraDBF=T KetDBF=F FulRan=T
         Omega=  0.000000  0.000000  1.000000  0.000000  0.000000 ICntrl=     500 IOpCl=  0
         NMat0=    1 NMatS0=    1 NMatT0=    0 NMatD0=    1 NMtDS0=    0 NMtDT0=    0
         I1Cent=           5 NGrid=           0.
 Petite list used in FoFCou.
 Iteration   1 EE= -76.2930425354007                                    Grad=4.280D-01
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-7.629304253540D+01 DE= 0.00D+00
     ILin= 2 X=3.000D-01 Y=-7.635978365921D+01 DE=-6.67D-02
     ILin= 3 X=4.243D-01 Y=-7.635325886944D+01 DE=-6.02D-02
     An  expanding polynomial of degree  3 produced  0.3216
 Iteration   2 EE= -76.3601320506475     Delta-E=       -0.067089515247 Grad=5.636D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-7.636013205065D+01 DE= 0.00D+00
     ILin= 2 X=3.216D-01 Y=-7.636052187833D+01 DE=-3.90D-04
     ILin= 3 X=4.548D-01 Y=-7.636063185364D+01 DE=-5.00D-04
     ILin= 4 X=6.433D-01 Y=-7.636073576147D+01 DE=-6.04D-04
     ILin= 5 X=9.097D-01 Y=-7.636077924089D+01 DE=-6.47D-04
     ILin= 6 X=1.287D+00 Y=-7.636063315275D+01 DE=-5.01D-04
     An  expanding polynomial of degree  6 produced  0.8719
 Iteration   3 EE= -76.3607804632052     Delta-E=       -0.000648412558 Grad=7.441D-03
 QCNR:  CnvC1=2.05D-09 CnvC2=2.05D-08
 LinEq1:  Iter=  0 NonCon=     1 RMS=2.92D-04 Max=3.02D-03
 AX will form     1 AO Fock derivatives at one time.
 LinEq1:  Iter=  1 NonCon=     1 RMS=1.72D-04 Max=1.40D-03
 LinEq1:  Iter=  2 NonCon=     1 RMS=8.82D-05 Max=7.18D-04
 LinEq1:  Iter=  3 NonCon=     1 RMS=1.67D-06 Max=1.06D-05
 LinEq1:  Iter=  4 NonCon=     1 RMS=1.36D-07 Max=6.68D-07
 LinEq1:  Iter=  5 NonCon=     1 RMS=1.42D-08 Max=8.42D-08
 LinEq1:  Iter=  6 NonCon=     0 RMS=5.24D-10 Max=2.70D-09
 Linear equations converged to 2.049D-09 2.049D-08 after     6 iterations.
 Angle between quadratic step and gradient=  52.02 degrees.
     ILin= 1 X=0.000D+00 Y=-7.636078046321D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-7.636080113325D+01 DE=-2.07D-05
     ILin= 3 X=1.414D+00 Y=-7.636079763506D+01 DE=-1.72D-05
     An  expanding polynomial of degree  3 produced  1.0020
 Iteration   4 EE= -76.3608011327571     Delta-E=       -0.000020669552 Grad=1.208D-05
 QCNR:  CnvC1=1.21D-10 CnvC2=1.21D-09
 LinEq1:  Iter=  0 NonCon=     1 RMS=6.64D-07 Max=8.23D-06
 LinEq1:  Iter=  1 NonCon=     1 RMS=4.16D-07 Max=3.27D-06
 LinEq1:  Iter=  2 NonCon=     1 RMS=1.07D-07 Max=9.43D-07
 LinEq1:  Iter=  3 NonCon=     1 RMS=1.20D-08 Max=7.31D-08
 LinEq1:  Iter=  4 NonCon=     1 RMS=1.00D-09 Max=7.78D-09
 LinEq1:  Iter=  5 NonCon=     0 RMS=5.43D-11 Max=3.07D-10
 Linear equations converged to 1.208D-10 1.208D-09 after     5 iterations.
 Angle between quadratic step and gradient=  54.33 degrees.
     ILin= 1 X=0.000D+00 Y=-7.636080113276D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-7.636080113336D+01 DE=-6.02D-10
 Iteration   5 EE= -76.3608011333586     Delta-E=       -0.000000000602 Grad=7.391D-10
 Rotation gradient small -- convergence achieved.
 Orbital symmetries in SymMO:
    1=1    2=1    3=4    4=1    5=3    6=1    7=4    8=4    9=1   10=1
   11=3   12=4   13=1   14=1   15=2   16=3   17=4   18=4   19=1   20=1
   21=4   22=3   23=2   24=1   25=3   26=1   27=4   28=2   29=1   30=4
   31=4   32=3   33=1   34=2   35=4   36=1   37=3   38=1   39=3   40=4
   41=1   42=1   43=2   44=3   45=4   46=4   47=1
 SCF Done:  E(RPBE-PBE) =  -76.3608011334     a.u. after    5 cycles
            Convg  =    0.7391D-09                    25 Fock formations.
              S**2 =  0.0000                  -V/T =  2.0026
 Leave Link  508 at Thu Nov 05 17:58:18 2015, MaxMem=   33554432 cpu:      46.0
)";