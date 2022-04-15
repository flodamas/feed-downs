#ifdef __CLING__

#include "../tools/Cosmetics.h"
#include "../tools/Graph.h"

#include "data/upsilonCMS7TeV.C"
#include "data/upsilonATLAS7TeV.C"
#include "data/upsilonLHCb7and8TeV.C"
#include "data/upsilonLHCb13TeV.C"

#endif

// Cross-section ratios as a function of rapidity to check the non-dependence

const Float_t xErrorWidth = 0.1;

TFitResultPtr getFitResult(TGraphErrors* graphCMS, TGraphErrors* graphLHCb) {
	Int_t nCMSPoints = graphCMS->GetN(), nLHCbPoints = graphLHCb->GetN();

	Int_t nDataPoints = nCMSPoints + nLHCbPoints;

	Float_t xBinning[nDataPoints + 1], dataPoints[nDataPoints], errorPoints[nDataPoints];

	for (Int_t i = 0; i < nCMSPoints; i++) {
		xBinning[i] = graphCMS->GetXaxis()->GetBinLowEdge(i);
		xBinning[i + 1] = graphCMS->GetXaxis()->GetBinUpEdge(i);

		dataPoints[i] = graphCMS->GetPointY(i);

		errorPoints[i] = graphCMS->GetErrorY(i);
	}

	for (Int_t i = 0; i < nLHCbPoints; i++) {
		xBinning[i + nCMSPoints] = graphLHCb->GetXaxis()->GetBinLowEdge(i);
		xBinning[i + nCMSPoints + 1] = graphLHCb->GetXaxis()->GetBinUpEdge(i);

		dataPoints[i + nCMSPoints] = graphLHCb->GetPointY(i);

		errorPoints[i + nCMSPoints] = graphLHCb->GetErrorY(i);
	}

	auto* dataPointsGraph = myStatGraph("", nDataPoints, xBinning, dataPoints, errorPoints);

	TF1* func = new TF1("pol0", "pol0", 0, 4.5);

	auto fitResult = dataPointsGraph->Fit(func, "QIEMS");

	cout << " chi2 / ndof = " << fitResult->Chi2() << " / " << fitResult->Ndf() << " = " << fitResult->Chi2() / fitResult->Ndf() << endl;

	for (Int_t i = 0; i < func->GetNpar(); i++) {
		cout << "Parameter " << i << " = " << func->GetParameter(i) << " +/- " << func->GetParError(i) << endl;
	}

	return fitResult;
}

