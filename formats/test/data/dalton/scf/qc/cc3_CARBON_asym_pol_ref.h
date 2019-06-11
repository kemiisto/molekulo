std::string dalton_scf_qc_cc3_CARBON_asym_pol_ref = R"(
        SIRIUS QC-HF optimization (SIROPT)
 ================================================


   <<< OUTPUT FROM SIRCNO >>>    Keyword = ONLYFD

     (Precalculated two-electron integrals are transformed to P-supermatrix elements.
      Threshold for discarding integrals :  1.00D-12 )


 <<< MACRO ITERATION  1 >>>
 --------------------------

 Total MCSCF energy       :           -11.202588104231971  (MACRO    1)

 - Nuclear repulsion      :             0.000000000000000
 - Inactive energy        :           -11.202588104231971
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             2.925557607659
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             2.925557607659
      Virial theorem: -V/T =      1.630989
@      MULPOP C       0.00; 

 Residual norm when dim(red L) =   2
 NEO root     CSF        orbital          total
    1     0.00000000     0.00000000     0.00000000 converged

 (NEONEX) NEO vector is converged.

   <<< OUTPUT FROM SIRCNO >>>    Keyword = FD+NO 



 <<< MACRO ITERATION  2 >>>
 --------------------------

 Total MCSCF energy       :           -12.666589373848407  (MACRO    2)

 - Nuclear repulsion      :             0.000000000000000
 - Inactive energy        :           -12.666589373848407
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             0.737219797736
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             0.737219797736
      Virial theorem: -V/T =      2.070148
@      MULPOP C       0.00; 

 Residual norm when dim(red L) =   2
 NEO root     CSF        orbital          total
    1     0.00000000     0.00000000     0.00000000 converged

 (NEONEX) NEO vector is converged.

   <<< OUTPUT FROM SIRCNO >>>    Keyword = FD+NO 



 <<< MACRO ITERATION  3 >>>
 --------------------------

 Total MCSCF energy       :           -12.706304076850222  (MACRO    3)

 - Nuclear repulsion      :             0.000000000000000
 - Inactive energy        :           -12.706304076850222
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             0.039572002949
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             0.039572002949
      Virial theorem: -V/T =      2.189817
@      MULPOP C      -0.00; 

 Residual norm when dim(red L) =   2
 NEO root     CSF        orbital          total
    1     0.00000000     0.00000000     0.00000000 converged

 (NEONEX) NEO vector is converged.

   <<< OUTPUT FROM SIRCNO >>>    Keyword = FD+NO 



 <<< MACRO ITERATION  4 >>>
 --------------------------

 Total MCSCF energy       :           -12.706411938684106  (MACRO    4)

 - Nuclear repulsion      :             0.000000000000000
 - Inactive energy        :           -12.706411938684106
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             0.000072746071
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             0.000072746071
      Virial theorem: -V/T =      2.183575
@      MULPOP C      -0.00; 

 Residual norm when dim(red L) =   2
 NEO root     CSF        orbital          total
    1     0.00000000     0.00000000     0.00000000 converged

 (NEONEX) NEO vector is converged.

   <<< OUTPUT FROM SIRCNO >>>    Keyword = FD+NO 



 <<< MACRO ITERATION  5 >>>
 --------------------------

 Total MCSCF energy       :           -12.706411939049516  (MACRO    5)

 - Nuclear repulsion      :             0.000000000000000
 - Inactive energy        :           -12.706411939049516
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             0.000000000252
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             0.000000000252
      Virial theorem: -V/T =      2.183563
@      MULPOP C       0.00; 

 (SIRSTP) Close to convergence, ratio set to one.
 Energy difference; actual and predicted:   -3.65411D-10   -3.65413D-10

 (SIRSTP) Close to convergence, ratio set to one.
 Energy difference; actual and predicted:    9.99993D-01
 Close to convergence, ratio set to one.

 Residual norm when dim(red L) =   2
 NEO root     CSF        orbital          total
    1     0.00000000     0.00000000     0.00000000 converged

 (NEONEX) NEO vector is converged.

   <<< OUTPUT FROM SIRCNO >>>    Keyword = FD+NO 



 <<< MACRO ITERATION  6 >>>
 --------------------------

 Total MCSCF energy       :           -12.706411939049520  (MACRO    6)

 - Nuclear repulsion      :             0.000000000000000
 - Inactive energy        :           -12.706411939049520
 - Active energy          :             0.000000000000000

 Norm of total gradient   :             0.000000000000
 -    of CI gradient      :             0.000000000000
 -    of orbital gradient :             0.000000000000
      Virial theorem: -V/T =      2.183563
@      MULPOP C      -0.00; 

 (SIRSTP) Close to convergence, ratio set to one.
 Energy difference; actual and predicted:   -3.55271D-15   -4.36773D-21

 (SIRSTP) Close to convergence, ratio set to one.
 Energy difference; actual and predicted:    8.13400D+05
 Close to convergence, ratio set to one.

 *** Optimization control: QC-HF converged ***
     Number of macro iterations used            6
     Number of micro iterations used            5
     Total number of CPU seconds used         0.00


 *** SCF orbital energy analysis ***

 Only the five lowest virtual orbital energies printed in each symmetry.

 Number of electrons :    6
 Orbital occupations :    0    1    1    0    1    0    0    0

 Sym       Hartree-Fock orbital energies

  2     -0.59853018     0.53749590

  3     -0.59853018     0.53749590

  5     -0.59853018     0.53749590

    E(LUMO) :     0.53749590 au (symmetry 2)
  - E(HOMO) :    -0.59853018 au (symmetry 3)
  ------------------------------------------
    gap     :     1.13602608 au

 >>>> CPU and wall time for SCF :       0.005       0.004
)";