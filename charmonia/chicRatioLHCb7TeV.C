/*

Cross-section ratio Chi_c2(1P)/Chi_c1(1P) as a function of J/psi pt

LHCb measurements at 7 TeV https://inspirehep.net/literature/1242869

*/

const Int_t nPoints_chic_lhcb7TeV = 10;

Float_t ptBinning_chic_lhcb7TeV[] = {3, 4, 5, 6, 7, 8, 9, 11, 13, 16, 20};

Float_t ratio2to1_chic_lhcb7TeV[] = {1.037, 0.923, 0.795, 0.746, 0.692, 0.699, 0.625, 0.6, 0.675, 0.581};

Float_t stat_ratio2to1_chic_lhcb7TeV[] = {0.033, 0.029, 0.028, 0.032, 0.039, 0.044, 0.035, 0.057, 0.067, 0.096};

Float_t syst_ratio2to1_chic_lhcb7TeV[] = {0.06, 0.06, 0.048, 0.044, 0.04, 0.041, 0.036, 0.036, 0.051, 0.038};

Float_t brSyst_ratio2to1_chic_lhcb7TeV[] = {0.1, 0.08, 0.1};

// scale the pT for chi_b

Float_t ptScaled_chic_lhcb7TeV[nPoints_chic_lhcb7TeV];

for (Int_t i = 0; i < nPoints_chic_lhcb7TeV; i++) ptScaled_chic_lhcb7TeV[i] = 2.8 * ptBinning_chic_lhcb7TeV[i];
