/*
Differential cross-section ratios between Y(nS) states (not corrected for branching fractions) for pt > 20 GeV/c !!!

CMS data at 13 TeV https://www.hepdata.net/record/ins1633431

*/

/// Double-Differential cross-section ratios

Float_t ptBinning_cms13TeV[] = {20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 43, 46, 50, 55, 60, 70, 100, 130};

// Y(2S)-to-Y(1S), |y| < 1.2 (from https://www.hepdata.net/record/ins1633431?version=1&table=Table%2012)

Float_t ptDiff_2Sto1S_cms13TeV[] = {.42, .43, .47, .46, .45, .48, .5, .51, .47, .5, .48, .49, .52, .56, .62, .48, .89};

Float_t statPerc_2Sto1S_cms13TeV[] = {1.7, 2., 2.3, 2.8, 3.2, 3.8, 4.3, 5., 6.1, 6.8, 6.1, 7.7, 8.3, 8.9, 11., 11.14., 40.};

Float_t systPerc_2Sto1S_cms13TeV[] = {8.5, 8.4, 6.9, 6.2, 6.4, 7.8, 6.3, 7.9, 8.3, 8.3, 5.7, 5.4, 5.3, 5.4, 6.2, 6.6, 6.6, 6.6};

// Y(3S)-to-Y(1S), |y| < 1.2 (from https://www.hepdata.net/record/ins1633431?version=1&table=Table%2012)

Float_t ptDiff_3Sto1S_cms13TeV[] = {.28, .31, .32, .33, .33, .35, .37, .38, .4, .47, .36, .36, .4, .43, .43, .46, .46, .35};

Float_t statPerc_3Sto1S_cms13TeV[] = {2., 2.3, 2.7, 3.1, 3.8, 4.3, 4.9, 5.5, 6.4, 6.9, 7., 8.8, 9., 9.8, 12., 12., 14., 52.};

Float_t systPerc_3Sto1S_cms13TeV[] = {9.1, 7.5, 7.1, 6.8, 8.1, 8.9, 8.3, 11., 11., 11., 7.1, 6.6, 6.6, 7.5, 9.2, 11., 14., 14.};
