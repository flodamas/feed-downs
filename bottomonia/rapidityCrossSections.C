#ifdef __CLING__

#include "../tools/Graph.h"

#include "data/upsilonCMS7TeV.C"
#include "data/upsilonLHCb7and8TeV.C"
#include "data/upsilonLHCb13TeV.C"

#include "data/BranchingRatios.h"

#endif

// Upsilon production cross sections as a function of rapidity, in nb

void rapidityCrossSections() {
	auto* canvas = Canvas("canvas");
	canvas->SetLogy();

	const char* title = ";y;d#sigma / dy [nb]";

	/// forward rapidity LHCb measurements
	const Int_t nPoints_lhcb = sizeof(rapidityBinning_lhcb13TeV) / sizeof(Float_t) - 1;

	Float_t cross1S_lhcb[nPoints_lhcb], error1S_lhcb[nPoints_lhcb], cross2S_lhcb[nPoints_lhcb], error2S_lhcb[nPoints_lhcb], cross3S_lhcb[nPoints_lhcb], error3S_lhcb[nPoints_lhcb];

	for (Int_t i = 0; i < nPoints_lhcb; i++) {
		cross1S_lhcb[i] = rapidityDiff_1S_lhcb13TeV[i] / (1000 * br1Stomumu / 100.);

		error1S_lhcb[i] = errorRapidityDiff_1S_lhcb13TeV[i] / (1000 * br1Stomumu / 100.);

		cross2S_lhcb[i] = rapidityDiff_2S_lhcb13TeV[i] / (1000 * br2Stomumu / 100.);

		error2S_lhcb[i] = errorRapidityDiff_2S_lhcb13TeV[i] / (1000 * br2Stomumu / 100.);

		cross3S_lhcb[i] = rapidityDiff_3S_lhcb13TeV[i] / (1000 * br3Stomumu / 100.);

		error3S_lhcb[i] = errorRapidityDiff_3S_lhcb13TeV[i] / (1000 * br3Stomumu / 100.);
	}

	// Y(1S)

	auto* statGraph1S_lhcb = StatGraph(title, nPoints_lhcb, rapidityBinning_lhcb13TeV, cross1S_lhcb, error1S_lhcb, color1S, markerLHCb);

	// Y(2S)

	auto* statGraph2S_lhcb = StatGraph(title, nPoints_lhcb, rapidityBinning_lhcb13TeV, cross2S_lhcb, error2S_lhcb, color2S, markerLHCb);

	// Y(3S)

	auto* statGraph3S_lhcb = StatGraph(title, nPoints_lhcb, rapidityBinning_lhcb13TeV, cross3S_lhcb, error3S_lhcb, color3S, markerLHCb);

	/// draw

	statGraph1S_lhcb->GetXaxis()->SetLimits(2, 5);
	statGraph1S_lhcb->SetMinimum(3);
	statGraph1S_lhcb->SetMaximum(1.01e3);
	statGraph1S_lhcb->Draw("APZ");
	statGraph2S_lhcb->Draw("PZ");
	statGraph3S_lhcb->Draw("PZ");

	// legend

	Float_t xHeader = .2, xUpsi = .7;

	Float_t yHeader = .9, yUpsi1S = yHeader - .07, yUpsi2S = yUpsi1S - .06, yUpsi3S = yUpsi2S - .06;

	drawHeaderLegend("LHCb #sqrt{#it{s}} = 13 TeV, L_{int} = 277 pb^{#minus 1}", xHeader, yHeader);
	drawHeaderLegend("p_{T} < 15 GeV", xHeader, yUpsi1S);

	drawLegend(statGraph1S_lhcb, "#varUpsilon(1S)", xUpsi, yUpsi1S, "pl");
	drawLegend(statGraph2S_lhcb, "#varUpsilon(2S)", xUpsi, yUpsi2S, "pl");
	drawLegend(statGraph3S_lhcb, "#varUpsilon(3S)", xUpsi, yUpsi3S, "pl");

	saveAs(canvas, "cross-sections_rapidity_LHCb");
}
