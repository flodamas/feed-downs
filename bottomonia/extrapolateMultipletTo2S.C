#ifdef __CLING__

#include "../tools/Cosmetics.h"
#include "../tools/Graph.h"

#include "data/BranchingRatios.h"

#include "data/feedLHCb7and8TeV.C"
#include "data/upsilonLHCb7and8TeV.C"
#include "data/upsilonCMS7TeV.C"
#include "data/upsilonCMS13TeV.C"

#include "data/chib1PstatesCMS8TeV.C"
#include "../charmonia/data/chicRatioLHCb7TeV.C"

#endif

Float_t xErrorWidth = .4;

/// rebin the Y(nS) cross-section ratios to match the FD binning(s)

// pt binning = (6,8,10,14,18,22,40)

Float_t ratio2Sto1S[] = {.2762, .3049, .338, .392, .438, .485};

Float_t stat2Sto1S[] = {.0021, .0027, .002, .003, .004, .005};

Float_t syst2Sto1S[] = {.0, .0, .019, .016, .015, .015};

// pt binning = (10,14,18,22,40)

Float_t ratio3Sto1S[] = {.191, .252, .304, .339};

Float_t stat3Sto1S[] = {.001, .002, .004, .004};

Float_t syst3Sto1S[] = {.013, .011, .012, .012};

