#ifdef __CLING__

#include "myPlot.C"

#include "bottomonia/branching.C"
#include "bottomonia/upsilonCMS7TeV.C"
#include "bottomonia/upsilonCMS13TeV.C"
#include "bottomonia/upsilonLHCb7and8TeV.C"

#endif

// check which of the CMS datasets is the most precise

Float_t xErrorWidth = .5, xMin = 20, xMax = 70;

void plotCMSratios(Bool_t withLogYaxis = kFALSE) {
	const char* title = ";#it{p}_{T} (GeV);BR(#varUpsilon#rightarrow #mu^{#plus}#mu^{#minus}) #times cross-section ratio";

	/// Y(2S)-to-Y(1S)

	auto* canvas2Sto1S = myCanvas("canvas2Sto1S");

	// CMS 7 TeV
	const Int_t nPoints_cms7TeV = sizeof(ptBinning_cms7TeV) / sizeof(Float_t) - 1;

	// from relative to absolute uncertainties and compute Y(3S) / Y(2S)
	Float_t stat_2Sto1S_cms7TeV[nPoints_cms7TeV], stat_3Sto1S_cms7TeV[nPoints_cms7TeV], syst_2Sto1S_cms7TeV[nPoints_cms7TeV], syst_3Sto1S_cms7TeV[nPoints_cms7TeV];

	Float_t ptDiff_3Sto2S_cms7TeV[nPoints_cms7TeV], stat_3Sto2S_cms7TeV[nPoints_cms7TeV], syst_3Sto2S_cms7TeV[nPoints_cms7TeV];

	for (Int_t i = 0; i < nPoints_cms7TeV; i++) {
		stat_2Sto1S_cms7TeV[i] = ptDiff_2Sto1S_cms7TeV[i] * statPerc_2Sto1S_cms7TeV[i] / 100.;
		syst_2Sto1S_cms7TeV[i] = ptDiff_2Sto1S_cms7TeV[i] * systPerc_2Sto1S_cms7TeV[i] / 100.;

		stat_3Sto1S_cms7TeV[i] = ptDiff_3Sto1S_cms7TeV[i] * statPerc_3Sto1S_cms7TeV[i] / 100.;
		syst_3Sto1S_cms7TeV[i] = ptDiff_3Sto1S_cms7TeV[i] * systPerc_3Sto1S_cms7TeV[i] / 100.;

		// Y(3S) / Y(2S)
		ptDiff_3Sto2S_cms7TeV[i] = ptDiff_3S_cms7TeV[i] / ptDiff_2S_cms7TeV[i];

		stat_3Sto2S_cms7TeV[i] = ptDiff_3Sto2S_cms7TeV[i] * TMath::Hypot(statPerc_3S_cms7TeV[i], statPerc_2S_cms7TeV[i]) / 100.;

		syst_3Sto2S_cms7TeV[i] = ptDiff_3Sto2S_cms7TeV[i] * systPerc_3Sto1S_cms7TeV[i] / 100.; // should be good
	}

	auto* statGraph_cms7TeV_2Sto1S = myStatGraph(title, nPoints_cms7TeV, ptBinning_cms7TeV, ptDiff_2Sto1S_cms7TeV, stat_2Sto1S_cms7TeV, colorCMS, markerCMS);

	statGraph_cms7TeV_2Sto1S->SetMinimum(0.3);
	statGraph_cms7TeV_2Sto1S->SetMaximum(0.8);

	if (withLogYaxis) {
		canvas2Sto1S->SetLogy();
		statGraph_cms7TeV_2Sto1S->SetMinimum(0.15);
		statGraph_cms7TeV_2Sto1S->SetMaximum(1.5);
	}

	statGraph_cms7TeV_2Sto1S->GetXaxis()->SetLimits(xMin, xMax);

	statGraph_cms7TeV_2Sto1S->Draw("APZ");

	auto* systGraph_cms7TeV_2Sto1S = mySystGraph(nPoints_cms7TeV, ptBinning_cms7TeV, xErrorWidth, ptDiff_2Sto1S_cms7TeV, syst_2Sto1S_cms7TeV, colorCMS - 1);

	systGraph_cms7TeV_2Sto1S->Draw("5");

	// CMS 13 TeV
	const Int_t nPoints_cms13TeV = sizeof(ptBinning_cms13TeV) / sizeof(Float_t) - 1;

	// from relative to absolute uncertainties and compute Y(3S) / Y(2S)
	Float_t stat_2Sto1S_cms13TeV[nPoints_cms13TeV], stat_3Sto1S_cms13TeV[nPoints_cms13TeV], syst_2Sto1S_cms13TeV[nPoints_cms13TeV], syst_3Sto1S_cms13TeV[nPoints_cms13TeV];

	Float_t ptDiff_3Sto2S_cms13TeV[nPoints_cms13TeV], stat_3Sto2S_cms13TeV[nPoints_cms13TeV], syst_3Sto2S_cms13TeV[nPoints_cms13TeV];

	for (Int_t i = 0; i < nPoints_cms13TeV; i++) {
		// shift the binning for readability
		ptBinning_cms13TeV[i] += .5;

		stat_2Sto1S_cms13TeV[i] = ptDiff_2Sto1S_cms13TeV[i] * statPerc_2Sto1S_cms13TeV[i] / 100.;
		syst_2Sto1S_cms13TeV[i] = ptDiff_2Sto1S_cms13TeV[i] * systPerc_2Sto1S_cms13TeV[i] / 100.;

		stat_3Sto1S_cms13TeV[i] = ptDiff_3Sto1S_cms13TeV[i] * statPerc_3Sto1S_cms13TeV[i] / 100.;
		syst_3Sto1S_cms13TeV[i] = ptDiff_3Sto1S_cms13TeV[i] * systPerc_3Sto1S_cms13TeV[i] / 100.;

		// Y(3S) / Y(2S)
		ptDiff_3Sto2S_cms13TeV[i] = ptDiff_3S_cms13TeV[i] / ptDiff_2S_cms13TeV[i];

		stat_3Sto2S_cms13TeV[i] = ptDiff_3Sto2S_cms13TeV[i] * TMath::Hypot(statPerc_3S_cms13TeV[i], statPerc_2S_cms13TeV[i]) / 100.;

		syst_3Sto2S_cms13TeV[i] = ptDiff_3Sto2S_cms13TeV[i] * systPerc_3Sto1S_cms13TeV[i] / 100.; // should be good
	}

	auto* statGraph_cms13TeV_2Sto1S = myStatGraph(title, nPoints_cms13TeV, ptBinning_cms13TeV, ptDiff_2Sto1S_cms13TeV, stat_2Sto1S_cms13TeV, kAzure + 1, 25);

	statGraph_cms13TeV_2Sto1S->Draw("PZ");

	auto* systGraph_cms13TeV_2Sto1S = mySystGraph(nPoints_cms13TeV, ptBinning_cms13TeV, xErrorWidth, ptDiff_2Sto1S_cms13TeV, syst_2Sto1S_cms13TeV, kAzure + 1);

	systGraph_cms13TeV_2Sto1S->Draw("5");

	// LHCb
	const Int_t nPoints_lhcb = sizeof(ptBinning_2p0y4p5_lhcb7and8TeV) / sizeof(Float_t) - 1 - 3;

	auto* statGraph_lhcb2Sto1S = myStatGraph(title, nPoints_lhcb, ptBinning_2p0y4p5_lhcb7and8TeV, ptDiff_2p0y4p5_2Sto1S_lhcb8TeV, errorPtDiff_2p0y4p5_2Sto1S_lhcb8TeV, colorLHCb, markerLHCb);
	//statGraph_lhcb2Sto1S->Draw("PZ");

	// legend

	Float_t xLegend = .18;
	Float_t yHeader = .9, yCMS7 = yHeader - .06, yCMS13 = yCMS7 - .06, yLHCb = yCMS13 - .06;

	drawHeaderLegend("#varUpsilon(2S) / #varUpsilon(1S)", xLegend, yHeader);

	drawLegend(statGraph_cms7TeV_2Sto1S, "CMS 7 TeV", xLegend, yCMS7, "pl");
	drawLegend(statGraph_cms13TeV_2Sto1S, "CMS 13 TeV", xLegend, yCMS13, "pl");
	//drawLegend(statGraph_lhcb2Sto1S, "LHCb 8 TeV", xLegend, yLHCb, "pl");

	canvas2Sto1S->SaveAs("figures/CMS_2Sto1S.png", "RECREATE");

	/// Y(3S)-to-Y(1S)

	auto* canvas3Sto1S = myCanvas("canvas3Sto1S");

	// CMS 7 TeV
	auto* statGraph_cms7TeV_3Sto1S = myStatGraph(title, nPoints_cms7TeV, ptBinning_cms7TeV, ptDiff_3Sto1S_cms7TeV, stat_3Sto1S_cms7TeV, colorCMS, markerCMS);

	statGraph_cms7TeV_3Sto1S->SetMinimum(0.2);
	statGraph_cms7TeV_3Sto1S->SetMaximum(0.7);

	if (withLogYaxis) {
		canvas3Sto1S->SetLogy();
		statGraph_cms7TeV_3Sto1S->SetMinimum(0.3);
		statGraph_cms7TeV_3Sto1S->SetMaximum(1.5);
	}

	statGraph_cms7TeV_3Sto1S->GetXaxis()->SetLimits(xMin, xMax);

	statGraph_cms7TeV_3Sto1S->Draw("APZ");

	auto* systGraph_cms7TeV_3Sto1S = mySystGraph(nPoints_cms7TeV, ptBinning_cms7TeV, xErrorWidth, ptDiff_3Sto1S_cms7TeV, syst_3Sto1S_cms7TeV, colorCMS - 1);

	systGraph_cms7TeV_3Sto1S->Draw("5");

	// CMS 13 TeV
	auto* statGraph_cms13TeV_3Sto1S = myStatGraph(title, nPoints_cms13TeV, ptBinning_cms13TeV, ptDiff_3Sto1S_cms13TeV, stat_3Sto1S_cms13TeV, kAzure + 1, 25);

	statGraph_cms13TeV_3Sto1S->Draw("PZ");

	auto* systGraph_cms13TeV_3Sto1S = mySystGraph(nPoints_cms13TeV, ptBinning_cms13TeV, xErrorWidth, ptDiff_3Sto1S_cms13TeV, syst_3Sto1S_cms13TeV, kAzure + 1);

	systGraph_cms13TeV_3Sto1S->Draw("5");

	// LHCb
	auto* statGraph_lhcb3Sto1S = myStatGraph(title, nPoints_lhcb, ptBinning_2p0y4p5_lhcb7and8TeV, ptDiff_2p0y4p5_3Sto1S_lhcb8TeV, errorPtDiff_2p0y4p5_3Sto1S_lhcb8TeV, colorLHCb, markerLHCb);

	//statGraph_lhcb3Sto1S->Draw("PZ");

	// legend

	drawHeaderLegend("#varUpsilon(3S) / #varUpsilon(1S)", xLegend, yHeader);

	drawLegend(statGraph_cms7TeV_3Sto1S, "CMS 7 TeV", xLegend, yCMS7, "pl");
	drawLegend(statGraph_cms13TeV_3Sto1S, "CMS 13 TeV", xLegend, yCMS13, "pl");

	//drawLegend(statGraph_lhcb3Sto1S, "LHCb 8 TeV", xLegend, yLHCb, "pl");

	canvas3Sto1S->SaveAs("figures/CMS_3Sto1S.png", "RECREATE");

	/// Y(3S)-to-Y(2S)

	auto* canvas3Sto2S = myCanvas("canvas3Sto2S");

	// CMS 7 TeV

	auto* statGraph_cms7TeV_3Sto2S = myStatGraph(title, nPoints_cms7TeV, ptBinning_cms7TeV, ptDiff_3Sto2S_cms7TeV, stat_3Sto2S_cms7TeV, colorCMS, markerCMS);

	statGraph_cms7TeV_3Sto2S->SetMinimum(0.5);
	statGraph_cms7TeV_3Sto2S->SetMaximum(1.2);

	if (withLogYaxis) {
		canvas3Sto2S->SetLogy();
		statGraph_cms7TeV_3Sto2S->SetMinimum(0.3);
		statGraph_cms7TeV_3Sto2S->SetMaximum(1.5);
	}

	statGraph_cms7TeV_3Sto2S->GetXaxis()->SetLimits(xMin, xMax);

	statGraph_cms7TeV_3Sto2S->Draw("APZ");

	auto* systGraph_cms7TeV_3Sto2S = mySystGraph(nPoints_cms7TeV, ptBinning_cms7TeV, xErrorWidth, ptDiff_3Sto2S_cms7TeV, syst_3Sto2S_cms7TeV, colorCMS - 1);

	systGraph_cms7TeV_3Sto2S->Draw("5");

	// CMS 13 TeV

	auto* statGraph_cms13TeV_3Sto2S = myStatGraph(title, nPoints_cms13TeV, ptBinning_cms13TeV, ptDiff_3Sto2S_cms13TeV, stat_3Sto2S_cms13TeV, kAzure + 1, 25);

	statGraph_cms13TeV_3Sto2S->Draw("PZ");

	auto* systGraph_cms13TeV_3Sto2S = mySystGraph(nPoints_cms13TeV, ptBinning_cms13TeV, xErrorWidth, ptDiff_3Sto2S_cms13TeV, syst_3Sto2S_cms13TeV, kAzure + 1);

	systGraph_cms13TeV_3Sto2S->Draw("5");

	// LHCb

	auto* statGraph_lhcb3Sto2S = myStatGraph(title, nPoints_lhcb, ptBinning_2p0y4p5_lhcb7and8TeV, ptDiff_2p0y4p5_3Sto2S_lhcb8TeV, errorPtDiff_2p0y4p5_3Sto2S_lhcb8TeV, colorLHCb, markerLHCb);

	//statGraph_lhcb3Sto2S->Draw("PZ");

	// legend

	drawHeaderLegend("#varUpsilon(3S) / #varUpsilon(2S)", xLegend, yHeader);

	drawLegend(statGraph_cms7TeV_3Sto2S, "CMS 7 TeV", xLegend, yCMS7, "pl");
	drawLegend(statGraph_cms13TeV_3Sto2S, "CMS 13 TeV", xLegend, yCMS13, "pl");
	//drawLegend(statGraph_lhcb3Sto2S, "LHCb 8 TeV", xLegend, yLHCb, "pl");

	canvas3Sto2S->SaveAs("figures/CMS_3Sto2S.png", "RECREATE");
}
