std::string dalton_scf_diis_cc2_r12_aux_ch4_a2_ref = R"(
 >>>>> DIIS optimization of Hartree-Fock <<<<<

 C1-DIIS algorithm; max error vectors =   10

 Iter      Total energy        Error norm    Delta(E)  DIIS dim.
 -----------------------------------------------------------------------------
   1  Screening settings (-IFTHRS, DIFDEN)   -7    T
@  1    -26.9208461930        1.73607D+01   -2.69D+01    1
      Virial theorem: -V/T =      1.397424
@      MULPOP C      -3.96; H       0.99; H       0.99; H       0.99; H       0.99; 
 -----------------------------------------------------------------------------
   2  Screening settings (-IFTHRS, DIFDEN)   -7    T
@  2    -34.5740130443        5.98235D+00   -7.65D+00    2
      Virial theorem: -V/T =      2.092202
@      MULPOP C       7.24; H      -1.81; H      -1.81; H      -1.81; H      -1.81; 
 -----------------------------------------------------------------------------
   3  Screening settings (-IFTHRS, DIFDEN)   -7    T
@  3    -38.7812864835        4.97171D+00   -4.21D+00    3
      Virial theorem: -V/T =      1.865551
@      MULPOP C      -2.05; H       0.51; H       0.51; H       0.51; H       0.51; 
 -----------------------------------------------------------------------------
   4  Screening settings (-IFTHRS, DIFDEN)   -7    T
@  4    -40.0920859293        1.20614D+00   -1.31D+00    4
      Virial theorem: -V/T =      1.982551
@      MULPOP C      -0.78; H       0.19; H       0.19; H       0.19; H       0.19; 
 -----------------------------------------------------------------------------
   5  Screening settings (-IFTHRS, DIFDEN)   -7    T
@  5    -40.1914986672        6.81149D-02   -9.94D-02    5
      Virial theorem: -V/T =      2.012916
@      MULPOP C      -0.36; H       0.09; H       0.09; H       0.09; H       0.09; 
 -----------------------------------------------------------------------------
   6  Screening settings (-IFTHRS, DIFDEN)  -10    F
@  6    -40.1917302506        2.38637D-02   -2.32D-04    6
      Virial theorem: -V/T =      2.011954
@      MULPOP C      -0.38; H       0.09; H       0.09; H       0.09; H       0.09; 
 -----------------------------------------------------------------------------
   7  Screening settings (-IFTHRS, DIFDEN)  -10    T
@  7    -40.1917714465        1.95517D-03   -4.12D-05    7
      Virial theorem: -V/T =      2.011289
@      MULPOP C      -0.38; H       0.10; H       0.10; H       0.10; H       0.10; 
 -----------------------------------------------------------------------------
   8  Screening settings (-IFTHRS, DIFDEN)  -10    T
@  8    -40.1917720845        2.23893D-04   -6.38D-07    8
      Virial theorem: -V/T =      2.011253
@      MULPOP C      -0.38; H       0.10; H       0.10; H       0.10; H       0.10; 
 -----------------------------------------------------------------------------
   9  Screening settings (-IFTHRS, DIFDEN)  -12    F
@  9    -40.1917720926        2.77686D-05   -8.10D-09    9
      Virial theorem: -V/T =      2.011254
@      MULPOP C      -0.38; H       0.09; H       0.09; H       0.09; H       0.09; 
 -----------------------------------------------------------------------------
  10  Screening settings (-IFTHRS, DIFDEN)  -12    T
@ 10    -40.1917720926        1.93555D-06   -6.98D-11   10
      Virial theorem: -V/T =      2.011255
@      MULPOP C      -0.38; H       0.09; H       0.09; H       0.09; H       0.09; 
 -----------------------------------------------------------------------------
  11  Screening settings (-IFTHRS, DIFDEN)  -14    F
@ 11    -40.1917720926        2.07188D-07   -5.83D-13   10
      Virial theorem: -V/T =      2.011255
@      MULPOP C      -0.38; H       0.09; H       0.09; H       0.09; H       0.09; 
 -----------------------------------------------------------------------------
  12  Screening settings (-IFTHRS, DIFDEN)  -17    F
@ 12    -40.1917720926        3.17360D-08    4.26D-14   10
      Virial theorem: -V/T =      2.011255
@      MULPOP C      -0.38; H       0.09; H       0.09; H       0.09; H       0.09; 
 -----------------------------------------------------------------------------
  13  Screening settings (-IFTHRS, DIFDEN)  -17    T
@ 13    -40.1917720926        6.88384D-10   -5.68D-14   10
      Virial theorem: -V/T =      2.011255
@      MULPOP C      -0.38; H       0.09; H       0.09; H       0.09; H       0.09; 
 -----------------------------------------------------------------------------
  14  Screening settings (-IFTHRS, DIFDEN)  -17    T
@ 14    -40.1917720926        1.72573D-11   -1.42D-14   10
      Virial theorem: -V/T =      2.011255
@      MULPOP C      -0.38; H       0.09; H       0.09; H       0.09; H       0.09; 
 -----------------------------------------------------------------------------
  15  Screening settings (-IFTHRS, DIFDEN)  -17    T
@ 15    -40.1917720926        7.77120D-13   -5.68D-14   10

@ *** DIIS converged in  15 iterations !
@     Converged SCF energy, gradient:    -40.191772092641    7.77D-13
    - total time used in SIRFCK :              0.00 seconds


 *** SCF orbital energy analysis ***

 Only the five lowest virtual orbital energies printed in each symmetry.

 Number of electrons :   10
 Orbital occupations :    5

 Sym       Hartree-Fock orbital energies

  1    -11.24614520    -0.91114126    -0.52478334    -0.52478334    -0.52478334
         0.15222200     0.22923252     0.22923252     0.22923252     0.41945542

    E(LUMO) :     0.15222200 au (symmetry 1)
  - E(HOMO) :    -0.52478334 au (symmetry 1)
  ------------------------------------------
    gap     :     0.67700534 au

 >>> Writing SIRIFC interface file <<<

  Canonical primary and secondary basis sets
  ISYM       NORB1 MBAS1       NORB2 MBAS2
     1          42    42          42    42

 Computation of exchange matrix done [6]

 AUXILIARY BASIS LOW EIGENVALUES
 ISYM         EIGENVALUE
   1      0.006483084240
 >>>  Time used in R12AUX     is   3.16 seconds

 >>>> CPU and wall time for SCF :       7.769       8.528
)";