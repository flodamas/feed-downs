/*
Differential cross-section ratios between Y(nS) states (not corrected for branching fractions) for pt < 50 GeV/c

CMS data at 7 TeV https://www.hepdata.net/record/ins1225274

*/

/// rapidity-differential ratios for pt < 50 GeV/c (to be made by hand!!!)

// Y(1S)
Float_t rapidityBinning_1S_cms7TeV[] = {0., 0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2., 2.2, 2.4};
Float_t dy1S_cms7TeV[] = {0.77, 0.777, 0.77, 0.795, 0.761, 0.738, 0.714, 0.738, 0.721, 0.708, 0.636, 0.528};
Float_t stat_dy1S_cms7TeV[] = {0.013, 0.013, 0.013, 0.013, 0.013, 0.013, 0.012, 0.012, 0.012, 0.013, 0.014, 0.022};
Float_t upsyst_dy1S_cms7TeV[] = {0.069, 0.068, 0.068, 0.057, 0.064, 0.043, 0.049, 0.036, 0.04, 0.034, 0.033, 0.04};
Float_t lowsyst_dy1S_cms7TeV[] = {0.056, 0.048, 0.049, 0.043, 0.039, 0.035, 0.031, 0.03, 0.033, 0.036, 0.035, 0.033};

// Y(2S)
Float_t rapidityBinning_2S_cms7TeV[] = {0., 0.4, 0.8, 1.2, 1.6, 2., 2.4};
Float_t dy2S_cms7TeV[] = {0.376, 0.4, 0.38, 0.382, 0.38, 0.295};
Float_t stat_dy2S_cms7TeV[] = {0.009, 0.01, 0.01, 0.01, 0.011, 0.015};
Float_t upsyst_dy2S_cms7TeV[] = {0.036, 0.033, 0.032, 0.026, 0.022, 0.023};
Float_t lowsyst_dy2S_cms7TeV[] = {0.025, 0.025, 0.023, 0.019, 0.024, 0.021};

// Y(3S)
Float_t rapidityBinning_3S_cms7TeV[] = {0., 0.4, 0.8, 1.4, 2., 2.4};
Float_t dy3S_cms7TeV[] = {0.185, 0.202, 0.282, 0.29, 0.164};
Float_t stat_dy3S_cms7TeV[] = {0.007, 0.008, 0.011, 0.012, 0.014};
Float_t upsyst_dy3S_cms7TeV[] = {0.019, 0.019, 0.025, 0.019, 0.017};
Float_t lowsyst_dy3S_cms7TeV[] = {0.015, 0.016, 0.02, 0.022, 0.017};

/// Rebinning to compute the ratios (with weighted averages)

// for Y(2S) / Y(1S)
Float_t rapidityBinning_2Sover1S_cms7TeV[] = {0., 0.4, 0.8, 1.2, 1.6, 2.};

Float_t dy1S_for2S_cms7TeV[] = {2 * 0.7735, 2 * 0.7825, 2 * 0.7495, 2 * 0.7260, 2 * 0.715019};
Float_t stat_dy1S_for2S_cms7TeV[] = {2 * 0.0092, 2 * 0.0092, 2 * 0.00919, 2 * 0.00848528, 2 * 0.00881764};

// for Y(3S) / Y(1S)
Float_t rapidityBinning_3Sover1S_cms7TeV[] = {0., 0.4, 0.8, 1.4, 2.};

Float_t dy1S_for3S_cms7TeV[] = {2 * 0.7735, 2 * 0.7825, 3 * 0.737667, 3 * 0.723077};
Float_t stat_dy1S_for3S_cms7TeV[] = {2 * 0.0092, 2 * 0.0092, 3 * 0.007505, 3 * 0.0071056};

// for Y(3S) / Y(2S)
Float_t rapidityBinning_3Sover2S_cms7TeV[] = {0., 0.4, 0.8, 1.4, 2.};

Float_t dy2S_for3S_cms7TeV[] = {0.376, 0.4, 1.5 * 0.3804, 1.5 * 0.380464};
Float_t stat_dy2S_for3S_cms7TeV[] = {0.009, 0.01, 1.5 * 0.0089, 1.5 * 0.00963837};

