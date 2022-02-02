/*
Ratios of production cross section times branching fractions at 13 TeV between ψ(2S) mesons and J/ψ mesons in bins of pT for prompt production

CMS data at 13 TeV https://inspirehep.net/literature/1633431

*/

/// pt-differential cross section ratio (https://www.hepdata.net/record/ins1633431?version=1&table=Table%2011)
const Int_t nPtPoints_psi2S_cms13TeV = 22;

Float_t ptBinning_psi2S_cms13TeV[] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 32, 34, 36, 38, 42, 46, 50, 60, 75, 95, 120, 150};

Float_t ptDiffRatio_psi2S_cms13TeV[] = {0.04, .04, .04, .05, .04, .04, .04, .04, .05, .05, .04, .04, .04, .04, .05, .04, .05, .05, .04, .05, .06, .07};

Float_t statPercPtRatio_psi2S_cms13TeV[] = {3, 3, 3, 3, 4, 4, 5, 5, 5, 6, 5, 6, 6, 7, 6, 9, 10, 10, 42, 10, 21, 71};

Float_t systPercPtRatio_psi2S_cms13TeV[] = {11, 11, 11, 11, 13, 14, 15, 16, 17, 17, 18, 18, 20, 20, 21, 22, 25, 25, 26, 29, 38, 38};
