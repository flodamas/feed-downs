/*
 Numerical values of branching ratios within the bottomonium family

 from PDG 2021 https://pdg.lbl.gov/2021/listings/contents_listings.html
*/

/// Dimuon branching ratios (in %)

const float br1Stomumu = 2.48;
const float syst1Stomumu = 0.05;

const float br2Stomumu = 1.93;
const float syst2Stomumu = 0.17;

const float br3Stomumu = 2.18;
const float syst3Stomumu = 0.21;

/// Y(3S) decays

// to Y(2S)
const float br3Sto2Sanything = 10.6;
const float syst3Sto2Sanything = 0.8; // i.e. 7.5% relative

const float br3Sto2Spipluspiminus = 2.82;
const float syst3Sto2Spipluspiminus = 0.18;

const float br3Sto2Stwopizero = 1.85;
const float syst3Sto2Stwopizero = 0.14;

const float br3Sto2Stwophotons = 5.0;
const float syst3Sto2Stwophotons = 0.7;

const float br3Sto2Spizero_CL = 5.1e-4; // absolute BR, 90% CL estimate

// to Y(1S)
const float br3Sto1Spipluspiminus = 4.37;
const float syst3Sto1Spipluspiminus = 0.08; // i.e. 1.8% relative

const float br3Sto1Stwopizero = 2.20;
const float syst3Sto1Stwopizero = 0.13; // i.e. 5.9% relative

const float br3Sto1Seta_CL = 1e-4; // absolute BR, 90% CL estimate

const float br3Sto1Spizero_CL = 7e-5; // absolute BR, 90% CL estimate

const float br3Sto1Sanything = br3Sto1Spipluspiminus + br3Sto1Stwopizero;

// to chi_b(2P)
const float br3Sto2P_Jequal2 = 13.1;
const float syst3Sto2P_Jequal2 = 1.6;

const float br3Sto2P_Jequal1 = 12.6;
const float syst3Sto2P_Jequal1 = 1.2;

const float br3Sto2P_Jequal0 = 5.9;
const float syst3Sto2P_Jequal0 = 0.6;

// to chi_b(1P)
const float br3Sto1P_Jequal2 = 1.0;
const float syst3Sto1P_Jequal2 = 0.1;

const float br3Sto1P_Jequal1 = 9e-2;
const float syst3Sto1P_Jequal1 = 5e-2;

const float br3Sto1P_Jequal0 = .27;
const float syst3Sto1P_Jequal0 = .04;

/// Y(2S) decays

// to Y(1S)
const float br2Sto1Spipluspiminus = 17.85;
const float syst2Sto1Spipluspiminus = 0.26;

const float br2Sto1Stwopizero = 8.6;
const float syst2Sto1Stwopizero = 0.4;

const float br2Sto1Seta = 2.9e-2;
const float syst2Sto1Seta = 0.4e-2;

const float br2Sto1Spizero = 4e-5; // absolute BR, 90% CL estimate

const float br2Sto1Sanything = br2Sto1Spipluspiminus + br2Sto1Stwopizero + br2Sto1Seta;

// to chi_b(1P)
const float br2Sto1P_Jequal2 = 6.9;
const float syst2Sto1P_Jequal2 = 0.4;

const float br2Sto1P_Jequal1 = 7.15;
const float syst2Sto1P_Jequal1 = 0.35;

const float br2Sto1P_Jequal0 = 3.8;
const float syst2Sto1P_Jequal0 = 0.4;

/// Chi_b(3P) radiative decays observed but no branching franctions available in the PDG

/*
- use feed-down fractions measured at high pt by LHCb? (7 and 8 TeV)
- predicted branching ratios? e.g. table 2 in https://arxiv.org/pdf/1410.8537.pdf
*/

// below predicted values from NRQCD (table 2 in https://arxiv.org/pdf/1410.8537.pdf)

// Chi_b,J(3P) -> Y(3S) gamma (in %)
const float br3P_Jequal0_to3Sgamma = 0.51;
const float br3P_Jequal1_to3Sgamma = 10.41;
const float br3P_Jequal2_to3Sgamma = 6.11;

const float br3P_to3Sall = br3P_Jequal0_to3Sgamma + br3P_Jequal1_to3Sgamma + br3P_Jequal2_to3Sgamma;

