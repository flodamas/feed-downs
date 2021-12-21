#ifdef __CLING__

#include "myPlot.C"

#include "data/branching.C"
#include "data/feedLHCb7and8TeV.C"
#include "data/upsilonLHCb7and8TeV.C"
#include "data/upsilonCMS7TeV.C"
#include "data/upsilonCMS13TeV.C"

#endif

Float_t xErrorWidth = .4;

const Color_t color2P = kAzure + 1;
const Color_t color3P = kGreen + 2;

const Color_t color3Sto2S_ = kPink + 6;

const Int_t marker2P = 21;
const Int_t marker3P = 22;

void feeddownsTo2S(Bool_t withLegend = kTRUE, Bool_t withLogYaxis = kFALSE) {
	// Feed-downs to Y(2S)
	auto* canv2S = myCanvas("canv2S");

	if (withLogYaxis) canv2S->SetLogy();

	const char* title2S =
	  ";#it{p}_{T}^{#varUpsilon(2S)} (GeV);Feed-down fractions to #varUpsilon(2S) (in %)";

	/// Chi_b first
	auto* stat2Pto2S =
	  myStatGraph(title2S, nPoints2Pto2S_lhcb, ptBinning2Pto2S_lhcb, frac2Pto2S_lhcb8TeV, stat2Pto2S_lhcb8TeV, color2P, marker2P);

	auto* syst2Pto2S =
	  mySystGraph(nPoints2Pto2S_lhcb, ptBinning2Pto2S_lhcb, xErrorWidth, frac2Pto2S_lhcb8TeV, syst2Pto2S_lhcb8TeV, color2P);

	stat2Pto2S->SetMinimum(0);
	stat2Pto2S->SetMaximum((withLegend) ? 50 : 45);
	stat2Pto2S->GetXaxis()->SetLimits(0, 50);

	if (withLogYaxis) {
		stat2Pto2S->SetMinimum(.4);
		stat2Pto2S->SetMaximum(1000);
	}

	stat2Pto2S->Draw("APZ");
	syst2Pto2S->Draw("5");

	auto* stat3Pto2S =
	  myStatGraph(title2S, nPoints3Pto2S_lhcb, ptBinning3Pto2S_lhcb, frac3Pto2S_lhcb8TeV, stat3Pto2S_lhcb8TeV, color3P, marker2P);

	auto* syst3Pto2S =
	  mySystGraph(nPoints3Pto2S_lhcb, ptBinning3Pto2S_lhcb, xErrorWidth, frac3Pto2S_lhcb8TeV, syst3Pto2S_lhcb8TeV, color3P);

	stat3Pto2S->Draw("PZ");
	syst3Pto2S->Draw("5");

	/// LHCb measurements

	const Int_t nPoints_lhcb = sizeof(ptDiff_2p0y4p5_2Sto1S_lhcb8TeV) / sizeof(float);

	Float_t frac3Sto2S_lhcb[nPoints_lhcb], error3Sto2S_lhcb[nPoints_lhcb];

	for (Int_t i = 0; i < nPoints_lhcb; i++) {
		frac3Sto2S_lhcb[i] = ptDiff_2p0y4p5_3Sto2S_lhcb8TeV[i] * (br2Stomumu / br3Stomumu) * br3Sto2Sanything;
		error3Sto2S_lhcb[i] = errorPtDiff_2p0y4p5_3Sto2S_lhcb8TeV[i] * (br2Stomumu / br3Stomumu) * br3Sto2Sanything;
	}

	auto* stat3Sto2Sgraph_lhcb = myStatGraph(title2S, nPoints_lhcb, ptBinning_2p0y4p5_lhcb7and8TeV, frac3Sto2S_lhcb, error3Sto2S_lhcb, color3Sto2S_, markerLHCb);

	stat3Sto2Sgraph_lhcb->Draw("PZ");

	/// CMS measurements
	const Int_t nPoints_cms = sizeof(ptBinning_cms13TeV) / sizeof(Float_t) - 1;

	// from relative to absolute uncertainties
	Float_t frac3Sto2S_cms[nPoints_cms], stat3Sto2S_cms[nPoints_cms], syst3Sto2S_cms[nPoints_cms];

	for (Int_t i = 0; i < nPoints_cms; i++) {
		frac3Sto2S_cms[i] = (ptDiff_3S_cms13TeV[i] / ptDiff_2S_cms13TeV[i]) * (br2Stomumu / br3Stomumu) * br3Sto2Sanything;

		stat3Sto2S_cms[i] = frac3Sto2S_cms[i] * TMath::Hypot(statPerc_3S_cms13TeV[i], statPerc_2S_cms13TeV[i]) / 100.;

		syst3Sto2S_cms[i] = frac3Sto2S_cms[i] * systPerc_3S_cms13TeV[i] / 100.; // should be good
	}

	auto* statGraph_cms3Sto2S = myStatGraph(title2S, nPoints_cms, ptBinning_cms13TeV, frac3Sto2S_cms, stat3Sto2S_cms, color3Sto2S_ + 1, markerCMS);

	statGraph_cms3Sto2S->Draw("PZ");

	auto* systGraph_cms3Sto2S = mySystGraph(nPoints_cms, ptBinning_cms13TeV, xErrorWidth, frac3Sto2S_cms, syst3Sto2S_cms, color3Sto2S_ + 1);

	systGraph_cms3Sto2S->Draw("5");

	/// legend

	auto* legend = new TLegend(.17, .92, .35, .65, "pp 7 and 8 TeV data, #varUpsilon(2S) from");
	legend->AddEntry(stat2Pto2S, "#chi_{b}(2P)", "p");
	legend->AddEntry(stat3Sto2Sgraph_lhcb, "#varUpsilon(3S)", "p");
	legend->AddEntry(stat3Pto2S, "#chi_{b}(3P)", "p");
	if (withLegend) legend->Draw();

	canv2S->SaveAs("figures/feeddowns_to_2S_8TeV.png", "RECREATE");
	canv2S->Close();
}
