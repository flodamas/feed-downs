/*
Differential cross-section ratios between Y(nS) states (not corrected for branching fractions)

LHCb data at 7 and 8 TeV (from https://www.hepdata.net/record/ins1392456)

*/

/// rapidity-differential ratios for pt < 30 GeV/c (https://www.hepdata.net/record/ins1392456?version=1&table=Table%2010)
Float_t rapidityBinning_lhcb7and8TeV[] = {2.0, 2.5, 3.0, 3.5, 4.0, 4.5};

// Y(2S)-to-Y(1S)

Float_t rapidDiff_2Sto1S_lhcb7TeV[] = {.259771347046, 0.251797556877, 0.248472332954, 0.250881642103, 0.251357287169};

Float_t errorRapidDiff_2Sto1S_lhcb7TeV[] = {0.00288399222414, 0.00222156033949, 0.00219635519134, 0.00243078327853, 0.00424920897977};

// Y(3S)-to-Y(1S)

Float_t rapidDiff_3Sto1S_lhcb7TeV[] = {0.127400368452, 0.12506608665, 0.1230609864, 0.12448888272, 0.11948941648};

Float_t errorRapidDiff_3Sto1S_lhcb7TeV[] = {0.00181657608321, 0.00130606896933, 0.00128978174238, 0.00147868936811, 0.00284868125215};

// Y(3S)-to-Y(2S)

Float_t rapidDiff_3Sto2S_lhcb7TeV[] = {0.490432739258, 0.496693074703, 0.495270401239, 0.496205657721, 0.475376814604};

Float_t errorRapidDiff_3Sto2S_lhcb7TeV[] = {0.00775812447269, 0.0056066867625, 0.00561480587554, 0.00646600927656, 0.0127904032532};
