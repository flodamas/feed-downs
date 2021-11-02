#ifdef __CLING__

#include "myPlot.C"

#include "data/branching.C"
#include "data/upsilonCMS13TeV.C"
#include "data/upsilonLHCb13TeV.C"

#endif

Float_t xErrorWidth = .4;

void ptRatios_13TeV(Bool_t withLogYaxis = kFALSE) {
	auto* canvas = myCanvas("canvas");

	const char* title = ";#it{p}_{T} (GeV/#it{c});BR #times cross-section ratio";

	/// Start with LHCb measurements
	const Int_t nPoints_lhcb = sizeof(ptBinning_2p5y3p0_2Sto1S_lhcb13TeV) / sizeof(Float_t) - 1;

	// Y(2S)-to-Y(1S)

	auto* statGraph_lhcb2Sto1S = myStatGraph(title, nPoints_lhcb, ptBinning_2p5y3p0_2Sto1S_lhcb13TeV, ptDiff_2p5y3p0_2Sto1S_lhcb13TeV, errorPtDiff_2p5y3p0_2Sto1S_lhcb13TeV, color2Sto1S, markerLHCb);

	statGraph_lhcb2Sto1S->SetMaximum(1);

	if (withLogYaxis) {
		canvas->SetLogy();
		statGraph_lhcb2Sto1S->SetMinimum(0.05);
		statGraph_lhcb2Sto1S->SetMaximum(8);
	}

	statGraph_lhcb2Sto1S->GetXaxis()->SetLimits(0, 70);
	statGraph_lhcb2Sto1S->Draw("APZ");

	// Y(3S)-to-Y(1S)

	auto* statGraph_lhcb3Sto1S = myStatGraph(title, nPoints_lhcb, ptBinning_2p5y3p0_3Sto1S_lhcb13TeV, ptDiff_2p5y3p0_3Sto1S_lhcb13TeV, errorPtDiff_2p5y3p0_3Sto1S_lhcb13TeV, color3Sto1S, markerLHCb);

	statGraph_lhcb3Sto1S->Draw("PZ");

	// Y(3S)-to-Y(2S)
	Float_t ptDiff_3Sto2S_lhcb13TeV[nPoints_lhcb], statPtDiff_3Sto2S_lhcb13TeV[nPoints_lhcb], systPtDiff_3Sto2S_lhcb13TeV[nPoints_lhcb];

	for (Int_t i = 0; i < nPoints_lhcb; i++) {
		ptDiff_3Sto2S_lhcb13TeV[i] = ptDiff_2p5y3p0_3S_lhcb13TeV[i] / ptDiff_2p5y3p0_2S_lhcb13TeV[i];

		statPtDiff_3Sto2S_lhcb13TeV[i] = ptDiff_3Sto2S_lhcb13TeV[i] * TMath::Hypot(statPtDiff_2p5y3p0_3S_lhcb13TeV[i] / ptDiff_2p5y3p0_3S_lhcb13TeV[i], statPtDiff_2p5y3p0_2S_lhcb13TeV[i] / ptDiff_2p5y3p0_2S_lhcb13TeV[i]);

		// systematic uncertainties are 100% correlated between states
	}

	auto* statGraph_lhcb3Sto2S = myStatGraph(title, nPoints_lhcb, ptBinning_2p5y3p0_lhcb13TeV, ptDiff_3Sto2S_lhcb13TeV, statPtDiff_3Sto2S_lhcb13TeV, color3Sto2S, markerLHCb);

	//statGraph_lhcb3Sto2S->Draw("PZ");

	/// CMS measurements
	const Int_t nPoints_cms = sizeof(ptBinning_cms13TeV) / sizeof(Float_t) - 1;

	// from relative to absolute uncertainties and compute Y(3S) / Y(2S)
	Float_t stat_2Sto1S_cms13TeV[nPoints_cms], stat_3Sto1S_cms13TeV[nPoints_cms], syst_2Sto1S_cms13TeV[nPoints_cms], syst_3Sto1S_cms13TeV[nPoints_cms];

	Float_t ptDiff_3Sto2S_cms13TeV[nPoints_cms], stat_3Sto2S_cms13TeV[nPoints_cms], syst_3Sto2S_cms13TeV[nPoints_cms];

	for (Int_t i = 0; i < nPoints_cms; i++) {
		stat_2Sto1S_cms13TeV[i] = ptDiff_2Sto1S_cms13TeV[i] * statPerc_2Sto1S_cms13TeV[i] / 100.;
		syst_2Sto1S_cms13TeV[i] = ptDiff_2Sto1S_cms13TeV[i] * systPerc_2Sto1S_cms13TeV[i] / 100.;

		stat_3Sto1S_cms13TeV[i] = ptDiff_3Sto1S_cms13TeV[i] * statPerc_3Sto1S_cms13TeV[i] / 100.;
		syst_3Sto1S_cms13TeV[i] = ptDiff_3Sto1S_cms13TeV[i] * systPerc_3Sto1S_cms13TeV[i] / 100.;

		// Y(3S) / Y(2S)
		ptDiff_3Sto2S_cms13TeV[i] = ptDiff_3S_cms13TeV[i] / ptDiff_2S_cms13TeV[i];

		stat_3Sto2S_cms13TeV[i] = ptDiff_3Sto2S_cms13TeV[i] * TMath::Hypot(statPerc_3S_cms13TeV[i], statPerc_2S_cms13TeV[i]) / 100.;

		syst_3Sto2S_cms13TeV[i] = ptDiff_3Sto2S_cms13TeV[i] * systPerc_3S_cms13TeV[i] / 100.; // should be good
	}

	// Y(2S)-to-Y(1S)

	auto* statGraph_cms2Sto1S = myStatGraph(title, nPoints_cms, ptBinning_cms13TeV, ptDiff_2Sto1S_cms13TeV, stat_2Sto1S_cms13TeV, color2Sto1S + 1, markerCMS);

	statGraph_cms2Sto1S->Draw("PZ");

	auto* systGraph_cms2Sto1S = mySystGraph(nPoints_cms, ptBinning_cms13TeV, xErrorWidth, ptDiff_2Sto1S_cms13TeV, syst_2Sto1S_cms13TeV, color2Sto1S + 1);

	systGraph_cms2Sto1S->Draw("5");

	// Y(3S)-to-Y(1S)

	auto* statGraph_cms3Sto1S = myStatGraph(title, nPoints_cms, ptBinning_cms13TeV, ptDiff_3Sto1S_cms13TeV, stat_3Sto1S_cms13TeV, color3Sto1S - 1, markerCMS);

	statGraph_cms3Sto1S->Draw("PZ");

	auto* systGraph_cms3Sto1S = mySystGraph(nPoints_cms, ptBinning_cms13TeV, xErrorWidth, ptDiff_3Sto1S_cms13TeV, syst_3Sto1S_cms13TeV, color3Sto1S - 1);

	systGraph_cms3Sto1S->Draw("5");

	// Y(3S)-to-Y(2S)

	auto* statGraph_cms3Sto2S = myStatGraph(title, nPoints_cms, ptBinning_cms13TeV, ptDiff_3Sto2S_cms13TeV, stat_3Sto2S_cms13TeV, color3Sto2S - 1, markerCMS);

	//statGraph_cms3Sto2S->Draw("PZ");

	auto* systGraph_cms3Sto2S = mySystGraph(nPoints_cms, ptBinning_cms13TeV, xErrorWidth, ptDiff_3Sto2S_cms13TeV, syst_3Sto2S_cms13TeV, color3Sto2S - 1);

	//systGraph_cms3Sto2S->Draw("5");

	// legend

	Float_t xUpsi = .2, xCMS = .8, xLHCb = .5;

	Float_t yHeader = .9, y3Sto2S = yHeader /*- .06*/, y2Sto1S = y3Sto2S - .06, y3Sto1S = y2Sto1S - .06;

	drawHeaderLegend("#sqrt{#it{s}} = 13 TeV", xUpsi, yHeader);
	//drawHeaderLegend("#varUpsilon(3S) / #varUpsilon(2S)", xUpsi, y3Sto2S);
	drawHeaderLegend("#varUpsilon(2S) / #varUpsilon(1S)", xUpsi, y2Sto1S);
	drawHeaderLegend("#varUpsilon(3S) / #varUpsilon(1S)", xUpsi, y3Sto1S);

	drawHeaderLegend("CMS, |#it{y} | < 1.2", xCMS - .1, yHeader);
	//drawLegend(statGraph_cms3Sto2S, " ", xCMS, y3Sto2S, "pl");
	drawLegend(statGraph_cms2Sto1S, " ", xCMS, y2Sto1S, "pl");
	drawLegend(statGraph_cms3Sto1S, " ", xCMS, y3Sto1S, "pl");

	drawHeaderLegend("LHCb, 2.5 < #it{y} < 3", xLHCb - .1, yHeader);
	//drawLegend(statGraph_lhcb3Sto2S, " ", xLHCb, y3Sto2S, "pl");
	drawLegend(statGraph_lhcb2Sto1S, " ", xLHCb, y2Sto1S, "pl");
	drawLegend(statGraph_lhcb3Sto1S, " ", xLHCb, y3Sto1S, "pl");

	canvas->SaveAs("figures/pt13TeV_CMS_LHCb.png", "RECREATE");
	//canvas->Close();
}
