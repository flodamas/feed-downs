/*
Differential cross-section ratios between Y(nS) states (not corrected for branching fractions) for pt > 20 GeV/c !!!

CMS data at 13 TeV https://www.hepdata.net/record/ins1633431

*/

Float_t ptBinning_cms13TeV[] = {20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 43, 46, 50, 55, 60, 70, 100};

/// Double-Differential cross-section ratios

// Y(2S)-to-Y(1S), |y| < 1.2 (from https://www.hepdata.net/record/ins1633431?version=1&table=Table%2012)

Float_t ptDiff_2Sto1S_cms13TeV[] = {.42, .43, .47, .46, .45, .48, .5, .51, .47, .5, .48, .48, .49, .52, .56, .62, .48};

Float_t statPerc_2Sto1S_cms13TeV[] = {1.7, 2., 2.3, 2.8, 3.2, 3.8, 4.3, 5., 6.1, 6.8, 6.1, 7.7, 8.3, 8.9, 11., 11., 14.};

Float_t systPerc_2Sto1S_cms13TeV[] = {8.5, 8.4, 6.9, 6.2, 6.4, 7.8, 6.3, 7.9, 8.3, 8.3, 5.7, 5.4, 5.3, 5.4, 6.2, 6.6, 6.6};

// Y(3S)-to-Y(1S), |y| < 1.2 (from https://www.hepdata.net/record/ins1633431?version=1&table=Table%2012)

Float_t ptDiff_3Sto1S_cms13TeV[] = {.28, .31, .32, .33, .33, .35, .37, .38, .4, .47, .36, .36, .4, .43, .43, .46, .46};

Float_t statPerc_3Sto1S_cms13TeV[] = {2., 2.3, 2.7, 3.1, 3.8, 4.3, 4.9, 5.5, 6.4, 6.9, 7., 8.8, 9., 9.8, 12., 12., 14.};

Float_t systPerc_3Sto1S_cms13TeV[] = {9.1, 7.5, 7.1, 6.8, 8.1, 8.9, 8.3, 11., 11., 11., 7.1, 6.6, 6.6, 7.5, 9.2, 11., 14.};

// compute Y(3S) / Y(2S) by hand

/// Y(2S) pt-differential cross section for |y| < 1.2 (from https://www.hepdata.net/record/ins1633431?version=1&table=Table%204)

Float_t ptDiff_2S_cms13TeV[] = {2.38, 1.57, 1.16, 0.789, 0.545, 0.414, 0.318, 0.241, 0.157, 0.126, 0.0989, 0.0619, 0.0393, 0.0268, 0.0188, 0.00996, 0.00208};

Float_t statPerc_2S_cms13TeV[] = {1.4, 1.7, 1.9, 2.3, 2.7, 3.1, 3.6, 4.1, 5., 5.7, 5., 6.4, 6.9, 7.3, 8.6, 8.8, 12.};

Float_t systPerc_2S_cms13TeV[] = {6.4, 6.8, 5.8, 5.6, 5.5, 6.3, 5.5, 6., 5.6, 5.6, 5.1, 4.7, 5., 4.9, 5.1, 5.5, 5.9};

/// Y(3S) pt-differential cross section for |y| < 1.2 (from https://www.hepdata.net/record/ins1633431?version=1&table=Table%205)

Float_t ptDiff_3S_cms13TeV[] = {1.6, 1.13, 0.788, 0.579, 0.396, 0.301, 0.234, 0.182, 0.134, 0.119, 0.0733, 0.0459, 0.0324, 0.0224, 0.0143, 0.00736, 0.00198};

Float_t statPerc_3S_cms13TeV[] = {1.8, 2., 2.4, 2.8, 3.3, 3.8, 4.3, 4.7, 5.4, 5.7, 6.1, 7.7, 8.4, 11., 10., 12.};

Float_t systPerc_3S_cms13TeV[] = {6.7, 6.2, 6.1, 6.3, 6.8, 7., 6.8, 7.9, 8., 7.9, 6.1, 5.8, 6., 6.9, 8.3, 10., 13.};