void extrapolateMultipletTo2S(Bool_t withLegend = kTRUE) {
	// Feed-downs to Y(2S)
	auto* canv = Canvas("canv");

	const char* title = ";#it{p}_{T}^{#varUpsilon(2S)} (GeV);Feed-down fractions to #varUpsilon(2S) (in %)";

	/// Chi_b(2P)

	// first, separate the X(2P)-> Y(1S) multiplet

	Int_t nPoints2Pto1S = nPoints2Pto1S_lhcb;

	Float_t frac2Pto1S_Jequal1[nPoints2Pto1S], stat2Pto1S_Jequal1[nPoints2Pto1S], syst2Pto1S_Jequal1[nPoints2Pto1S];
	Float_t frac2Pto1S_Jequal2[nPoints2Pto1S], stat2Pto1S_Jequal2[nPoints2Pto1S], syst2Pto1S_Jequal2[nPoints2Pto1S];

	for (Int_t i = 0; i < nPoints2Pto1S; i++) {
		// J = 1
		frac2Pto1S_Jequal1[i] = frac2Pto1S_weightedLHCb[i] / (1. + ratio2to1_chib1P_CMSaverage * (br2P_Jequal2_to1Sgamma / br2P_Jequal1_to1Sgamma));

		stat2Pto1S_Jequal1[i] = frac2Pto1S_Jequal1[i] * (stat2Pto1S_weightedLHCb[i] / frac2Pto1S_weightedLHCb[i]);

		syst2Pto1S_Jequal1[i] = frac2Pto1S_Jequal1[i] * (syst2Pto1S_weightedLHCb[i] / frac2Pto1S_weightedLHCb[i]);

		// J = 2
		frac2Pto1S_Jequal2[i] = frac2Pto1S_weightedLHCb[i] - frac2Pto1S_Jequal1[i];

		stat2Pto1S_Jequal2[i] = frac2Pto1S_Jequal2[i] * (stat2Pto1S_weightedLHCb[i] / frac2Pto1S_weightedLHCb[i]);

		syst2Pto1S_Jequal2[i] = frac2Pto1S_Jequal2[i] * (syst2Pto1S_weightedLHCb[i] / frac2Pto1S_weightedLHCb[i]);
	}

	// separate the X(2P)-> Y(2S) multiplet

	Int_t nPoints2Pto2S = nPoints2Pto2S_lhcb;

	Float_t frac2Pto2S_Jequal1[nPoints2Pto2S], stat2Pto2S_Jequal1[nPoints2Pto2S], syst2Pto2S_Jequal1[nPoints2Pto2S];
	Float_t frac2Pto2S_Jequal2[nPoints2Pto2S], stat2Pto2S_Jequal2[nPoints2Pto2S], syst2Pto2S_Jequal2[nPoints2Pto2S];

	for (Int_t i = 0; i < nPoints2Pto2S; i++) {
		// J = 1
		frac2Pto2S_Jequal1[i] = frac2Pto2S_weightedLHCb[i] / (1. + ratio2to1_chib1P_CMSaverage * (br2P_Jequal2_to2Sgamma / br2P_Jequal1_to2Sgamma));

		stat2Pto2S_Jequal1[i] = frac2Pto2S_Jequal1[i] * (stat2Pto2S_weightedLHCb[i] / frac2Pto2S_weightedLHCb[i]);

		syst2Pto2S_Jequal1[i] = frac2Pto2S_Jequal1[i] * (syst2Pto2S_weightedLHCb[i] / frac2Pto2S_weightedLHCb[i]);

		// J = 2
		frac2Pto2S_Jequal2[i] = frac2Pto2S_weightedLHCb[i] - frac2Pto2S_Jequal1[i];

		stat2Pto2S_Jequal2[i] = frac2Pto2S_Jequal2[i] * (stat2Pto2S_weightedLHCb[i] / frac2Pto2S_weightedLHCb[i]);

		syst2Pto2S_Jequal2[i] = frac2Pto2S_Jequal2[i] * (syst2Pto2S_weightedLHCb[i] / frac2Pto2S_weightedLHCb[i]);
	}

	auto* statGraph2Pto2S_Jequal1 = StatGraph(title, nPoints2Pto2S, ptBinning2Pto2S_lhcb, frac2Pto2S_Jequal1, stat2Pto2S_Jequal1, color2P, marker2P);

	statGraph2Pto2S_Jequal1->SetMaximum((withLegend) ? 40 : 45);
	statGraph2Pto2S_Jequal1->GetXaxis()->SetLimits(0, 40);

	statGraph2Pto2S_Jequal1->Draw("APZ");

	auto* systGraph2Pto2S_Jequal1 = SystGraph(nPoints2Pto2S, ptBinning2Pto2S_lhcb, xErrorWidth, frac2Pto2S_Jequal1, syst2Pto2S_Jequal1, color2P);
	systGraph2Pto2S_Jequal1->Draw("5");

	auto* statGraph2Pto2S_Jequal2 = StatGraph(title, nPoints2Pto2S, ptBinning2Pto2S_lhcb, frac2Pto2S_Jequal2, stat2Pto2S_Jequal2, color1S, marker2P);
	statGraph2Pto2S_Jequal2->Draw("PZ");

	auto* systGraph2Pto2S_Jequal2 = SystGraph(nPoints2Pto2S, ptBinning2Pto2S_lhcb, xErrorWidth, frac2Pto2S_Jequal2, syst2Pto2S_Jequal2, color1S);
	systGraph2Pto2S_Jequal2->Draw("5");

	// extrapolate X_J(2P)-> Y(2S) with X_J(2P) -> Y(1S) FD measurements

	Float_t extFD_2Pto2S_Jequal1[nPoints2Pto1S], statExtFD_2Pto2S_Jequal1[nPoints2Pto1S], systExtFD_2Pto2S_Jequal1[nPoints2Pto1S];
	Float_t extFD_2Pto2S_Jequal2[nPoints2Pto1S], statExtFD_2Pto2S_Jequal2[nPoints2Pto1S], systExtFD_2Pto2S_Jequal2[nPoints2Pto1S];

	Float_t br2P_Jequal1_to2S = br2P_Jequal1_to2Sgamma;
	Float_t br2P_Jequal2_to2S = br2P_Jequal2_to2Sgamma;

	Float_t br2P_Jequal1_to1S = br2P_Jequal1_to1Sgamma + br2P_Jequal1_to1Somega;
	Float_t br2P_Jequal2_to1S = br2P_Jequal2_to1Sgamma + br2P_Jequal2_to1Somega;

	for (Int_t i = 0; i < nPoints2Pto1S; i++) {
		// J = 1

		// with Lansberg's formula
		extFD_2Pto2S_Jequal1[i] = (frac2Pto1S_Jequal1[i] / (ratio2Sto1S[i] * br1Stomumu / br2Stomumu)) * (br2P_Jequal1_to2S / br2P_Jequal1_to1Sgamma);

		statExtFD_2Pto2S_Jequal1[i] = extFD_2Pto2S_Jequal1[i] * TMath::Hypot(stat2Pto1S_Jequal1[i] / frac2Pto1S_Jequal1[i], stat2Sto1S[i] / ratio2Sto1S[i]);

		systExtFD_2Pto2S_Jequal1[i] = extFD_2Pto2S_Jequal1[i] * TMath::Hypot(syst2Pto1S_Jequal1[i] / frac2Pto1S_Jequal1[i], syst2Sto1S[i] / ratio2Sto1S[i]);

		// J = 2

		// with Lansberg's formula
		extFD_2Pto2S_Jequal2[i] = (frac2Pto1S_Jequal2[i] / (ratio2Sto1S[i] * br1Stomumu / br2Stomumu)) * (br2P_Jequal2_to2S / br2P_Jequal2_to1Sgamma);

		statExtFD_2Pto2S_Jequal2[i] = extFD_2Pto2S_Jequal2[i] * TMath::Hypot(stat2Pto1S_Jequal2[i] / frac2Pto1S_Jequal2[i], stat2Sto1S[i] / ratio2Sto1S[i]);

		systExtFD_2Pto2S_Jequal2[i] = extFD_2Pto2S_Jequal2[i] * TMath::Hypot(syst2Pto1S_Jequal2[i] / frac2Pto1S_Jequal2[i], syst2Sto1S[i] / ratio2Sto1S[i]);
	}

	auto* extStat2Pto2S_Jequal1 =
	  StatGraph(title, nPoints2Pto1S, ptBinning2Pto1S_lhcb, extFD_2Pto2S_Jequal1, statExtFD_2Pto2S_Jequal1, color2S + 1, marker2P + 4);

	extStat2Pto2S_Jequal1->Draw("PZ");

	auto* extSyst2Pto2S_Jequal1 =
	  SystGraph(nPoints2Pto1S, ptBinning2Pto1S_lhcb, xErrorWidth, extFD_2Pto2S_Jequal1, systExtFD_2Pto2S_Jequal1, color2S + 1);

	extSyst2Pto2S_Jequal1->Draw("5");

	auto* extStat2Pto2S_Jequal2 =
	  StatGraph(title, nPoints2Pto1S, ptBinning2Pto1S_lhcb, extFD_2Pto2S_Jequal2, statExtFD_2Pto2S_Jequal2, kOrange + 1, marker2P + 4);

	extStat2Pto2S_Jequal2->Draw("PZ");

	auto* extSyst2Pto2S_Jequal2 =
	  SystGraph(nPoints2Pto1S, ptBinning2Pto1S_lhcb, xErrorWidth, extFD_2Pto2S_Jequal2, systExtFD_2Pto2S_Jequal2, kOrange + 1);

	extSyst2Pto2S_Jequal2->Draw("5");

	/// legend

	Float_t yHeader = .9, y2P = yHeader - .07, yJequal1 = yHeader - .07, yJequal2 = yJequal1 - .07;

	Float_t xChib = .17, xExtrap = xChib + .19;

	drawHeaderLegend("pp 7 and 8 TeV data, #varUpsilon(2S) from", xChib, yHeader);

	//drawLegend(directStat2Pto2S, "#chi_{b}(2P) from LHCb data", xChib, y2P, "pl");
	drawLegend(statGraph2Pto2S_Jequal1, "#chi_{b,1}(2P)", xChib, yJequal1, "pl");
	drawLegend(extStat2Pto2S_Jequal1, "derived from #chi_{b,1}(2P) #rightarrow #varUpsilon(1S)", xExtrap, yJequal1, "pl");

	drawLegend(statGraph2Pto2S_Jequal2, "#chi_{b,2}(2P)", xChib, yJequal2, "pl");
	drawLegend(extStat2Pto2S_Jequal2, "derived from #chi_{b,2}(2P) #rightarrow #varUpsilon(1S)", xExtrap, yJequal2, "pl");

	drawHeaderLegend(Form("#it{R}_{21} = %.2f #pm %.2f", ratio2to1_chib1P_CMSaverage, systRatio2to1_chib1P_CMSaverage), xChib, .6);

	saveCanvas(canv, "extrapolateMultiplet_FDto2S");
}
