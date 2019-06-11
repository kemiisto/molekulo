std::string dalton_scf_qc_water_hf = R"(
        SIRIUS QC-HF optimization (SIROPT)
 ================================================


   <<< OUTPUT FROM SIRCNO >>>    Keyword = ONLYFD

     (Precalculated two-electron integrals are transformed to P-supermatrix elements.
      Threshold for discarding integrals :  1.00D-12 )


  <<< MACRO ITERATION  1 >>>
 --------------------------

 Total QC-HF energy       :           -75.397166677311489  (MACRO    1)

 - Nuclear repulsion      :             9.157239627729570
 - Inactive energy        :           -84.554406305041056
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             2.173669213739
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             2.173669213739
      Virial theorem: -V/T =      1.997114
@      MULPOP O      -0.38; H   _1  0.19; H   _2  0.19; 

 Residual norm when dim(red L) =   3
 NEO root     CSF        orbital          total
    1     0.00000000     0.17975571     0.17975571 converged

 (NEONEX) NEO vector is converged.

   <<< OUTPUT FROM SIRCNO >>>    Keyword = FD+NO 



 <<< MACRO ITERATION  2 >>>
 --------------------------

 Total QC-HF energy       :           -75.585044187858003  (MACRO    2)

 - Nuclear repulsion      :             9.157239627729570
 - Inactive energy        :           -84.742283815587570
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             0.129161652942
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             0.129161652942
      Virial theorem: -V/T =      2.001286
@      MULPOP O      -0.74; H   _1  0.37; H   _2  0.37; 

 Residual norm when dim(red L) =   3
 NEO root     CSF        orbital          total
    1     0.00000000     0.00638328     0.00638328 converged

 (NEONEX) NEO vector is converged.

   <<< OUTPUT FROM SIRCNO >>>    Keyword = FD+NO 



 <<< MACRO ITERATION  3 >>>
 --------------------------

 Total QC-HF energy       :           -75.585805579057805  (MACRO    3)

 - Nuclear repulsion      :             9.157239627729570
 - Inactive energy        :           -84.743045206787372
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             0.006382088927
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             0.006382088927
      Virial theorem: -V/T =      2.001826
@      MULPOP O      -0.74; H   _1  0.37; H   _2  0.37; 

 Residual norm when dim(red L) =   6
 NEO root     CSF        orbital          total
    1     0.00000000     0.00000088     0.00000088 converged

 (NEONEX) NEO vector is converged.

   <<< OUTPUT FROM SIRCNO >>>    Keyword = FD+NO 



 <<< MACRO ITERATION  4 >>>
 --------------------------

 Total QC-HF energy       :           -75.585808994255316  (MACRO    4)

 - Nuclear repulsion      :             9.157239627729570
 - Inactive energy        :           -84.743048621984883
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             0.000004761678
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             0.000004761678
      Virial theorem: -V/T =      2.001837
@      MULPOP O      -0.74; H   _1  0.37; H   _2  0.37; 

 *** Optimization control: QC-HF converged ***
     Number of macro iterations used            4
     Number of micro iterations used            9
     Total number of CPU seconds used         0.01


 *** SCF orbital energy analysis ***

 Only the five lowest virtual orbital energies printed in each symmetry.

 Number of electrons :   10
 Orbital occupations :    3    1    1    0

 Sym       Hartree-Fock orbital energies

1 A1    -20.42409522    -1.32206061    -0.52704007     0.26331690     1.27314111
          1.85830398     3.10430946

2 B1     -0.47639443     1.78510524

3 B2     -0.69199194     0.36340938     1.22120134     2.02915816

    E(LUMO) :     0.26331690 au (symmetry 1)
  - E(HOMO) :    -0.47639443 au (symmetry 2)
  ------------------------------------------
    gap     :     0.73971134 au

 >>>> CPU and wall time for SCF :       0.011       0.021
)";