// Chi_b,J(3P) -> Y(2S) gamma (in %)
const float br3P_Jequal0_to2Sgamma = 0.22;
const float br3P_Jequal1_to2Sgamma = 3.68;
const float br3P_Jequal2_to2Sgamma = 1.91;

const float br3P_to2Sall = br3P_Jequal0_to2Sgamma + br3P_Jequal1_to2Sgamma + br3P_Jequal2_to2Sgamma;

// Chi_b,J(3P) -> Y(1S) gamma (in %)
const float br3P_Jequal0_to1Sgamma = 0.24;
const float br3P_Jequal1_to1Sgamma = 3.81;
const float br3P_Jequal2_to1Sgamma = 1.92;

const float br3P_to1Sall = br3P_Jequal0_to1Sgamma + br3P_Jequal1_to1Sgamma + br3P_Jequal2_to1Sgamma;

/// Chi_b(2P) radiative decays (branching fractions in %)

// PS: recent Belle measurements https://arxiv.org/pdf/2108.03497.pdf

// J = 2
const float br2P_Jequal2_to2Sgamma = 8.9;
const float syst2P_Jequal2_to2Sgamma = 1.2;

const float br2P_Jequal2_to1Sgamma = 6.6;
const float syst2P_Jequal2_to1Sgamma = 0.8;

const float br2P_Jequal2_to1Somega = 1.10;
const float systUp2P_Jequal2_to1Somega = 0.34;
const float systDown2P_Jequal2_to1Somega = 0.30;

const float br2P_Jequal2_to1Somega_Belle = 0.46;
const float stat2P_Jequal2_to1Somega_Belle = 0.12;
const float systUp2P_Jequal2_to1Somega_Belle = 0.06;
const float systDown2P_Jequal2_to1Somega_Belle = 0.07;

// J = 1
const float br2P_Jequal1_to2Sgamma = 18.1;
const float syst2P_Jequal1_to2Sgamma = 1.9;

const float br2P_Jequal1_to1Sgamma = 9.9;
const float syst2P_Jequal1_to1Sgamma = 1.0;

const float br2P_Jequal1_to1Somega = 1.63;
const float systUp2P_Jequal1_to1Somega = 0.40;
const float systDown2P_Jequal1_to1Somega = 0.34;

const float br2P_Jequal1_to1Somega_Belle = 2.38;
const float stat2P_Jequal1_to1Somega_Belle = 0.18;
const float systUp2P_Jequal1_to1Somega_Belle = 0.23;
const float systDown2P_Jequal1_to1Somega_Belle = 0.24;

// J = 0
const float br2P_Jequal0_to2Sgamma = 1.38;
const float syst2P_Jequal0_to2Sgamma = 0.30;

const float br2P_Jequal0_to1Sgamma = 0.38;
const float syst2P_Jequal0_to1Sgamma = 0.17;

const float br2P_Jequal0_to1Somega_Belle = 0.56;
const float statUp2P_Jequal0_to1Somega_Belle = 0.19;
const float statDown2P_Jequal0_to1Somega_Belle = 0.18;
const float syst2P_Jequal0_to1Somega_Belle = 0.08;

// if the triplet is not resolved
const float br2P_to2Sall = br2P_Jequal2_to2Sgamma + br2P_Jequal1_to2Sgamma + br2P_Jequal0_to2Sgamma;

const float br2P_to1Sall = br2P_Jequal2_to1Sgamma + br2P_Jequal2_to1Somega + br2P_Jequal1_to1Sgamma + br2P_Jequal1_to1Somega + br2P_Jequal0_to1Sgamma + br2P_Jequal0_to1Somega_Belle;

// predicted values from NRQCD (table 2 in https://arxiv.org/pdf/1410.8537.pdf)

const float br2P_to2Sall_NRQCD = 15.6 + 8.3;

const float br2P_to1Sall_NRQCD = 9.7 + 7.3;

/// Chi_b(1P) radiative decays (branching fractions in %)

// J = 2
const float br1P_Jequal2_to1Sgamma = 18.0;
const float syst1P_Jequal2_to1Sgamma = 1.0;

// J = 1
const float br1P_Jequal1_to1Sgamma = 35.2;
const float syst1P_Jequal1_to1Sgamma = 2.0;

// J = 0
const float br1P_Jequal0_to1Sgamma = 1.94;
const float syst1P_Jequal0_to1Sgamma = 0.27;
