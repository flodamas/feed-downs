/*
Ratios of production cross-sections at 13 TeV between ψ(2S) mesons and J/ψ mesons in bins of pT for prompt production

LHCb data at 13 TeV https://inspirehep.net/literature/1748712

already corrected for branching fractions

*/

/// pt-differential cross section ratio (Table 12 in the paper)
const Int_t nPtPoints_psi2S_lhcb13TeV = 12;

Float_t ptBinning_psi2S_lhcb13TeV[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

Float_t ptDiffRatio_psi2S_lhcb13TeV[] = {.14, .16, .18, .20, .23, .26, .27, .28, .31, .31, .32, .29};

Float_t errorPtDiffRatio_psi2S_lhcb13TeV[] = {.01, .01, .01, .01, .02, .02, .02, .01, .02, .02, .03, .03};
