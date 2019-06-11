std::string dalton_scf_diis_water_hf = R"(
 >>>>> DIIS optimization of Hartree-Fock <<<<<

 C1-DIIS algorithm; max error vectors =    8

 Automatic occupation of symmetries with  10 electrons.

 Iter     Total energy    Error norm  Delta(E)    SCF occupation
 -----------------------------------------------------------------------------
     (Precalculated two-electron integrals are transformed to P-supermatrix elements.
      Threshold for discarding integrals :  1.00D-12 )
@  1  -75.3971666773       2.17D+00  -7.54D+01     3   1   1   0
      Virial theorem: -V/T =      1.997114
@      MULPOP O1        -0.38; H2    _1  0.19; H2    _2  0.19; 
 -----------------------------------------------------------------------------
@  2  -75.5791995958       2.71D-01  -1.82D-01     3   1   1   0
      Virial theorem: -V/T =      2.003138
@      MULPOP O1        -0.67; H2    _1  0.34; H2    _2  0.34; 
 -----------------------------------------------------------------------------
@  3  -75.5855993905       5.06D-02  -6.40D-03     3   1   1   0
      Virial theorem: -V/T =      2.002233
@      MULPOP O1        -0.73; H2    _1  0.36; H2    _2  0.36; 
 -----------------------------------------------------------------------------
@  4  -75.5858057410       5.66D-03  -2.06D-04     3   1   1   0
      Virial theorem: -V/T =      2.001782
@      MULPOP O1        -0.74; H2    _1  0.37; H2    _2  0.37; 
 -----------------------------------------------------------------------------
@  5  -75.5858084159       2.76D-03  -2.67D-06     3   1   1   0
      Virial theorem: -V/T =      2.001883
@      MULPOP O1        -0.74; H2    _1  0.37; H2    _2  0.37; 
 -----------------------------------------------------------------------------
@  6  -75.5858089159       5.85D-04  -5.00D-07     3   1   1   0
      Virial theorem: -V/T =      2.001840
@      MULPOP O1        -0.74; H2    _1  0.37; H2    _2  0.37; 
 -----------------------------------------------------------------------------
@  7  -75.5858089931       7.74D-05  -7.72D-08     3   1   1   0
      Virial theorem: -V/T =      2.001838
@      MULPOP O1        -0.74; H2    _1  0.37; H2    _2  0.37; 
 -----------------------------------------------------------------------------
@  8  -75.5858089943       6.51D-06  -1.13D-09     3   1   1   0

@ *** DIIS converged in   8 iterations !
@     Converged SCF energy, gradient:    -75.585808994254    6.51D-06
    - total time used in SIRFCK :              0.00 seconds


 *** SCF orbital energy analysis ***

 Only the five lowest virtual orbital energies printed in each symmetry.

 Number of electrons :   10
 Orbital occupations :    3    1    1    0

 Sym       Hartree-Fock orbital energies

1 A1    -20.42409394    -1.32206014    -0.52703977     0.26331694     1.27314108
          1.85830439     3.10431000

2 B1     -0.47639366     1.78510603

3 B2     -0.69199174     0.36340943     1.22120138     2.02915862

    E(LUMO) :     0.26331694 au (symmetry 1)
  - E(HOMO) :    -0.47639366 au (symmetry 2)
  ------------------------------------------
    gap     :     0.73971060 au

 >>> Writing SIRIFC interface file <<<

 >>>> CPU and wall time for SCF :       0.007       0.007
)";
