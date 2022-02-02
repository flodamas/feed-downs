#ifdef __CLING__

#include "myPlot.C"

#include "bottomonia/branching.C"
#include "bottomonia/upsilonATLAS7TeV.C"
#include "bottomonia/upsilonCMS7TeV.C"
#include "bottomonia/upsilonLHCb7and8TeV.C"

#endif

Float_t xErrorWidth = .4;

void ptRatios_7TeV(Bool_t withLogYaxis = kFALSE) {
	const char* title = ";#it{p}_{T} (GeV);BR(#varUpsilon#rightarrow #mu^{#plus}#mu^{#minus}) #times cross-section ratio";

	/// Y(2S)-to-Y(1S)

	auto* canvas2Sto1S = myCanvas("canvas2Sto1S");

	// ATLAS first
	const Int_t nPoints_atlas = sizeof(ptBinning_atlas7TeV) / sizeof(Float_t) - 1;

	auto* statGraph_atlas2Sto1S = myStatGraph(title, nPoints_atlas, ptBinning_atlas7TeV, ptDiff_2Sto1S_atlas7TeV, statPtDiff_2Sto1S_atlas7TeV, colorATLAS, markerATLAS);

	statGraph_atlas2Sto1S->SetMaximum(.8);

	if (withLogYaxis) {
		canvas2Sto1S->SetLogy();
		statGraph_atlas2Sto1S->SetMinimum(0.15);
		statGraph_atlas2Sto1S->SetMaximum(.8);
	}

	statGraph_atlas2Sto1S->GetXaxis()->SetLimits(0, 50);
	statGraph_atlas2Sto1S->Draw("APZ");

	auto* systGraph_atlas2Sto1S = mySystGraph(nPoints_atlas, ptBinning_atlas7TeV, xErrorWidth, ptDiff_2Sto1S_atlas7TeV, systPtDiff_2Sto1S_atlas7TeV, colorATLAS - 1);
	systGraph_atlas2Sto1S->Draw("5");

	// CMS
	const Int_t nPoints_cms = sizeof(ptBinning_cms7TeV) / sizeof(Float_t) - 1;

	// from relative to absolute uncertainties and compute Y(3S) / Y(2S)
	Float_t stat_2Sto1S_cms7TeV[nPoints_cms], stat_3Sto1S_cms7TeV[nPoints_cms], syst_2Sto1S_cms7TeV[nPoints_cms], syst_3Sto1S_cms7TeV[nPoints_cms];

	Float_t ptDiff_3Sto2S_cms7TeV[nPoints_cms], stat_3Sto2S_cms7TeV[nPoints_cms], syst_3Sto2S_cms7TeV[nPoints_cms];

	for (Int_t i = 0; i < nPoints_cms; i++) {
		stat_2Sto1S_cms7TeV[i] = ptDiff_2Sto1S_cms7TeV[i] * statPerc_2Sto1S_cms7TeV[i] / 100.;
		syst_2Sto1S_cms7TeV[i] = ptDiff_2Sto1S_cms7TeV[i] * systPerc_2Sto1S_cms7TeV[i] / 100.;

		stat_3Sto1S_cms7TeV[i] = ptDiff_3Sto1S_cms7TeV[i] * statPerc_3Sto1S_cms7TeV[i] / 100.;
		syst_3Sto1S_cms7TeV[i] = ptDiff_3Sto1S_cms7TeV[i] * systPerc_3Sto1S_cms7TeV[i] / 100.;

		// Y(3S) / Y(2S)
		ptDiff_3Sto2S_cms7TeV[i] = ptDiff_3S_cms7TeV[i] / ptDiff_2S_cms7TeV[i];

		stat_3Sto2S_cms7TeV[i] = ptDiff_3Sto2S_cms7TeV[i] * TMath::Hypot(statPerc_3S_cms7TeV[i], statPerc_2S_cms7TeV[i]) / 100.;

		syst_3Sto2S_cms7TeV[i] = ptDiff_3Sto2S_cms7TeV[i] * systPerc_3Sto1S_cms7TeV[i] / 100.; // should be good
	}

	auto* statGraph_cms2Sto1S = myStatGraph(title, nPoints_cms, ptBinning_cms7TeV, ptDiff_2Sto1S_cms7TeV, stat_2Sto1S_cms7TeV, colorCMS, markerCMS);

	statGraph_cms2Sto1S->Draw("PZ");

	auto* systGraph_cms2Sto1S = mySystGraph(nPoints_cms, ptBinning_cms7TeV, xErrorWidth, ptDiff_2Sto1S_cms7TeV, syst_2Sto1S_cms7TeV, colorCMS - 1);

	systGraph_cms2Sto1S->Draw("5");

	// LHCb
	const Int_t nPoints_lhcb = sizeof(ptBinning_2p0y4p5_lhcb7and8TeV) / sizeof(Float_t) - 1;

	auto* statGraph_lhcb2Sto1S = myStatGraph(title, nPoints_lhcb, ptBinning_2p0y4p5_lhcb7and8TeV, ptDiff_2p0y4p5_2Sto1S_lhcb7TeV, errorPtDiff_2p0y4p5_2Sto1S_lhcb7TeV, colorLHCb, markerLHCb);
	statGraph_lhcb2Sto1S->Draw("PZ");

	// legend

	Float_t xLegend = .5;
	Float_t yHeader = .9, yATLAS = .4, yCMS = yATLAS - .06, yLHCb = yCMS - .06;

	drawHeaderLegend("#varUpsilon(2S) / #varUpsilon(1S), pp #sqrt{#it{s}} = 7 TeV", .2, yHeader);

	drawLegend(statGraph_atlas2Sto1S, "ATLAS, |#it{y} | < 1.2", xLegend, yATLAS, "pl");
	drawLegend(statGraph_cms2Sto1S, "CMS, |#it{y} | < 1.2", xLegend, yCMS, "pl");
	drawLegend(statGraph_lhcb2Sto1S, "LHCb, 2.0 < #it{y} < 4.5", xLegend, yLHCb, "pl");

	canvas2Sto1S->SaveAs("figures/pt7TeV_2Sto1S.png", "RECREATE");

	/// Y(3S)-to-Y(1S)

	auto* canvas3Sto1S = myCanvas("canvas3Sto1S");

	// ATLAS first

	auto* statGraph_atlas3Sto1S = myStatGraph(title, nPoints_atlas, ptBinning_atlas7TeV, ptDiff_3Sto1S_atlas7TeV, statPtDiff_3Sto1S_atlas7TeV, colorATLAS, markerATLAS);

	statGraph_atlas3Sto1S->SetMaximum(.6);

	if (withLogYaxis) {
		canvas3Sto1S->SetLogy();
		statGraph_atlas3Sto1S->SetMinimum(0.06);
		statGraph_atlas3Sto1S->SetMaximum(.7);
	}

	statGraph_atlas3Sto1S->GetXaxis()->SetLimits(0, 50);
	statGraph_atlas3Sto1S->Draw("APZ");

	auto* systGraph_atlas3Sto1S = mySystGraph(nPoints_atlas, ptBinning_atlas7TeV, xErrorWidth, ptDiff_3Sto1S_atlas7TeV, systPtDiff_3Sto1S_atlas7TeV, colorATLAS - 1);
	systGraph_atlas3Sto1S->Draw("5");

	// CMS
	auto* statGraph_cms3Sto1S = myStatGraph(title, nPoints_cms, ptBinning_cms7TeV, ptDiff_3Sto1S_cms7TeV, stat_3Sto1S_cms7TeV, colorCMS, markerCMS);

	statGraph_cms3Sto1S->Draw("PZ");

	auto* systGraph_cms3Sto1S = mySystGraph(nPoints_cms, ptBinning_cms7TeV, xErrorWidth, ptDiff_3Sto1S_cms7TeV, syst_3Sto1S_cms7TeV, colorCMS - 1);

	systGraph_cms3Sto1S->Draw("5");

	// LHCb
	auto* statGraph_lhcb3Sto1S = myStatGraph(title, nPoints_lhcb, ptBinning_2p0y4p5_lhcb7and8TeV, ptDiff_2p0y4p5_3Sto1S_lhcb7TeV, errorPtDiff_2p0y4p5_3Sto1S_lhcb7TeV, colorLHCb, markerLHCb);

	statGraph_lhcb3Sto1S->Draw("PZ");

	// legend

	drawHeaderLegend("#varUpsilon(3S) / #varUpsilon(1S), pp #sqrt{#it{s}} = 7 TeV", .2, yHeader);

	drawLegend(statGraph_atlas3Sto1S, "ATLAS, |#it{y} | < 1.2", xLegend, yATLAS, "pl");
	drawLegend(statGraph_cms3Sto1S, "CMS, |#it{y} | < 1.2", xLegend, yCMS, "pl");
	drawLegend(statGraph_lhcb3Sto1S, "LHCb, 2.0 < #it{y} < 4.5", xLegend, yLHCb, "pl");

	canvas3Sto1S->SaveAs("figures/pt7TeV_3Sto1S.png", "RECREATE");

	/// Y(3S)-to-Y(2S)

	auto* canvas3Sto2S = myCanvas("canvas3Sto2S");

	// ATLAS first

	Float_t ptDiff_3Sto2S_atlas7TeV[nPoints_atlas], stat_3Sto2S_atlas7TeV[nPoints_atlas], syst_3Sto2S_atlas7TeV[nPoints_atlas];

	for (Int_t i = 0; i < nPoints_atlas; i++) {
		ptDiff_3Sto2S_atlas7TeV[i] = ptDiff_3S_atlas7TeV[i] / ptDiff_2S_atlas7TeV[i];

		stat_3Sto2S_atlas7TeV[i] = ptDiff_3Sto2S_atlas7TeV[i] * TMath::Hypot(statPtDiff_3S_atlas7TeV[i] / ptDiff_3S_atlas7TeV[i], statPtDiff_2S_atlas7TeV[i] / ptDiff_2S_atlas7TeV[i]);

		syst_3Sto2S_atlas7TeV[i] = ptDiff_3Sto2S_atlas7TeV[i] * systPtDiff_3S_atlas7TeV[i] / ptDiff_3S_atlas7TeV[i]; // should be good
	}

	auto* statGraph_atlas3Sto2S = myStatGraph(title, nPoints_atlas, ptBinning_atlas7TeV, ptDiff_3Sto2S_atlas7TeV, stat_3Sto2S_atlas7TeV, colorATLAS, markerATLAS);

	statGraph_atlas3Sto2S->SetMaximum(1.4);

	if (withLogYaxis) {
		canvas3Sto2S->SetLogy();
		statGraph_atlas3Sto2S->SetMinimum(0.3);
		statGraph_atlas3Sto2S->SetMaximum(1.1);
	}

	statGraph_atlas3Sto2S->GetXaxis()->SetLimits(0, 50);
	statGraph_atlas3Sto2S->Draw("APZ");

	auto* systGraph_atlas3Sto2S = mySystGraph(nPoints_atlas, ptBinning_atlas7TeV, xErrorWidth, ptDiff_3Sto2S_atlas7TeV, syst_3Sto2S_atlas7TeV, colorATLAS - 1);
	systGraph_atlas3Sto2S->Draw("5");

	// CMS

	auto* statGraph_cms3Sto2S = myStatGraph(title, nPoints_cms, ptBinning_cms7TeV, ptDiff_3Sto2S_cms7TeV, stat_3Sto2S_cms7TeV, colorCMS, markerCMS);

	statGraph_cms3Sto2S->Draw("PZ");

	auto* systGraph_cms3Sto2S = mySystGraph(nPoints_cms, ptBinning_cms7TeV, xErrorWidth, ptDiff_3Sto2S_cms7TeV, syst_3Sto2S_cms7TeV, colorCMS - 1);

	systGraph_cms3Sto2S->Draw("5");

	// LHCb

	auto* statGraph_lhcb3Sto2S = myStatGraph(title, nPoints_lhcb, ptBinning_2p0y4p5_lhcb7and8TeV, ptDiff_2p0y4p5_3Sto2S_lhcb7TeV, errorPtDiff_2p0y4p5_3Sto2S_lhcb7TeV, colorLHCb, markerLHCb);

	statGraph_lhcb3Sto2S->Draw("PZ");

	// legend

	drawHeaderLegend("#varUpsilon(3S) / #varUpsilon(2S), pp #sqrt{#it{s}} = 7 TeV", .2, yHeader);

	drawLegend(statGraph_atlas3Sto2S, "ATLAS, |#it{y} | < 1.2", xLegend, yATLAS, "pl");
	drawLegend(statGraph_cms3Sto2S, "CMS, |#it{y} | < 1.2", xLegend, yCMS, "pl");
	drawLegend(statGraph_lhcb3Sto2S, "LHCb, 2.0 < #it{y} < 4.5", xLegend, yLHCb, "pl");

	canvas3Sto2S->SaveAs("figures/pt7TeV_3Sto2S.png", "RECREATE");
}
