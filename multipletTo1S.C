#ifdef __CLING__

#include "myPlot.C"

#include "bottomonia/branching.C"
#include "bottomonia/feedLHCb7and8TeV.C"
#include "bottomonia/upsilonLHCb7and8TeV.C"
#include "bottomonia/upsilonCMS7TeV.C"

#include "bottomonia/chib1PstatesCMS8TeV.C"

#endif

Float_t xErrorWidth = .4;

const Color_t color1P = kRed + 1;
const Color_t color2P = kAzure + 1;
const Color_t color3P = kGreen + 2;

const Int_t marker1P = 20;
const Int_t marker2P = 21;
const Int_t marker3P = 22;

void multipletTo1S(Bool_t withLogYaxis = kFALSE) {
	string color = "\033[1;31m";

	// Feed-downs to Y(1S)
	auto* canv = myCanvas("canv");

	if (withLogYaxis) canv->SetLogy();

	const char* title = ";#it{p}_{T}^{#varUpsilon(1S)} (GeV);Feed-down fractions to #varUpsilon(1S) (in %)";

	/// Chi_b(1P) first

	Int_t nPoints1P = nPoints1Pto1S_lhcb;

	auto* stat1Pto1S =
	  myStatGraph(title, nPoints1P, ptBinning1Pto1S_lhcb, frac1Pto1S_weightedLHCb, stat1Pto1S_weightedLHCb, color1P, marker2P);

	auto* syst1Pto1S =
	  mySystGraph(nPoints1P, ptBinning1Pto1S_lhcb, xErrorWidth, frac1Pto1S_weightedLHCb, syst1Pto1S_weightedLHCb, color1P - 1);

	stat1Pto1S->SetMinimum(0);
	stat1Pto1S->SetMaximum(40);
	stat1Pto1S->GetXaxis()->SetLimits(0, 40);

	if (withLogYaxis) {
		stat1Pto1S->SetMinimum(.4);
		stat1Pto1S->SetMaximum(1000);
	}

	stat1Pto1S->Draw("APZ");
	syst1Pto1S->Draw("5");

	// separate the multiplet

	Float_t frac1Pto1S_Jequal1[nPoints1P], stat1Pto1S_Jequal1[nPoints1P], syst1Pto1S_Jequal1[nPoints1P];
	Float_t frac1Pto1S_Jequal2[nPoints1P], stat1Pto1S_Jequal2[nPoints1P], syst1Pto1S_Jequal2[nPoints1P];

	for (Int_t i = 0; i < nPoints1P; i++) {
		// J = 1
		frac1Pto1S_Jequal1[i] = frac1Pto1S_weightedLHCb[i] / (1. + ratio2over1);

		stat1Pto1S_Jequal1[i] = frac1Pto1S_Jequal1[i] * (stat1Pto1S_weightedLHCb[i] / frac1Pto1S_weightedLHCb[i]);

		syst1Pto1S_Jequal1[i] = frac1Pto1S_Jequal1[i] * (syst1Pto1S_weightedLHCb[i] / frac1Pto1S_weightedLHCb[i]);

		// J = 2
		frac1Pto1S_Jequal2[i] = frac1Pto1S_weightedLHCb[i] - frac1Pto1S_Jequal1[i];

		stat1Pto1S_Jequal2[i] = frac1Pto1S_Jequal2[i] * (stat1Pto1S_weightedLHCb[i] / frac1Pto1S_weightedLHCb[i]);

		syst1Pto1S_Jequal2[i] = frac1Pto1S_Jequal2[i] * (syst1Pto1S_weightedLHCb[i] / frac1Pto1S_weightedLHCb[i]);
	}

	auto* statGraph1Pto1S_Jequal1 = myStatGraph(title, nPoints1P, ptBinning1Pto1S_lhcb, frac1Pto1S_Jequal1, stat1Pto1S_Jequal1, kPink + 6, marker2P);
	statGraph1Pto1S_Jequal1->Draw("PZ");

	auto* systGraph1Pto1S_Jequal1 = mySystGraph(nPoints1P, ptBinning1Pto1S_lhcb, xErrorWidth, frac1Pto1S_Jequal1, syst1Pto1S_Jequal1, kPink + 6);
	systGraph1Pto1S_Jequal1->Draw("5");

	auto* statGraph1Pto1S_Jequal2 = myStatGraph(title, nPoints1P, ptBinning1Pto1S_lhcb, frac1Pto1S_Jequal2, stat1Pto1S_Jequal2, kOrange + 1, marker2P);
	statGraph1Pto1S_Jequal2->Draw("PZ");

	auto* systGraph1Pto1S_Jequal2 = mySystGraph(nPoints1P, ptBinning1Pto1S_lhcb, xErrorWidth, frac1Pto1S_Jequal2, syst1Pto1S_Jequal2, kOrange + 1);
	systGraph1Pto1S_Jequal2->Draw("5");

	/// Chi_b(2P)

	auto* stat2Pto1S = myStatGraph(title, nPoints2Pto1S_lhcb, ptBinning2Pto1S_lhcb, frac2Pto1S_weightedLHCb, stat2Pto1S_weightedLHCb, color2P, marker2P);

	auto* syst2Pto1S = mySystGraph(nPoints2Pto1S_lhcb, ptBinning2Pto1S_lhcb, xErrorWidth, frac2Pto1S_weightedLHCb, syst2Pto1S_weightedLHCb, color2P);

	//stat2Pto1S->Draw("PZ");
	//syst2Pto1S->Draw("5");

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

	auto* stat2Sto1Sgraph_lhcb = myStatGraph(title, nPoints2Sto1S_lhcb, ptBinning_2p0y4p5_lhcb7and8TeV, frac2Sto1S_lhcb, error2Sto1S_lhcb, color2Sto1S, markerLHCb);

	//stat2Sto1Sgraph_lhcb->Draw("PZ");

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

	auto* statGraph_cms2Sto1S = myStatGraph(title, nPoints2Sto1S_cms, ptBinning_cms7TeV, frac2Sto1S_cms, stat2Sto1S_cms, color2Sto1S + 1, markerCMS);

	//statGraph_cms2Sto1S->Draw("PZ");

	auto* systGraph_cms2Sto1S = mySystGraph(nPoints2Sto1S_cms, ptBinning_cms7TeV, xErrorWidth, frac2Sto1S_cms, syst2Sto1S_cms, color2Sto1S + 1);

	//systGraph_cms2Sto1S->Draw("5");

	/// legend

	Float_t x1 = .17, x2 = .33, x3 = .5;
	Float_t y = .9;
	drawHeaderLegend("7 and 8 TeV pp data, #varUpsilon(1S) from", x1 + .01, y);
	y -= .06;
	drawLegend(stat1Pto1S, "#chi_{b}(1P)", x1, y);
	drawLegend(statGraph1Pto1S_Jequal1, "#chi_{b,1}(1P)", x2, y);
	drawLegend(statGraph1Pto1S_Jequal2, Form("#chi_{b,2}(1P), #it{R}_{21} = %.2f #pm %.2f", ratio2to1_chib1P_CMSaverage, systRatio2to1_chib1P_CMSaverage), x3, y);
	y -= .07;
	//drawLegend(stat2Sto1Sgraph_lhcb, "#varUpsilon(2S)", x1, y);

	canv->SaveAs("figures/multiplet_to_1S.png", "RECREATE");
	canv->Close();
}
