#ifdef __CLING__

#include "myPlot.C"

#include "charmonia/branching.C"
#include "charmonia/chicToJpsiLHCb7TeV.C"
#include "charmonia/chicToJpsiATLAS7TeV.C"

#include "charmonia/psi2StoJpsiLHCb13TeV.C"
#include "charmonia/psi2StoJpsiCMS7TeV.C"
#include "charmonia/psi2StoJpsiCMS13TeV.C"

#endif

Float_t xErrorWidth = .3;

const Color_t colorChic = kRed;
const Color_t colorPsi2S = kAzure + 1;

const Int_t markerChic = 20;
const Int_t markerPsi2S = 21;

void jpsiFeedDowns(Bool_t withLegend = kFALSE, Bool_t withLogYaxis = kFALSE) {
	string color = "\033[1;31m";

	auto* canv1S = myCanvas("canv1S");

	if (withLogYaxis) canv1S->SetLogy();

	const char* title = ";#it{p}_{T}^{J/#psi} (GeV);Feed-down fractions to J/#psi (in %)";

	/// Chi_c(1P) first

	// LHCb measurements

	Float_t fracChicToJpsi[nPoints_chic_lhcb7TeV], upStat_fracChicToJpsi[nPoints_chic_lhcb7TeV], downStat_fracChicToJpsi[nPoints_chic_lhcb7TeV], upSyst_fracChicToJpsi[nPoints_chic_lhcb7TeV], downSyst_fracChicToJpsi[nPoints_chic_lhcb7TeV];

	Float_t meanLHCb[nPoints_chic_lhcb7TeV];

	for (Int_t i = 0; i < nPoints_chic_lhcb7TeV; i++) {
		meanLHCb[i] = (ptBinning_chicToJpsi_lhcb7TeV[i] + ptBinning_chicToJpsi_lhcb7TeV[i + 1]) / 2.;

		fracChicToJpsi[i] = 100. * ratioChicToJpsi_lhcb7TeV[i];

		upStat_fracChicToJpsi[i] = 100. * upStat_ratioChicToJpsi_lhcb7TeV[i];
		downStat_fracChicToJpsi[i] = 100. * downStat_ratioChicToJpsi_lhcb7TeV[i];

		upSyst_fracChicToJpsi[i] = 100. * TMath::Hypot(upSyst_ratioChicToJpsi_lhcb7TeV[i], 0.);     // upPolSyst_ratioChicToJpsi_lhcb7TeV[i]);
		downSyst_fracChicToJpsi[i] = 100. * TMath::Hypot(downSyst_ratioChicToJpsi_lhcb7TeV[i], 0.); // downPolSyst_ratioChicToJpsi_lhcb7TeV[i]);
	}

	auto* statChic_lhcb =
	  statAsymmGraph(title, nPoints_chic_lhcb7TeV, meanLHCb, ptBinning_chicToJpsi_lhcb7TeV, fracChicToJpsi, downStat_fracChicToJpsi, upStat_fracChicToJpsi, colorChic, markerChic);

	auto* systChic_lhcb =
	  systAsymmGraph(nPoints_chic_lhcb7TeV, ptBinning_chicToJpsi_lhcb7TeV, xErrorWidth, fracChicToJpsi, downSyst_fracChicToJpsi, upSyst_fracChicToJpsi, colorChic);

	statChic_lhcb->SetMinimum(0);
	statChic_lhcb->SetMaximum((withLegend) ? 45 : 35);
	statChic_lhcb->GetXaxis()->SetLimits(0, 40);

	if (withLogYaxis) {
		statChic_lhcb->SetMinimum(.4);
		statChic_lhcb->SetMaximum(1000);
	}

	statChic_lhcb->Draw("APZ");
	systChic_lhcb->Draw("5");

	// ATLAS measurements

	Float_t fracChicToJpsi_atlas[nPoints_chic_atlas7TeV], stat_fracChicToJpsi_atlas[nPoints_chic_atlas7TeV], upSyst_fracChicToJpsi_atlas[nPoints_chic_atlas7TeV], downSyst_fracChicToJpsi_atlas[nPoints_chic_atlas7TeV];

	for (Int_t i = 0; i < nPoints_chic_atlas7TeV; i++) {
		fracChicToJpsi_atlas[i] = 100. * ratioChicToJpsi_atlas7TeV[i];

		stat_fracChicToJpsi_atlas[i] = 100. * stat_ratioChicToJpsi_atlas7TeV[i];

		upSyst_fracChicToJpsi_atlas[i] = 100. * TMath::Hypot(syst_ratioChicToJpsi_atlas7TeV[i], 0.);   //upPolSyst_ratioChicToJpsi_atlas7TeV[i]);
		downSyst_fracChicToJpsi_atlas[i] = 100. * TMath::Hypot(syst_ratioChicToJpsi_atlas7TeV[i], 0.); //downPolSyst_ratioChicToJpsi_atlas7TeV[i]);
	}

	auto* statChic_atlas = myStatGraph(title, nPoints_chic_atlas7TeV, ptBinning_chicToJpsi_atlas7TeV, fracChicToJpsi_atlas, stat_fracChicToJpsi_atlas, colorChic + 1, markerATLAS);

	statChic_atlas->Draw("PZ");

	auto* systChic_atlas = systAsymmGraph(nPoints_chic_atlas7TeV, ptBinning_chicToJpsi_atlas7TeV, xErrorWidth, fracChicToJpsi_atlas, downSyst_fracChicToJpsi_atlas, upSyst_fracChicToJpsi_atlas, colorChic + 1);

	systChic_atlas->Draw("5");

	/// from Psi(2S)

	// LHCb measurements at 13 TeV, already corrected for dimuon branching fractions!!!

	const Int_t nPointsPsi2S_lhcb = nPtPoints_psi2S_lhcb13TeV;

	Float_t fracPsi2SToJpsi_lhcb[nPointsPsi2S_lhcb], errorPsi2SToJpsi_lhcb[nPointsPsi2S_lhcb];

	for (Int_t i = 0; i < nPointsPsi2S_lhcb; i++) {
		fracPsi2SToJpsi_lhcb[i] = ptDiffRatio_psi2S_lhcb13TeV[i] * brPsi2StoJpsianything;

		errorPsi2SToJpsi_lhcb[i] = errorPtDiffRatio_psi2S_lhcb13TeV[i] * brPsi2StoJpsianything;
	}

	auto* statPsi2S_lhcb = myStatGraph(title, nPointsPsi2S_lhcb, ptBinning_psi2S_lhcb13TeV, fracPsi2SToJpsi_lhcb, errorPsi2SToJpsi_lhcb, colorPsi2S, markerLHCb);

	statPsi2S_lhcb->Draw("PZ");

	// CMS measurements at 7 TeV (4.90 fb-1), reported in percent!!

	const Int_t nPointsPsi2S_cms = nPtPoints_psi2S_cms7TeV;

	Float_t fracPsi2SToJpsi_cms[nPointsPsi2S_cms], statPsi2SToJpsi_cms[nPointsPsi2S_cms], systPsi2SToJpsi_cms[nPointsPsi2S_cms];

	for (Int_t i = 0; i < nPointsPsi2S_cms; i++) {
		fracPsi2SToJpsi_cms[i] = ptDiffRatio_psi2S_cms7TeV[i] * (brJpsitomumu / brPsi2Stomumu) * brPsi2StoJpsianything / 100.;

		statPsi2SToJpsi_cms[i] = statPtRatio_psi2S_cms7TeV[i] * (brJpsitomumu / brPsi2Stomumu) * brPsi2StoJpsianything / 100.;

		systPsi2SToJpsi_cms[i] = systPtRatio_psi2S_cms7TeV[i] * (brJpsitomumu / brPsi2Stomumu) * brPsi2StoJpsianything / 100.;

		//statPsi2SToJpsi_cms[i] = fracPsi2SToJpsi_cms[i] * statPercPtRatio_psi2S_cms13TeV[i] / 100.;
		//systPsi2SToJpsi_cms[i] = fracPsi2SToJpsi_cms[i] * systPercPtRatio_psi2S_cms13TeV[i] / 100.;
	}

	auto* statPsi2S_cms = statAsymmGraph(title, nPointsPsi2S_cms, meanPt_psi2S_cms7TeV, ptBinning_psi2S_cms7TeV, fracPsi2SToJpsi_cms, statPsi2SToJpsi_cms, statPsi2SToJpsi_cms, colorPsi2S + 1, markerCMS);

	statPsi2S_cms->Draw("PZ");

	auto* systPsi2S_cms = systDoubleAsymmGraph(nPointsPsi2S_cms, meanPt_psi2S_cms7TeV, xErrorWidth, fracPsi2SToJpsi_cms, systPsi2SToJpsi_cms, systPsi2SToJpsi_cms, colorPsi2S + 1);

	systPsi2S_cms->Draw("5");

	/// legend

	//if (!withLegend) drawHeaderLegend("7 and 13 TeV pp data", .18, .9);

	auto* legend = new TLegend(.17, .92, .35, .7, "Feed-down to prompt J/#psi from");
	legend->AddEntry(statChic_lhcb, "#chi_{c}(1P), LHCb 7 TeV", "p");
	legend->AddEntry(statChic_atlas, "#chi_{c}(1P), ATLAS 7 TeV", "p");

	legend->AddEntry(statPsi2S_lhcb, "#psi(2S), LHCb 13 TeV", "p");
	legend->AddEntry(statPsi2S_cms, "#psi(2S), CMS 7 TeV (4.90 fb^{#minus 1})", "p");

	if (withLegend) legend->Draw();

	canv1S->SaveAs("figures/jpsiFeedDowns.png", "RECREATE");
	canv1S->Close();
}
