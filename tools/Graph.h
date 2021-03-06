TCanvas* Canvas(const char* name, Int_t width = 700, Int_t height = 600) {
	auto* c = new TCanvas(name, "", width, height);
	c->SetFillColor(0);
	return c;
}

void saveCanvas(TCanvas* canv, const char* name) {
	canv->Update();
	canv->RedrawAxis();
	canv->SaveAs(Form("figures/%s.png", name), "RECREATE");
	canv->Close();
}

TGraphErrors* StatGraph(const char* title, Int_t nPoints, Float_t xBinning[], Float_t y[], Float_t yErr[], Color_t color = kRed, Int_t markerStyle = 20) {
	Float_t x[nPoints], xErr[nPoints];

	for (Int_t i = 0; i < nPoints; i++) {
		x[i] = (xBinning[i + 1] + xBinning[i]) / 2.;
		xErr[i] = (xBinning[i + 1] - xBinning[i]) / 2.;
	}

	auto* graph = new TGraphErrors(nPoints, x, y, xErr, yErr);

	graph->SetTitle(title);
	graph->SetMarkerStyle(markerStyle);
	graph->SetMarkerColor(color);
	graph->SetLineColor(color); // for error bars
	graph->SetLineWidth(2);

	graph->SetMinimum(0);

	return graph;
}

TGraphErrors* SystGraph(Int_t nPoints, Float_t xBinning[], Float_t xErrorWidth, Float_t y[], Float_t yErr[], Color_t color = kRed) {
	Float_t x[nPoints], xErr[nPoints];

	for (Int_t i = 0; i < nPoints; i++) {
		x[i] = (xBinning[i + 1] + xBinning[i]) / 2.;
		xErr[i] = xErrorWidth;
	}

	auto* graph = new TGraphErrors(nPoints, x, y, xErr, yErr);

	graph->SetLineWidth(0);
	graph->SetFillStyle(1001);
	graph->SetLineColor(color); // box
	//graph->SetFillColor(color);
	graph->SetFillColorAlpha(color, .4);

	return graph;
}

TGraphAsymmErrors* AsymmStatGraph(const char* title, Int_t nPoints, Float_t xMean[], Float_t xBinning[], Float_t y[], Float_t yErrMinus[], Float_t yErrPlus[], Color_t color = kRed, Int_t markerStyle = 20) {
	Float_t xErrMinus[nPoints], xErrPlus[nPoints];

	for (Int_t i = 0; i < nPoints; i++) {
		xErrMinus[i] = (xMean[i] - xBinning[i]);
		xErrPlus[i] = (xBinning[i + 1] - xMean[i]);
	}

	auto* graph = new TGraphAsymmErrors(nPoints, xMean, y, xErrMinus, xErrPlus, yErrMinus, yErrPlus);

	graph->SetTitle(title);
	graph->SetMarkerStyle(markerStyle);
	graph->SetMarkerColor(color);
	graph->SetLineColor(color); // for error bars
	graph->SetLineWidth(2);

	graph->SetMinimum(0);

	return graph;
}

TGraphAsymmErrors* AsymmSystGraph(Int_t nPoints, Float_t xBinning[], Float_t xErrorWidth, Float_t y[], Float_t yErrMinus[], Float_t yErrPlus[], Color_t color = kRed) {
	Float_t x[nPoints], xErr[nPoints];

	for (Int_t i = 0; i < nPoints; i++) {
		x[i] = (xBinning[i + 1] + xBinning[i]) / 2.;
		xErr[i] = xErrorWidth;
	}

	auto* graph = new TGraphAsymmErrors(nPoints, x, y, xErr, xErr, yErrMinus, yErrPlus);

	graph->SetLineWidth(0);
	graph->SetFillStyle(1001);
	graph->SetLineColor(color); // box
	//graph->SetFillColor(color);
	graph->SetFillColorAlpha(color, .4);

	return graph;
}

TGraphAsymmErrors* DoubleAsymmSystGraph(Int_t nPoints, Float_t xMean[], Float_t xErrorWidth, Float_t y[], Float_t yErrMinus[], Float_t yErrPlus[], Color_t color = kRed) {
	Float_t xErr[nPoints];

	for (Int_t i = 0; i < nPoints; i++) {
		xErr[i] = xErrorWidth;
	}

	auto* graph = new TGraphAsymmErrors(nPoints, xMean, y, xErr, xErr, yErrMinus, yErrPlus);

	graph->SetLineWidth(0);
	graph->SetFillStyle(1001);
	graph->SetLineColor(color); // box
	//graph->SetFillColor(color);
	graph->SetFillColorAlpha(color, .5);

	return graph;
}

void drawUnityLine(TCanvas* canvas) {
	canvas->Modified();
	canvas->Update();
	TLine* line = new TLine(canvas->GetUxmin(), 1, canvas->GetUxmax(), 1);
	line->SetLineStyle(2);
	line->SetLineColor(kBlack);
	line->Draw("SAME");
}

void drawHeaderLegend(const char* text, Float_t x = 0.2, Float_t y = 0.9) {
	TLatex* header = new TLatex();
	header->SetTextAlign(12);
	header->SetTextSize(.05);
	header->DrawLatexNDC(x, y, text);
}

void drawLegend(TObject* graph, const char* text, Float_t x, Float_t y = .84,
                const char* opt = "p") {
	TLegend* legend = new TLegend(x, y + 0.03, x + 0.2, y - 0.03);
	// legend->SetTextAlign(12);
	legend->AddEntry(graph, text, opt);

	legend->Draw();
}

TGraph* SimpleGraph(Int_t nPoints, Float_t x[], Float_t y[], Color_t color = kBlack,
                    Int_t lineStyle = 1) {
	TGraph* graph = new TGraph(nPoints, x, y);
	graph->SetLineWidth(2);
	graph->SetLineColor(color);
	graph->SetLineStyle(lineStyle);

	return graph;
}
