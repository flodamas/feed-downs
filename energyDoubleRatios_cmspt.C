#ifdef __CLING__

#include "myPlot.C"

#include "data/branching.C"

#include "data/upsilonCMS7TeV.C"
#include "data/upsilonCMS13TeV.C"

#endif

Float_t xErrorWidth = .5;

// Is there a significant energy dependence of the pt-differential cross-section ratios?

void energyDoubleRatios_cmspt() {
	auto* canvas = myCanvas("canvas");

	const char* title = ";#it{p}_{T} (GeV);13-to-7 TeV cross-section double ratio";

	/// CMS measurements
	const Int_t nPointsCMS = sizeof(ptBinning_cms7TeV) / sizeof(Float_t) - 1;

	Float_t ptDiff_2Sto1S_cms[nPointsCMS], stat_2Sto1S_cms[nPointsCMS], syst_2Sto1S_cms[nPointsCMS];
	Float_t ptDiff_3Sto1S_cms[nPointsCMS], stat_3Sto1S_cms[nPointsCMS], syst_3Sto1S_cms[nPointsCMS];
	Float_t ptDiff_3Sto2S_cms[nPointsCMS], stat_3Sto2S_cms[nPointsCMS];

	Float_t binning2Sto1S[nPointsCMS + 1], binning3Sto2S[nPointsCMS + 1];

	binning2Sto1S[0] = ptBinning_cms7TeV[0] - .4;
	binning3Sto2S[0] = ptBinning_cms7TeV[0] + .4;

	for (Int_t i = 0; i < nPointsCMS; i++) {
		// Y(2S) / Y(1S)
		binning2Sto1S[i + 1] = ptBinning_cms7TeV[i + 1] - .4;

		ptDiff_2Sto1S_cms[i] = ptDiff_2Sto1S_cms13TeV[i] / ptDiff_2Sto1S_cms7TeV[i];

		stat_2Sto1S_cms[i] = ptDiff_2Sto1S_cms[i] * TMath::Hypot(statPerc_2Sto1S_cms13TeV[i], statPerc_2Sto1S_cms7TeV[i]) / 100.;

		syst_2Sto1S_cms[i] = ptDiff_2Sto1S_cms[i] * TMath::Hypot(systPerc_2Sto1S_cms13TeV[i], systPerc_2Sto1S_cms7TeV[i]) / 100.; // totally uncorrelated?

		// Y(3S) / Y(1S)
		ptDiff_3Sto1S_cms[i] = ptDiff_3Sto1S_cms13TeV[i] / ptDiff_3Sto1S_cms7TeV[i];

		stat_3Sto1S_cms[i] = ptDiff_3Sto1S_cms[i] * TMath::Hypot(statPerc_3Sto1S_cms13TeV[i], statPerc_3Sto1S_cms7TeV[i]) / 100.;

		syst_3Sto1S_cms[i] = ptDiff_3Sto1S_cms[i] * TMath::Hypot(systPerc_3Sto1S_cms13TeV[i], systPerc_3Sto1S_cms7TeV[i]) / 100.; // totally uncorrelated?

		// Y(3S) / Y(2S)
		binning3Sto2S[i + 1] = ptBinning_cms7TeV[i + 1] + .4;

		ptDiff_3Sto2S_cms[i] = (ptDiff_3S_cms13TeV[i] / ptDiff_2S_cms13TeV[i]) / (ptDiff_3S_cms7TeV[i] / ptDiff_2S_cms7TeV[i]);

		stat_3Sto2S_cms[i] = ptDiff_3Sto2S_cms[i] * TMath::Hypot(TMath::Hypot(statPerc_3S_cms13TeV[i], statPerc_3S_cms7TeV[i]), TMath::Hypot(statPerc_2S_cms13TeV[i], statPerc_2S_cms7TeV[i])) / 100.;
	}

	// Y(2S)-to-Y(1S)

	auto* statGraph_cms2Sto1S = myStatGraph(title, nPointsCMS, binning2Sto1S, ptDiff_2Sto1S_cms, stat_2Sto1S_cms, color2Sto1S + 1, markerCMS);

	statGraph_cms2Sto1S->SetMinimum(0.5);
	statGraph_cms2Sto1S->SetMaximum(1.6);

	statGraph_cms2Sto1S->GetXaxis()->SetLimits(20, 100);

	statGraph_cms2Sto1S->Draw("APZ");

	auto* systGraph_cms2Sto1S = mySystGraph(nPointsCMS, binning2Sto1S, xErrorWidth, ptDiff_2Sto1S_cms, syst_2Sto1S_cms, color2Sto1S);

	systGraph_cms2Sto1S->Draw("5");

	// Y(3S)-to-Y(1S)

	auto* statGraph_cms3Sto1S = myStatGraph(title, nPointsCMS, ptBinning_cms13TeV, ptDiff_3Sto1S_cms, stat_3Sto1S_cms, color3Sto1S - 1, markerCMS);

	statGraph_cms3Sto1S->Draw("PZ");

	auto* systGraph_cms3Sto1S = mySystGraph(nPointsCMS, ptBinning_cms13TeV, xErrorWidth, ptDiff_3Sto1S_cms, syst_3Sto1S_cms, color3Sto1S - 1);

	systGraph_cms3Sto1S->Draw("5");

	// Y(3S)-to-Y(2S)

	auto* statGraph_cms3Sto2S = myStatGraph(title, nPointsCMS, binning3Sto2S, ptDiff_3Sto2S_cms, stat_3Sto2S_cms, color3Sto2S - 1, markerCMS);

	statGraph_cms3Sto2S->Draw("PZ");

	// legend

	Float_t xUpsi = .65;

	Float_t yHeader = .9, y3Sto2S = yHeader, y2Sto1S = y3Sto2S - .06, y3Sto1S = y2Sto1S - .06;

	drawHeaderLegend("CMS, |#it{y}| < 1.2", .2, yHeader);
	drawLegend(statGraph_cms3Sto2S, "#varUpsilon(3S) / #varUpsilon(2S)", xUpsi, y3Sto2S, "pl");
	drawLegend(statGraph_cms2Sto1S, "#varUpsilon(2S) / #varUpsilon(1S)", xUpsi, y2Sto1S, "pl");
	drawLegend(statGraph_cms3Sto1S, "#varUpsilon(3S) / #varUpsilon(1S)", xUpsi, y3Sto1S, "pl");

	drawUnityLine(canvas);

	gPad->RedrawAxis();

	canvas->SaveAs("figures/pt13to7TeV_cms.png", "RECREATE");
	//canvas->Close();
}
