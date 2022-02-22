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

// pt binning = (6,8,10,14,18,22,40)

Float_t ratio2Sto1S[] = {.2762, .3049, .338, .392, .438, .485};

Float_t stat2Sto1S[] = {.0021, .0027, .002, .003, .004, .005};

Float_t syst2Sto1S[] = {.0, .0, .019, .016, .015, .015};

// pt binning = (10,14,18,22,40)

Float_t ratio3Sto1S[] = {.191, .252, .304, .339};

Float_t stat3Sto1S[] = {.001, .002, .004, .004};

Float_t syst3Sto1S[] = {.013, .011, .012, .012};

void extrapolateTo2S(Bool_t withLegend = kTRUE, Bool_t withLogYaxis = kFALSE) {
	// Feed-downs to Y(2S)
	auto* canv2S = myCanvas("canv2S");

	if (withLogYaxis) canv2S->SetLogy();

	const char* title2S =
	  ";#it{p}_{T}^{#varUpsilon(2S)} (GeV);Feed-down fractions to #varUpsilon(2S) (in %)";

	/// Y(2S) CMS measurements
	const Int_t nPoints_cms = sizeof(ptBinning_cms7TeV) / sizeof(Float_t) - 1;

	// from relative to absolute uncertainties
	Float_t frac3Sto2S_cms[nPoints_cms], stat3Sto2S_cms[nPoints_cms], syst3Sto2S_cms[nPoints_cms];

	for (Int_t i = 0; i < nPoints_cms; i++) {
		frac3Sto2S_cms[i] = (ptDiff_3S_cms7TeV[i] / ptDiff_2S_cms7TeV[i]) * (br2Stomumu / br3Stomumu) * br3Sto2Sanything;

		stat3Sto2S_cms[i] = frac3Sto2S_cms[i] * TMath::Hypot(statPerc_3S_cms7TeV[i], statPerc_2S_cms7TeV[i]) / 100.;

		syst3Sto2S_cms[i] = frac3Sto2S_cms[i] * systPerc_3Sto1S_cms7TeV[i] / 100.; // should be good
	}

	auto* statGraph_cms3Sto2S = myStatGraph(title2S, nPoints_cms, ptBinning_cms7TeV, frac3Sto2S_cms, stat3Sto2S_cms, color3Sto2S_, markerCMS);

	statGraph_cms3Sto2S->SetMaximum((withLegend) ? 50 : 45);
	statGraph_cms3Sto2S->GetXaxis()->SetLimits(0, 40);
	//statGraph_cms3Sto2S->Draw("APZ");

	auto* systGraph_cms3Sto2S = mySystGraph(nPoints_cms, ptBinning_cms7TeV, xErrorWidth, frac3Sto2S_cms, syst3Sto2S_cms, color3Sto2S_);

	//systGraph_cms3Sto2S->Draw("5");

	/// Chi_b(2P)

	// direct measurements
	auto* directStat2Pto2S =
	  myStatGraph(title2S, nPoints2Pto2S_lhcb, ptBinning2Pto2S_lhcb, frac2Pto2S_lhcb8TeV, stat2Pto2S_lhcb8TeV, color2P, marker3P);

	auto* directSyst2Pto2S =
	  mySystGraph(nPoints2Pto2S_lhcb, ptBinning2Pto2S_lhcb, xErrorWidth, frac2Pto2S_lhcb8TeV, syst2Pto2S_lhcb8TeV, color2P);

	directStat2Pto2S->SetMinimum(0);
	directStat2Pto2S->SetMaximum((withLegend) ? 60 : 45);
	directStat2Pto2S->GetXaxis()->SetLimits(0, 40);

	directStat2Pto2S->Draw("APZ");
	directSyst2Pto2S->Draw("5");

	// extrapolate with chi_b(2P) -> Y(1S) FD measurements

	Float_t extFD_2Pto2S[nPoints2Pto1S_lhcb], statExtFD_2Pto2S[nPoints2Pto1S_lhcb], systExtFD_2Pto2S[nPoints2Pto1S_lhcb];

	Float_t br2P_Jequal1_to2S = br2P_Jequal1_to2Sgamma;
	Float_t br2P_Jequal2_to2S = br2P_Jequal2_to2Sgamma;

	Float_t br2P_Jequal1_to1S = br2P_Jequal1_to1Sgamma + br2P_Jequal1_to1Somega;
	Float_t br2P_Jequal2_to1S = br2P_Jequal2_to1Sgamma + br2P_Jequal2_to1Somega;

	for (Int_t i = 0; i < nPoints2Pto1S_lhcb; i++) {
		// with Lansberg's formula
		//extFD_2Pto2S[i] = (frac2Pto1S_lhcb8TeV[i] / (ratio2Sto1S[i] * br1Stomumu / br2Stomumu)) * (br2P_to2Sall / br2P_to1Sall);

		extFD_2Pto2S[i] = (frac2Pto1S_lhcb8TeV[i] / (ratio2Sto1S[i] * br1Stomumu / br2Stomumu)) * ((br2P_Jequal1_to2S + ratio2to1_chib1P_CMSaverage * br2P_Jequal2_to2S) / (br2P_Jequal1_to1S + ratio2to1_chib1P_CMSaverage * br2P_Jequal2_to1S));

		statExtFD_2Pto2S[i] = extFD_2Pto2S[i] * TMath::Hypot(stat2Pto1S_lhcb8TeV[i] / frac2Pto1S_lhcb8TeV[i], stat2Sto1S[i] / ratio2Sto1S[i]);

		systExtFD_2Pto2S[i] = extFD_2Pto2S[i] * TMath::Hypot(syst2Pto1S_lhcb8TeV[i] / frac2Pto1S_lhcb8TeV[i], syst2Sto1S[i] / ratio2Sto1S[i]);
	}

	auto* extStat2Pto2S =
	  myStatGraph(title2S, nPoints2Pto1S_lhcb, ptBinning2Pto1S_lhcb, extFD_2Pto2S, statExtFD_2Pto2S, color2P + 1, marker2P + 4);

	extStat2Pto2S->Draw("PZ");

	auto* extSyst2Pto2S =
	  mySystGraph(nPoints2Pto1S_lhcb, ptBinning2Pto1S_lhcb, xErrorWidth, extFD_2Pto2S, systExtFD_2Pto2S, kGray + 1);

	extSyst2Pto2S->Draw("5");

	/// Chi_b(3P)

	// direct measurements

	auto* directStat3Pto2S =
	  myStatGraph(title2S, nPoints3Pto2S_lhcb, ptBinning3Pto2S_lhcb, frac3Pto2S_lhcb8TeV, stat3Pto2S_lhcb8TeV, color3P, marker3P);

	auto* directSyst3Pto2S =
	  mySystGraph(nPoints3Pto2S_lhcb, ptBinning3Pto2S_lhcb, xErrorWidth, frac3Pto2S_lhcb8TeV, syst3Pto2S_lhcb8TeV, color3P);

	directStat3Pto2S->Draw("PZ");
	directSyst3Pto2S->Draw("5");

	// extrapolate with chi_b(3P) -> Y(1S) FD measurements

	Float_t extFD_3Pto2S[nPoints3Pto1S_lhcb], statExtFD_3Pto2S[nPoints3Pto1S_lhcb], systExtFD_3Pto2S[nPoints3Pto1S_lhcb];

	for (Int_t i = 0; i < nPoints3Pto1S_lhcb; i++) {
		// with Lansberg's formula
		//extFD_3Pto2S[i] = (frac3Pto1S_lhcb8TeV[i] / (ratio3Sto1S[i] * br1Stomumu / br3Stomumu)) * (br3P_to2Sall / br3P_to1Sall);

		extFD_3Pto2S[i] = (frac3Pto1S_lhcb8TeV[i] / (ratio3Sto1S[i] * br1Stomumu / br3Stomumu)) * ((br3P_Jequal1_to2Sgamma + ratio2to1_chib1P_CMSaverage * br3P_Jequal2_to2Sgamma) / (br3P_Jequal1_to1Sgamma + ratio2to1_chib1P_CMSaverage * br3P_Jequal2_to1Sgamma));

		statExtFD_3Pto2S[i] = extFD_3Pto2S[i] * TMath::Hypot(stat3Pto1S_lhcb8TeV[i] / frac3Pto1S_lhcb8TeV[i], stat3Sto1S[i] / ratio3Sto1S[i]);

		systExtFD_3Pto2S[i] = extFD_3Pto2S[i] * TMath::Hypot(syst3Pto1S_lhcb8TeV[i] / frac3Pto1S_lhcb8TeV[i], syst3Sto1S[i] / ratio3Sto1S[i]);
	}

	auto* extStat3Pto2S =
	  myStatGraph(title2S, nPoints3Pto1S_lhcb, ptBinning3Pto1S_lhcb, extFD_3Pto2S, statExtFD_3Pto2S, color3P - 1, marker2P + 4);

	extStat3Pto2S->Draw("PZ");

	auto* extSyst3Pto2S =
	  mySystGraph(nPoints3Pto1S_lhcb, ptBinning3Pto1S_lhcb, xErrorWidth, extFD_3Pto2S, systExtFD_3Pto2S, color3P);

	extSyst3Pto2S->Draw("5");

	/// legend

	Float_t yHeader = .9, y2P = yHeader - .07, y3P = y2P - .07;

	Float_t xChib = .17, xDirect = .265, xExtrap = xDirect + .19;

	drawHeaderLegend("pp 7 and 8 TeV data, #varUpsilon(2S) from", xChib, yHeader);

	drawHeaderLegend("#chi_{b}(2P)", xChib, y2P);
	drawLegend(directStat2Pto2S, "reported", xDirect, y2P, "pl");
	drawLegend(extStat2Pto2S, "derived from #chi_{b}(2P) #rightarrow #varUpsilon(1S)", xExtrap, y2P, "pl");

	drawHeaderLegend("#chi_{b}(3P)", xChib, y3P);
	drawLegend(directStat3Pto2S, "reported", xDirect, y3P, "pl");
	drawLegend(extStat3Pto2S, "derived from #chi_{b}(3P) #rightarrow #varUpsilon(1S)", xExtrap, y3P, "pl");

	drawHeaderLegend(Form("#it{R}_{21} = %.2f #pm %.2f", ratio2to1_chib1P_CMSaverage, systRatio2to1_chib1P_CMSaverage), xChib, .6);

	canv2S->SaveAs("figures/extrapolate_FDto2S.png", "RECREATE");
	canv2S->Close();

	//

	for (Int_t i = 0; i < nPoints_chic_lhcb7TeV; i++) {
		//ptScaled_chic_lhcb7TeV[i] = 2.8 * ptBinning_chic_lhcb7TeV[i];
		cout << ptScaled_chic_lhcb7TeV[i] << endl;
	}
}
