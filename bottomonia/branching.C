/*
 Numerical values of branching ratios within the bottomonium family

 from PDG 2021 https://pdg.lbl.gov/2021/listings/contents_listings.html
*/

/// Dimuon branching ratios (in %)

Float_t br1Stomumu = 2.48;
Float_t syst1Stomumu = 0.05;

Float_t br2Stomumu = 1.93;
Float_t syst2Stomumu = 0.17;

Float_t br3Stomumu = 2.18;
Float_t syst3Stomumu = 0.21;

/// Y(3S) decays

// to Y(2S)
Float_t br3Sto2Sanything = 10.6;
Float_t syst3Sto2Sanything = 0.8; // i.e. 7.5% relative

Float_t br3Sto2Spipluspiminus = 2.82;
Float_t syst3Sto2Spipluspiminus = 0.18;

Float_t br3Sto2Stwopizero = 1.85;
Float_t syst3Sto2Stwopizero = 0.14;

Float_t br3Sto2Stwophotons = 5.0;
Float_t syst3Sto2Stwophotons = 0.7;

Float_t br3Sto2Spizero_CL = 5.1e-4; // absolute BR, 90% CL estimate

// to Y(1S)
Float_t br3Sto1Spipluspiminus = 4.37;
Float_t syst3Sto1Spipluspiminus = 0.08; // i.e. 1.8% relative

Float_t br3Sto1Stwopizero = 2.20;
Float_t syst3Sto1Stwopizero = 0.13; // i.e. 5.9% relative

Float_t br3Sto1Seta_CL = 1e-4; // absolute BR, 90% CL estimate

Float_t br3Sto1Spizero_CL = 7e-5; // absolute BR, 90% CL estimate

Float_t br3Sto1Sanything = br3Sto1Spipluspiminus + br3Sto1Stwopizero;

// to chi_b(2P)
Float_t br3Sto2P_Jequal2 = 13.1;
Float_t syst3Sto2P_Jequal2 = 1.6;

Float_t br3Sto2P_Jequal1 = 12.6;
Float_t syst3Sto2P_Jequal1 = 1.2;

Float_t br3Sto2P_Jequal0 = 5.9;
Float_t syst3Sto2P_Jequal0 = 0.6;

// to chi_b(1P)
Float_t br3Sto1P_Jequal2 = 1.0;
Float_t syst3Sto1P_Jequal2 = 0.1;

Float_t br3Sto1P_Jequal1 = 9e-2;
Float_t syst3Sto1P_Jequal1 = 5e-2;

Float_t br3Sto1P_Jequal0 = .27;
Float_t syst3Sto1P_Jequal0 = .04;

/// Y(2S) decays

// to Y(1S)
Float_t br2Sto1Spipluspiminus = 17.85;
Float_t syst2Sto1Spipluspiminus = 0.26;

Float_t br2Sto1Stwopizero = 8.6;
Float_t syst2Sto1Stwopizero = 0.4;

Float_t br2Sto1Seta = 2.9e-2;
Float_t syst2Sto1Seta = 0.4e-2;

Float_t br2Sto1Spizero = 4e-5; // absolute BR, 90% CL estimate

Float_t br2Sto1Sanything = br2Sto1Spipluspiminus + br2Sto1Stwopizero + br2Sto1Seta;

// to chi_b(1P)
Float_t br2Sto1P_Jequal2 = 6.9;
Float_t syst2Sto1P_Jequal2 = 0.4;

Float_t br2Sto1P_Jequal1 = 7.15;
Float_t syst2Sto1P_Jequal1 = 0.35;

Float_t br2Sto1P_Jequal0 = 3.8;
Float_t syst2Sto1P_Jequal0 = 0.4;

/// Chi_b(3P) radiative decays observed but no branching franctions available in the PDG

/*
- use feed-down fractions measured at high pt by LHCb? (7 and 8 TeV)
- predicted branching ratios? e.g. table 2 in https://arxiv.org/pdf/1410.8537.pdf
*/

// below predicted values from NRQCD (table 2 in https://arxiv.org/pdf/1410.8537.pdf)

// Chi_b,J(3P) -> Y(3S) gamma (in %)
Float_t br3P_Jequal0_to3Sgamma = 0.51;
Float_t br3P_Jequal1_to3Sgamma = 10.41;
Float_t br3P_Jequal2_to3Sgamma = 6.11;

const Float_t br3P_to3Sall = br3P_Jequal0_to3Sgamma + br3P_Jequal1_to3Sgamma + br3P_Jequal2_to3Sgamma;

