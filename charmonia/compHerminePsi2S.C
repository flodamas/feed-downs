#ifdef __CLING__

#include "../tools/Cosmetics.h"
#include "../tools/Graph.h"

#include "data/BranchingRatios.h"

#include "data/psi2StoJpsiALICE7TeV.C"
#include "data/chicToJpsiLHCb7TeV.C"
#include "data/chicToJpsiATLAS7TeV.C"

#include "data/psi2StoJpsiLHCb13TeV.C"
#include "data/psi2StoJpsiCMS7TeV.C"
#include "data/psi2StoJpsiCMS13TeV.C"

#endif

Float_t xErrorWidth = .3;

const Color_t myColor = kRed;

void compHerminePsi2S() {
	auto* canv = Canvas("canv", 900);
	canv->SetGridy();

	const char* title = ";#it{p}_{T}^{J/#psi} (GeV);#psi(2S)-to-J/#psi feed-down fractions (in %)";

	/// my results

	Float_t myBR = brPsi2StoJpsianything;

	// LHCb measurements at 13 TeV, already corrected for dimuon branching fractions!!!

	const Int_t nPointsPsi2S_lhcb = nPtPoints_psi2S_lhcb13TeV;

	Float_t fracPsi2SToJpsi_lhcb[nPointsPsi2S_lhcb], errorPsi2SToJpsi_lhcb[nPointsPsi2S_lhcb];

	for (Int_t i = 0; i < nPointsPsi2S_lhcb; i++) {
		fracPsi2SToJpsi_lhcb[i] = ptDiffRatio_psi2S_lhcb13TeV[i] * myBR;

		errorPsi2SToJpsi_lhcb[i] = errorPtDiffRatio_psi2S_lhcb13TeV[i] * myBR;
	}

	auto* statPsi2S_lhcb = StatGraph(title, nPointsPsi2S_lhcb, ptBinning_psi2S_lhcb13TeV, fracPsi2SToJpsi_lhcb, errorPsi2SToJpsi_lhcb, myColor, markerLHCb);

	statPsi2S_lhcb->SetMaximum(40);
	statPsi2S_lhcb->GetXaxis()->SetLimits(0, 45);

	statPsi2S_lhcb->Draw("APZ");

	// CMS measurements at 7 TeV (4.90 fb-1), reported in percent!!

	const Int_t nPointsPsi2S_cms = nPtPoints_psi2S_cms7TeV;

	Float_t fracCMS_mine[nPointsPsi2S_cms], statFracCMS_mine[nPointsPsi2S_cms], systFracCMS_mine[nPointsPsi2S_cms];

	for (Int_t i = 0; i < nPointsPsi2S_cms; i++) {
		fracCMS_mine[i] = ptDiffRatio_psi2S_cms7TeV[i] * (brJpsitomumu / brPsi2Stomumu) * myBR / 100.;

		statFracCMS_mine[i] = statPtRatio_psi2S_cms7TeV[i] * (brJpsitomumu / brPsi2Stomumu) * myBR / 100.;

		systFracCMS_mine[i] = systPtRatio_psi2S_cms7TeV[i] * (brJpsitomumu / brPsi2Stomumu) * myBR / 100.;
	}

	auto* statCMS_mine = AsymmStatGraph(title, nPointsPsi2S_cms, meanPt_psi2S_cms7TeV, ptBinning_psi2S_cms7TeV, fracCMS_mine, statFracCMS_mine, statFracCMS_mine, myColor + 1, markerCMS);

	statCMS_mine->Draw("PZ");

	auto* systCMS_mine = DoubleAsymmSystGraph(nPointsPsi2S_cms, meanPt_psi2S_cms7TeV, xErrorWidth, fracCMS_mine, systFracCMS_mine, systFracCMS_mine, myColor + 1);

	systCMS_mine->Draw("5");

	/// Hermine's feed-down fractions (based on the plot in slide 17 of https://indico.cern.ch/event/278195/contributions/628553/attachments/508351/701717/HKWoehri-QWG2014.pdf)

	Float_t brHermine = brPsi2StoJpsineutrals;

	// inclusive ALICE data at 7 TeV, already corrected for dimuon branching fractions!!!

	const Int_t nPointsPsi2S_alice = nPtPoints_psi2S_alice7TeV;

	Float_t fracALICE_hermine[nPointsPsi2S_alice], statFracALICE_hermine[nPointsPsi2S_alice], systFracALICE_hermine[nPointsPsi2S_alice];

	for (Int_t i = 0; i < nPointsPsi2S_alice; i++) {
		fracALICE_hermine[i] = ptDiffRatio_psi2S_alice7TeV[i] * brHermine;

		statFracALICE_hermine[i] = statPtDiffRatio_psi2S_alice7TeV[i] * brHermine;

		systFracALICE_hermine[i] = systPtDiffRatio_psi2S_alice7TeV[i] * brHermine;
	}

	auto* statALICE_hermine = StatGraph(title, nPointsPsi2S_alice, ptBinning_psi2S_alice7TeV, fracALICE_hermine, statFracALICE_hermine, kBlack, markerLHCb);

	statALICE_hermine->Draw("PZ");

	auto* systALICE_hermine = SystGraph(nPointsPsi2S_alice, ptBinning_psi2S_alice7TeV, xErrorWidth, fracALICE_hermine, systFracALICE_hermine, kBlack);

	systALICE_hermine->Draw("5");

	// CMS measurements at 7 TeV (4.90 fb-1), reported in percent!!

	const Int_t nPointsCMS_hermine = 10; // only plot the 10 points in 10 < pT < 20 GeV as in her figure

	Float_t fracCMS_hermine[nPointsCMS_hermine], statFracCMS_hermine[nPointsCMS_hermine], systFracCMS_hermine[nPointsCMS_hermine];

	for (Int_t i = 0; i < nPointsCMS_hermine; i++) {
		fracCMS_hermine[i] = ptDiffRatio_psi2S_cms7TeV[i] * (brJpsitomumu / brPsi2Stomumu) * brHermine / 100.;

		statFracCMS_hermine[i] = statPtRatio_psi2S_cms7TeV[i] * (brJpsitomumu / brPsi2Stomumu) * brHermine / 100.;

		systFracCMS_hermine[i] = systPtRatio_psi2S_cms7TeV[i] * (brJpsitomumu / brPsi2Stomumu) * brHermine / 100.;
	}

	auto* statCMS_hermine = StatGraph(title, nPointsCMS_hermine, ptBinning_psi2S_cms7TeV, fracCMS_hermine, statFracCMS_hermine, kBlue, markerCMS);

	statCMS_hermine->Draw("PZ");

	auto* systCMS_hermine = SystGraph(nPointsCMS_hermine, ptBinning_psi2S_cms7TeV, xErrorWidth, fracCMS_hermine, systFracCMS_hermine, kBlue);

	systCMS_hermine->Draw("5");

	/// legend

	auto* myLegend = new TLegend(.17, .93, .35, .70, "My results, BR(#psi(2S) #rightarrow J/#psi + anything) = 61.4%");
	myLegend->AddEntry(statPsi2S_lhcb, "prompt, LHCb 13 TeV", "p");
	myLegend->AddEntry(statCMS_mine, "prompt, CMS 7 TeV (4.90 fb^{-1})", "p");
	myLegend->Draw();

	auto* hermineLegend = new TLegend(.55, .45, .75, .25, "Hermine's results");
	hermineLegend->AddEntry(statALICE_hermine, "inclusive, ALICE 7 TeV", "p");
	hermineLegend->AddEntry(statCMS_hermine, "prompt, CMS 7 TeV", "p");
	hermineLegend->Draw();
	drawHeaderLegend(Form("reproduced with BR(#psi(2S) #rightarrow J/#psi + neutrals) = %2.1f%%", brHermine), .25, .2);

	saveCanvas(canv, "herminePsi2S");
}
