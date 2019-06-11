std::string dalton_coupled_cluster_section_water_cc_t = R"(
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
 Iter.  1: Coupled cluster CCSD  energy :     -75.7114047772544438
 Iter.  2: Coupled cluster CCSD  energy :     -75.7150068138121242
 Iter.  3: Coupled cluster CCSD  energy :     -75.7152816480859343
 Iter.  4: Coupled cluster CCSD  energy :     -75.7153071378344436
 Iter.  5: Coupled cluster CCSD  energy :     -75.7152981874026949
 Iter.  6: Coupled cluster CCSD  energy :     -75.7152973446152373
 Iter.  7: Coupled cluster CCSD  energy :     -75.7152973796429478
 Iter.  8: Coupled cluster CCSD  energy :     -75.7152972480084969
 Iter.  9: Coupled cluster CCSD  energy :     -75.7152972493591392

 CCSD  energy converged to within   0.10D-07 is          -75.715297249359
 Final 2-norm of the CC vector function:  5.57509524D-07





             +-------------------------------------------------------+
             ! Final results from the Coupled Cluster energy program !
             +-------------------------------------------------------+



            Total SCF   energy:                   -75.5858089943

            Total MP2   energy:                   -75.7080410460

            Total CCSD  energy:                   -75.7152972494


                     Perturbative triples corrections
                     --------------------------------

            The E4 doubles and triples:            -0.0014066167
            The E5 singles and triples:             0.0000809740

            Total energy CCSD(T):                 -75.7166228920
  

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
            Total CCSD  energy:                   -75.7152972494                
                                                                                
                                                                                
                     Perturbative triples corrections                           
                     --------------------------------                           
                                                                                
            The E4 doubles and triples:            -0.0014066167                
            The E5 singles and triples:             0.0000809740                
                                                                                
            Total energy CCSD(T):                 -75.7166228920                
  

 *******************************************************************************
 *******************************************************************************
 *                                                                             *
 *                                                                             *
 *                      END OF COUPLED CLUSTER CALCULATION                     *
 *                                                                             *
 *                                                                             *
 *******************************************************************************
 *******************************************************************************


 >>>> CPU and wall time for CC :       0.125       0.725

 
     Date and time (Linux)  : Sun May 24 19:47:27 2015
     Host name              : login-0-1.local                         


                      .-------------------------------------.
                      | End of Coupled Cluster Section (CC) |
                      `-------------------------------------'
)";