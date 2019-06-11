std::string dalton_coupled_cluster_section_water_ccd = R"(
                    .------------------------------------------.
                    | Starting in Coupled Cluster Section (CC) |
                    `------------------------------------------'

  

 *******************************************************************************
 *******************************************************************************
 *                                                                             *
 *                                                                             *
 *                    START OF COUPLED CLUSTER CALCULATION                     *
 *                                                                             *
 *                                                                             *
 *******************************************************************************
 *******************************************************************************



 CCR12 ANSATZ =   0

 CCR12 APPROX =   0

   

 *******************************************************************
 *                                                                 *
 *<<<<<<<<<<                                             >>>>>>>>>>*
 *<<<<<<<<<< OUTPUT FROM COUPLED CLUSTER ENERGY PROGRAM  >>>>>>>>>>*
 *<<<<<<<<<<                                             >>>>>>>>>>*
 *                                                                 *
 *******************************************************************

 
             The Direct Coupled Cluster Energy Program
             -----------------------------------------


          Number of t1 amplitudes                 :        16
          Number of t2 amplitudes                 :       265
          Total number of amplitudes in ccsd      :       281
 
 Iter.  1: Coupled cluster MP2   energy :     -75.7080410459820428
 Iter.  1: Coupled cluster CCD   energy :     -75.7114225476481266
 Iter.  2: Coupled cluster CCD   energy :     -75.7144965483238366
 Iter.  3: Coupled cluster CCD   energy :     -75.7144698768817932
 Iter.  4: Coupled cluster CCD   energy :     -75.7145072172477427
 Iter.  5: Coupled cluster CCD   energy :     -75.7145069949516625
 Iter.  6: Coupled cluster CCD   energy :     -75.7145068376580781
 Iter.  7: Coupled cluster CCD   energy :     -75.7145070501725286
 Iter.  8: Coupled cluster CCD   energy :     -75.7145070435463055

 CCD   energy converged to within   0.10D-07 is          -75.714507043546
 Final 2-norm of the CC vector function:  5.84777032D-07





             +-------------------------------------------------------+
             ! Final results from the Coupled Cluster energy program !
             +-------------------------------------------------------+



            Total SCF   energy:                   -75.5858089943

            Total MP2   energy:                   -75.7080410460

            Total CCD   energy:                   -75.7145070435
  

 *******************************************************************************
 *******************************************************************************
 *                                                                             *
 *                                                                             *
 *                   SUMMARY OF COUPLED CLUSTER CALCULATION                    *
 *                                                                             *
 *                                                                             *
 *******************************************************************************
 *******************************************************************************

                                                                                
                                                                                
            Total SCF   energy:                   -75.5858089943                
            Total MP2   energy:                   -75.7080410460                
            Total CCD   energy:                   -75.7145070435                
  

 *******************************************************************************
 *******************************************************************************
 *                                                                             *
 *                                                                             *
 *                      END OF COUPLED CLUSTER CALCULATION                     *
 *                                                                             *
 *                                                                             *
 *******************************************************************************
 *******************************************************************************


 >>>> CPU and wall time for CC :       0.078       0.509

 
     Date and time (Linux)  : Sun May 24 19:59:42 2015
     Host name              : login-0-1.local                         


                      .-------------------------------------.
                      | End of Coupled Cluster Section (CC) |
                      `-------------------------------------'
)";