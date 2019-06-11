std::string dalton_scf_qc_water_hf_not_converged = R"(
        SIRIUS QC-HF optimization (SIROPT)
 ================================================


   <<< OUTPUT FROM SIRCNO >>>    Keyword = ONLYFD

     (Precalculated two-electron integrals are transformed to P-supermatrix elements.
      Threshold for discarding integrals :  1.00D-12 )


 <<< MACRO ITERATION  1 >>>
 --------------------------

 Total QC-HF energy       :           -75.397166677311503  (MACRO    1)

 - Nuclear repulsion      :             9.157239627729570
 - Inactive energy        :           -84.554406305041070
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

 Total QC-HF energy       :           -75.585044187857960  (MACRO    2)

 - Nuclear repulsion      :             9.157239627729570
 - Inactive energy        :           -84.742283815587527
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

 Total QC-HF energy       :           -75.585805579057819  (MACRO    3)

 - Nuclear repulsion      :             9.157239627729570
 - Inactive energy        :           -84.743045206787386
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             0.006382088927
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             0.006382088927
      Virial theorem: -V/T =      2.001826
@      MULPOP O      -0.74; H   _1  0.37; H   _2  0.37; 

 *** Optimization control WARNING: QC-HF not converged ***
     Maximum number of iterations or backsteps reached:
     Number of macro iterations used            3
        Maximum                                 3
     Number of micro iterations used            4
        Maximum                                36
     Number of back steps this macro            0
        Maximum                                 5
     Total number of CPU seconds used         0.01

 >>>> CPU and wall time for SCF :       0.012       0.025
)";
