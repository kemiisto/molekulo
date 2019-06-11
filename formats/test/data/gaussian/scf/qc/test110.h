std::string gaussian_scf_qc_test110 = R"(
 (Enter c:\g09w\l508.exe)
 Direct SCF.
 Tight linear equation convergence will be used.
 UHF wavefunction.
 Quadratic Convergence SCF Method.
 Line search only if initial step raises energy.
 Integral symmetry usage will be decided dynamically.
 ReadGW:  IGet=1 IStart=           2 Next=           2 LGW=           0.
 Keep R1 and R2 ints in memory in canonical form, NReq=1045123.
 Symmetry not used in FoFDir.
 MinBra= 0 MaxBra= 2 Meth= 1.
 IRaf=       0 NMat=   1 IRICut=       1 DoRegI=T DoRafI=F ISym2E= 0 JSym2E=0.
 Iteration   1 EE= -75.4720039043009                                    Grad=1.504D-09
 Rotation gradient small -- convergence achieved.
 Orbital symmetries in SymMO:
    1=1    2=6    3=1    4=6    5=1    6=7    7=8    8=4    9=3   10=6
   11=1   12=7   13=8   14=1   15=4   16=3   17=6   18=6   19=7   20=8
   21=1   22=2   23=5   24=6   25=1   26=4   27=3   28=6   29=1   30=6
 Orbital symmetries in SymMO:
    1=1    2=6    3=1    4=6    5=8    6=1    7=7    8=3    9=4   10=6
   11=1   12=8   13=7   14=1   15=3   16=4   17=6   18=6   19=8   20=7
   21=2   22=1   23=5   24=6   25=1   26=4   27=3   28=6   29=1   30=6
 SCF Done:  E(UHF) =  -75.4720039043     a.u. after    1 cycles
            Convg  =    0.1504D-08                     1 Fock formations.
              S**2 =  2.0120                  -V/T =  2.0000
 <Sx>= 0.0000 <Sy>= 0.0000 <Sz>= 1.0000 <S**2>= 2.0120 S= 1.0040
 <L.S>= 0.000000000000E+00
 Annihilation of the first spin contaminant:
 S**2 before annihilation     2.0120,   after     2.0000
 Leave Link  508 at Thu Nov 05 20:22:58 2015, MaxMem=   33554432 cpu:       0.0
)";