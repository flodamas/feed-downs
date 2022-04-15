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

void feeddowns_upsilon1S(Bool_t withLegend = kFALSE, Bool_t withLogYaxis = kFALSE) {
	string color = "\033[1;31m";

	// Feed-downs to Y(1S)
	auto* canv = Canvas("canv");

	if (withLogYaxis) canv->SetLogy();

	const char* title = ";#it{p}_{T}^{#varUpsilon(1S)} (GeV);#varUpsilon(1S) feed-down fractions (in %)";

	// Chi_b(1P) first

	auto* stat1Pto1S = StatGraph(title, nPoints1Pto1S_lhcb, ptBinning1Pto1S_lhcb, frac1Pto1S_weightedLHCb, stat1Pto1S_weightedLHCb, color1P, marker2P);

	auto* syst1Pto1S = SystGraph(nPoints1Pto1S_lhcb, ptBinning1Pto1S_lhcb, xErrorWidth, frac1Pto1S_weightedLHCb, syst1Pto1S_weightedLHCb, color1P - 1);

	stat1Pto1S->SetMaximum((withLegend) ? 40 : 35);
	stat1Pto1S->GetXaxis()->SetLimits(0, 50);

	if (withLogYaxis) {
		stat1Pto1S->SetMinimum(.4);
		stat1Pto1S->SetMaximum(1000);
	}

	stat1Pto1S->Draw("APZ");
	syst1Pto1S->Draw("5");

	// Chi_b(2P)

	auto* stat2Pto1S = StatGraph(title, nPoints2Pto1S_lhcb, ptBinning2Pto1S_lhcb, frac2Pto1S_weightedLHCb, stat2Pto1S_weightedLHCb, color2P, marker2P);

	auto* syst2Pto1S = SystGraph(nPoints2Pto1S_lhcb, ptBinning2Pto1S_lhcb, xErrorWidth, frac2Pto1S_weightedLHCb, syst2Pto1S_weightedLHCb, color2P);

	stat2Pto1S->Draw("PZ");
	syst2Pto1S->Draw("5");

	// Chi_b(3P)

	auto* stat3Pto1S = StatGraph(title, nPoints3Pto1S_lhcb, ptBinning3Pto1S_lhcb, frac3Pto1S_weightedLHCb, stat3Pto1S_weightedLHCb, color3P, marker2P);

	auto* syst3Pto1S = SystGraph(nPoints3Pto1S_lhcb, ptBinning3Pto1S_lhcb, xErrorWidth, frac3Pto1S_weightedLHCb, syst3Pto1S_weightedLHCb, color3P);

	stat3Pto1S->Draw("PZ");
	syst3Pto1S->Draw("5");

	/// LHCb measurements

	const Int_t nPoints2Sto1S_lhcb = sizeof(ptDiff_2p0y4p5_2Sto1S_lhcb8TeV) / sizeof(float) - 3;

	Float_t frac2Sto1S_lhcb[nPoints2Sto1S_lhcb], error2Sto1S_lhcb[nPoints2Sto1S_lhcb];
	Float_t frac3Sto1S_lhcb[nPoints2Sto1S_lhcb], error3Sto1S_lhcb[nPoints2Sto1S_lhcb];

	for (Int_t i = 0; i < nPoints2Sto1S_lhcb; i++) {
		frac2Sto1S_lhcb[i] = ptDiff_2p0y4p5_2Sto1S_lhcb8TeV[i] * (br1Stomumu / br2Stomumu) * br2Sto1Sanything;
		error2Sto1S_lhcb[i] = errorPtDiff_2p0y4p5_2Sto1S_lhcb8TeV[i] * (br1Stomumu / br2Stomumu) * br2Sto1Sanything;

		frac3Sto1S_lhcb[i] = ptDiff_2p0y4p5_3Sto1S_lhcb8TeV[i] * (br1Stomumu / br3Stomumu) * br3Sto1Sanything;
		error3Sto1S_lhcb[i] = errorPtDiff_2p0y4p5_3Sto1S_lhcb8TeV[i] * (br1Stomumu / br3Stomumu) * br3Sto1Sanything;
	}

	auto* stat2Sto1Sgraph_lhcb = StatGraph(title, nPoints2Sto1S_lhcb, ptBinning_2p0y4p5_lhcb7and8TeV, frac2Sto1S_lhcb, error2Sto1S_lhcb, color2Sover1S, markerLHCb);

	stat2Sto1Sgraph_lhcb->Draw("PZ");

	auto* stat3Sto1Sgraph_lhcb = StatGraph(title, nPoints2Sto1S_lhcb, ptBinning_2p0y4p5_lhcb7and8TeV, frac3Sto1S_lhcb, error3Sto1S_lhcb, color3Sover1S, markerLHCb);

	stat3Sto1Sgraph_lhcb->Draw("PZ");

	/// CMS measurements
	const Int_t nPoints2Sto1S_cms = sizeof(ptBinning_cms7TeV) / sizeof(Float_t) - 1;

	// from relative to absolute uncertainties
	Float_t frac2Sto1S_cms[nPoints2Sto1S_cms], stat2Sto1S_cms[nPoints2Sto1S_cms], syst2Sto1S_cms[nPoints2Sto1S_cms];
	Float_t frac3Sto1S_cms[nPoints2Sto1S_cms], stat3Sto1S_cms[nPoints2Sto1S_cms], syst3Sto1S_cms[nPoints2Sto1S_cms];

	for (Int_t i = 0; i < nPoints2Sto1S_cms; i++) {
		frac2Sto1S_cms[i] = ptDiff_2Sto1S_cms7TeV[i] * (br1Stomumu / br2Stomumu) * br2Sto1Sanything;

		stat2Sto1S_cms[i] = frac2Sto1S_cms[i] * statPerc_2Sto1S_cms7TeV[i] / 100.;

		syst2Sto1S_cms[i] = frac2Sto1S_cms[i] * systPerc_2Sto1S_cms7TeV[i] / 100.;

		frac3Sto1S_cms[i] = ptDiff_3Sto1S_cms7TeV[i] * (br1Stomumu / br3Stomumu) * br3Sto1Sanything;

		stat3Sto1S_cms[i] = frac3Sto1S_cms[i] * statPerc_3Sto1S_cms7TeV[i] / 100.;

		syst3Sto1S_cms[i] = frac3Sto1S_cms[i] * systPerc_3Sto1S_cms7TeV[i] / 100.;
	}

	// Y(2S)-to-Y(1S)

	auto* statGraph_cms2Sto1S = StatGraph(title, nPoints2Sto1S_cms, ptBinning_cms7TeV, frac2Sto1S_cms, stat2Sto1S_cms, color2Sover1S + 1, markerCMS);

	statGraph_cms2Sto1S->Draw("PZ");

	auto* systGraph_cms2Sto1S = SystGraph(nPoints2Sto1S_cms, ptBinning_cms7TeV, xErrorWidth, frac2Sto1S_cms, syst2Sto1S_cms, color2Sover1S + 1);

	systGraph_cms2Sto1S->Draw("5");

	// Y(3S)-to-Y(1S)

	auto* statGraph_cms3Sto1S = StatGraph(title, nPoints2Sto1S_cms, ptBinning_cms7TeV, frac3Sto1S_cms, stat3Sto1S_cms, color3Sover1S - 1, markerCMS);

	statGraph_cms3Sto1S->Draw("PZ");

	auto* systGraph_cms3Sto1S = SystGraph(nPoints2Sto1S_cms, ptBinning_cms7TeV, xErrorWidth, frac3Sto1S_cms, syst3Sto1S_cms, color3Sover1S - 1);

	systGraph_cms3Sto1S->Draw("5");

	/// legend

	if (!withLegend) drawHeaderLegend("7 and 8 TeV pp data", .18, .9);

	auto* legend = new TLegend(.17, .92, .35, .55, "pp 7 and 8 TeV data, #varUpsilon(1S) from");
	legend->AddEntry(stat1Pto1S, "#chi_{b}(1P)", "p");
	legend->AddEntry(stat2Sto1Sgraph_lhcb, "#varUpsilon(2S)", "p");
	legend->AddEntry(stat2Pto1S, "#chi_{b}(2P)", "p");
	legend->AddEntry(stat3Sto1Sgraph_lhcb, "#varUpsilon(3S)", "p");
	legend->AddEntry(stat3Pto1S, "#chi_{b}(3P)", "p");
	if (withLegend) legend->Draw();

	saveCanvas(canv, "feeddownsToUpsilon1S_8TeV");

	/// print the results, in the order of importance

	// Chi_b(1P) first

	cout << color << endl
	     << "X_b(1P) -> Y(1S)"
	     << "\033[0m" << endl;

	for (Int_t i = 0; i < nPoints1Pto1S_lhcb; i++)
		cout << ptBinning1Pto1S_lhcb[i] << " < pT < " << ptBinning1Pto1S_lhcb[i + 1] << " : " << frac1Pto1S_lhcb8TeV[i] << " +/- " << stat1Pto1S_lhcb8TeV[i] << " +/- " << syst1Pto1S_lhcb8TeV[i] << endl;

	// Y(2S)

	cout << color << endl
	     << "Y(2S) -> Y(1S)"
	     << "\033[0m" << endl;

	cout << "LHCb" << endl;
	for (Int_t i = 0; i < nPoints2Sto1S_lhcb; i++)
		cout << ptBinning_2p0y4p5_lhcb7and8TeV[i] << " < pT < " << ptBinning_2p0y4p5_lhcb7and8TeV[i + 1] << " : " << frac2Sto1S_lhcb[i] << " +/- " << error2Sto1S_lhcb[i] << endl;

	cout << endl
	     << "CMS" << endl;
	for (Int_t i = 0; i < nPoints2Sto1S_cms; i++)
		cout << ptBinning_cms7TeV[i] << " < pT < " << ptBinning_cms7TeV[i + 1] << " : " << frac2Sto1S_cms[i] << " +/- " << stat2Sto1S_cms[i] << " +/- " << syst2Sto1S_cms[i] << endl;

	// Chi_b(2P)

	cout << color << endl
	     << "X_b(2P) -> Y(1S)"
	     << "\033[0m" << endl;

	for (Int_t i = 0; i < nPoints2Pto1S_lhcb; i++)
		cout << ptBinning2Pto1S_lhcb[i] << " < pT < " << ptBinning2Pto1S_lhcb[i + 1] << " : " << frac2Pto1S_lhcb8TeV[i] << " +/- " << stat2Pto1S_lhcb8TeV[i] << " +/- " << syst2Pto1S_lhcb8TeV[i] << endl;

	// Y(3S)

	cout << color << endl
	     << "Y(3S) -> Y(1S)"
	     << "\033[0m" << endl;

	cout << "LHCb" << endl;
	for (Int_t i = 0; i < nPoints2Sto1S_lhcb; i++)
		cout << ptBinning_2p0y4p5_lhcb7and8TeV[i] << " < pT < " << ptBinning_2p0y4p5_lhcb7and8TeV[i + 1] << " : " << frac3Sto1S_lhcb[i] << " +/- " << error3Sto1S_lhcb[i] << endl;

	cout << endl
	     << "CMS" << endl;
	for (Int_t i = 0; i < nPoints2Sto1S_cms; i++)
		cout << ptBinning_cms7TeV[i] << " < pT < " << ptBinning_cms7TeV[i + 1] << " : " << frac3Sto1S_cms[i] << " +/- " << stat3Sto1S_cms[i] << " +/- " << syst3Sto1S_cms[i] << endl;

	// Chi_b(3P)

	cout << color << endl
	     << "X_b(3P) -> Y(1S)"
	     << "\033[0m" << endl;

	for (Int_t i = 0; i < nPoints3Pto1S_lhcb; i++)
		cout << ptBinning3Pto1S_lhcb[i] << " < pT < " << ptBinning3Pto1S_lhcb[i + 1] << " : " << frac3Pto1S_lhcb8TeV[i] << " +/- " << stat3Pto1S_lhcb8TeV[i] << " +/- " << downSyst3Pto1S_lhcb8TeV[i] << endl;
}
