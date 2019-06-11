std::string dalton_scf_diis_cc2_r12_aux2_bh_a2_ref = R"(
 >>>>> DIIS optimization of Hartree-Fock <<<<<

 C1-DIIS algorithm; max error vectors =   10

 Iter      Total energy        Error norm    Delta(E)  DIIS dim.
 -----------------------------------------------------------------------------
   1  Screening settings (-IFTHRS, DIFDEN)   -6    T
@  1    -23.7919251551        2.34990D+00   -2.38D+01    1
      Virial theorem: -V/T =      1.842685
@      MULPOP B      -0.85; H       0.85; 
 -----------------------------------------------------------------------------
   2  Screening settings (-IFTHRS, DIFDEN)   -6    T
@  2    -24.8475362942        3.24810D-01   -1.06D+00    2
      Virial theorem: -V/T =      2.020807
@      MULPOP B      -0.07; H       0.07; 
 -----------------------------------------------------------------------------
   3  Screening settings (-IFTHRS, DIFDEN)   -8    F
@  3    -24.8632919723        1.01775D-01   -1.58D-02    3
      Virial theorem: -V/T =      2.008046
@      MULPOP B      -0.20; H       0.20; 
 -----------------------------------------------------------------------------
   4  Screening settings (-IFTHRS, DIFDEN)   -8    T
@  4    -24.8661450214        1.99210D-02   -2.85D-03    4
      Virial theorem: -V/T =      2.005996
@      MULPOP B      -0.25; H       0.25; 
 -----------------------------------------------------------------------------
   5  Screening settings (-IFTHRS, DIFDEN)   -8    T
@  5    -24.8662245512        1.60363D-03   -7.95D-05    5
      Virial theorem: -V/T =      2.005979
@      MULPOP B      -0.24; H       0.24; 
 -----------------------------------------------------------------------------
   6  Screening settings (-IFTHRS, DIFDEN)  -10    F
@  6    -24.8662249440        2.87850D-04   -3.93D-07    6
      Virial theorem: -V/T =      2.005930
@      MULPOP B      -0.24; H       0.24; 
 -----------------------------------------------------------------------------
   7  Screening settings (-IFTHRS, DIFDEN)  -10    T
@  7    -24.8662249627        4.42328D-05   -1.87D-08    7
      Virial theorem: -V/T =      2.005927
@      MULPOP B      -0.24; H       0.24; 
 -----------------------------------------------------------------------------
   8  Screening settings (-IFTHRS, DIFDEN)  -12    F
@  8    -24.8662249632        6.36095D-06   -4.55D-10    8
      Virial theorem: -V/T =      2.005926
@      MULPOP B      -0.24; H       0.24; 
 -----------------------------------------------------------------------------
   9  Screening settings (-IFTHRS, DIFDEN)  -15    F
@  9    -24.8662249632        7.38034D-07   -1.02D-11    9
      Virial theorem: -V/T =      2.005927
@      MULPOP B      -0.24; H       0.24; 
 -----------------------------------------------------------------------------
  10  Screening settings (-IFTHRS, DIFDEN)  -15    T
@ 10    -24.8662249632        8.14436D-08   -1.49D-13   10
      Virial theorem: -V/T =      2.005927
@      MULPOP B      -0.24; H       0.24; 
 -----------------------------------------------------------------------------
  11  Screening settings (-IFTHRS, DIFDEN)  -15    T
@ 11    -24.8662249632        5.72005D-09    0.00D+00   10
      Virial theorem: -V/T =      2.005927
@      MULPOP B      -0.24; H       0.24; 
 -----------------------------------------------------------------------------
  12  Screening settings (-IFTHRS, DIFDEN)  -15    T
@ 12    -24.8662249632        3.12455D-10   -1.78D-14   10
      Virial theorem: -V/T =      2.005927
@      MULPOP B      -0.24; H       0.24; 
 -----------------------------------------------------------------------------
  13  Screening settings (-IFTHRS, DIFDEN)  -15    T
@ 13    -24.8662249632        1.31822D-11    3.55D-15   10

@ *** DIIS converged in  13 iterations !
@     Converged SCF energy, gradient:    -24.866224963189    1.32D-11
    - total time used in SIRFCK :              0.00 seconds


 *** SCF orbital energy analysis ***

 Only the five lowest virtual orbital energies printed in each symmetry.

 Number of electrons :    6
 Orbital occupations :    3

 Sym       Hartree-Fock orbital energies

  1     -7.70595215    -0.61638695    -0.24792717    -0.06775641     0.05644934
         0.25454406     0.33040601     0.42240231

    E(LUMO) :    -0.06775641 au (symmetry 1)
  - E(HOMO) :    -0.24792717 au (symmetry 1)
  ------------------------------------------
    gap     :     0.18017076 au

 >>> Writing SIRIFC interface file <<<

  Canonical primary and secondary basis sets
  ISYM       NORB1 MBAS1       NORB2 MBAS2
     1          11    11          18    18

 Computation of exchange matrix done [6]

 AUXILIARY BASIS LOW EIGENVALUES
 ISYM         EIGENVALUE
   1      0.002208830033

 >>>> CPU and wall time for SCF :       0.042       0.042
)";