/*
Differential cross-section ratios between Y(nS) states (not corrected for branching fractions) for pt < 100 GeV/c

2011 CMS data at 7 TeV https://www.hepdata.net/record/ins1342266

*/

/// pt-differential ratios for |y| < 1.2 (https://www.hepdata.net/record/ins1342266?version=1&table=Table%206)

Float_t ptBinning_cms7TeV[] = {/*10, 12, 14, 16, 18,*/ 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 43, 46, 50, 55, 60, 70, 100};

// Y(2S) / Y(1S)

Float_t ptDiff_2Sto1S_cms7TeV[] = {/*0.33, 0.35, 0.38, 0.41, 0.43,*/ 0.45, 0.46, 0.49, 0.5, 0.5, 0.48, 0.47, 0.53, 0.58, 0.56, 0.55, 0.49, 0.49, 0.59, 0.65, 0.49, 0.56};

Float_t statPerc_2Sto1S_cms7TeV[] = {/*0.7, 0.8, 1., 1.1, 1.3,*/ 1.6, 1.9, 2.2, 2.8, 3.2, 4., 4.7, 5., 5.7, 6.6, 6.6, 8.6, 8.4, 10.1, 12.6, 13.6, 16.};

Float_t systPerc_2Sto1S_cms7TeV[] = {/*6.2, 4.8, 4.1, 4., 3.6,*/ 3.4, 3., 3., 3.2, 3.1, 3.3, 3.8, 3.1, 3.1, 3., 2.9, 4.5, 2.7, 2.6, 2.8, 2.5, 3.3};

// Y(3S) / Y(1S)

Float_t ptDiff_3Sto1S_cms7TeV[] = {/*0.18, 0.21, 0.24, 0.27, 0.29,*/ 0.33, 0.33, 0.32, 0.34, 0.36, 0.35, 0.36, 0.37, 0.44, 0.35, 0.4, 0.5, 0.37, 0.4, 0.65, 0.45, 0.5};

Float_t statPerc_3Sto1S_cms7TeV[] = {/*1.0, 1.1, 1.3, 1.4, 1.6, */ 1.9, 2.2, 2.7, 3.3, 3.7, 4.6, 5.3, 5.9, 6.4, 8.2, 7.5, 8.9, 9.7, 12.5, 12.4, 13.9, 16.5};

Float_t systPerc_3Sto1S_cms7TeV[] = {/*7.4, 5.4, 4.5, 4.3, 3.9, */ 3.7, 3.3, 3.4, 3.4, 3.5, 3.5, 4., 3.5, 3.4, 3.3, 3.2, 3.7, 3.2, 3.6, 3., 2.6, 7.};

// to compute Y(3S) / Y(2S)

Float_t ptDiff_2S_cms7TeV[] = {/*38540.,23088.,14321.,8969.,5665.,*/ 3683., 2393., 1715., 1089., 811., 517., 369., 309., 236., 173., 116., 73., 50., 31., 19., 8.3, 2.2};

Float_t statPerc_2S_cms7TeV[] = {/*0.7,0.8,0.9,1.1,1.3,*/ 1.5, 1.7, 1.9, 2.5, 2.8, 3.8, 4.2, 4.2, 4.8, 5.6, 5.6, 7.2, 7.3, 8.4, 10.7, 12.4, 14.6};

Float_t ptDiff_3S_cms7TeV[] = {/*20882.,13947.,8909.,5873.,3842.,*/ 2648., 1713., 1124., 759., 588., 380., 286., 213., 176., 109., 86., 73., 38., 21., 20., 8.1, 2.3};

Float_t statPerc_3S_cms7TeV[] = {/*1.1,1.,1.3,1.4,1.6,*/ 1.8, 2., 2.4, 3.1, 3.4, 4.5, 5., 5.3, 5.7, 7.5, 6.8, 7.2, 8.7, 11., 10.3, 12.2, 14.};
