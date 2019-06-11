std::string dalton_scf_diis_water_hf_not_converged = R"(
 >>>>> DIIS optimization of Hartree-Fock <<<<<

 C1-DIIS algorithm; max error vectors =    8

 Automatic occupation of symmetries with  10 electrons.

 Iter     Total energy    Error norm  Delta(E)    SCF occupation
 -----------------------------------------------------------------------------
     (Precalculated two-electron integrals are transformed to P-supermatrix elements.
      Threshold for discarding integrals :  1.00D-12 )
@  1  -75.3971666773       2.17D+00  -7.54D+01     3   1   1   0
      Virial theorem: -V/T =      1.997114
@      MULPOP O	     -0.38; H	  _1  0.19; H	  _2  0.19; 
 -----------------------------------------------------------------------------
@  2  -75.5791995958       2.71D-01  -1.82D-01     3   1   1   0
      Virial theorem: -V/T =      2.003138
@      MULPOP O	     -0.67; H	  _1  0.34; H	  _2  0.34; 
 -----------------------------------------------------------------------------
@  3  -75.5855993905       5.06D-02  -6.40D-03     3   1   1   0
      Virial theorem: -V/T =      2.002233
@      MULPOP O	     -0.73; H	  _1  0.36; H	  _2  0.36; 
 -----------------------------------------------------------------------------
@  4  -75.5858057410       5.66D-03  -2.06D-04     3   1   1   0
      Virial theorem: -V/T =      2.001782
@      MULPOP O	     -0.74; H	  _1  0.37; H	  _2  0.37; 
 -----------------------------------------------------------------------------
@  5  -75.5858084159       2.76D-03  -2.67D-06     3   1   1   0

WARNING !!! DIIS aborted because max DIIS iterations reached !

 >>>> CPU and wall time for SCF :       0.011       0.267
)";