// Chi_b,J(3P) -> Y(2S) gamma (in %)
Float_t br3P_Jequal0_to2Sgamma = 0.22;
Float_t br3P_Jequal1_to2Sgamma = 3.68;
Float_t br3P_Jequal2_to2Sgamma = 1.91;

const Float_t br3P_to2Sall = br3P_Jequal0_to2Sgamma + br3P_Jequal1_to2Sgamma + br3P_Jequal2_to2Sgamma;

// Chi_b,J(3P) -> Y(1S) gamma (in %)
Float_t br3P_Jequal0_to1Sgamma = 0.24;
Float_t br3P_Jequal1_to1Sgamma = 3.81;
Float_t br3P_Jequal2_to1Sgamma = 1.92;

const Float_t br3P_to1Sall = br3P_Jequal0_to1Sgamma + br3P_Jequal1_to1Sgamma + br3P_Jequal2_to1Sgamma;

/// Chi_b(2P) radiative decays (branching fractions in %)

// PS: recent Belle measurements https://arxiv.org/pdf/2108.03497.pdf

// J = 2
Float_t br2P_Jequal2_to2Sgamma = 8.9;
Float_t syst2P_Jequal2_to2Sgamma = 1.2;

Float_t br2P_Jequal2_to1Sgamma = 6.6;
Float_t syst2P_Jequal2_to1Sgamma = 0.8;

Float_t br2P_Jequal2_to1Somega = 1.10;
Float_t systUp2P_Jequal2_to1Somega = 0.34;
Float_t systDown2P_Jequal2_to1Somega = 0.30;

Float_t br2P_Jequal2_to1Somega_Belle = 0.46;
Float_t stat2P_Jequal2_to1Somega_Belle = 0.12;
Float_t systUp2P_Jequal2_to1Somega_Belle = 0.06;
Float_t systDown2P_Jequal2_to1Somega_Belle = 0.07;

// J = 1
Float_t br2P_Jequal1_to2Sgamma = 18.1;
Float_t syst2P_Jequal1_to2Sgamma = 1.9;

Float_t br2P_Jequal1_to1Sgamma = 9.9;
Float_t syst2P_Jequal1_to1Sgamma = 1.0;

Float_t br2P_Jequal1_to1Somega = 1.63;
Float_t systUp2P_Jequal1_to1Somega = 0.40;
Float_t systDown2P_Jequal1_to1Somega = 0.34;

Float_t br2P_Jequal1_to1Somega_Belle = 2.38;
Float_t stat2P_Jequal1_to1Somega_Belle = 0.18;
Float_t systUp2P_Jequal1_to1Somega_Belle = 0.23;
Float_t systDown2P_Jequal1_to1Somega_Belle = 0.24;

// J = 0
Float_t br2P_Jequal0_to2Sgamma = 1.38;
Float_t syst2P_Jequal0_to2Sgamma = 0.30;

Float_t br2P_Jequal0_to1Sgamma = 0.38;
Float_t syst2P_Jequal0_to1Sgamma = 0.17;

Float_t br2P_Jequal0_to1Somega_Belle = 0.56;
Float_t statUp2P_Jequal0_to1Somega_Belle = 0.19;
Float_t statDown2P_Jequal0_to1Somega_Belle = 0.18;
Float_t syst2P_Jequal0_to1Somega_Belle = 0.08;

// if the triplet is not resolved
const Float_t br2P_to2Sall = br2P_Jequal2_to2Sgamma + br2P_Jequal1_to2Sgamma + br2P_Jequal0_to2Sgamma;

const Float_t br2P_to1Sall = br2P_Jequal2_to1Sgamma + br2P_Jequal2_to1Somega + br2P_Jequal1_to1Sgamma + br2P_Jequal1_to1Somega + br2P_Jequal0_to1Sgamma + br2P_Jequal0_to1Somega_Belle;

// predicted values from NRQCD (table 2 in https://arxiv.org/pdf/1410.8537.pdf)

const Float_t br2P_to2Sall_NRQCD = 15.6 + 8.3;

const Float_t br2P_to1Sall_NRQCD = 9.7 + 7.3;

/// Chi_b(1P) radiative decays (branching fractions in %)

// J = 2
Float_t br1P_Jequal2_to1Sgamma = 18.0;
Float_t syst1P_Jequal2_to1Sgamma = 1.0;

// J = 1
Float_t br1P_Jequal1_to1Sgamma = 35.2;
Float_t syst1P_Jequal1_to1Sgamma = 2.0;

// J = 0
Float_t br1P_Jequal0_to1Sgamma = 1.94;
Float_t syst1P_Jequal0_to1Sgamma = 0.27;
