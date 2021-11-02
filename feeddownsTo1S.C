#ifdef __CLING__

#include "myPlot.C"

#include "data/branching.C"
#include "data/feedLHCb7and8TeV.C"
#include "data/upsilonLHCb7and8TeV.C"
#include "data/upsilonCMS13TeV.C"

#endif

Float_t xErrorWidth = .4;

const Color_t color1P = kRed;
const Color_t color2P = kAzure + 1;
const Color_t color3P = kGreen + 2;

const Int_t marker1P = 20;
const Int_t marker2P = 21;
const Int_t marker3P = 22;

void feeddownsTo1S(Bool_t withLogYaxis = kFALSE) {
	// Feed-downs to Y(1S)
	auto* canv1S = myCanvas("canv1S");

	if (withLogYaxis) canv1S->SetLogy();

	const char* title1S =
	  ";#it{p}_{T}^{#varUpsilon(1S)} (GeV/#it{c});Feed-down fractions to #varUpsilon(1S) (in %)";

	/// Chi_b first
	auto* stat1Pto1S =
	  myStatGraph(title1S, nPoints1Pto1S_lhcb, ptBinning1Pto1S_lhcb, frac1Pto1S_lhcb8TeV, stat1Pto1S_lhcb8TeV, color1P, marker2P);

	auto* syst1Pto1S =
	  mySystGraph(nPoints1Pto1S_lhcb, ptBinning1Pto1S_lhcb, xErrorWidth, frac1Pto1S_lhcb8TeV, syst1Pto1S_lhcb8TeV, color1P);

	stat1Pto1S->SetMinimum(0);
	stat1Pto1S->SetMaximum(35);
	stat1Pto1S->GetXaxis()->SetLimits(0, 40);

	if (withLogYaxis) {
		stat1Pto1S->SetMinimum(.4);
		stat1Pto1S->SetMaximum(1000);
	}

	stat1Pto1S->Draw("APZ");
	syst1Pto1S->Draw("5");

	auto* stat2Pto1S =
	  myStatGraph(title1S, nPoints2Pto1S_lhcb, ptBinning2Pto1S_lhcb, frac2Pto1S_lhcb8TeV, stat2Pto1S_lhcb8TeV, color2P, marker2P);

	auto* syst2Pto1S =
	  mySystGraph(nPoints2Pto1S_lhcb, ptBinning2Pto1S_lhcb, xErrorWidth, frac2Pto1S_lhcb8TeV, syst2Pto1S_lhcb8TeV, color2P);

	stat2Pto1S->Draw("PZ");
	syst2Pto1S->Draw("5");

	auto* stat3Pto1S =
	  myStatGraph(title1S, nPoints3Pto1S_lhcb, ptBinning3Pto1S_lhcb, frac3Pto1S_lhcb8TeV, stat3Pto1S_lhcb8TeV, color3P, marker2P);

	auto* syst3Pto1S =
	  mySystGraph(nPoints3Pto1S_lhcb, ptBinning3Pto1S_lhcb, xErrorWidth, frac3Pto1S_lhcb8TeV, syst3Pto1S_lhcb8TeV, color3P);

	stat3Pto1S->Draw("PZ");
	syst3Pto1S->Draw("5");

	/// LHCb measurements

	const Int_t nPoints2Sto1S_lhcb = sizeof(ptDiff_2p0y4p5_2Sto1S_lhcb8TeV) / sizeof(float) - 1;

	Float_t frac2Sto1S_lhcb[nPoints2Sto1S_lhcb], error2Sto1S_lhcb[nPoints2Sto1S_lhcb];
	Float_t frac3Sto1S_lhcb[nPoints2Sto1S_lhcb], error3Sto1S_lhcb[nPoints2Sto1S_lhcb];

	for (Int_t i = 0; i < nPoints2Sto1S_lhcb; i++) {
		frac2Sto1S_lhcb[i] = ptDiff_2p0y4p5_2Sto1S_lhcb8TeV[i] * (br1Stomumu / br2Stomumu) * br2Sto1Sanything;
		error2Sto1S_lhcb[i] = errorPtDiff_2p0y4p5_2Sto1S_lhcb8TeV[i] * (br1Stomumu / br2Stomumu) * br2Sto1Sanything;

		frac3Sto1S_lhcb[i] = ptDiff_2p0y4p5_3Sto1S_lhcb8TeV[i] * (br1Stomumu / br3Stomumu) * (br3Sto1Spipluspiminus + br3Sto1Stwopizero);
		error3Sto1S_lhcb[i] = errorPtDiff_2p0y4p5_3Sto1S_lhcb8TeV[i] * (br1Stomumu / br3Stomumu) * (br3Sto1Spipluspiminus + br3Sto1Stwopizero);
	}

	auto* stat2Sto1Sgraph_lhcb = myStatGraph(title1S, nPoints2Sto1S_lhcb, ptBinning_2p0y4p5_lhcb7and8TeV, frac2Sto1S_lhcb, error2Sto1S_lhcb, color2Sto1S, markerLHCb);

	stat2Sto1Sgraph_lhcb->Draw("PZ");

	auto* stat3Sto1Sgraph_lhcb = myStatGraph(title1S, nPoints2Sto1S_lhcb, ptBinning_2p0y4p5_lhcb7and8TeV, frac3Sto1S_lhcb, error3Sto1S_lhcb, color3Sto1S, markerLHCb);

	stat3Sto1Sgraph_lhcb->Draw("PZ");

	/// CMS measurements
	const Int_t nPoints2Sto1S_cms = sizeof(ptBinning_cms13TeV) / sizeof(Float_t) - 1;

	// from relative to absolute uncertainties
	Float_t frac2Sto1S_cms[nPoints2Sto1S_cms], stat2Sto1S_cms[nPoints2Sto1S_cms], syst2Sto1S_cms[nPoints2Sto1S_cms];
	Float_t frac3Sto1S_cms[nPoints2Sto1S_cms], stat3Sto1S_cms[nPoints2Sto1S_cms], syst3Sto1S_cms[nPoints2Sto1S_cms];

	for (Int_t i = 0; i < nPoints2Sto1S_cms; i++) {
		frac2Sto1S_cms[i] = ptDiff_2Sto1S_cms13TeV[i] * (br1Stomumu / br2Stomumu) * br2Sto1Sanything;

		stat2Sto1S_cms[i] = frac2Sto1S_cms[i] * statPerc_2Sto1S_cms13TeV[i] / 100.;

		syst2Sto1S_cms[i] = frac2Sto1S_cms[i] * systPerc_2Sto1S_cms13TeV[i] / 100.;

		frac3Sto1S_cms[i] = ptDiff_3Sto1S_cms13TeV[i] * (br1Stomumu / br3Stomumu) * (br3Sto1Spipluspiminus + br3Sto1Stwopizero);

		stat3Sto1S_cms[i] = frac3Sto1S_cms[i] * statPerc_3Sto1S_cms13TeV[i] / 100.;

		syst3Sto1S_cms[i] = frac3Sto1S_cms[i] * systPerc_3Sto1S_cms13TeV[i] / 100.;
	}

	// Y(2S)-to-Y(1S)

	auto* statGraph_cms2Sto1S = myStatGraph(title1S, nPoints2Sto1S_cms, ptBinning_cms13TeV, frac2Sto1S_cms, stat2Sto1S_cms, color2Sto1S, markerCMS);

	statGraph_cms2Sto1S->Draw("PZ");

	auto* systGraph_cms2Sto1S = mySystGraph(nPoints2Sto1S_cms, ptBinning_cms13TeV, xErrorWidth, frac2Sto1S_cms, syst2Sto1S_cms, color2Sto1S);

	systGraph_cms2Sto1S->Draw("5");

	// Y(3S)-to-Y(1S)

	auto* statGraph_cms3Sto1S = myStatGraph(title1S, nPoints2Sto1S_cms, ptBinning_cms13TeV, frac3Sto1S_cms, stat3Sto1S_cms, color3Sto1S, markerCMS);

	statGraph_cms3Sto1S->Draw("PZ");

	auto* systGraph_cms3Sto1S = mySystGraph(nPoints2Sto1S_cms, ptBinning_cms13TeV, xErrorWidth, frac3Sto1S_cms, syst3Sto1S_cms, color3Sto1S);

	systGraph_cms3Sto1S->Draw("5");

	/// legend

	auto* legend = new TLegend(.15, .9, .4, .6);
	legend->AddEntry(stat1Pto1S, "from #chi_{b}(1P) (8 TeV)", "p");
	legend->AddEntry(stat2Sto1Sgraph_lhcb, "from #varUpsilon(2S) (13 TeV)", "p");
	legend->AddEntry(stat2Pto1S, "from #chi_{b}(2P) (8 TeV)", "p");
	legend->AddEntry(stat3Sto1Sgraph_lhcb, "from #varUpsilon(3S) (13 TeV)", "p");
	legend->AddEntry(stat3Pto1S, "from #chi_{b}(3P) (8 TeV)", "p");
	//legend->Draw();

	canv1S->SaveAs("figures/feeddowns_to_1S_8TeV.png", "RECREATE");
	canv1S->Close();
}
