#ifdef __CLING__

#include "myPlot.C"

#include "data/branching.C"

#include "data/upsilonLHCb7and8TeV.C"
#include "data/upsilonLHCb13TeV.C"

#endif

Float_t xErrorWidth = .4;

// Is there a significant energy dependence of the pt-differential cross-section ratios?

void energyDoubleRatios_lhcbpt() {
	auto* canvas = myCanvas("canvas");

	const char* title = ";#it{p}_{T} (GeV/#it{c});13-to-8 TeV cross-section double ratio";

	/// Start with LHCb measurements
	const Int_t nPointsLHCb = sizeof(ptBinning_2p0y4p5_lhcb13TeV) / sizeof(Float_t) - 1;

	Float_t ptDiff_2Sto1S_lhcb[nPointsLHCb], stat_2Sto1S_lhcb[nPointsLHCb];
	Float_t ptDiff_3Sto1S_lhcb[nPointsLHCb], stat_3Sto1S_lhcb[nPointsLHCb];
	Float_t ptDiff_3Sto2S_lhcb[nPointsLHCb], stat_3Sto2S_lhcb[nPointsLHCb];

	Float_t binning2Sto1S[nPointsLHCb + 1], binning3Sto2S[nPointsLHCb + 1];

	binning2Sto1S[0] = ptBinning_2p0y4p5_lhcb13TeV[0] - .05;
	binning3Sto2S[0] = ptBinning_2p0y4p5_lhcb13TeV[0] + .05;

	for (Int_t i = 0; i < nPointsLHCb; i++) {
		binning2Sto1S[i + 1] = ptBinning_2p0y4p5_lhcb13TeV[i + 1] - .05;

		ptDiff_2Sto1S_lhcb[i] = ptDiff_2Sto1S_2p0y4p5_lhcb13TeV[i] / ptDiff_2p0y4p5_2Sto1S_lhcb8TeV[i];

		stat_2Sto1S_lhcb[i] = ptDiff_2Sto1S_lhcb[i] * TMath::Hypot(errorPtDiff_2Sto1S_2p0y4p5_lhcb13TeV[i] / ptDiff_2Sto1S_2p0y4p5_lhcb13TeV[i], errorPtDiff_2p0y4p5_2Sto1S_lhcb8TeV[i] / ptDiff_2p0y4p5_2Sto1S_lhcb8TeV[i]);

		ptDiff_3Sto1S_lhcb[i] = ptDiff_3Sto1S_2p0y4p5_lhcb13TeV[i] / ptDiff_2p0y4p5_3Sto1S_lhcb8TeV[i];

		stat_3Sto1S_lhcb[i] = ptDiff_3Sto1S_lhcb[i] * TMath::Hypot(errorPtDiff_3Sto1S_2p0y4p5_lhcb13TeV[i] / ptDiff_3Sto1S_2p0y4p5_lhcb13TeV[i], errorPtDiff_2p0y4p5_3Sto1S_lhcb8TeV[i] / ptDiff_2p0y4p5_3Sto1S_lhcb8TeV[i]);

		// Y(3S) / Y(2S)
		binning3Sto2S[i + 1] = ptBinning_2p0y4p5_lhcb13TeV[i + 1] + .05;

		ptDiff_3Sto2S_lhcb[i] = (ptDiff_2p0y4p5_3S_lhcb13TeV[i] / ptDiff_2p0y4p5_2S_lhcb13TeV[i]) / ptDiff_2p0y4p5_3Sto2S_lhcb8TeV[i];

		stat_3Sto2S_lhcb[i] = ptDiff_3Sto2S_lhcb[i] * TMath::Hypot(errorPtDiff_2p0y4p5_3S_lhcb13TeV[i] / ptDiff_2p0y4p5_3S_lhcb13TeV[i], errorPtDiff_2p0y4p5_3Sto2S_lhcb8TeV[i] / ptDiff_2p0y4p5_3Sto2S_lhcb8TeV[i]);
	}

	// Y(3S)-to-Y(2S)

	auto* statGraph_lhcb3Sto2S = myStatGraph(title, nPointsLHCb, binning3Sto2S, ptDiff_3Sto2S_lhcb, stat_3Sto2S_lhcb, color3Sto2S, markerLHCb);

	statGraph_lhcb3Sto2S->SetMinimum(0.85);
	statGraph_lhcb3Sto2S->SetMaximum(1.3);

	statGraph_lhcb3Sto2S->GetXaxis()->SetLimits(0, 13);

	statGraph_lhcb3Sto2S->Draw("APZ");

	// Y(2S)-to-Y(1S)

	auto* statGraph_lhcb2Sto1S = myStatGraph(title, nPointsLHCb, binning2Sto1S, ptDiff_2Sto1S_lhcb, stat_2Sto1S_lhcb, color2Sto1S, markerLHCb);

	statGraph_lhcb2Sto1S->Draw("PZ");

	// Y(3S)-to-Y(1S)

	auto* statGraph_lhcb3Sto1S = myStatGraph(title, nPointsLHCb, ptBinning_2p0y4p5_lhcb13TeV, ptDiff_3Sto1S_lhcb, stat_3Sto1S_lhcb, color3Sto1S, markerLHCb);

	statGraph_lhcb3Sto1S->Draw("PZ");

	// legend

	Float_t xUpsi = .65;

	Float_t yHeader = .9, y3Sto2S = yHeader, y2Sto1S = y3Sto2S - .06, y3Sto1S = y2Sto1S - .06;

	drawHeaderLegend("LHCb, 2 < #it{y} < 4.5", 0.2, yHeader);
	drawLegend(statGraph_lhcb3Sto2S, "#varUpsilon(3S) / #varUpsilon(2S)", xUpsi, y3Sto2S, "pl");
	drawLegend(statGraph_lhcb2Sto1S, "#varUpsilon(2S) / #varUpsilon(1S)", xUpsi, y2Sto1S, "pl");
	drawLegend(statGraph_lhcb3Sto1S, "#varUpsilon(3S) / #varUpsilon(1S)", xUpsi, y3Sto1S, "pl");

	drawUnityLine(canvas);

	gPad->RedrawAxis();

	canvas->SaveAs("figures/pt13to8TeV_lhcb.png", "RECREATE");
	//canvas->Close();
}
