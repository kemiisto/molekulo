std::string dalton_coupled_cluster_section_water_cc2 = R"(
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
 Iter.  1: Coupled cluster CC2   energy :     -75.7080232755880616
 Iter.  2: Coupled cluster CC2   energy :     -75.7088253520351913
 Iter.  3: Coupled cluster CC2   energy :     -75.7088651759714821
 Iter.  4: Coupled cluster CC2   energy :     -75.7088564496682608
 Iter.  5: Coupled cluster CC2   energy :     -75.7088567780194950
 Iter.  6: Coupled cluster CC2   energy :     -75.7088571750223878
 Iter.  7: Coupled cluster CC2   energy :     -75.7088571888367596
 Iter.  8: Coupled cluster CC2   energy :     -75.7088571863635735

 CC2   energy converged to within   0.10D-07 is          -75.708857186364
 Final 2-norm of the CC vector function:  3.75805434D-07





             +-------------------------------------------------------+
             ! Final results from the Coupled Cluster energy program !
             +-------------------------------------------------------+



            Total SCF   energy:                   -75.5858089943

            Total MP2   energy:                   -75.7080410460

            Total CC2   energy:                   -75.7088571864
  

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
            Total CC2   energy:                   -75.7088571864                
  

 *******************************************************************************
 *******************************************************************************
 *                                                                             *
 *                                                                             *
 *                      END OF COUPLED CLUSTER CALCULATION                     *
 *                                                                             *
 *                                                                             *
 *******************************************************************************
 *******************************************************************************


 >>>> CPU and wall time for CC :       0.051       0.474

 
     Date and time (Linux)  : Sun May 24 19:55:51 2015
     Host name              : login-0-1.local                         


                      .-------------------------------------.
                      | End of Coupled Cluster Section (CC) |
                      `-------------------------------------'
)";