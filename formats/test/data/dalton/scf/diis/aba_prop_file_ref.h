std::string dalton_scf_diis_aba_prop_file_ref = R"(
 >>>>> DIIS optimization of Hartree-Fock <<<<<

 C1-DIIS algorithm; max error vectors =   10
 -----------------------------------------------------------------------------
     (Precalculated two-electron integrals are transformed to P-supermatrix elements.
      Threshold for discarding integrals :  1.00D-12 )

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.   1    -112.128425712        1.63457D+00   -1.12D+02   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -2.67D+00
    1.000000
      Virial theorem: -V/T =      2.002358
@      MULPOP C       1.10; O      -0.82; H      -0.14; H      -0.14; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.   2    -112.279310189        1.07267D+00   -1.51D-01   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -9.39D-02
    0.390332    0.609668
      Virial theorem: -V/T =      2.011710
@      MULPOP C      -0.47; O       0.28; H       0.09; H       0.09; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.   3    -112.353421199        5.10041D-02   -7.41D-02   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -1.66D-03
   -0.045535   -0.063425    1.108960
      Virial theorem: -V/T =      2.008826
@      MULPOP C       0.08; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.   4    -112.353675938        1.38491D-02   -2.55D-04   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -3.36D-05
    0.005502   -0.003473   -0.228428    1.226399
      Virial theorem: -V/T =      2.008767
@      MULPOP C       0.07; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.   5    -112.353695014        3.70690D-03   -1.91D-05   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -2.70D-06
   -0.002922    0.000021    0.137674   -0.857772    1.722999
      Virial theorem: -V/T =      2.008740
@      MULPOP C       0.08; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.   6    -112.353697423        6.98061D-04   -2.41D-06   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -7.47D-08
    0.000705   -0.000164   -0.032329    0.228583   -0.630037    1.433242
      Virial theorem: -V/T =      2.008744
@      MULPOP C       0.08; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.   7    -112.353697509        9.36682D-05   -8.56D-08   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -4.39D-10
   -0.000062    0.000024    0.003453   -0.033719    0.127608   -0.433229    1.335924
      Virial theorem: -V/T =      2.008746
@      MULPOP C       0.08; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.   8    -112.353697510        6.52754D-06   -1.02D-09   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -4.87D-12
    0.000014   -0.000004   -0.000805    0.008564   -0.033259    0.117073   -0.373481    1.281898
      Virial theorem: -V/T =      2.008746
@      MULPOP C       0.08; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.   9    -112.353697510        8.41124D-07   -4.72D-12   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -5.83D-14
   -0.000001    0.000000    0.000077   -0.000911    0.003536   -0.012653    0.038194   -0.190839    1.162597
      Virial theorem: -V/T =      2.008746
@      MULPOP C       0.08; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.  10    -112.353697510        8.19246D-08   -8.53D-14   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -1.51D-15
    0.000000    0.000000   -0.000004    0.000073   -0.000292    0.001093   -0.002843    0.023389   -0.241596    1.220180
      Virial theorem: -V/T =      2.008746
@      MULPOP C       0.08; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.  11    -112.353697510        1.46923D-08   -8.53D-14   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -1.28D-17
    1.552492   -0.000000    0.000002   -0.000029    0.000118   -0.000442    0.001093   -0.009627    0.104462   -0.648068
      Virial theorem: -V/T =      2.008746
@      MULPOP C       0.08; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.  12    -112.353697510        1.14741D-09    5.68D-14   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -9.95D-19
   -0.104087    1.076647   -0.000000    0.000002   -0.000007    0.000025   -0.000064    0.000487   -0.004672    0.031670
      Virial theorem: -V/T =      2.008746
@      MULPOP C       0.08; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.  13    -112.353697510        6.02449D-10   -5.68D-14   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -1.97D-19
    0.018589   -0.765893    1.747843    0.000000    0.000000   -0.000000   -0.000000   -0.000000   -0.000215   -0.000324
      Virial theorem: -V/T =      2.008746
@      MULPOP C       0.08; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.  14    -112.353697510        2.64007D-10    1.14D-13   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -1.54D-20
   -0.007184    0.385219   -1.360498    1.982560   -0.000000    0.000000   -0.000001    0.000005    0.000095   -0.000197
      Virial theorem: -V/T =      2.008746
@      MULPOP C       0.08; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.  15    -112.353697510        7.95576D-11   -1.14D-13   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -4.03D-21
    0.003436   -0.150434    0.614194   -1.087985    1.621069    0.000000   -0.000000   -0.000003    0.000023   -0.000298
      Virial theorem: -V/T =      2.008746
@      MULPOP C       0.08; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.  16    -112.353697510        3.62865D-11    0.00D+00   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -3.52D-23
   -0.000654    0.034312   -0.151221    0.315601   -1.217179    2.019110    0.000000    0.000001   -0.000005    0.000034
      Virial theorem: -V/T =      2.008746
@      MULPOP C       0.08; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.  17    -112.353697510        2.18703D-12    5.68D-14   -6    T

 DIIS C vector; C2DIIS = F, LAMBDA = -7.46D-25
    0.000021    0.000086    0.000646   -0.003375    0.033998   -0.078812    1.047445   -0.000000    0.000002   -0.000010
      Virial theorem: -V/T =      2.008746
@      MULPOP C       0.08; O      -0.19; H       0.06; H       0.06; 
 -----------------------------------------------------------------------------

 ITDIIS, energy, error norm, change in energy, scr.thr., difden:
@ DIIS iter.  18    -112.353697510        5.64530D-13    0.00D+00   -6    T

@ *** DIIS converged in  18 iterations !
@     Converged SCF energy, gradient:   -112.353697509557    5.65D-13
    - total time used in SIRFCK :              0.00 seconds


 *** SCF orbital energy analysis ***

 Only the five lowest virtual orbital energies printed in each symmetry.

 Number of electrons :   16
 Orbital occupations :    8

 Sym       Hartree-Fock orbital energies

  1    -20.31162719   -11.12542328    -1.34192804    -0.80369198    -0.63876325
        -0.54427391    -0.44621587    -0.35362572     0.28583524     0.62008686
         0.74574226     0.92100240

    E(LUMO) :     0.28583524 au (symmetry 1)
  - E(HOMO) :    -0.35362572 au (symmetry 1)
  ------------------------------------------
    gap     :     0.63946096 au

 >>> Writing SIRIFC interface file <<<

 >>>> CPU and wall time for SCF :       0.008       0.007
)";