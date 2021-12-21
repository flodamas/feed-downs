/*

Nuclear modification factors measured by CMS at 5.02 TeV (from https://www.hepdata.net/record/ins1674529)

as a function of pt to estimate the direct suppression(s)

*/

Double_t globalSyst_RAACMS = TMath::Hypot(4.14, 4.57) / 100;

// 1S
const Int_t nRAAbins_CMS1S = 6;
Double_t binningRAA_CMS1S[nCMSbins1S + 1] = {0, 2, 4, 6, 9, 12, 30};
Double_t ptBinsRAA_CMS1S[nCMSbins1S] = {1, 3, 5, 7.5, 10.5, 21};

Double_t resultRAA_CMS1S[nCMSbins1S] = {0.301, 0.362, 0.388, 0.402, 0.422, 0.425};
Double_t statRAA_CMS1S[nCMSbins1S] = {0.027, 0.029, 0.033, 0.028, 0.035, 0.026};
Double_t systRAA_CMS1S[nCMSbins1S] = {0.123, 0.035, 0.035, 0.032, 0.045, 0.036};

// 2S
const Int_t nRAAbins_CMS2S = 3;
Double_t binningRAA_CMS2S[nCMSbins2S + 1] = {0, 4, 9, 30};
Double_t ptBinsRAA_CMS2S[nCMSbins2S] = {2, 6.5, 19.5};

Double_t resultRAA_CMS2S[] = {0.085, 0.129, 0.126};
Double_t statRAA_CMS2S[] = {0.039, 0.038, 0.032};
Double_t systRAA_CMS2S[] = {0.095, 0.031, 0.016};
