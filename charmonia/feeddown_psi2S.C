#ifdef __CLING__

#include "../tools/Cosmetics.h"
#include "../tools/Graph.h"

#include "data/BranchingRatios.h"

#include "data/X3872toPsi2S_ATLAS8TeV.C"
#include "data/X3872toPsi2S_LHCb8and13TeV.C"

#endif

Float_t xErrorWidth = .5;

void feeddown_psi2S() {
	auto* canv = Canvas("canv", 800);

	const char* title = ";#it{p}_{T}^{#psi(2S)} (GeV);Fraction of prompt #psi(2S) from X(3872)";

	Float_t brCorrection = (brPsi2StoJpsipipluspiminus / brX3842toJpsipipluspiminus) * brX3842toPsi2Sgamma;

	// ATLAS measurements

	Float_t frac_atlas[nPtPoints_X3872_atlas8TeV], stat_atlas[nPtPoints_X3872_atlas8TeV], syst_atlas[nPtPoints_X3872_atlas8TeV];

	for (Int_t i = 0; i < nPtPoints_X3872_atlas8TeV; i++) {
		frac_atlas[i] = ptDiffRatio_X3872_atlas8TeV[i] * brCorrection;

		stat_atlas[i] = statPtRatio_X3872_atlas8TeV[i] * brCorrection;

		syst_atlas[i] = systPtRatio_X3872_atlas8TeV[i] * brCorrection;
	}

	auto* statGraph_atlas = AsymmStatGraph(title, nPtPoints_X3872_atlas8TeV, meanPt_X3872_atlas8TeV, ptBinning_X3872_atlas8TeV, frac_atlas, stat_atlas, stat_atlas, colorX3872, markerATLAS);

	auto* systGraph_atlas = DoubleAsymmSystGraph(nPtPoints_X3872_atlas8TeV, meanPt_X3872_atlas8TeV, xErrorWidth, frac_atlas, syst_atlas, syst_atlas, colorX3872);

	statGraph_atlas->SetMaximum(10);
	statGraph_atlas->GetXaxis()->SetLimits(0, 70);

	statGraph_atlas->Draw("APZ");
	systGraph_atlas->Draw("5");

	// LHCb measurements at 8 TeV

	Float_t frac_lhcb[nPtPoints_X3872_lhcb8TeV], error_lhcb[nPtPoints_X3872_lhcb8TeV];

	for (Int_t i = 0; i < nPtPoints_X3872_lhcb8TeV; i++) {
		frac_lhcb[i] = ptDiffRatio_X3872_lhcb8TeV[i] * brCorrection;

		error_lhcb[i] = errorPtRatio_X3872_lhcb8TeV[i] * brCorrection;
	}

	auto* statGraph_lhcb = StatGraph(title, nPtPoints_X3872_lhcb8TeV, ptBinning_X3872_lhcb8TeV, frac_lhcb, error_lhcb, colorLHCb, markerLHCb);

	statGraph_lhcb->Draw("PZ");

	/// legend

	drawHeaderLegend(Form("BR(X(3872) #rightarrow #psi(2S) + #gamma) = (%1.1f #pm %1.1f)%%", brX3842toPsi2Sgamma, systX3842toPsi2Sgamma), .25, .25);
	auto* legend = new TLegend(.17, .92, .35, .72, "8 TeV pp measurements, J/#psi #pi^{#plus} #pi^{-} channel");
	legend->AddEntry(statGraph_atlas, "ATLAS, |y| < 0.75", "p");
	legend->AddEntry(statGraph_lhcb, "LHCb, 2.0 < y < 4.5 (dummy values!!!)", "p");

	legend->Draw();

	saveCanvas(canv, "psi2SFeedDowns");
}
