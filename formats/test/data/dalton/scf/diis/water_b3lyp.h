std::string dalton_scf_diis_water_b3lyp = R"(
 >>>>> DIIS optimization of Hartree-Fock <<<<<

 C1-DIIS algorithm; max error vectors =    8

 Automatic occupation of symmetries with  10 electrons.

 Iter     Total energy    Error norm  Delta(E)    SCF occupation
 -----------------------------------------------------------------------------
      K-S energy, electrons, error :     -7.463880845068   9.9999983338   -1.67D-06
@  1  -75.7529362048       2.25D+00  -7.58D+01     3   1   1   0
      Virial theorem: -V/T =      2.001819
@      MULPOP O      -0.38; H     _1  0.19; H     _2  0.19; 
 -----------------------------------------------------------------------------
      K-S energy, electrons, error :     -7.551489202844   9.9999983735   -1.63D-06
@  2  -75.9332556012       1.54D-01  -1.80D-01     3   1   1   0
      Virial theorem: -V/T =      2.003048
@      MULPOP O      -0.69; H     _1  0.34; H     _2  0.34; 
 -----------------------------------------------------------------------------
      K-S energy, electrons, error :     -7.511398036644   9.9999983621   -1.64D-06
@  3  -75.9335440727       1.40D-01  -2.88D-04     3   1   1   0
      Virial theorem: -V/T =      2.007599
@      MULPOP O      -0.63; H     _1  0.32; H     _2  0.32; 
 -----------------------------------------------------------------------------
      K-S energy, electrons, error :     -7.533548944445   9.9999983692   -1.63D-06
@  4  -75.9342935879       1.69D-02  -7.50D-04     3   1   1   0
      Virial theorem: -V/T =      2.004901
@      MULPOP O      -0.67; H     _1  0.34; H     _2  0.34; 
 -----------------------------------------------------------------------------
      K-S energy, electrons, error :     -7.531036751421   9.9999983682   -1.63D-06
@  5  -75.9343064566       1.17D-03  -1.29D-05     3   1   1   0
      Virial theorem: -V/T =      2.005185
@      MULPOP O      -0.67; H     _1  0.33; H     _2  0.33; 
 -----------------------------------------------------------------------------
      K-S energy, electrons, error :     -7.531189686130   9.9999983682   -1.63D-06
@  6  -75.9343065207       3.26D-05  -6.41D-08     3   1   1   0
      Virial theorem: -V/T =      2.005166
@      MULPOP O      -0.67; H     _1  0.33; H     _2  0.33; 
 -----------------------------------------------------------------------------
      K-S energy, electrons, error :     -7.531186684031   9.9999983682   -1.63D-06
@  7  -75.9343065208       1.77D-06  -1.60D-10     3   1   1   0

@ *** DIIS converged in   7 iterations !
@     Converged SCF energy, gradient:    -75.934306520840    1.77D-06
    - total time used in SIRFCK :              0.00 seconds


 *** SCF orbital energy analysis ***

 Only the five lowest virtual orbital energies printed in each symmetry.

 Number of electrons :   10
 Orbital occupations :    3    1    1    0

 Sym       Kohn-Sham orbital energies

1 A1    -18.98762931    -0.98074235    -0.31086250     0.10359617     0.98957470
          1.51125546     2.74864604

2 B1     -0.25191630     1.44507942

3 B2     -0.51042857     0.19820734     0.95814868     1.66148879

    E(LUMO) :     0.10359617 au (symmetry 1)
  - E(HOMO) :    -0.25191630 au (symmetry 2)
  ------------------------------------------
    gap     :     0.35551246 au

 >>> Writing SIRIFC interface file <<<

 >>>> CPU and wall time for SCF :       1.092       1.109
)";
