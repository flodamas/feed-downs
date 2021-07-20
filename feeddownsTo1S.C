#ifdef __CLING__

#include "myPlot.C"

#include "data/branching.C"
#include "data/feedLHCb7and8TeV.C"
#include "data/upsilonLHCb13TeV.C"

#endif

const Color_t color1P = kRed;
const Color_t color2P = kAzure + 1;
const Color_t color3P = kGreen + 2;

const Int_t marker1P = 20;
const Int_t marker2P = 21;
const Int_t marker3P = 22;

void feeddownsTo1S(Bool_t withLogYaxis = kFALSE) {
	// Feed-downs to Y(1S)
	auto* canv1S = myCanvas("canv1S");
	// canv1S->SetLogx();
	if (withLogYaxis) canv1S->SetLogy();

	const char* title1S =
	  ";#it{p}_{T}^{#varUpsilon(1S)} (GeV/#it{c});Feed-down fractions to #varUpsilon(1S) (in %)";

	const Int_t nPoints2Sto1S = sizeof(ptDiff_2p5y3p0_2Sto1S) / sizeof(float);

	cout << nPoints2Sto1S << " pt points" << endl;

	Float_t frac2Sto1S[nPoints2Sto1S], error2Sto1S[nPoints2Sto1S];
	Float_t frac3Sto1S[nPoints2Sto1S], error3Sto1S[nPoints2Sto1S];

	for (Int_t i = 0; i < nPoints2Sto1S; i++) {
		frac2Sto1S[i] = ptDiff_2p5y3p0_2Sto1S[i] * (br1Stomumu / br2Stomumu) * br2Sto1Sanything;
		error2Sto1S[i] = errorPtDiff_2p5y3p0_2Sto1S[i] * (br1Stomumu / br2Stomumu) * br2Sto1Sanything;

		frac3Sto1S[i] = ptDiff_2p5y3p0_3Sto1S[i] * (br1Stomumu / br3Stomumu) * (br3Sto1Spipluspiminus + br3Sto1Stwopizero);
		error3Sto1S[i] = errorPtDiff_2p5y3p0_3Sto1S[i] * (br1Stomumu / br3Stomumu) * (br3Sto1Spipluspiminus + br3Sto1Stwopizero);
	}

	auto* stat2Sto1Sgraph = myStatGraph(title1S, nPoints2Sto1S, ptBinning_2p5y3p0_2Sto1S, frac2Sto1S, error2Sto1S, color2P, marker2P);

	stat2Sto1Sgraph->SetMaximum(25);
	stat2Sto1Sgraph->GetXaxis()->SetLimits(0, 30);

	stat2Sto1Sgraph->Draw("APZ");

	auto* stat3Sto1Sgraph = myStatGraph(title1S, nPoints2Sto1S, ptBinning_2p5y3p0_3Sto1S, frac3Sto1S, error3Sto1S, color3P, marker3P);

	stat3Sto1Sgraph->Draw("PZ");

	auto* legend = new TLegend(.2, .9, .4, .7, "LHCb 13 TeV data");
	legend->AddEntry(stat2Sto1Sgraph, "#varUpsilon(2S) #rightarrow #varUpsilon(1S)", "p");
	legend->AddEntry(stat3Sto1Sgraph, "#varUpsilon(3S) #rightarrow #varUpsilon(1S)", "p");
	legend->Draw();

	canv1S->SaveAs("figures/feeddowns_to_1S_lhcb13TeV.png", "RECREATE");
	canv1S->Close();
}