void rapidityRatios() {
	auto* canvas = Canvas("canvas");

	const char* title = ";|#it{y} |;BR #times cross-section ratio";

	/// mid-rapidity measurements (either ATLAS or CMS)

	// Y(2S)-to-Y(1S)

	const Int_t nPoints_mid2Sover1S = sizeof(rapidityBinning_2Sover1S_cms7TeV) / sizeof(Float_t) - 1;

	Float_t rapidDiff_2Sover1S_cms7TeV[nPoints_mid2Sover1S], statRapidDiff_2Sover1S_cms7TeV[nPoints_mid2Sover1S];

	for (Int_t i = 0; i < nPoints_mid2Sover1S; i++) {
		rapidDiff_2Sover1S_cms7TeV[i] = dy2S_cms7TeV[i] / (dy1S_for2S_cms7TeV[i]);

		statRapidDiff_2Sover1S_cms7TeV[i] = rapidDiff_2Sover1S_cms7TeV[i] * TMath::Hypot(stat_dy2S_cms7TeV[i] / dy2S_cms7TeV[i], stat_dy1S_for2S_cms7TeV[i] / dy1S_for2S_cms7TeV[i]);
	}

	auto* statGraph_mid2Sto1S = StatGraph(title, nPoints_mid2Sover1S, rapidityBinning_2Sover1S_cms7TeV, rapidDiff_2Sover1S_cms7TeV, statRapidDiff_2Sover1S_cms7TeV, color2Sto1S + 1, markerCMS);

	// Y(3S)-to-Y(1S)

	const Int_t nPoints_mid3Sover1S = sizeof(rapidityBinning_3Sover1S_cms7TeV) / sizeof(Float_t) - 1;

	Float_t rapidDiff_3Sover1S_cms7TeV[nPoints_mid3Sover1S], statRapidDiff_3Sover1S_cms7TeV[nPoints_mid3Sover1S];

	for (Int_t i = 0; i < nPoints_mid3Sover1S; i++) {
		rapidDiff_3Sover1S_cms7TeV[i] = dy3S_cms7TeV[i] / dy1S_for3S_cms7TeV[i];

		statRapidDiff_3Sover1S_cms7TeV[i] = rapidDiff_3Sover1S_cms7TeV[i] * TMath::Hypot(stat_dy3S_cms7TeV[i] / dy3S_cms7TeV[i], stat_dy1S_for3S_cms7TeV[i] / dy1S_for3S_cms7TeV[i]);
	}

	auto* statGraph_mid3Sto1S = StatGraph(title, nPoints_mid3Sover1S, rapidityBinning_3Sover1S_cms7TeV, rapidDiff_3Sover1S_cms7TeV, statRapidDiff_3Sover1S_cms7TeV, color3Sto1S - 1, markerCMS);

	// Y(3S)-to-Y(2S)

	const Int_t nPoints_mid3Sover2S = sizeof(rapidityBinning_3Sover2S_cms7TeV) / sizeof(Float_t) - 1;

	Float_t rapidDiff_3Sover2S_cms7TeV[nPoints_mid3Sover2S], statRapidDiff_3Sover2S_cms7TeV[nPoints_mid3Sover2S];

	for (Int_t i = 0; i < nPoints_mid3Sover2S; i++) {
		rapidDiff_3Sover2S_cms7TeV[i] = dy3S_cms7TeV[i] / dy2S_for3S_cms7TeV[i];

		statRapidDiff_3Sover2S_cms7TeV[i] = rapidDiff_3Sover2S_cms7TeV[i] * TMath::Hypot(stat_dy3S_cms7TeV[i] / dy3S_cms7TeV[i], stat_dy2S_for3S_cms7TeV[i] / dy2S_for3S_cms7TeV[i]);
	}

	auto* statGraph_mid3Sto2S = StatGraph(title, nPoints_mid3Sover2S, rapidityBinning_3Sover2S_cms7TeV, rapidDiff_3Sover2S_cms7TeV, statRapidDiff_3Sover2S_cms7TeV, color3Sto2S - 1, markerCMS);

	/// forward rapidity LHCb measurements
	const Int_t nPoints_lhcb = sizeof(rapidityBinning_lhcb7and8TeV) / sizeof(Float_t) - 1;

	// Y(2S)-to-Y(1S)

	auto* statGraph_lhcb2Sto1S = StatGraph(title, nPoints_lhcb, rapidityBinning_lhcb7and8TeV, rapidDiff_2Sto1S_lhcb7TeV, errorRapidDiff_2Sto1S_lhcb7TeV, color2Sto1S, markerLHCb);

	// Y(3S)-to-Y(1S)

	auto* statGraph_lhcb3Sto1S = StatGraph(title, nPoints_lhcb, rapidityBinning_lhcb7and8TeV, rapidDiff_3Sto1S_lhcb7TeV, errorRapidDiff_3Sto1S_lhcb7TeV, color3Sto1S, markerLHCb);

	// Y(3S)-to-Y(2S)

	auto* statGraph_lhcb3Sto2S = StatGraph(title, nPoints_lhcb, rapidityBinning_lhcb7and8TeV, rapidDiff_3Sto2S_lhcb7TeV, errorRapidDiff_3Sto2S_lhcb7TeV, color3Sto2S, markerLHCb);

	/// draw

	// graphs
	statGraph_mid2Sto1S->GetXaxis()->SetLimits(0, 4.5);
	statGraph_mid2Sto1S->SetMaximum(.9);
	statGraph_mid2Sto1S->Draw("APZ");
	statGraph_mid3Sto1S->Draw("PZ");
	statGraph_mid3Sto2S->Draw("PZ");

	statGraph_lhcb2Sto1S->Draw("PZ");
	statGraph_lhcb3Sto1S->Draw("PZ");
	statGraph_lhcb3Sto2S->Draw("PZ");

	// legend

	Float_t xUpsi = .2, xCMS = .43, xLHCb = .53, xFit = .62;

	Float_t yHeader = .9, y3Sto2S = yHeader - .06, y2Sto1S = y3Sto2S - .06, y3Sto1S = y2Sto1S - .06;

	drawHeaderLegend("#sqrt{#it{s}} = 7 TeV", xUpsi, yHeader);
	drawHeaderLegend("#varUpsilon(3S) / #varUpsilon(2S)", xUpsi, y3Sto2S);
	drawHeaderLegend("#varUpsilon(2S) / #varUpsilon(1S)", xUpsi, y2Sto1S);
	drawHeaderLegend("#varUpsilon(3S) / #varUpsilon(1S)", xUpsi, y3Sto1S);

	drawHeaderLegend("CMS", xCMS - .02, yHeader);
	drawLegend(statGraph_mid3Sto2S, " ", xCMS, y3Sto2S, "pl");
	drawLegend(statGraph_mid2Sto1S, " ", xCMS, y2Sto1S, "pl");
	drawLegend(statGraph_mid3Sto1S, " ", xCMS, y3Sto1S, "pl");

	drawHeaderLegend("LHCb", xLHCb - .02, yHeader);
	drawLegend(statGraph_lhcb3Sto2S, " ", xLHCb, y3Sto2S, "pl");
	drawLegend(statGraph_lhcb2Sto1S, " ", xLHCb, y2Sto1S, "pl");
	drawLegend(statGraph_lhcb3Sto1S, " ", xLHCb, y3Sto1S, "pl");

	drawHeaderLegend("constant fit (#chi^{2} / n_{d.o.f})", xFit, yHeader);

	/// fit
	cout << endl
	     << "Y(3S) / Y(2S) fit:";
	auto fit3Sto2S = getFitResult(statGraph_mid3Sto2S, statGraph_lhcb3Sto2S);
	drawHeaderLegend(Form("%.3f #pm%.3f (%.1f / %d)", fit3Sto2S->Value(0), fit3Sto2S->ParError(0), fit3Sto2S->Chi2(), fit3Sto2S->Ndf()), xFit, y3Sto2S);

	cout << endl
	     << "Y(2S) / Y(1S) fit:";
	auto fit2Sto1S = getFitResult(statGraph_mid2Sto1S, statGraph_lhcb2Sto1S);
	drawHeaderLegend(Form("%.3f #pm%.3f (%.1f / %d)", fit2Sto1S->Value(0), fit2Sto1S->ParError(0), fit2Sto1S->Chi2(), fit2Sto1S->Ndf()), xFit, y2Sto1S);

	cout << endl
	     << "Y(3S) / Y(1S) fit:";
	auto fit3Sto1S = getFitResult(statGraph_mid3Sto1S, statGraph_lhcb3Sto1S);
	drawHeaderLegend(Form("%.3f #pm%.3f (%.1f / %d)", fit3Sto1S->Value(0), fit3Sto1S->ParError(0), fit3Sto1S->Chi2(), fit3Sto1S->Ndf()), xFit, y3Sto1S);

	saveAs(canvas, "rapidity7TeV_CMS_LHCb");
}
