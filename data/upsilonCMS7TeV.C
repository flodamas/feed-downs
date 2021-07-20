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
