#ifdef __CLING__

#include "../tools/Cosmetics.h"
#include "../tools/Graph.h"

#include "data/BranchingRatios.h"

#include "data/psi2StoJpsiCMS7TeV.C"
#include "data/psi2StoJpsiCMS13TeV.C"
#include "data/psi2StoJpsiLHCb13TeV.C"

#endif

Float_t xErrorWidth = .4;

void ptCrossRatio_psi2S(Bool_t withLogYaxis = kFALSE) {
	const char* title = ";#it{p}_{T} (GeV);BR(#psi#rightarrow #mu^{#plus}#mu^{#minus}) #times cross-section ratio";

	auto* canv = Canvas("canv", 800);

	// CMS 7 TeV first

	for (Int_t i = 0; i < nPtPoints_psi2S_cms7TeV; i++) {
		ptDiffRatio_psi2S_cms7TeV[i] /= 100.;

		statPtRatio_psi2S_cms7TeV[i] /= 100.;

		systPtRatio_psi2S_cms7TeV[i] /= 100.;
	}

	auto* statGraph_cms7TeV = StatGraph(title, nPtPoints_psi2S_cms7TeV, ptBinning_psi2S_cms7TeV, ptDiffRatio_psi2S_cms7TeV, statPtRatio_psi2S_cms7TeV, colorATLAS, markerATLAS);

	statGraph_cms7TeV->SetMaximum(.07);

	if (withLogYaxis) {
		canv->SetLogy();
		statGraph_cms7TeV->SetMinimum(0.15);
		statGraph_cms7TeV->SetMaximum(.8);
	}

	statGraph_cms7TeV->GetXaxis()->SetLimits(0, 50);
	statGraph_cms7TeV->Draw("APZ");

	auto* systGraph_cms7TeV = SystGraph(nPtPoints_psi2S_cms7TeV, ptBinning_psi2S_cms7TeV, xErrorWidth, ptDiffRatio_psi2S_cms7TeV, systPtRatio_psi2S_cms7TeV, colorATLAS - 1);
	systGraph_cms7TeV->Draw("5");

	// 13 TeV
	Float_t statPtRatio_psi2S_cms13TeV[nPtPoints_psi2S_cms13TeV], systPtRatio_psi2S_cms13TeV[nPtPoints_psi2S_cms13TeV];

	for (Int_t i = 0; i < nPtPoints_psi2S_cms13TeV; i++) {
		statPtRatio_psi2S_cms13TeV[i] = ptDiffRatio_psi2S_cms13TeV[i] * statPercPtRatio_psi2S_cms13TeV[i] / 100.;

		systPtRatio_psi2S_cms13TeV[i] = ptDiffRatio_psi2S_cms13TeV[i] * systPercPtRatio_psi2S_cms13TeV[i] / 100.;
	}

	auto* statGraph_cms13TeV = StatGraph(title, nPtPoints_psi2S_cms13TeV, ptBinning_psi2S_cms13TeV, ptDiffRatio_psi2S_cms13TeV, statPtRatio_psi2S_cms13TeV, colorCMS, markerCMS);

	statGraph_cms13TeV->Draw("PZ");

	auto* systGraph_cms13TeV = SystGraph(nPtPoints_psi2S_cms13TeV, ptBinning_psi2S_cms13TeV, xErrorWidth, ptDiffRatio_psi2S_cms13TeV, systPtRatio_psi2S_cms13TeV, colorCMS - 1);
	systGraph_cms13TeV->Draw("5");

	// LHCb 13 TeV
	for (Int_t i = 0; i < nPtPoints_psi2S_lhcb13TeV; i++) {
		ptDiffRatio_psi2S_lhcb13TeV[i] *= brPsi2Stomumu / brJpsitomumu;
		errorPtDiffRatio_psi2S_lhcb13TeV[i] *= brPsi2Stomumu / brJpsitomumu;
	}

	auto* statGraph_lhcb13TeV = StatGraph(title, nPtPoints_psi2S_lhcb13TeV, ptBinning_psi2S_lhcb13TeV, ptDiffRatio_psi2S_lhcb13TeV, errorPtDiffRatio_psi2S_lhcb13TeV, colorLHCb, markerLHCb);

	statGraph_lhcb13TeV->Draw("PZ");

	// legend

	Float_t xLegend = .4;
	Float_t yHeader = .9, yATLAS = .4, yCMS = yATLAS - .06, yLHCb = yCMS - .06;

	drawHeaderLegend("#psi(2S) over J/#psi yield ratio", .2, yHeader);

	drawLegend(statGraph_cms7TeV, "CMS 7 TeV, |#it{y} | < 1.2", xLegend, yATLAS, "pl");
	drawLegend(statGraph_cms13TeV, "CMS 13 TeV, |#it{y} | < 1.2", xLegend, yCMS, "pl");
	drawLegend(statGraph_lhcb13TeV, "LHCb 13 TeV, 2.0 < #it{y} < 4.5", xLegend, yLHCb, "pl");

	saveCanvas(canv, "ptPsi2StoJpsi");
}
