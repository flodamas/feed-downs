#ifdef __CLING__

#include "myPlot.C"

#include "charmonia/branching.C"

#include "charmonia/X3872toPsi2S_ATLAS8TeV.C"
#include "charmonia/X3872toPsi2S_LHCb8and13TeV.C"

#endif

Float_t xErrorWidth = .5;

const Color_t colorX3872 = kRed + 1;

void psi2SFeedDowns(Bool_t withLegend = kFALSE) {
	string color = "\033[1;31m";

	auto* canv = myCanvas("canv");

	const char* title = ";#it{p}_{T}^{#psi(2S)} (GeV);Fraction of prompt #psi(2S) from X(3872) (in %)";

	// ATLAS measurements

	Float_t frac_atlas[nPtPoints_X3872_atlas8TeV], stat_atlas[nPtPoints_X3872_atlas8TeV], syst_atlas[nPtPoints_X3872_atlas8TeV];

	for (Int_t i = 0; i < nPtPoints_X3872_atlas8TeV; i++) {
		frac_atlas[i] = ptDiffRatio_X3872_atlas8TeV[i] * (brPsi2StoJpsipipluspiminus / brX3842toJpsipipluspiminus) * brX3842toPsi2Sgamma;

		stat_atlas[i] = statPtRatio_X3872_atlas8TeV[i] * (brPsi2StoJpsipipluspiminus / brX3842toJpsipipluspiminus) * brX3842toPsi2Sgamma;

		syst_atlas[i] = systPtRatio_X3872_atlas8TeV[i] * (brPsi2StoJpsipipluspiminus / brX3842toJpsipipluspiminus) * brX3842toPsi2Sgamma;
	}

	auto* statGraph_atlas = statAsymmGraph(title, nPtPoints_X3872_atlas8TeV, meanPt_X3872_atlas8TeV, ptBinning_X3872_atlas8TeV, frac_atlas, stat_atlas, stat_atlas, colorX3872, markerATLAS);

	auto* systGraph_atlas = systAsymmGraph(nPtPoints_X3872_atlas8TeV, meanPt_X3872_atlas8TeV, xErrorWidth, frac_atlas, syst_atlas, syst_atlas, colorX3872);

	statGraph_atlas->SetMinimum(0);
	statGraph_atlas->SetMaximum(10);
	statGraph_atlas->GetXaxis()->SetLimits(0, 70);

	statGraph_atlas->Draw("APZ");
	systGraph_atlas->Draw("5");

	// LHCb measurements at 8 TeV

	Float_t frac_lhcb[nPtPoints_X3872_lhcb8TeV], error_lhcb[nPtPoints_X3872_lhcb8TeV];

	for (Int_t i = 0; i < nPtPoints_X3872_lhcb8TeV; i++) {
		frac_lhcb[i] = ptDiffRatio_X3872_lhcb8TeV[i] * (brPsi2StoJpsipipluspiminus / brX3842toJpsipipluspiminus) * brX3842toPsi2Sgamma;

		error_lhcb[i] = errorPtRatio_X3872_lhcb8TeV[i] * (brPsi2StoJpsipipluspiminus / brX3842toJpsipipluspiminus) * brX3842toPsi2Sgamma;
	}

	auto* statGraph_lhcb = myStatGraph(title, nPtPoints_X3872_lhcb8TeV, ptBinning_X3872_lhcb8TeV, frac_lhcb, error_lhcb, colorLHCb, markerLHCb);

	statGraph_lhcb->Draw("PZ");

	/// legend

	auto* legend = new TLegend(.17, .92, .35, .72, Form("with BR(X(3872) #rightarrow #psi(2S) + #gamma) = (%1.1f #pm %1.1f)%%", brX3842toPsi2Sgamma, systX3842toPsi2Sgamma));
	legend->AddEntry(statGraph_atlas, "ATLAS 8 TeV, |y| < 0.75", "p");
	legend->AddEntry(statGraph_lhcb, "LHCb 8 TeV, 2.0 < y < 4.5", "p");

	legend->Draw();

	canv->SaveAs("figures/psi2SFeedDowns.png", "RECREATE");
	canv->Close();
}
