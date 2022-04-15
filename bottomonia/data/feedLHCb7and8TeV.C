// LHCb measurements at 7 and 8 TeV, from https://www.hepdata.net/record/ins1308738

/// Feed-down contributions to Y(1S) (in %)

// Chi_b(1P) -> Y(1S)
const int nPoints1Pto1S_lhcb = 6;
Float_t ptBinning1Pto1S_lhcb[] = {6, 8, 10, 14, 18, 22, 40};

Float_t frac1Pto1S_lhcb7TeV[] = {14.8, 17.2, 21.3, 24.4, 27.2, 29.2};
Float_t stat1Pto1S_lhcb7TeV[] = {1.2, 1.0, 0.8, 1.3, 2.1, 2.5};
Float_t syst1Pto1S_lhcb7TeV[] = {1.3, 1.4, 1.4, 1.2, 2.1, 1.7};

Float_t frac1Pto1S_lhcb8TeV[] = {15.5, 18.5, 23.2, 24.2, 26.0, 28.5};
Float_t stat1Pto1S_lhcb8TeV[] = {0.9, 0.7, 0.6, 0.9, 1.4, 1.8};
Float_t syst1Pto1S_lhcb8TeV[] = {1.3, 1.5, 1.4, 1.2, 1.2, 2.1};

Float_t frac1Pto1S_weightedLHCb[] = {15.2, 18.1, 22.5, 24.3, 28.6, 28.7};
Float_t stat1Pto1S_weightedLHCb[] = {0.7, 0.6, 0.5, 0.7, 1.2, 1.5};
Float_t syst1Pto1S_weightedLHCb[] = {1.3, 1.5, 1.4, 1.2, 1.5, 2.0};

// Chi_b(2P) -> Y(1S) feed-down fraction (in %)
const int nPoints2Pto1S_lhcb = 6;
Float_t ptBinning2Pto1S_lhcb[] = {6, 8, 10, 14, 18, 22, 40};

Float_t frac2Pto1S_lhcb7TeV[] = {3.3, 5.2, 4.0, 5.2, 5.5, 6.0};
Float_t stat2Pto1S_lhcb7TeV[] = {0.6, 0.6, 0.5, 0.8, 1.0, 1.2};
Float_t syst2Pto1S_lhcb7TeV[] = {0.2, 0.3, 0.3, 0.4, 0.7, 0.5};

Float_t frac2Pto1S_lhcb8TeV[] = {2.8, 4.6, 3.0, 5.0, 4.0, 7.6};
Float_t stat2Pto1S_lhcb8TeV[] = {0.5, 0.4, 0.4, 0.5, 0.7, 1.0};
Float_t syst2Pto1S_lhcb8TeV[] = {0.2, 0.3, 0.2, 0.3, 0.3, 0.6};

Float_t frac2Pto1S_weightedLHCb[] = {3.0, 4.8, 3.4, 5.1, 4.5, 6.9};
Float_t stat2Pto1S_weightedLHCb[] = {0.4, 0.3, 0.3, 0.4, 0.6, 0.8};
Float_t syst2Pto1S_weightedLHCb[] = {0.2, 0.3, 0.2, 0.3, 0.4, 0.6};

// Chi_b(3P) -> Y(1S) feed-down fraction (in %)
const int nPoints3Pto1S_lhcb = 4;
Float_t ptBinning3Pto1S_lhcb[] = {10, 14, 18, 22, 40};

Float_t frac3Pto1S_lhcb7TeV[] = {1.7, 1.8, 1.9, 2.9};
Float_t stat3Pto1S_lhcb7TeV[] = {0.5, 0.6, 0.7, 1.0};
Float_t syst3Pto1S_lhcb7TeV[] = {0.1, 0.2, 0.3, 0.4};

Float_t frac3Pto1S_lhcb8TeV[] = {1.4, 1.2, 0.9, 2.1};
Float_t stat3Pto1S_lhcb8TeV[] = {0.4, 0.4, 0.5, 0.5};
Float_t upSyst3Pto1S_lhcb8TeV[] = {0.1, 0.1, 0.1, 0.7};
Float_t downSyst3Pto1S_lhcb8TeV[] = {0.1, 0.1, 0.1, 0.2};

Float_t frac3Pto1S_weightedLHCb[] = {1.5, 1.4, 1.2, 2.3};
Float_t stat3Pto1S_weightedLHCb[] = {0.3, 0.3, 0.4, 0.4};
Float_t syst3Pto1S_weightedLHCb[] = {0.1, 0.1, 0.2, 0.4};

/// Feed-down contributions to Y(2S) (in %)

// Chi_b(2P) -> Y(2S)
const int nPoints2Pto2S_lhcb = 5;
Float_t ptBinning2Pto2S_lhcb[] = {18, 20, 22, 24, 28, 40};

Float_t frac2Pto2S_lhcb7TeV[] = {31, 30, 33, 28, 29};
Float_t stat2Pto2S_lhcb7TeV[] = {6, 9, 10, 9, 8};
Float_t syst2Pto2S_lhcb7TeV[] = {4, 3, 5, 3, 3};

Float_t frac2Pto2S_lhcb8TeV[] = {31, 30, 30, 37, 28};
Float_t stat2Pto2S_lhcb8TeV[] = {4, 5, 6, 5, 5};
Float_t upSyst2Pto2S_lhcb8TeV[] = {4, 3, 3, 4, 3};
Float_t downSyst2Pto2S_lhcb8TeV[] = {4, 3, 3, 8, 3};

Float_t frac2Pto2S_weightedLHCb[] = {31, 30, 31, 35, 28};
Float_t stat2Pto2S_weightedLHCb[] = {3, 4, 5, 4, 4};
Float_t syst2Pto2S_weightedLHCb[] = {4, 3, 4, 5, 3};

// Chi_b(3P) -> Y(2S)
const int nPoints3Pto2S_lhcb = 1;
Float_t ptBinning3Pto2S_lhcb[] = {18, 40};

Float_t frac3Pto2S_lhcb7TeV[] = {4.4};
Float_t stat3Pto2S_lhcb7TeV[] = {1.6};
Float_t syst3Pto2S_lhcb7TeV[] = {0.5};

Float_t frac3Pto2S_lhcb8TeV[] = {2.7};
Float_t stat3Pto2S_lhcb8TeV[] = {1.0};
Float_t syst3Pto2S_lhcb8TeV[] = {0.3};

Float_t frac3Pto2S_weightedLHCb[] = {3.2};
Float_t stat3Pto2S_weightedLHCb[] = {0.8};
Float_t syst3Pto2S_weightedLHCb[] = {0.4};

/// Feed-down contributions to Y(3S) (in %)

// Chi_b(3P) -> Y(3S)
const int nPoints3Pto3S_lhcb = 2;
Float_t ptBinning3Pto3S_lhcb[] = {24, 29, 40};

Float_t frac3Pto3S_lhcb7TeV[] = {44, 36};
Float_t stat3Pto3S_lhcb7TeV[] = {12, 14};
Float_t syst3Pto3S_lhcb7TeV[] = {10, 8};

Float_t frac3Pto3S_lhcb8TeV[] = {34, 40};
Float_t stat3Pto3S_lhcb8TeV[] = {8.0, 9.0};
Float_t upSyst3Pto3S_lhcb8TeV[] = {7.0, 9.5};
Float_t downSyst3Pto3S_lhcb8TeV[] = {5, 14};

Float_t frac3Pto3S_weightedLHCb[] = {37, 39};
Float_t stat3Pto3S_weightedLHCb[] = {7, 8};
Float_t syst3Pto3S_weightedLHCb[] = {7, 11};
