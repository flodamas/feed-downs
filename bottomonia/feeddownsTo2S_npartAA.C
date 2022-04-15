#ifdef __CLING__

#include "../tools/Cosmetics.h"
#include "../tools/Graph.h"

#include "data/BranchingRatios.h"

#include "data/feedLHCb7and8TeV.C"
#include "data/upsilonLHCb7and8TeV.C"
#include "data/upsilonCMS7TeV.C"

#endif

Float_t xErrorWidth = .4;

void feeddownsTo2S_npartAA(Bool_t withLegend = kTRUE, Bool_t withLogYaxis = kFALSE) {
	// Feed-downs to Y(2S)
	auto* canv = Canvas("canv", 800);

	const char* title = ";#LTN_{part}#GT;Fraction of #varUpsilon(2S) from feed-down (in %)";

	/// Chi_b first

	/// Scale the P-wave feed-down fractions by the ratio of survival probabilities from https://link.springer.com/content/pdf/10.1007/JHEP05(2021)136.pdf

	const Int_t nPoints = 10;

	Float_t nPart[] = {0, 20, 40, 70, 110, 170, 250, 320, 380, 400, 410};

	Float_t survival_2S[] = {1, .96, .61, .3, .15, .1, .06, .05, .04, .04};

	Float_t survival_2P[] = {1, .95, .55, .22, .06, 0.02, 0.01, 0.005, 0.00, 0.00};

	Float_t frac2Pto2S_pp = 30., error2Pto2S_pp = 5.;

	Float_t frac2Pto2S_pbpb[nPoints], error2Pto2S_pbpb[nPoints], xErr[nPoints];

	for (Int_t i = 0; i < nPoints; i++) {
		frac2Pto2S_pbpb[i] = frac2Pto2S_pp * (survival_2P[i] / survival_2S[i]);

		error2Pto2S_pbpb[i] = error2Pto2S_pp * (survival_2P[i] / survival_2S[i]);
	}

	auto* stat2Pto2S = StatGraph(title, nPoints, nPart, frac2Pto2S_pbpb, error2Pto2S_pbpb, color2P, marker2P);
	stat2Pto2S->SetLineWidth(0);
	stat2Pto2S->SetFillStyle(1001);
	stat2Pto2S->SetFillColorAlpha(color2P, .5);
	stat2Pto2S->SetMaximum(40);

	stat2Pto2S->GetXaxis()->SetLimits(0, 400);

	stat2Pto2S->Draw("A3");

	auto* line2Pto2S = SimpleGraph(nPoints, nPart, frac2Pto2S_pbpb, color2P);
	line2Pto2S->Draw("l");

	/// CMS 2018 PbPb 5 TeV data
	TFile* file_pbpb = new TFile("bottomonia/PbPb2018Upsilon_SingleRatio.root", "READ");

	auto* histo = (TH1*)file_pbpb->Get("PbPbSR_IntCent");

	const Int_t nPoints_pbpb = 5;

	Float_t centBinning_pbpb[] = {0, 30, 50, 70, 90};

	// in the order of the centrality binning
	Float_t nPart_pbpb[] = {0, 270, 110, 40, 10};

	Float_t frac3Sto2S_pbpb[nPoints_pbpb], error3Sto2S_pbpb[nPoints_pbpb];

	for (Int_t i = 1; i < nPoints_pbpb; i++) {
		frac3Sto2S_pbpb[i] = histo->GetBinContent(i + 1) * (br2Stomumu / br3Stomumu) * br3Sto2Sanything;

		error3Sto2S_pbpb[i] = histo->GetBinError(i + 1) * (br2Stomumu / br3Stomumu) * br3Sto2Sanything;
	}

	auto* stat3Sto2Sgraph_pbpb = StatGraph(title, nPoints_pbpb, nPart_pbpb, frac3Sto2S_pbpb, error3Sto2S_pbpb, kRed + 1, markerCMS);

	stat3Sto2Sgraph_pbpb->Draw("PZ");

	/// legend

	auto* legend = new TLegend(.47, .8, .7, .45, "PbPb 5 TeV");
	legend->AddEntry(stat2Pto2S, "#chi_{b}(2P), derivation with", "f");
	legend->AddEntry((TObject*)0, "pNRQCD+OQS", " ");
	legend->AddEntry((TObject*)0, "survival probabilities", " ");
	legend->AddEntry(stat3Sto2Sgraph_pbpb, "#varUpsilon(3S), CMS data", "p");
	if (withLegend) legend->Draw();

	drawHeaderLegend("overestimation using FD(#chi_{b}(2P)#rightarrow #varUpsilon(2S))_{pp} = (30 #pm 5)%", .17);

	saveCanvas(canv, "feeddownsTo2S_nPartCMSPbPb");
}
