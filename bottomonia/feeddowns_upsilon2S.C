#ifdef __CLING__

#include "../tools/Cosmetics.h"
#include "../tools/Graph.h"

#include "data/BranchingRatios.h"

#include "data/feedLHCb7and8TeV.C"
#include "data/upsilonLHCb7and8TeV.C"
#include "data/upsilonCMS7TeV.C"
#include "data/upsilonCMS13TeV.C"

#endif

Float_t xErrorWidth = .4;

void feeddowns_upsilon2S(Bool_t withLegend = kFALSE, Bool_t withLogYaxis = kFALSE) {
	// Feed-downs to Y(2S)
	auto* canv = Canvas("canv");

	if (withLogYaxis) canv->SetLogy();

	const char* title = ";#it{p}_{T}^{#varUpsilon(2S)} (GeV);#varUpsilon(2S) feed-down fractions (in %)";

	/// Chi_b first
	auto* stat2Pto2S = StatGraph(title, nPoints2Pto2S_lhcb, ptBinning2Pto2S_lhcb, frac2Pto2S_weightedLHCb, stat2Pto2S_weightedLHCb, color2P, marker2P);

	auto* syst2Pto2S = SystGraph(nPoints2Pto2S_lhcb, ptBinning2Pto2S_lhcb, xErrorWidth, frac2Pto2S_weightedLHCb, syst2Pto2S_weightedLHCb, color2P);

	stat2Pto2S->SetMaximum((withLegend) ? 50 : 45);
	stat2Pto2S->GetXaxis()->SetLimits(0, 50);

	if (withLogYaxis) {
		stat2Pto2S->SetMinimum(.4);
		stat2Pto2S->SetMaximum(1000);
	}

	stat2Pto2S->Draw("APZ");
	syst2Pto2S->Draw("5");

	auto* stat3Pto2S = StatGraph(title, nPoints3Pto2S_lhcb, ptBinning3Pto2S_lhcb, frac3Pto2S_weightedLHCb, stat3Pto2S_weightedLHCb, color3P, marker2P);

	auto* syst3Pto2S = SystGraph(nPoints3Pto2S_lhcb, ptBinning3Pto2S_lhcb, xErrorWidth, frac3Pto2S_weightedLHCb, syst3Pto2S_weightedLHCb, color3P);

	stat3Pto2S->Draw("PZ");
	syst3Pto2S->Draw("5");

	/// Y(3S) -> Y(2S)
	Float_t brCorrection_3Sto2S = (br2Stomumu / br3Stomumu) * br3Sto2Sanything;

	/// LHCb measurements

	const Int_t nPoints_lhcb = sizeof(ptDiff_2p0y4p5_2Sto1S_lhcb8TeV) / sizeof(float) - 3;

	Float_t frac3Sto2S_lhcb[nPoints_lhcb], error3Sto2S_lhcb[nPoints_lhcb];

	for (Int_t i = 0; i < nPoints_lhcb; i++) {
		frac3Sto2S_lhcb[i] = ptDiff_2p0y4p5_3Sto2S_lhcb8TeV[i] * brCorrection_3Sto2S;
		error3Sto2S_lhcb[i] = errorPtDiff_2p0y4p5_3Sto2S_lhcb8TeV[i] * brCorrection_3Sto2S;
	}

	auto* stat3Sto2Sgraph_lhcb = StatGraph(title, nPoints_lhcb, ptBinning_2p0y4p5_lhcb7and8TeV, frac3Sto2S_lhcb, error3Sto2S_lhcb, color3Sto2S, markerLHCb);

	stat3Sto2Sgraph_lhcb->Draw("PZ");

	/// CMS measurements
	const Int_t nPoints_cms = sizeof(ptBinning_cms7TeV) / sizeof(Float_t) - 1;

	// from relative to absolute uncertainties
	Float_t frac3Sto2S_cms[nPoints_cms], stat3Sto2S_cms[nPoints_cms], syst3Sto2S_cms[nPoints_cms];

	for (Int_t i = 0; i < nPoints_cms; i++) {
		frac3Sto2S_cms[i] = (ptDiff_3S_cms7TeV[i] / ptDiff_2S_cms7TeV[i]) * brCorrection_3Sto2S;

		stat3Sto2S_cms[i] = frac3Sto2S_cms[i] * TMath::Hypot(statPerc_3S_cms7TeV[i], statPerc_2S_cms7TeV[i]) / 100.;

		syst3Sto2S_cms[i] = frac3Sto2S_cms[i] * systPerc_3Sto1S_cms7TeV[i] / 100.; // should be good
	}

	auto* statGraph_cms3Sto2S = StatGraph(title, nPoints_cms, ptBinning_cms7TeV, frac3Sto2S_cms, stat3Sto2S_cms, color3Sto2S + 1, markerCMS);

	statGraph_cms3Sto2S->Draw("PZ");

	auto* systGraph_cms3Sto2S = SystGraph(nPoints_cms, ptBinning_cms7TeV, xErrorWidth, frac3Sto2S_cms, syst3Sto2S_cms, color3Sto2S + 1);

	systGraph_cms3Sto2S->Draw("5");

	/// legend
	if (!withLegend) drawHeaderLegend("7 and 8 TeV pp data", .18, .9);

	auto* legend = new TLegend(.17, .92, .35, .65, "7 and 8 TeV data, #varUpsilon(2S) from");
	legend->AddEntry(stat2Pto2S, "#chi_{b}(2P)", "p");
	legend->AddEntry(stat3Sto2Sgraph_lhcb, "#varUpsilon(3S)", "p");
	legend->AddEntry(stat3Pto2S, "#chi_{b}(3P)", "p");
	if (withLegend) legend->Draw();

	saveCanvas(canv, "feeddownsToUpsilon2S_8TeV");
}
