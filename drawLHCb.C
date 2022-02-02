#ifdef __CLING__

#include "bottomonia/feedLHCb7and8TeV.C"
#include "myPlot.C"

#endif
Float_t xErrorWidth = .4;

const Color_t color1P = kRed;
const Color_t color2P = kAzure + 1;
const Color_t color3P = kGreen + 2;

const Int_t marker1P = 20;
const Int_t marker2P = 21;
const Int_t marker3P = 22;

void drawLHCb(Bool_t withLogYaxis = kFALSE) {
	gStyle->SetPadLeftMargin(0.13);

	// Feed-downs to Y(1S)
	auto* canv1S = myCanvas("canv1S");
	// canv1S->SetLogx();
	if (withLogYaxis) canv1S->SetLogy();

	const char* title1S =
	  ";#it{p}_{T}^{#varUpsilon(1S)} (GeV);#chi_{b}-to-#varUpsilon(1S) feed-down fraction (in %)";

	auto* stat1Pto1S =
	  myStatGraph(title1S, nPoints1Pto1S_lhcb, ptBinning1Pto1S_lhcb, frac1Pto1S_lhcb8TeV, stat1Pto1S_lhcb8TeV, color1P, marker1P);

	auto* syst1Pto1S =
	  mySystGraph(nPoints1Pto1S_lhcb, ptBinning1Pto1S_lhcb, xErrorWidth, frac1Pto1S_lhcb8TeV, syst1Pto1S_lhcb8TeV, color1P);

	stat1Pto1S->SetMaximum(50);
	stat1Pto1S->GetXaxis()->SetLimits(0, 40);

	stat1Pto1S->Draw("APZ");
	syst1Pto1S->Draw("5");

	auto* stat2Pto1S =
	  myStatGraph(title1S, nPoints2Pto1S_lhcb, ptBinning2Pto1S_lhcb, frac2Pto1S_lhcb8TeV, stat2Pto1S_lhcb8TeV, color2P, marker2P);

	auto* syst2Pto1S =
	  mySystGraph(nPoints2Pto1S_lhcb, ptBinning2Pto1S_lhcb, xErrorWidth, frac2Pto1S_lhcb8TeV, syst2Pto1S_lhcb8TeV, color2P);

	stat2Pto1S->Draw("PZ");
	syst2Pto1S->Draw("5");

	auto* stat3Pto1S =
	  myStatGraph(title1S, nPoints3Pto1S_lhcb, ptBinning3Pto1S_lhcb, frac3Pto1S_lhcb8TeV, stat3Pto1S_lhcb8TeV, color3P, marker3P);

	auto* syst3Pto1S =
	  mySystGraph(nPoints3Pto1S_lhcb, ptBinning3Pto1S_lhcb, xErrorWidth, frac3Pto1S_lhcb8TeV, syst3Pto1S_lhcb8TeV, color3P);

	stat3Pto1S->Draw("PZ");
	syst3Pto1S->Draw("5");

	//drawHeaderLegend("LHCb 8 TeV data", .2, .9);

	auto* legend1S = new TLegend(.2, .9, .4, .65, "LHCb 8 TeV data");
	legend1S->AddEntry(stat1Pto1S, "#chi_{b}(1P) #rightarrow #varUpsilon(1S) #gamma", "p");
	legend1S->AddEntry(stat2Pto1S, "#chi_{b}(2P) #rightarrow #varUpsilon(1S) #gamma", "p");
	legend1S->AddEntry(stat3Pto1S, "#chi_{b}(3P) #rightarrow #varUpsilon(1S) #gamma", "p");
	legend1S->Draw();

	canv1S->SaveAs("figures/chib_to_1S_lhcb8TeV.png", "RECREATE");
	canv1S->Close();

	// Feed-downs to Y(2S)
	auto* canv2S = myCanvas("canv2S");
	// canv1S->SetLogx();
	if (withLogYaxis) canv2S->SetLogy();

	const char* title2S =
	  ";#it{p}_{T}^{#varUpsilon(2S)} (GeV);#chi_{b}-to-#varUpsilon(2S) feed-down fraction (in %)";

	auto* stat2Pto2S =
	  myStatGraph(title2S, nPoints2Pto2S_lhcb, ptBinning2Pto2S_lhcb, frac2Pto2S_lhcb8TeV, stat2Pto2S_lhcb8TeV, color2P, marker2P);

	auto* syst2Pto2S =
	  mySystGraph(nPoints2Pto2S_lhcb, ptBinning2Pto2S_lhcb, xErrorWidth, frac2Pto2S_lhcb8TeV, syst2Pto2S_lhcb8TeV, color2P);

	stat2Pto2S->SetMaximum(50);
	stat2Pto2S->GetXaxis()->SetLimits(0, 40);

	stat2Pto2S->Draw("APZ");
	syst2Pto2S->Draw("5");

	auto* stat3Pto2S =
	  myStatGraph(title2S, nPoints3Pto2S_lhcb, ptBinning3Pto2S_lhcb, frac3Pto2S_lhcb8TeV, stat3Pto2S_lhcb8TeV, color3P, marker3P);

	auto* syst3Pto2S =
	  mySystGraph(nPoints3Pto2S_lhcb, ptBinning3Pto2S_lhcb, xErrorWidth, frac3Pto2S_lhcb8TeV, syst3Pto2S_lhcb8TeV, color3P);

	stat3Pto2S->Draw("PZ");
	syst3Pto2S->Draw("5");

	auto* legend2S = new TLegend(.2, .92, .4, .75, "LHCb 8 TeV data");
	legend2S->AddEntry(stat2Pto2S, "#chi_{b}(2P) #rightarrow #varUpsilon(2S) #gamma", "p");
	legend2S->AddEntry(stat3Pto2S, "#chi_{b}(3P) #rightarrow #varUpsilon(2S) #gamma", "p");
	legend2S->Draw();

	canv2S->SaveAs("figures/chib_to_2S_lhcb8TeV.png", "RECREATE");
	canv2S->Close();

	// Feed-downs to Y(3S)
	auto* canv3S = myCanvas("canv3S");
	// canv1S->SetLogx();
	if (withLogYaxis) canv3S->SetLogy();

	const char* title3S =
	  ";#it{p}_{T}^{#varUpsilon(3S)} (GeV);#chi_{b}-to-#varUpsilon(3S) feed-down fraction (in %)";

	auto* stat3Pto3S =
	  myStatGraph(title3S, nPoints3Pto3S_lhcb, ptBinning3Pto3S_lhcb, frac3Pto3S_lhcb8TeV, stat3Pto3S_lhcb8TeV, color3P, marker3P);

	auto* syst3Pto3S =
	  mySystGraph(nPoints3Pto3S_lhcb, ptBinning3Pto3S_lhcb, xErrorWidth, frac3Pto3S_lhcb8TeV, syst3Pto3S_lhcb8TeV, color3P);

	stat3Pto3S->SetMaximum(50);
	stat3Pto3S->GetXaxis()->SetLimits(0, 40);

	stat3Pto3S->Draw("APZ");
	syst3Pto3S->Draw("5");

	auto* legend3S = new TLegend(.2, .92, .4, .8, "LHCb 8 TeV data");
	legend3S->AddEntry(stat3Pto3S, "#chi_{b}(3P) #rightarrow #varUpsilon(3S) #gamma", "p");
	legend3S->Draw();

	canv3S->SaveAs("figures/chib_to_3S_lhcb8TeV.png", "RECREATE");
	canv3S->Close();
}
