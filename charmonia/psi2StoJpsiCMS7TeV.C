/*
Ratios of production cross section times branching fractions between ψ(2S) mesons and J/ψ mesons in bins of pT for prompt production

CMS data at 7 TeV https://inspirehep.net/literature/1345023

in percent!!!

*/

/// pt-differential cross section ratio for |y| < 1.2 (https://www.hepdata.net/record/ins1345023?version=1&table=Table%205)
const Int_t nPtPoints_psi2S_cms7TeV = 19;

Float_t ptBinning_psi2S_cms7TeV[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22.5, 25, 27.5, 30, 35, 40, 55, 75, 100};

Float_t meanPt_psi2S_cms7TeV[] = {10.5, 11.5, 12.5, 13.5, 14.5, 15.5, 16.5, 17.5, 18.5, 19.5, 21.1, 23.6, 26.1, 28.7, 32.2, 37.2, 45.5, 62.3, 82.9};

Float_t ptDiffRatio_psi2S_cms7TeV[] = {3.75, 3.93, 4.04, 4.11, 4.3, 4.2, 4.39, 4.42, 4.45, 4.37, 4.49, 4.58, 4.69, 4.85, 4.84, 4.47, 4.47, 6.08, 7.64};

Float_t statPtRatio_psi2S_cms7TeV[] = {0.03, 0.03, 0.04, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1, 0.08, 0.1, 0.14, 0.18, 0.18, 0.26, 0.3, 0.8, 1.98};

Float_t systPtRatio_psi2S_cms7TeV[] = {0.11, 0.11, 0.11, 0.11, 0.12, 0.11, 0.12, 0.12, 0.12, 0.11, 0.05, 0.05, 0.04, 0.05, 0.05, 0.05, 0.04, 0.12, 0.41};
