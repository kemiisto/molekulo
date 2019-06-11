std::string gaussian_scf_qc_test018 = R"(
 (Enter c:\g09w\l508.exe)
 Direct SCF.
 Tight linear equation convergence will be used.
 UHF wavefunction.
 Quadratic Convergence SCF Method.
 Line search only if initial step raises energy.
 2E integral symmetry used by replicating integrals.
 ReadGW:  IGet=1 IStart=           2 Next=           2 LGW=           0.
 Keep R1 and R2 ints in memory in canonical form, NReq=810046.
 Symmetry not used in FoFDir.
 MinBra= 0 MaxBra= 1 Meth= 1.
 IRaf=       0 NMat=   1 IRICut=       1 DoRegI=T DoRafI=F ISym2E= 0 JSym2E=0.
 Perform preliminary linear searches along instability eigenvector.
     ILin= 1 X=0.000D+00 Y=-1.553119700379D+01 DE= 0.00D+00
     ILin= 2 X=1.000D-01 Y=-1.553251924143D+01 DE=-1.32D-03
     ILin= 3 X=1.414D-01 Y=-1.553382322471D+01 DE=-2.63D-03
     ILin= 4 X=2.000D-01 Y=-1.553637697970D+01 DE=-5.18D-03
     ILin= 5 X=2.828D-01 Y=-1.554127145242D+01 DE=-1.01D-02
     ILin= 6 X=4.000D-01 Y=-1.555023810828D+01 DE=-1.90D-02
     ILin= 7 X=5.657D-01 Y=-1.556511142467D+01 DE=-3.39D-02
     ILin= 8 X=8.000D-01 Y=-1.558430402132D+01 DE=-5.31D-02
     ILin= 9 X=1.131D+00 Y=-1.559184591963D+01 DE=-6.06D-02
     ILin=10 X=1.600D+00 Y=-1.554737480018D+01 DE=-1.62D-02
     An  expanding polynomial of degree 10 produced  1.0475
 Iteration F X= 1.048D+00 EE=-1.559295597859765D+01
     ILin= 1 X=0.000D+00 Y=-1.553119700379D+01 DE= 0.00D+00
     ILin= 2 X=1.000D-01 Y=-1.553251924143D+01 DE=-1.32D-03
     ILin= 3 X=1.414D-01 Y=-1.553382322471D+01 DE=-2.63D-03
 The two search directions are symmetric.
 Iteration B X= 1.048D+00 EE=-1.559295597859765D+01
 Take forward step, X= 1.048D+00 Step= 1.048D+00
 Iteration   1 EE= -15.5929559780688                                    Grad=6.300D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-1.559295597807D+01 DE= 0.00D+00
     ILin= 2 X=3.000D-01 Y=-1.559450610535D+01 DE=-1.55D-03
     ILin= 3 X=4.243D-01 Y=-1.559502063363D+01 DE=-2.06D-03
     ILin= 4 X=6.000D-01 Y=-1.559562096391D+01 DE=-2.66D-03
     ILin= 5 X=8.485D-01 Y=-1.559621579483D+01 DE=-3.26D-03
     ILin= 6 X=1.200D+00 Y=-1.559655020758D+01 DE=-3.59D-03
     ILin= 7 X=1.697D+00 Y=-1.559601448292D+01 DE=-3.06D-03
     An  expanding polynomial of degree  7 produced  1.2228
 Iteration   2 EE= -15.5965514472216     Delta-E=       -0.003595469153 Grad=1.136D-02
 Gradient too large for Newton-Raphson -- use scaled steepest descent instead.
     ILin= 1 X=0.000D+00 Y=-1.559655144722D+01 DE= 0.00D+00
     ILin= 2 X=1.223D+00 Y=-1.559686877890D+01 DE=-3.17D-04
     ILin= 3 X=1.729D+00 Y=-1.559689092237D+01 DE=-3.39D-04
     ILin= 4 X=2.446D+00 Y=-1.559681456923D+01 DE=-2.63D-04
     An  expanding polynomial of degree  4 produced  1.6529
 Iteration   3 EE= -15.5968916421114     Delta-E=       -0.000340194890 Grad=7.368D-03
 QCNR:  CnvC1=1.00D-09 CnvC2=1.00D-08
 LinEq1:  Iter=  0 NonCon=     1 RMS=8.93D-04 Max=2.22D-03
 AX will form     1 AO Fock derivatives at one time.
 LinEq1:  Iter=  1 NonCon=     1 RMS=3.62D-04 Max=1.75D-03
 LinEq1:  Iter=  2 NonCon=     1 RMS=1.22D-05 Max=4.43D-05
 LinEq1:  Iter=  3 NonCon=     1 RMS=1.76D-06 Max=6.96D-06
 LinEq1:  Iter=  4 NonCon=     1 RMS=2.96D-07 Max=6.82D-07
 LinEq1:  Iter=  5 NonCon=     1 RMS=5.72D-08 Max=1.65D-07
 LinEq1:  Iter=  6 NonCon=     1 RMS=3.45D-09 Max=1.05D-08
 LinEq1:  Iter=  7 NonCon=     0 RMS=2.34D-10 Max=6.46D-10
 Linear equations converged to 1.000D-09 1.000D-08 after     7 iterations.
 Angle between quadratic step and gradient=  52.66 degrees.
     ILin= 1 X=0.000D+00 Y=-1.559689164211D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-1.559696426403D+01 DE=-7.26D-05
     ILin= 3 X=1.414D+00 Y=-1.559695214059D+01 DE=-6.05D-05
     An  expanding polynomial of degree  3 produced  1.0040
 Iteration   4 EE= -15.5969642648891     Delta-E=       -0.000072622778 Grad=3.484D-05
 QCNR:  CnvC1=3.48D-10 CnvC2=3.48D-09
 LinEq1:  Iter=  0 NonCon=     1 RMS=4.53D-06 Max=1.35D-05
 LinEq1:  Iter=  1 NonCon=     1 RMS=7.60D-07 Max=1.94D-06
 LinEq1:  Iter=  2 NonCon=     1 RMS=1.84D-07 Max=7.37D-07
 LinEq1:  Iter=  3 NonCon=     1 RMS=2.01D-08 Max=5.75D-08
 LinEq1:  Iter=  4 NonCon=     1 RMS=3.06D-09 Max=1.01D-08
 LinEq1:  Iter=  5 NonCon=     1 RMS=4.75D-10 Max=1.27D-09
 LinEq1:  Iter=  6 NonCon=     0 RMS=4.46D-11 Max=1.05D-10
 Linear equations converged to 3.484D-10 3.484D-09 after     6 iterations.
 Angle between quadratic step and gradient=  35.70 degrees.
     ILin= 1 X=0.000D+00 Y=-1.559696426489D+01 DE= 0.00D+00
     ILin= 2 X=1.000D+00 Y=-1.559696426783D+01 DE=-2.94D-09
 Iteration   5 EE= -15.5969642678297     Delta-E=       -0.000000002941 Grad=2.810D-08
 Rotation gradient small -- convergence achieved.
 Density matrix breaks symmetry, PCut= 1.00D-04
 Density matrix has no symmetry -- integrals replicated.
 Density matrix is not symmetric, so final MOs not symmetrized.
 SCF Done:  E(UHF) =  -15.5969642678     a.u. after    5 cycles
            Convg  =    0.2810D-07                    40 Fock formations.
              S**2 =  1.0290                  -V/T =  1.9894
 <Sx>= 0.0000 <Sy>= 0.0000 <Sz>= 0.0000 <S**2>= 1.0290 S= 0.6309
 <L.S>= 0.000000000000E+00
 Annihilation of the first spin contaminant:
 S**2 before annihilation     1.0290,   after     0.2333
 Leave Link  508 at Thu Nov 05 17:22:00 2015, MaxMem=   33554432 cpu:       0.0
)";