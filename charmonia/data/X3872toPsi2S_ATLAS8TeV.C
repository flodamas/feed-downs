/*
Ratios of production cross section times branching fractions X(3872) and Psi(2S) in bins of pT for prompt production

ATLAS data at 8 TeV https://inspirehep.net/literature/1495026

*/

/// pt-differential cross section ratio for |y| < 0.75 (https://www.hepdata.net/record/ins1495026?version=1&table=Table%204)
const Int_t nPtPoints_X3872_atlas8TeV = 5;

Float_t ptBinning_X3872_atlas8TeV[] = {10, 12, 16, 22, 40, 70};

Float_t meanPt_X3872_atlas8TeV[] = {10.9, 13.5, 18.2, 26.6, 47.6};

Float_t ptDiffRatio_X3872_atlas8TeV[] = {0.065, 0.098, 0.106, 0.107, 0.128};

Float_t statPtRatio_X3872_atlas8TeV[] = {0.014, 0.007, 0.008, 0.011, 0.044};

Float_t systPtRatio_X3872_atlas8TeV[] = {0.004, 0.004, 0.004, 0.004, 0.012};
