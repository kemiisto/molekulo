std::string gaussian_scf_qc_water_hf_not_converged = R"(
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
 Convergence failure.
 Error termination via Lnk1e in c:\g09w\l508.exe at Wed Jul 08 19:47:15 2015.
)";