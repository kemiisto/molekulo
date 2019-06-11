std::string dalton_scf_diis_cc2_r12_aux_h2o_a2_ref = R"(
 >>>>> DIIS optimization of Hartree-Fock <<<<<

 C1-DIIS algorithm; max error vectors =   10

 Iter      Total energy        Error norm    Delta(E)  DIIS dim.
 -----------------------------------------------------------------------------
   1  Screening settings (-IFTHRS, DIFDEN)   -7    T

***  INFO  GETGAB: GABAOXXX not found on AOPROPER. Regenerating.
@  1    -61.9064868849        2.30241D+01   -6.19D+01    1
      Virial theorem: -V/T =      1.513486
@      MULPOP O      -1.89; H       0.95; H       0.95; 
 -----------------------------------------------------------------------------
   2  Screening settings (-IFTHRS, DIFDEN)   -7    T
@  2    -67.5183719652        8.23744D+00   -5.61D+00    2
      Virial theorem: -V/T =      2.101881
@      MULPOP O       5.53; H      -2.77; H      -2.77; 
 -----------------------------------------------------------------------------
   3  Screening settings (-IFTHRS, DIFDEN)   -7    T
@  3    -73.7989315582        7.47588D+00   -6.28D+00    3
      Virial theorem: -V/T =      1.837753
@      MULPOP O      -1.68; H       0.84; H       0.84; 
 -----------------------------------------------------------------------------
   4  Screening settings (-IFTHRS, DIFDEN)   -7    T
@  4    -75.6877048599        2.58523D+00   -1.89D+00    4
      Virial theorem: -V/T =      1.948019
@      MULPOP O      -1.30; H       0.65; H       0.65; 
 -----------------------------------------------------------------------------
   5  Screening settings (-IFTHRS, DIFDEN)   -7    T
@  5    -76.0063796622        1.33067D-01   -3.19D-01    5
      Virial theorem: -V/T =      1.999631
@      MULPOP O      -0.88; H       0.44; H       0.44; 
 -----------------------------------------------------------------------------
   6  Screening settings (-IFTHRS, DIFDEN)   -9    F
@  6    -76.0082538736        7.28542D-02   -1.87D-03    6
      Virial theorem: -V/T =      2.001202
@      MULPOP O      -0.80; H       0.40; H       0.40; 
 -----------------------------------------------------------------------------
   7  Screening settings (-IFTHRS, DIFDEN)   -9    T
@  7    -76.0085436998        8.05379D-03   -2.90D-04    7
      Virial theorem: -V/T =      1.999713
@      MULPOP O      -0.79; H       0.40; H       0.40; 
 -----------------------------------------------------------------------------
   8  Screening settings (-IFTHRS, DIFDEN)   -9    T
@  8    -76.0085548901        1.44595D-03   -1.12D-05    8
      Virial theorem: -V/T =      1.999736
@      MULPOP O      -0.79; H       0.40; H       0.40; 
 -----------------------------------------------------------------------------
   9  Screening settings (-IFTHRS, DIFDEN)  -11    F
@  9    -76.0085552884        2.64137D-04   -3.98D-07    9
      Virial theorem: -V/T =      1.999736
@      MULPOP O      -0.79; H       0.40; H       0.40; 
 -----------------------------------------------------------------------------
  10  Screening settings (-IFTHRS, DIFDEN)  -11    T
@ 10    -76.0085552985        6.66374D-05   -1.01D-08   10
      Virial theorem: -V/T =      1.999736
@      MULPOP O      -0.79; H       0.40; H       0.40; 
 -----------------------------------------------------------------------------
  11  Screening settings (-IFTHRS, DIFDEN)  -11    T
@ 11    -76.0085552989        1.06287D-05   -3.37D-10   10
      Virial theorem: -V/T =      1.999735
@      MULPOP O      -0.79; H       0.40; H       0.40; 
 -----------------------------------------------------------------------------
  12  Screening settings (-IFTHRS, DIFDEN)  -13    F
@ 12    -76.0085552989        8.16565D-07   -7.67D-12   10
      Virial theorem: -V/T =      1.999735
@      MULPOP O      -0.79; H       0.40; H       0.40; 
 -----------------------------------------------------------------------------
  13  Screening settings (-IFTHRS, DIFDEN)  -16    F
@ 13    -76.0085552989        1.02986D-07    0.00D+00   10
      Virial theorem: -V/T =      1.999735
@      MULPOP O      -0.79; H       0.40; H       0.40; 
 -----------------------------------------------------------------------------
  14  Screening settings (-IFTHRS, DIFDEN)  -16    T
@ 14    -76.0085552989        9.29853D-09   -1.42D-14   10
      Virial theorem: -V/T =      1.999735
@      MULPOP O      -0.79; H       0.40; H       0.40; 
 -----------------------------------------------------------------------------
  15  Screening settings (-IFTHRS, DIFDEN)  -16    T
@ 15    -76.0085552989        7.17402D-10   -2.84D-14   10
      Virial theorem: -V/T =      1.999735
@      MULPOP O      -0.79; H       0.40; H       0.40; 
 -----------------------------------------------------------------------------
  16  Screening settings (-IFTHRS, DIFDEN)  -16    T
@ 16    -76.0085552989        6.72432D-11   -1.42D-14   10

@ *** DIIS converged in  16 iterations !
@     Converged SCF energy, gradient:    -76.008555298862    6.72D-11
    - total time used in SIRFCK :              0.00 seconds


 *** SCF orbital energy analysis ***

 Only the five lowest virtual orbital energies printed in each symmetry.

 Number of electrons :   10
 Orbital occupations :    5

 Sym       Hartree-Fock orbital energies

  1    -20.55592147    -1.35102480    -0.70370486    -0.56185905    -0.50342293
         0.13921191     0.21169558     0.55054994     0.58845705     1.00026935

    E(LUMO) :     0.13921191 au (symmetry 1)
  - E(HOMO) :    -0.50342293 au (symmetry 1)
  ------------------------------------------
    gap     :     0.64263484 au

 >>> Writing SIRIFC interface file <<<

  Canonical primary and secondary basis sets
  ISYM       NORB1 MBAS1       NORB2 MBAS2
     1          19    19          36    36

 Computation of exchange matrix done [6]

 AUXILIARY BASIS LOW EIGENVALUES
 ISYM         EIGENVALUE
   1      0.000049708918
 >>>  Time used in R12AUX     is   0.14 seconds

 >>>> CPU and wall time for SCF :       0.287       0.289
)";