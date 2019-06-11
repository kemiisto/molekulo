std::string dalton_scf_qc_cc3_HF_ccpVDZ_asym_pol_ref = R"(
        SIRIUS QC-HF optimization (SIROPT)
 ================================================


   <<< OUTPUT FROM SIRCNO >>>    Keyword = ONLYFD

     (Precalculated two-electron integrals are transformed to P-supermatrix elements.
      Threshold for discarding integrals :  1.00D-15 )


 <<< MACRO ITERATION  1 >>>
 --------------------------

 Total MCSCF energy       :           -93.628855123816152  (MACRO    1)

 - Nuclear repulsion      :             5.193668373494606
 - Inactive energy        :           -98.822523497310755
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             8.748990163229
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             8.748990163229
      Virial theorem: -V/T =      1.742249
@      MULPOP F      -1.07; H       1.07; 

 (SIRNEO) iteration (  1,  2)
 Micro iteration termination criterion met, EVAL(ISTATE+1) = -1.48D+00

   <<< OUTPUT FROM SIRCNO >>>    Keyword = FD+NO 



 <<< MACRO ITERATION  2 >>>
 --------------------------

 Total MCSCF energy       :           -98.569258505426532  (MACRO    2)

 - Nuclear repulsion      :             5.193668373494606
 - Inactive energy        :          -103.762926878921135
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             6.085376458643
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             6.085376458643
      Virial theorem: -V/T =      1.891208
@      MULPOP F      -0.60; H       0.60; 

 Residual norm when dim(red L) =   3
 NEO root     CSF        orbital          total
    1     0.00000000     1.01493370     1.01493370 converged

 (NEONEX) NEO vector is converged.

   <<< OUTPUT FROM SIRCNO >>>    Keyword = FD+NO 



 <<< MACRO ITERATION  3 >>>
 --------------------------

 Total MCSCF energy       :           -99.867871161456378  (MACRO    3)

 - Nuclear repulsion      :             5.193668373494606
 - Inactive energy        :          -105.061539534950981
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             2.110028947460
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             2.110028947460
      Virial theorem: -V/T =      2.034455
@      MULPOP F      -0.10; H       0.10; 

 Residual norm when dim(red L) =   3
 NEO root     CSF        orbital          total
    1     0.00000000     0.03492161     0.03492161 converged

 (NEONEX) NEO vector is converged.

   <<< OUTPUT FROM SIRCNO >>>    Keyword = FD+NO 



 <<< MACRO ITERATION  4 >>>
 --------------------------

 Total MCSCF energy       :          -100.019193968062879  (MACRO    4)

 - Nuclear repulsion      :             5.193668373494606
 - Inactive energy        :          -105.212862341557482
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             0.055206190204
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             0.055206190204
      Virial theorem: -V/T =      1.999860
@      MULPOP F      -0.24; H       0.24; 

 Residual norm when dim(red L) =   3
 NEO root     CSF        orbital          total
    1     0.00000000     0.00200150     0.00200150 converged

 (NEONEX) NEO vector is converged.

   <<< OUTPUT FROM SIRCNO >>>    Keyword = FD+NO 



 <<< MACRO ITERATION  5 >>>
 --------------------------

 Total MCSCF energy       :          -100.019411138017404  (MACRO    5)

 - Nuclear repulsion      :             5.193668373494606
 - Inactive energy        :          -105.213079511512007
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             0.001843182856
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             0.001843182856
      Virial theorem: -V/T =      1.999913
@      MULPOP F      -0.24; H       0.24; 

 Residual norm when dim(red L) =   6
 NEO root     CSF        orbital          total
    1     0.00000000     0.00000036     0.00000036 converged

 (NEONEX) NEO vector is converged.

   <<< OUTPUT FROM SIRCNO >>>    Keyword = FD+NO 



 <<< MACRO ITERATION  6 >>>
 --------------------------

 Total MCSCF energy       :          -100.019411261974994  (MACRO    6)

 - Nuclear repulsion      :             5.193668373494606
 - Inactive energy        :          -105.213079635469597
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             0.000000377586
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             0.000000377586
      Virial theorem: -V/T =      1.999936
@      MULPOP F      -0.24; H       0.24; 

 Residual norm when dim(red L) =   8
 NEO root     CSF        orbital          total
    1     0.00000000     0.00000000     0.00000000 converged

 (NEONEX) NEO vector is converged.

   <<< OUTPUT FROM SIRCNO >>>    Keyword = FD+NO 



 <<< MACRO ITERATION  7 >>>
 --------------------------

 Total MCSCF energy       :          -100.019411261974540  (MACRO    7)

 - Nuclear repulsion      :             5.193668373494606
 - Inactive energy        :          -105.213079635469143
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             0.000000000000
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             0.000000000000
      Virial theorem: -V/T =      1.999936
@      MULPOP F      -0.24; H       0.24; 

 (SIRSTP) Close to convergence, ratio set to one.
 Energy difference; actual and predicted:    4.54747D-13   -3.29784D-15

 (SIRSTP) Close to convergence, ratio set to one.
 Energy difference; actual and predicted:   -1.37892D+02
 Close to convergence, ratio set to one.

 *** Optimization control: QC-HF converged ***
     Number of macro iterations used            7
     Number of micro iterations used           20
     Total number of CPU seconds used         0.01


 *** SCF orbital energy analysis ***

 Only the five lowest virtual orbital energies printed in each symmetry.

 Number of electrons :   10
 Orbital occupations :    3    1    1    0

 Sym       Hartree-Fock orbital energies

  1    -26.27812790    -1.58345225    -0.74719710     0.18383997     0.81004875
         1.41561908     2.13409617     2.49887227

  2     -0.62888914     1.41187802     1.60414910     4.28032814

  3     -0.62888914     1.41187802     1.60414910     4.28032814

  4      4.00435439

    E(LUMO) :     0.18383997 au (symmetry 1)
  - E(HOMO) :    -0.62888914 au (symmetry 3)
  ------------------------------------------
    gap     :     0.81272910 au

 >>>> CPU and wall time for SCF :       0.008       0.007
)";