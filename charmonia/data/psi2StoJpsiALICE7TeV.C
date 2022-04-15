/*
Ratios of production cross-sections at 7 TeV between ψ(2S) mesons and J/ψ mesons in bins of pT for INCLUSIVE production

ALICE data at 7 TeV https://inspirehep.net/literature/1285950

already corrected for dimuon branching fractions

*/

/// pt-differential cross section ratio https://www.hepdata.net/record/ins1285950?version=1&table=Table%207
const Int_t nPtPoints_psi2S_alice7TeV = 9;

Float_t ptBinning_psi2S_alice7TeV[] = {0, 1, 2, 3, 4, 5, 6, 8, 10, 12};

Float_t ptDiffRatio_psi2S_alice7TeV[] = {0.097, 0.173, 0.148, 0.176, 0.215, 0.282, 0.218, 0.356, 0.416};

Float_t statPtDiffRatio_psi2S_alice7TeV[] = {0.026, 0.022, 0.024, 0.029, 0.033, 0.05, 0.045, 0.078, 0.143};

Float_t systPtDiffRatio_psi2S_alice7TeV[] = {0.007, 0.015, 0.011, 0.019, 0.019, 0.028, 0.016, 0.028, 0.031};
