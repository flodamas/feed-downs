#ifdef __CLING__

#include "myPlot.C"

#include "bottomonia/branching.C"
#include "bottomonia/feedLHCb7and8TeV.C"
#include "bottomonia/upsilonLHCb7and8TeV.C"
#include "bottomonia/upsilonCMS7TeV.C"

#include "bottomonia/chib1PstatesCMS8TeV.C"

#endif

Float_t xErrorWidth = .4;

const Color_t color3P = kOrange + 1;

const Int_t marker2P = 21;
const Int_t marker3P = 22;

/// rebin the Y(nS) cross-section ratios to match the FD binning(s)

// pt binning = (10,14,18,22,40)

Float_t ratio3Sto1S[] = {.191, .252, .304, .339};

Float_t stat3Sto1S[] = {.001, .002, .004, .004};

Float_t syst3Sto1S[] = {.013, .011, .012, .012};

void extrapolateTo3S(Bool_t withLegend = kTRUE, Bool_t withLogYaxis = kFALSE) {
	// Feed-downs to Y(3S)
	auto* canv3S = myCanvas("canv3S");

	if (withLogYaxis) canv3S->SetLogy();

	const char* title3S =
	  ";#it{p}_{T}^{#varUpsilon(3S)} (GeV);Feed-down fractions to #varUpsilon(3S) (in %)";

	/// Chi_b(3P)

	// direct measurements

	auto* directStat3Pto3S =
	  myStatGraph(title3S, nPoints3Pto3S_lhcb, ptBinning3Pto3S_lhcb, frac3Pto3S_lhcb8TeV, stat3Pto3S_lhcb8TeV, color3P, marker3P);

	directStat3Pto3S->SetMaximum(60);
	directStat3Pto3S->GetXaxis()->SetLimits(0, 40);

	auto* directSyst3Pto3S =
	  mySystGraph(nPoints3Pto3S_lhcb, ptBinning3Pto3S_lhcb, xErrorWidth, frac3Pto3S_lhcb8TeV, syst3Pto3S_lhcb8TeV, color3P);

	directStat3Pto3S->Draw("APZ");
	directSyst3Pto3S->Draw("5");

	// extrapolate with chi_b(3P) -> Y(1S) FD measurements

	Float_t extFD_3Pto3S[nPoints3Pto1S_lhcb], statExtFD_3Pto3S[nPoints3Pto1S_lhcb], systExtFD_3Pto3S[nPoints3Pto1S_lhcb];

	for (Int_t i = 0; i < nPoints3Pto1S_lhcb; i++) {
		extFD_3Pto3S[i] = (frac3Pto1S_lhcb8TeV[i] / (ratio3Sto1S[i] * br1Stomumu / br3Stomumu)) * ((br3P_Jequal1_to3Sgamma + ratio2to1_chib1P_CMSaverage * br3P_Jequal2_to3Sgamma) / (br3P_Jequal1_to1Sgamma + ratio2to1_chib1P_CMSaverage * br3P_Jequal2_to1Sgamma));

		statExtFD_3Pto3S[i] = extFD_3Pto3S[i] * TMath::Hypot(stat3Pto1S_lhcb8TeV[i] / frac3Pto1S_lhcb8TeV[i], stat3Sto1S[i] / ratio3Sto1S[i]);

		systExtFD_3Pto3S[i] = extFD_3Pto3S[i] * TMath::Hypot(syst3Pto1S_lhcb8TeV[i] / frac3Pto1S_lhcb8TeV[i], syst3Sto1S[i] / ratio3Sto1S[i]);
	}

	auto* extStat3Pto3S =
	  myStatGraph(title3S, nPoints3Pto1S_lhcb, ptBinning3Pto1S_lhcb, extFD_3Pto3S, statExtFD_3Pto3S, color3P + 1, marker2P + 4);

	extStat3Pto3S->Draw("PZ");

	auto* extSyst3Pto3S =
	  mySystGraph(nPoints3Pto1S_lhcb, ptBinning3Pto1S_lhcb, xErrorWidth, extFD_3Pto3S, systExtFD_3Pto3S, color3P - 1);

	extSyst3Pto3S->Draw("5");

	/// legend

	Float_t yHeader = .9, y3P = yHeader - .07;

	Float_t xDirect = .18, xExtrap = xDirect + .2;

	drawHeaderLegend("pp 7 and 8 TeV data, #varUpsilon(3S) from #chi_{b}(3P)", xDirect, yHeader);

	drawLegend(directStat3Pto3S, "reported", xDirect, y3P, "pl");
	drawLegend(extStat3Pto3S, "derived from #chi_{b}(3P) #rightarrow #varUpsilon(1S)", xExtrap, y3P, "pl");

	drawHeaderLegend(Form("#it{R}_{21} = %.2f #pm %.2f", ratio2to1_chib1P_CMSaverage, systRatio2to1_chib1P_CMSaverage), xDirect, .6);

	canv3S->SaveAs("figures/extrapolate_FDto3S.png", "RECREATE");
	canv3S->Close();
}
