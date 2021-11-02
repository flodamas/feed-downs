#ifdef __CLING__

#include "myPlot.C"

#include "data/upsilonCMS7TeV.C"
#include "data/upsilonLHCb7and8TeV.C"
#include "data/upsilonLHCb13TeV.C"

#endif

// Cross-section ratios as a function of rapidity to check the non-dependence

const Float_t xErrorWidth = 0.1;

TFitResultPtr getLHCbFitResult(TGraphErrors* graphLHCb) {
	TF1* func = new TF1("pol0", "pol0", 2, 4.5);

	auto fitResult = graphLHCb->Fit(func, "QIEMSN0");

	cout << " chi2 / ndof = " << fitResult->Chi2() << " / " << fitResult->Ndf() << " = " << fitResult->Chi2() / fitResult->Ndf() << endl;

	for (Int_t i = 0; i < func->GetNpar(); i++) {
		cout << "Parameter " << i << " = " << func->GetParameter(i) << " +/- " << func->GetParError(i) << endl;
	}

	return fitResult;
}

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

void energyDoubleRatios_rapidity() {
	auto* canvas = myCanvas("canvas");

	const char* title = ";|#it{y} |;13-to-8 TeV cross-section double ratio";

	/// forward rapidity LHCb measurements
	const Int_t nPoints_lhcb = sizeof(rapidityBinning_lhcb13TeV) / sizeof(Float_t) - 1;

	Float_t rapidDiff_2Sto1S_lhcb[nPoints_lhcb], errorRapidDiff_2Sto1S_lhcb[nPoints_lhcb], rapidDiff_3Sto1S_lhcb[nPoints_lhcb], errorRapidDiff_3Sto1S_lhcb[nPoints_lhcb], rapidDiff_3Sto2S_lhcb[nPoints_lhcb], errorRapidDiff_3Sto2S_lhcb[nPoints_lhcb];

	Float_t binning2Sto1S[nPoints_lhcb + 1], binning3Sto2S[nPoints_lhcb + 1];

	binning2Sto1S[0] = rapidityBinning_lhcb13TeV[0] - .02;
	binning3Sto2S[0] = rapidityBinning_lhcb13TeV[0] + .02;

	for (Int_t i = 0; i < nPoints_lhcb; i++) {
		binning2Sto1S[i + 1] = rapidityBinning_lhcb13TeV[i + 1] - .02;

		rapidDiff_2Sto1S_lhcb[i] = rapidDiff_2S_lhcb13to8TeV[i] / rapidDiff_1S_lhcb13to8TeV[i];

		errorRapidDiff_2Sto1S_lhcb[i] = rapidDiff_2Sto1S_lhcb[i] * errorRapidDiff_1S_lhcb13to8TeV[i] / rapidDiff_1S_lhcb13to8TeV[i];

		//errorRapidDiff_2Sto1S_lhcb[i] = 0;

		rapidDiff_3Sto1S_lhcb[i] = rapidDiff_3S_lhcb13to8TeV[i] / rapidDiff_1S_lhcb13to8TeV[i];

		errorRapidDiff_3Sto1S_lhcb[i] = rapidDiff_3Sto1S_lhcb[i] * errorRapidDiff_1S_lhcb13to8TeV[i] / rapidDiff_1S_lhcb13to8TeV[i];

		//errorRapidDiff_3Sto1S_lhcb[i] = 0.;

		binning3Sto2S[i + 1] = rapidityBinning_lhcb13TeV[i + 1] + .02;

		rapidDiff_3Sto2S_lhcb[i] = rapidDiff_3S_lhcb13to8TeV[i] / rapidDiff_2S_lhcb13to8TeV[i];

		errorRapidDiff_3Sto2S_lhcb[i] = rapidDiff_3Sto2S_lhcb[i] * errorRapidDiff_2S_lhcb13to8TeV[i] / rapidDiff_2S_lhcb13to8TeV[i];

		//errorRapidDiff_3Sto2S_lhcb[i] = 0.;
	}

	// Y(2S)-to-Y(1S)

	auto* statGraph_lhcb2Sto1S = myStatGraph(title, nPoints_lhcb, binning2Sto1S, rapidDiff_2Sto1S_lhcb, errorRapidDiff_2Sto1S_lhcb, color2Sto1S, markerLHCb);

	// Y(3S)-to-Y(1S)

	auto* statGraph_lhcb3Sto1S = myStatGraph(title, nPoints_lhcb, rapidityBinning_lhcb13TeV, rapidDiff_3Sto1S_lhcb, errorRapidDiff_3Sto1S_lhcb, color3Sto1S, markerLHCb);

	// Y(3S)-to-Y(2S)

	auto* statGraph_lhcb3Sto2S = myStatGraph(title, nPoints_lhcb, binning3Sto2S, rapidDiff_3Sto2S_lhcb, errorRapidDiff_3Sto2S_lhcb, color3Sto2S, markerLHCb);

	/// draw

	// graphs
	/*
	statGraph_mid2Sto1S->GetXaxis()->SetLimits(0, 4.5);
	statGraph_mid2Sto1S->SetMaximum(.9);
	statGraph_mid2Sto1S->Draw("APZ");
	statGraph_mid3Sto1S->Draw("PZ");
	statGraph_mid3Sto2S->Draw("PZ");
*/
	statGraph_lhcb2Sto1S->SetMinimum(0.9);
	statGraph_lhcb2Sto1S->SetMaximum(1.3);
	statGraph_lhcb2Sto1S->Draw("APZ");
	statGraph_lhcb3Sto1S->Draw("PZ");
	statGraph_lhcb3Sto2S->Draw("PZ");

	// legend

	Float_t xUpsi = .2, xCMS = .43, xLHCb = .53, xFit = .62;

	Float_t yHeader = .9, y3Sto2S = yHeader - .06, y3Sto1S = y3Sto2S - .06, y2Sto1S = y3Sto1S - .06;

	drawHeaderLegend("#sqrt{#it{s}} = 13, 8 TeV", xUpsi, yHeader);
	drawHeaderLegend("#varUpsilon(3S) / #varUpsilon(2S)", xUpsi, y3Sto2S);
	drawHeaderLegend("#varUpsilon(3S) / #varUpsilon(1S)", xUpsi, y3Sto1S);
	drawHeaderLegend("#varUpsilon(2S) / #varUpsilon(1S)", xUpsi, y2Sto1S);

	//drawHeaderLegend("CMS", xCMS - .02, yHeader);
	//	drawLegend(statGraph_mid3Sto2S, " ", xCMS, y3Sto2S, "pl");
	//	drawLegend(statGraph_mid2Sto1S, " ", xCMS, y2Sto1S, "pl");
	//	drawLegend(statGraph_mid3Sto1S, " ", xCMS, y3Sto1S, "pl");

	drawHeaderLegend("LHCb", xLHCb - .02, yHeader);
	drawLegend(statGraph_lhcb2Sto1S, " ", xLHCb, y2Sto1S, "pl");
	drawLegend(statGraph_lhcb3Sto1S, " ", xLHCb, y3Sto1S, "pl");
	drawLegend(statGraph_lhcb3Sto2S, " ", xLHCb, y3Sto2S, "pl");

	drawHeaderLegend("constant fit (#chi^{2} / n_{d.o.f})", xFit, yHeader);

	/// fit
	cout << endl
	     << "Y(3S) / Y(2S) fit:";
	auto fit3Sto2S = getLHCbFitResult(statGraph_lhcb3Sto2S);
	drawHeaderLegend(Form("%.3f #pm%.3f (%.1f / %d)", fit3Sto2S->Value(0), fit3Sto2S->ParError(0), fit3Sto2S->Chi2(), fit3Sto2S->Ndf()), xFit, y3Sto2S);

	cout << endl
	     << "Y(2S) / Y(1S) fit:";
	auto fit2Sto1S = getLHCbFitResult(statGraph_lhcb2Sto1S);
	drawHeaderLegend(Form("%.3f #pm%.3f (%.1f / %d)", fit2Sto1S->Value(0), fit2Sto1S->ParError(0), fit2Sto1S->Chi2(), fit2Sto1S->Ndf()), xFit, y2Sto1S);

	cout << endl
	     << "Y(3S) / Y(1S) fit:";
	auto fit3Sto1S = getLHCbFitResult(statGraph_lhcb3Sto1S);
	drawHeaderLegend(Form("%.3f #pm%.3f (%.1f / %d)", fit3Sto1S->Value(0), fit3Sto1S->ParError(0), fit3Sto1S->Chi2(), fit3Sto1S->Ndf()), xFit, y3Sto1S);

	gPad->RedrawAxis();

	canvas->SaveAs("figures/rapidity13to8TeV.png", "RECREATE");
	canvas->Close();
}
