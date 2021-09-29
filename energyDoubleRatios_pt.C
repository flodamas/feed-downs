#ifdef __CLING__

#include "myPlot.C"

#include "data/branching.C"

#include "data/upsilonCMS7TeV.C"
#include "data/upsilonCMS13TeV.C"

#include "data/upsilonLHCb7and8TeV.C"
#include "data/upsilonLHCb13TeV.C"

#endif

Float_t xErrorWidth = .4;

// Is there a significant energy dependence of the pt-differential cross-section ratios?

void energyDoubleRatios_pt(Bool_t withLogYaxis = kFALSE) {
	auto* canvas = myCanvas("canvas");

	const char* title = ";#it{p}_{T} (GeV/#it{c});13-to-7 TeV cross-section double ratio";

	/// Start with LHCb measurements
	const Int_t nPointsLHCb = sizeof(ptBinning_2p0y4p5_lhcb13TeV) / sizeof(Float_t) - 1;

	Float_t ptDiff_2Sto1S_lhcb[nPointsLHCb], stat_2Sto1S_lhcb[nPointsLHCb];
	Float_t ptDiff_3Sto1S_lhcb[nPointsLHCb], stat_3Sto1S_lhcb[nPointsLHCb];
	Float_t ptDiff_3Sto2S_lhcb[nPointsLHCb], stat_3Sto2S_lhcb[nPointsLHCb];

	for (Int_t i = 0; i < nPointsLHCb; i++) {
		ptDiff_2Sto1S_lhcb[i] = ptDiff_2Sto1S_2p0y4p5_lhcb13TeV[i] / ptDiff_2p0y4p5_2Sto1S_lhcb7TeV[i];

		stat_2Sto1S_lhcb[i] = ptDiff_2Sto1S_lhcb[i] * TMath::Hypot(errorPtDiff_2Sto1S_2p0y4p5_lhcb13TeV[i] / ptDiff_2Sto1S_2p0y4p5_lhcb13TeV[i], errorPtDiff_2p0y4p5_2Sto1S_lhcb7TeV[i] / ptDiff_2p0y4p5_2Sto1S_lhcb7TeV[i]);

		ptDiff_3Sto1S_lhcb[i] = ptDiff_3Sto1S_2p0y4p5_lhcb13TeV[i] / ptDiff_2p0y4p5_3Sto1S_lhcb7TeV[i];

		stat_3Sto1S_lhcb[i] = ptDiff_3Sto1S_lhcb[i] * TMath::Hypot(errorPtDiff_3Sto1S_2p0y4p5_lhcb13TeV[i] / ptDiff_3Sto1S_2p0y4p5_lhcb13TeV[i], errorPtDiff_2p0y4p5_3Sto1S_lhcb7TeV[i] / ptDiff_2p0y4p5_3Sto1S_lhcb7TeV[i]);

		// Y(3S) / Y(2S)
		ptDiff_3Sto2S_lhcb[i] = (ptDiff_2p0y4p5_3S_lhcb13TeV[i] / ptDiff_2p0y4p5_2S_lhcb13TeV[i]) / ptDiff_2p0y4p5_3Sto2S_lhcb7TeV[i];

		stat_3Sto2S_lhcb[i] = ptDiff_3Sto2S_lhcb[i] * TMath::Hypot(errorPtDiff_2p0y4p5_3S_lhcb13TeV[i] / ptDiff_2p0y4p5_3S_lhcb13TeV[i], errorPtDiff_2p0y4p5_3Sto2S_lhcb7TeV[i] / ptDiff_2p0y4p5_3Sto2S_lhcb7TeV[i]);
	}

	// Y(3S)-to-Y(2S)

	auto* statGraph_lhcb3Sto2S = myStatGraph(title, nPointsLHCb, ptBinning_2p0y4p5_lhcb13TeV, ptDiff_3Sto2S_lhcb, stat_3Sto2S_lhcb, color3Sto2S, markerLHCb);

	statGraph_lhcb3Sto2S->SetMinimum(0.5);
	statGraph_lhcb3Sto2S->SetMaximum(1.8);

	if (withLogYaxis) {
		canvas->SetLogy();
		statGraph_lhcb3Sto2S->SetMinimum(0.5);
		statGraph_lhcb3Sto2S->SetMaximum(8);
	}

	statGraph_lhcb3Sto2S->GetXaxis()->SetLimits(0, 100);

	statGraph_lhcb3Sto2S->Draw("APZ");

	// Y(2S)-to-Y(1S)

	auto* statGraph_lhcb2Sto1S = myStatGraph(title, nPointsLHCb, ptBinning_2p0y4p5_lhcb13TeV, ptDiff_2Sto1S_lhcb, stat_2Sto1S_lhcb, color2Sto1S, markerLHCb);

	statGraph_lhcb2Sto1S->Draw("PZ");

	// Y(3S)-to-Y(1S)

	auto* statGraph_lhcb3Sto1S = myStatGraph(title, nPointsLHCb, ptBinning_2p0y4p5_lhcb13TeV, ptDiff_3Sto1S_lhcb, stat_3Sto1S_lhcb, color3Sto1S, markerLHCb);

	statGraph_lhcb3Sto1S->Draw("PZ");

	/// CMS measurements
	const Int_t nPointsCMS = sizeof(ptBinning_cms7TeV) / sizeof(Float_t) - 1;

	Float_t ptDiff_2Sto1S_cms[nPointsCMS], stat_2Sto1S_cms[nPointsCMS];
	Float_t ptDiff_3Sto1S_cms[nPointsCMS], stat_3Sto1S_cms[nPointsCMS];
	Float_t ptDiff_3Sto2S_cms[nPointsCMS], stat_3Sto2S_cms[nPointsCMS];

	for (Int_t i = 0; i < nPointsCMS; i++) {
		// Y(2S) / Y(1S)
		ptDiff_2Sto1S_cms[i] = ptDiff_2Sto1S_cms13TeV[i] / ptDiff_2Sto1S_cms7TeV[i];

		stat_2Sto1S_cms[i] = ptDiff_2Sto1S_cms[i] * TMath::Hypot(statPerc_2Sto1S_cms13TeV[i], statPerc_2Sto1S_cms7TeV[i]) / 100.;

		// Y(3S) / Y(1S)
		ptDiff_3Sto1S_cms[i] = ptDiff_3Sto1S_cms13TeV[i] / ptDiff_3Sto1S_cms7TeV[i];

		stat_3Sto1S_cms[i] = ptDiff_3Sto1S_cms[i] * TMath::Hypot(statPerc_3Sto1S_cms13TeV[i], statPerc_3Sto1S_cms7TeV[i]) / 100.;

		// Y(3S) / Y(2S)

		ptDiff_3Sto2S_cms[i] = (ptDiff_3S_cms13TeV[i] / ptDiff_2S_cms13TeV[i]) / (ptDiff_3S_cms7TeV[i] / ptDiff_2S_cms7TeV[i]);

		stat_3Sto2S_cms[i] = ptDiff_3Sto2S_cms[i] * TMath::Hypot(TMath::Hypot(statPerc_3S_cms13TeV[i], statPerc_3S_cms7TeV[i]), TMath::Hypot(statPerc_2S_cms13TeV[i], statPerc_2S_cms7TeV[i])) / 100.;
	}

	// Y(3S)-to-Y(2S)

	auto* statGraph_cms3Sto2S = myStatGraph(title, nPointsCMS, ptBinning_cms13TeV, ptDiff_3Sto2S_cms, stat_3Sto2S_cms, color3Sto2S - 1, markerCMS);

	statGraph_cms3Sto2S->Draw("PZ");

	// Y(2S)-to-Y(1S)

	auto* statGraph_cms2Sto1S = myStatGraph(title, nPointsCMS, ptBinning_cms7TeV, ptDiff_2Sto1S_cms, stat_2Sto1S_cms, color2Sto1S + 1, markerCMS);

	statGraph_cms2Sto1S->Draw("PZ");

	// Y(3S)-to-Y(1S)

	auto* statGraph_cms3Sto1S = myStatGraph(title, nPointsCMS, ptBinning_cms13TeV, ptDiff_3Sto1S_cms, stat_3Sto1S_cms, color3Sto1S - 1, markerCMS);

	statGraph_cms3Sto1S->Draw("PZ");

	// legend

	Float_t xUpsi = .2, xCMS = .8, xLHCb = .5;

	Float_t yHeader = .9, y3Sto2S = yHeader - .06, y2Sto1S = y3Sto2S - .06, y3Sto1S = y2Sto1S - .06;

	//drawHeaderLegend("#sqrt{#it{s}} = 7,13 TeV", xUpsi, yHeader);
	drawHeaderLegend("#varUpsilon(3S) / #varUpsilon(2S)", xUpsi, y3Sto2S);
	drawHeaderLegend("#varUpsilon(2S) / #varUpsilon(1S)", xUpsi, y2Sto1S);
	drawHeaderLegend("#varUpsilon(3S) / #varUpsilon(1S)", xUpsi, y3Sto1S);

	drawHeaderLegend("CMS, |#it{y} | < 1.2", xCMS - .1, yHeader);
	drawLegend(statGraph_cms3Sto2S, " ", xCMS, y3Sto2S, "pl");
	drawLegend(statGraph_cms2Sto1S, " ", xCMS, y2Sto1S, "pl");
	drawLegend(statGraph_cms3Sto1S, " ", xCMS, y3Sto1S, "pl");

	drawHeaderLegend("LHCb, 2 < #it{y} < 4.5", xLHCb - .1, yHeader);
	drawLegend(statGraph_lhcb3Sto2S, " ", xLHCb, y3Sto2S, "pl");
	drawLegend(statGraph_lhcb2Sto1S, " ", xLHCb, y2Sto1S, "pl");
	drawLegend(statGraph_lhcb3Sto1S, " ", xLHCb, y3Sto1S, "pl");

	canvas->SaveAs("figures/pt13to7TeV.png", "RECREATE");
	//canvas->Close();
}
