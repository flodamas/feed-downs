#ifdef __CLING__

#include "myPlot.C"

#include "charmonia/data/BranchingRatios.h"
#include "bottomonia/data/BranchingRatios.h"

#include "charmonia/chicToJpsiLHCb7TeV.C"
#include "charmonia/chicToJpsiATLAS7TeV.C"
#include "bottomonia/feedLHCb7and8TeV.C"

#endif

Float_t xErrorWidth = .4;

void pwavesTo1S(Bool_t withLegend = kFALSE, Bool_t withLogYaxis = kFALSE) {
	string color = "\033[1;31m";

	auto* canv = myCanvas("canv");

	if (withLogYaxis) canv->SetLogy();

	const char* title = ";#it{p}_{T}^{Q#bar{Q}(1S)} (GeV);Feed-down fractions to Q#bar{Q}(1S) (in %)";

	/// Chi_c(1P) -> J/psi

	// LHCb measurements

	Float_t fracChicToJpsi[nPoints_chic_lhcb7TeV], upStat_fracChicToJpsi[nPoints_chic_lhcb7TeV], downStat_fracChicToJpsi[nPoints_chic_lhcb7TeV], upSyst_fracChicToJpsi[nPoints_chic_lhcb7TeV], downSyst_fracChicToJpsi[nPoints_chic_lhcb7TeV];

	for (Int_t i = 0; i < nPoints_chic_lhcb7TeV; i++) {
		fracChicToJpsi[i] = 100. * ratioChicToJpsi_lhcb7TeV[i];

		upStat_fracChicToJpsi[i] = 100. * upStat_ratioChicToJpsi_lhcb7TeV[i];
		downStat_fracChicToJpsi[i] = 100. * downStat_ratioChicToJpsi_lhcb7TeV[i];

		upSyst_fracChicToJpsi[i] = 100. * TMath::Hypot(upSyst_ratioChicToJpsi_lhcb7TeV[i], 0.);     // upPolSyst_ratioChicToJpsi_lhcb7TeV[i]);
		downSyst_fracChicToJpsi[i] = 100. * TMath::Hypot(downSyst_ratioChicToJpsi_lhcb7TeV[i], 0.); // downPolSyst_ratioChicToJpsi_lhcb7TeV[i]);
	}

	auto* statChic_lhcb =
	  statAsymmGraph(title, nPoints_chic_lhcb7TeV, ptBinning_chicToJpsi_lhcb7TeV, fracChicToJpsi, downStat_fracChicToJpsi, upStat_fracChicToJpsi, colorChic, marker1P);

	statChic_lhcb->SetMinimum(10);
	statChic_lhcb->SetMaximum(40);
	statChic_lhcb->GetXaxis()->SetLimits(0, 45);

	if (withLogYaxis) {
		statChic_lhcb->SetMinimum(.4);
		statChic_lhcb->SetMaximum(1000);
	}

	auto* systChic_lhcb =
	  systAsymmGraph(nPoints_chic_lhcb7TeV, ptBinning_chicToJpsi_lhcb7TeV, xErrorWidth, fracChicToJpsi, downSyst_fracChicToJpsi, upSyst_fracChicToJpsi, colorChic - 1);

	statChic_lhcb->Draw("APZ");
	systChic_lhcb->Draw("5");

	// scale the pT for chi_b

	Float_t ptScaled_chic_lhcb7TeV[nPoints_chic_lhcb7TeV + 1];

	for (Int_t i = 0; i <= nPoints_chic_lhcb7TeV; i++) ptScaled_chic_lhcb7TeV[i] = 3.0 * ptBinning_chicToJpsi_lhcb7TeV[i];

	auto* statScaledChic_lhcb =
	  statAsymmGraph(title, nPoints_chic_lhcb7TeV, ptScaled_chic_lhcb7TeV, fracChicToJpsi, downStat_fracChicToJpsi, upStat_fracChicToJpsi, kGray + 2, marker1P);

	auto* systScaledChic_lhcb =
	  systAsymmGraph(nPoints_chic_lhcb7TeV, ptScaled_chic_lhcb7TeV, xErrorWidth, fracChicToJpsi, downSyst_fracChicToJpsi, upSyst_fracChicToJpsi, kGray + 1);

	statScaledChic_lhcb->Draw("PZ");
	systScaledChic_lhcb->Draw("5");

	/// Chi_b(1P) -> Y(1S)

	auto* stat1Pto1S =
	  myStatGraph(title, nPoints1Pto1S_lhcb, ptBinning1Pto1S_lhcb, frac1Pto1S_lhcb8TeV, stat1Pto1S_lhcb8TeV, color1P, marker2P);

	auto* syst1Pto1S =
	  mySystGraph(nPoints1Pto1S_lhcb, ptBinning1Pto1S_lhcb, xErrorWidth, frac1Pto1S_lhcb8TeV, syst1Pto1S_lhcb8TeV, color1P - 1);

	stat1Pto1S->Draw("PZ");
	syst1Pto1S->Draw("5");

	// Chi_b(2P)

	auto* stat2Pto1S =
	  myStatGraph(title, nPoints2Pto1S_lhcb, ptBinning2Pto1S_lhcb, frac2Pto1S_lhcb8TeV, stat2Pto1S_lhcb8TeV, color2P, marker2P);

	auto* syst2Pto1S =
	  mySystGraph(nPoints2Pto1S_lhcb, ptBinning2Pto1S_lhcb, xErrorWidth, frac2Pto1S_lhcb8TeV, syst2Pto1S_lhcb8TeV, color2P);

	//stat2Pto1S->Draw("PZ");
	//	syst2Pto1S->Draw("5");

	auto* stat3Pto1S =
	  myStatGraph(title, nPoints3Pto1S_lhcb, ptBinning3Pto1S_lhcb, frac3Pto1S_lhcb8TeV, stat3Pto1S_lhcb8TeV, color3P, marker2P);

	auto* syst3Pto1S = mySystGraph(nPoints3Pto1S_lhcb, ptBinning3Pto1S_lhcb, xErrorWidth, frac3Pto1S_lhcb8TeV, syst3Pto1S_lhcb8TeV, color3P);

	//stat3Pto1S->Draw("PZ");
	//syst3Pto1S->Draw("5");

	/// legend

	Float_t xHeader = .18, x2 = .6;
	Float_t yHeader = .9, y1 = yHeader - .06, y2 = .4, y3 = .25;

	drawHeaderLegend("pp 7 and 8 TeV, LHCb data", xHeader, yHeader);

	if (withLegend) {
		drawLegend(statChic_lhcb, "#chi_{c}(1P) #rightarrow J/#psi", xHeader, y1, "p");
		drawLegend(statScaledChic_lhcb, "#it{p}_{T} scaled", xHeader, y1 - .06, "p");
		drawLegend(stat1Pto1S, "#chi_{b}(1P) #rightarrow #varUpsilon(1S)", x2, y1, "p");
		//drawLegend(stat2Pto1S, "#chi_{b}(2P) #rightarrow #varUpsilon(1S)", x2, y2, "p");
		//drawLegend(stat3Pto1S, "#chi_{b}(3P) #rightarrow #varUpsilon(1S)", x2, y3, "p");
	}

	canv->SaveAs("figures/pwaveTo1S.png", "RECREATE");
	canv->Close();
}
