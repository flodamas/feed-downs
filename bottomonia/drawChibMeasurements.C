#ifdef __CLING__

#include "../tools/Cosmetics.h"
#include "../tools/Graph.h"

#include "data/feedLHCb7and8TeV.C"

#endif
Float_t xErrorWidth = .4;

void drawChibMeasurements() {
	gStyle->SetPadLeftMargin(0.13);

	// Feed-downs to Y(1S)
	auto* canv1S = Canvas("canv1S", 750);

	const char* title1S = ";#it{p}_{T}^{#varUpsilon(1S)} (GeV);#chi_{b}-to-#varUpsilon(1S) feed-down fraction (in %)";

	auto* stat1Pto1S = StatGraph(title1S, nPoints1Pto1S_lhcb, ptBinning1Pto1S_lhcb, frac1Pto1S_weightedLHCb, stat1Pto1S_weightedLHCb, color1P, markerLHCb);

	auto* syst1Pto1S = SystGraph(nPoints1Pto1S_lhcb, ptBinning1Pto1S_lhcb, xErrorWidth, frac1Pto1S_weightedLHCb, syst1Pto1S_weightedLHCb, color1P);

	stat1Pto1S->SetMaximum(50);
	stat1Pto1S->GetXaxis()->SetLimits(0, 40);

	stat1Pto1S->Draw("APZ");
	syst1Pto1S->Draw("5");

	auto* stat2Pto1S = StatGraph(title1S, nPoints2Pto1S_lhcb, ptBinning2Pto1S_lhcb, frac2Pto1S_weightedLHCb, stat2Pto1S_weightedLHCb, color2P, markerLHCb);

	auto* syst2Pto1S = SystGraph(nPoints2Pto1S_lhcb, ptBinning2Pto1S_lhcb, xErrorWidth, frac2Pto1S_weightedLHCb, syst2Pto1S_weightedLHCb, color2P);

	stat2Pto1S->Draw("PZ");
	syst2Pto1S->Draw("5");

	auto* stat3Pto1S = StatGraph(title1S, nPoints3Pto1S_lhcb, ptBinning3Pto1S_lhcb, frac3Pto1S_weightedLHCb, stat3Pto1S_weightedLHCb, color3P, markerLHCb);

	auto* syst3Pto1S = SystGraph(nPoints3Pto1S_lhcb, ptBinning3Pto1S_lhcb, xErrorWidth, frac3Pto1S_weightedLHCb, syst3Pto1S_weightedLHCb, color3P);

	stat3Pto1S->Draw("PZ");
	syst3Pto1S->Draw("5");

	// legend
	Float_t x1 = .18, x2 = x1 + .2, y1 = .9;
	auto* legend1S = new TLegend(x1, y1, x2, .65, "LHCb, 7 and 8 TeV data (weighted average)");
	legend1S->AddEntry(stat1Pto1S, "#chi_{b}(1P) #rightarrow #varUpsilon(1S)", "p");
	legend1S->AddEntry(stat2Pto1S, "#chi_{b}(2P) #rightarrow #varUpsilon(1S)", "p");
	legend1S->AddEntry(stat3Pto1S, "#chi_{b}(3P) #rightarrow #varUpsilon(1S)", "p");
	legend1S->Draw();

	saveCanvas(canv1S, "chibTo1S_weightedLHCb");

	// Feed-downs to Y(2S)
	auto* canv2S = Canvas("canv2S", 750);

	const char* title2S = ";#it{p}_{T}^{#varUpsilon(2S)} (GeV);#chi_{b}-to-#varUpsilon(2S) feed-down fraction (in %)";

	auto* stat2Pto2S = StatGraph(title2S, nPoints2Pto2S_lhcb, ptBinning2Pto2S_lhcb, frac2Pto2S_weightedLHCb, stat2Pto2S_weightedLHCb, color2P, markerLHCb);

	auto* syst2Pto2S = SystGraph(nPoints2Pto2S_lhcb, ptBinning2Pto2S_lhcb, xErrorWidth, frac2Pto2S_weightedLHCb, syst2Pto2S_weightedLHCb, color2P);

	stat2Pto2S->SetMaximum(50);
	stat2Pto2S->GetXaxis()->SetLimits(0, 40);

	stat2Pto2S->Draw("APZ");
	syst2Pto2S->Draw("5");

	auto* stat3Pto2S = StatGraph(title2S, nPoints3Pto2S_lhcb, ptBinning3Pto2S_lhcb, frac3Pto2S_weightedLHCb, stat3Pto2S_weightedLHCb, color3P, markerLHCb);

	auto* syst3Pto2S = SystGraph(nPoints3Pto2S_lhcb, ptBinning3Pto2S_lhcb, xErrorWidth, frac3Pto2S_weightedLHCb, syst3Pto2S_weightedLHCb, color3P);

	stat3Pto2S->Draw("PZ");
	syst3Pto2S->Draw("5");

	auto* legend2S = new TLegend(x1, y1, x2, .7, "LHCb, 7 and 8 TeV data (weighted average)");
	legend2S->AddEntry(stat2Pto2S, "#chi_{b}(2P) #rightarrow #varUpsilon(2S)", "p");
	legend2S->AddEntry(stat3Pto2S, "#chi_{b}(3P) #rightarrow #varUpsilon(2S)", "p");
	legend2S->Draw();

	saveCanvas(canv2S, "chibTo2S_weightedLHCb");

	// Feed-downs to Y(3S)
	auto* canv3S = Canvas("canv3S", 750);

	const char* title3S = ";#it{p}_{T}^{#varUpsilon(3S)} (GeV);#chi_{b}-to-#varUpsilon(3S) feed-down fraction (in %)";

	auto* stat3Pto3S = StatGraph(title3S, nPoints3Pto3S_lhcb, ptBinning3Pto3S_lhcb, frac3Pto3S_weightedLHCb, stat3Pto3S_weightedLHCb, color3P, markerLHCb);

	auto* syst3Pto3S = SystGraph(nPoints3Pto3S_lhcb, ptBinning3Pto3S_lhcb, xErrorWidth, frac3Pto3S_weightedLHCb, syst3Pto3S_weightedLHCb, color3P);

	stat3Pto3S->SetMaximum(50);
	stat3Pto3S->GetXaxis()->SetLimits(0, 40);

	stat3Pto3S->Draw("APZ");
	syst3Pto3S->Draw("5");

	auto* legend3S = new TLegend(x1, y1, x2, .78, "LHCb, 7 and 8 TeV data (weighted average)");
	legend3S->AddEntry(stat3Pto3S, "#chi_{b}(3P) #rightarrow #varUpsilon(3S)", "p");
	legend3S->Draw();

	saveCanvas(canv3S, "chibTo3S_weightedLHCb");
}
