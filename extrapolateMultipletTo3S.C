#ifdef __CLING__

#include "myPlot.C"

#include "bottomonia/branching.C"
#include "bottomonia/feedLHCb7and8TeV.C"
#include "bottomonia/upsilonLHCb7and8TeV.C"
#include "bottomonia/upsilonCMS7TeV.C"
#include "bottomonia/upsilonCMS13TeV.C"

#include "bottomonia/chib1PstatesCMS8TeV.C"
#include "charmonia/chicRatioLHCb7TeV.C"

#endif

Float_t xErrorWidth = .4;

const Color_t color2P = kAzure + 1;
const Color_t color3P = kGreen + 2;
const Color_t color3Sto2S_ = kPink + 6;

const Int_t marker2P = 21;
const Int_t marker3P = 22;

/// rebin the Y(nS) cross-section ratios to match the FD binning(s)

// pt binning = (10,14,18,22,40)

Float_t ratio3Sto1S[] = {.191, .252, .304, .339};

Float_t stat3Sto1S[] = {.001, .002, .004, .004};

Float_t syst3Sto1S[] = {.013, .011, .012, .012};

void extrapolateMultipletTo3S(Bool_t withLegend = kTRUE, Bool_t withLogYaxis = kFALSE) {
	// Feed-downs to Y(3S)
	auto* canv = myCanvas("canv");

	if (withLogYaxis) canv->SetLogy();

	const char* title = ";#it{p}_{T}^{#varUpsilon(3S)} (GeV);Feed-down fractions to #varUpsilon(3S) (in %)";

	/// Chi_b(3P)

	// first, separate the X(3P)-> Y(1S) multiplet

	Int_t nPoints3Pto1S = nPoints3Pto1S_lhcb;

	Float_t frac3Pto1S_Jequal1[nPoints3Pto1S], stat3Pto1S_Jequal1[nPoints3Pto1S], syst3Pto1S_Jequal1[nPoints3Pto1S];
	Float_t frac3Pto1S_Jequal2[nPoints3Pto1S], stat3Pto1S_Jequal2[nPoints3Pto1S], syst3Pto1S_Jequal2[nPoints3Pto1S];

	for (Int_t i = 0; i < nPoints3Pto1S; i++) {
		// J = 1
		frac3Pto1S_Jequal1[i] = frac3Pto1S_weightedLHCb[i] / (1. + ratio2to1_chib1P_CMSaverage * (br3P_Jequal2_to1Sgamma / br3P_Jequal1_to1Sgamma));

		stat3Pto1S_Jequal1[i] = frac3Pto1S_Jequal1[i] * (stat3Pto1S_weightedLHCb[i] / frac3Pto1S_weightedLHCb[i]);

		syst3Pto1S_Jequal1[i] = frac3Pto1S_Jequal1[i] * (syst3Pto1S_weightedLHCb[i] / frac3Pto1S_weightedLHCb[i]);

		// J = 2
		frac3Pto1S_Jequal2[i] = frac3Pto1S_weightedLHCb[i] - frac3Pto1S_Jequal1[i];

		stat3Pto1S_Jequal2[i] = frac3Pto1S_Jequal2[i] * (stat3Pto1S_weightedLHCb[i] / frac3Pto1S_weightedLHCb[i]);

		syst3Pto1S_Jequal2[i] = frac3Pto1S_Jequal2[i] * (syst3Pto1S_weightedLHCb[i] / frac3Pto1S_weightedLHCb[i]);
	}

	// separate the X(3P)-> Y(3S) multiplet

	Int_t nPoints3Pto3S = nPoints3Pto3S_lhcb;

	Float_t frac3Pto3S_Jequal1[nPoints3Pto3S], stat3Pto3S_Jequal1[nPoints3Pto3S], syst3Pto3S_Jequal1[nPoints3Pto3S];
	Float_t frac3Pto3S_Jequal2[nPoints3Pto3S], stat3Pto3S_Jequal2[nPoints3Pto3S], syst3Pto3S_Jequal2[nPoints3Pto3S];

	for (Int_t i = 0; i < nPoints3Pto3S; i++) {
		// J = 1
		frac3Pto3S_Jequal1[i] = frac3Pto3S_weightedLHCb[i] / (1. + ratio2to1_chib1P_CMSaverage * (br3P_Jequal2_to3Sgamma / br3P_Jequal1_to3Sgamma));

		stat3Pto3S_Jequal1[i] = frac3Pto3S_Jequal1[i] * (stat3Pto3S_weightedLHCb[i] / frac3Pto3S_weightedLHCb[i]);

		syst3Pto3S_Jequal1[i] = frac3Pto3S_Jequal1[i] * (syst3Pto3S_weightedLHCb[i] / frac3Pto3S_weightedLHCb[i]);

		// J = 2
		frac3Pto3S_Jequal2[i] = frac3Pto3S_weightedLHCb[i] - frac3Pto3S_Jequal1[i];

		stat3Pto3S_Jequal2[i] = frac3Pto3S_Jequal2[i] * (stat3Pto3S_weightedLHCb[i] / frac3Pto3S_weightedLHCb[i]);

		syst3Pto3S_Jequal2[i] = frac3Pto3S_Jequal2[i] * (syst3Pto3S_weightedLHCb[i] / frac3Pto3S_weightedLHCb[i]);
	}

	auto* statGraph3Pto3S_Jequal1 = myStatGraph(title, nPoints3Pto3S, ptBinning3Pto3S_lhcb, frac3Pto3S_Jequal1, stat3Pto3S_Jequal1, color2P, marker2P);

	statGraph3Pto3S_Jequal1->SetMinimum(0);
	statGraph3Pto3S_Jequal1->SetMaximum((withLegend) ? 50 : 45);
	statGraph3Pto3S_Jequal1->GetXaxis()->SetLimits(0, 40);

	statGraph3Pto3S_Jequal1->Draw("APZ");

	auto* systGraph3Pto3S_Jequal1 = mySystGraph(nPoints3Pto3S, ptBinning3Pto3S_lhcb, xErrorWidth, frac3Pto3S_Jequal1, syst3Pto3S_Jequal1, color2P);
	systGraph3Pto3S_Jequal1->Draw("5");

	auto* statGraph3Pto3S_Jequal2 = myStatGraph(title, nPoints3Pto3S, ptBinning3Pto3S_lhcb, frac3Pto3S_Jequal2, stat3Pto3S_Jequal2, color1S, marker2P);
	statGraph3Pto3S_Jequal2->Draw("PZ");

	auto* systGraph3Pto3S_Jequal2 = mySystGraph(nPoints3Pto3S, ptBinning3Pto3S_lhcb, xErrorWidth, frac3Pto3S_Jequal2, syst3Pto3S_Jequal2, color1S);
	systGraph3Pto3S_Jequal2->Draw("5");

	// extrapolate X_J(2P)-> Y(2S) with X_J(2P) -> Y(1S) FD measurements

	Float_t extFD_3Pto3S_Jequal1[nPoints3Pto1S], statExtFD_3Pto3S_Jequal1[nPoints3Pto1S], systExtFD_3Pto3S_Jequal1[nPoints3Pto1S];
	Float_t extFD_3Pto3S_Jequal2[nPoints3Pto1S], statExtFD_3Pto3S_Jequal2[nPoints3Pto1S], systExtFD_3Pto3S_Jequal2[nPoints3Pto1S];

	for (Int_t i = 0; i < nPoints3Pto1S; i++) {
		// J = 1

		// with Lansberg's formula
		extFD_3Pto3S_Jequal1[i] = (frac3Pto1S_Jequal1[i] / (ratio3Sto1S[i] * br1Stomumu / br2Stomumu)) * (br3P_Jequal1_to3Sgamma / br3P_Jequal1_to1Sgamma);

		statExtFD_3Pto3S_Jequal1[i] = extFD_3Pto3S_Jequal1[i] * TMath::Hypot(stat3Pto1S_Jequal1[i] / frac3Pto1S_Jequal1[i], stat3Sto1S[i] / ratio3Sto1S[i]);

		systExtFD_3Pto3S_Jequal1[i] = extFD_3Pto3S_Jequal1[i] * TMath::Hypot(syst3Pto1S_Jequal1[i] / frac3Pto1S_Jequal1[i], syst3Sto1S[i] / ratio3Sto1S[i]);

		// J = 2

		// with Lansberg's formula
		extFD_3Pto3S_Jequal2[i] = (frac3Pto1S_Jequal2[i] / (ratio3Sto1S[i] * br1Stomumu / br2Stomumu)) * (br3P_Jequal2_to3Sgamma / br3P_Jequal2_to1Sgamma);

		statExtFD_3Pto3S_Jequal2[i] = extFD_3Pto3S_Jequal2[i] * TMath::Hypot(stat3Pto1S_Jequal2[i] / frac3Pto1S_Jequal2[i], stat3Sto1S[i] / ratio3Sto1S[i]);

		systExtFD_3Pto3S_Jequal2[i] = extFD_3Pto3S_Jequal2[i] * TMath::Hypot(syst3Pto1S_Jequal2[i] / frac3Pto1S_Jequal2[i], syst3Sto1S[i] / ratio3Sto1S[i]);
	}

	auto* extStat3Pto3S_Jequal1 =
	  myStatGraph(title, nPoints3Pto1S, ptBinning3Pto1S_lhcb, extFD_3Pto3S_Jequal1, statExtFD_3Pto3S_Jequal1, color2S + 1, marker2P + 4);

	extStat3Pto3S_Jequal1->Draw("PZ");

	auto* extSyst3Pto3S_Jequal1 =
	  mySystGraph(nPoints3Pto1S, ptBinning3Pto1S_lhcb, xErrorWidth, extFD_3Pto3S_Jequal1, systExtFD_3Pto3S_Jequal1, color2S + 1);

	extSyst3Pto3S_Jequal1->Draw("5");

	auto* extStat3Pto3S_Jequal2 =
	  myStatGraph(title, nPoints3Pto1S, ptBinning3Pto1S_lhcb, extFD_3Pto3S_Jequal2, statExtFD_3Pto3S_Jequal2, kOrange + 1, marker2P + 4);

	extStat3Pto3S_Jequal2->Draw("PZ");

	auto* extSyst3Pto3S_Jequal2 =
	  mySystGraph(nPoints3Pto1S, ptBinning3Pto1S_lhcb, xErrorWidth, extFD_3Pto3S_Jequal2, systExtFD_3Pto3S_Jequal2, kOrange + 1);

	extSyst3Pto3S_Jequal2->Draw("5");

	/// legend

	Float_t yHeader = .9, y2P = yHeader - .07, yJequal1 = yHeader - .07, yJequal2 = yJequal1 - .07;

	Float_t xChib = .17, xExtrap = xChib + .19;

	drawHeaderLegend("pp 7 and 8 TeV data, #varUpsilon(3S) from", xChib, yHeader);

	//drawLegend(directStat3Pto3S, "#chi_{b}(2P) from LHCb data", xChib, y2P, "pl");
	drawLegend(statGraph3Pto3S_Jequal1, "#chi_{b,1}(3P)", xChib, yJequal1, "pl");
	drawLegend(extStat3Pto3S_Jequal1, "derived from #chi_{b,1}(3P) #rightarrow #varUpsilon(1S)", xExtrap, yJequal1, "pl");

	drawLegend(statGraph3Pto3S_Jequal2, "#chi_{b,2}(3P)", xChib, yJequal2, "pl");
	drawLegend(extStat3Pto3S_Jequal2, "derived from #chi_{b,2}(3P) #rightarrow #varUpsilon(1S)", xExtrap, yJequal2, "pl");

	drawHeaderLegend(Form("#it{R}_{21} = %.2f #pm %.2f", ratio2to1_chib1P_CMSaverage, systRatio2to1_chib1P_CMSaverage), xChib, .6);

	canv->SaveAs("figures/extrapolateMultiplet_FDto3S.png", "RECREATE");
	canv->Close();
}
