std::string dalton_scf_diis_cc2_r12_aux_n2_gamma2_ref = R"(
 >>>>> DIIS optimization of Hartree-Fock <<<<<

 C1-DIIS algorithm; max error vectors =   10

 Automatic occupation of symmetries with  14 electrons.

 Iter     Total energy    Error norm  Delta(E)    SCF occupation
 -----------------------------------------------------------------------------
   1  Screening settings (-IFTHRS, DIFDEN)   -6    T

***  INFO  GETGAB: GABAOXXX not found on AOPROPER. Regenerating.
@  1  -99.9001864071       8.40D+00  -9.99D+01     2   1   1   0   2   1   0   0
      Virial theorem: -V/T =      1.764633
@      MULPOP N   _1 -0.00; N   _2 -0.00; 
 -----------------------------------------------------------------------------
   2  Screening settings (-IFTHRS, DIFDEN)   -6    T
@  2  -106.570438337       6.17D+00  -6.67D+00     3   1   1   0   2   0   0   0
      Virial theorem: -V/T =      2.068769
@      MULPOP N   _1 -0.00; N   _2 -0.00; 
 -----------------------------------------------------------------------------
   3  Screening settings (-IFTHRS, DIFDEN)   -6    T
@  3  -108.865160281       1.19D+00  -2.29D+00     3   1   1   0   2   0   0   0
      Virial theorem: -V/T =      2.012765
@      MULPOP N   _1 -0.00; N   _2 -0.00; 
 -----------------------------------------------------------------------------
   4  Screening settings (-IFTHRS, DIFDEN)   -6    T
@  4  -108.950942395       1.77D-01  -8.58D-02     3   1   1   0   2   0   0   0
      Virial theorem: -V/T =      2.003496
@      MULPOP N   _1  0.00; N   _2  0.00; 
 -----------------------------------------------------------------------------
   5  Screening settings (-IFTHRS, DIFDEN)   -8    F
@  5  -108.954044008       3.11D-02  -3.10D-03     3   1   1   0   2   0   0   0
      Virial theorem: -V/T =      2.001923
@      MULPOP N   _1 -0.00; N   _2 -0.00; 
 -----------------------------------------------------------------------------
   6  Screening settings (-IFTHRS, DIFDEN)   -8    T
@  6  -108.954130007       2.84D-03  -8.60D-05     3   1   1   0   2   0   0   0
      Virial theorem: -V/T =      2.002181
@      MULPOP N   _1 -0.00; N   _2 -0.00; 
 -----------------------------------------------------------------------------
   7  Screening settings (-IFTHRS, DIFDEN)  -10    F
@  7  -108.954130754       4.14D-04  -7.48D-07     3   1   1   0   2   0   0   0
      Virial theorem: -V/T =      2.002201
@      MULPOP N   _1  0.00; N   _2  0.00; 
 -----------------------------------------------------------------------------
   8  Screening settings (-IFTHRS, DIFDEN)  -10    T
@  8  -108.954130767       5.09D-05  -1.22D-08     3   1   1   0   2   0   0   0
      Virial theorem: -V/T =      2.002196
@      MULPOP N   _1 -0.00; N   _2 -0.00; 
 -----------------------------------------------------------------------------
   9  Screening settings (-IFTHRS, DIFDEN)  -12    F
@  9  -108.954130767       3.32D-06  -1.61D-10     3   1   1   0   2   0   0   0
      Virial theorem: -V/T =      2.002197
@      MULPOP N   _1 -0.00; N   _2 -0.00; 
 -----------------------------------------------------------------------------
  10  Screening settings (-IFTHRS, DIFDEN)  -15    F
@ 10  -108.954130767       2.79D-07  -8.81D-13     3   1   1   0   2   0   0   0
      Virial theorem: -V/T =      2.002197
@      MULPOP N   _1 -0.00; N   _2 -0.00; 
 -----------------------------------------------------------------------------
  11  Screening settings (-IFTHRS, DIFDEN)  -15    T
@ 11  -108.954130767       2.51D-08  -2.84D-14     3   1   1   0   2   0   0   0
      Virial theorem: -V/T =      2.002197
@      MULPOP N   _1  0.00; N   _2  0.00; 
 -----------------------------------------------------------------------------
  12  Screening settings (-IFTHRS, DIFDEN)  -15    T
@ 12  -108.954130767       2.15D-09   0.00D+00     3   1   1   0   2   0   0   0
      Virial theorem: -V/T =      2.002197
@      MULPOP N   _1  0.00; N   _2  0.00; 
 -----------------------------------------------------------------------------
  13  Screening settings (-IFTHRS, DIFDEN)  -15    T
@ 13  -108.954130767       2.64D-10   0.00D+00     3   1   1   0   2   0   0   0
      Virial theorem: -V/T =      2.002197
@      MULPOP N   _1 -0.00; N   _2 -0.00; 
 -----------------------------------------------------------------------------
  14  Screening settings (-IFTHRS, DIFDEN)  -15    T
@ 14  -108.954130767       3.00D-11  -2.84D-14     3   1   1   0   2   0   0   0

@ *** DIIS converged in  14 iterations !
@     Converged SCF energy, gradient:   -108.954130766747    3.00D-11
    - total time used in SIRFCK :              0.00 seconds


 *** SCF orbital energy analysis ***

 Only the five lowest virtual orbital energies printed in each symmetry.

 Number of electrons :   14
 Orbital occupations :    3    1    1    0    2    0    0    0

 Sym       Hartree-Fock orbital energies

  1    -15.68643302    -1.47120859    -0.62622749     0.82008402     0.99224378
         1.75739121     2.87449467

  2     -0.60815945     0.87221405     1.88205530

  3     -0.60815945     0.87221405     1.88205530

  4      1.75739121

  5    -15.68303014    -0.77409691     0.59463530     1.14441040     1.64322976
         2.29898758     3.28384200

  6      0.17565814     1.05104251     2.99647723

  7      0.17565814     1.05104251     2.99647723

  8      2.29898758

    E(LUMO) :     0.17565814 au (symmetry 7)
  - E(HOMO) :    -0.60815945 au (symmetry 2)
  ------------------------------------------
    gap     :     0.78381760 au

 >>> Writing SIRIFC interface file <<<

  Canonical primary and secondary basis sets
  ISYM       NORB1 MBAS1       NORB2 MBAS2
     1           7     7           7     7
     2           3     3           3     3
     3           3     3           3     3
     4           1     1           1     1
     5           7     7           7     7
     6           3     3           3     3
     7           3     3           3     3
     8           1     1           1     1

 Computation of exchange matrix done [5]

 AUXILIARY BASIS LOW EIGENVALUES
 ISYM         EIGENVALUE
   1      0.000000000000
   2      0.000000000000
   3      0.000000000000
   4      0.000000000000
   5      0.000000000000
   6      0.000000000000
   7      0.000000000000
   8      0.000000000000

 >>>> CPU and wall time for SCF :       0.373       0.375
)";