TCanvas* myCanvas(const char* name) {
	auto* c = new TCanvas(name, "", 800, 600);
	c->SetFillColor(0);
	return c;
}

const Color_t color1S = kRed;
const Color_t color2S = kAzure + 1;
const Color_t color3S = kGreen + 2;

const Color_t color2Sto1S = kViolet - 8;
const Color_t color3Sto1S = kOrange + 1;
const Color_t color3Sto2S = kTeal + 2;

const Int_t markerATLAS = 21;
const Int_t markerCMS = 20;
const Int_t markerLHCb = 22;

TGraphErrors* myStatGraph(const char* title, Int_t nPoints, Float_t xBinning[],
                          Float_t y[], Float_t yErr[], Color_t color = kRed,
                          Int_t markerStyle = 20) {
	Float_t x[nPoints], xErr[nPoints];

	for (Int_t i = 0; i < nPoints; i++) {
		x[i] = (xBinning[i + 1] + xBinning[i]) / 2;
		xErr[i] = (xBinning[i + 1] - xBinning[i]) / 2;
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

TGraphErrors* mySystGraph(Int_t nPoints, Float_t xBinning[], Float_t xErrorWidth, Float_t y[],
                          Float_t yErr[], Color_t color = kRed) {
	Float_t x[nPoints], xErr[nPoints];

	for (Int_t i = 0; i < nPoints; i++) {
		x[i] = (xBinning[i + 1] + xBinning[i]) / 2;
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
	legend->SetFillStyle(0);
	legend->AddEntry(graph, text, opt);

	legend->Draw();
}

TGraph* myGraph(Int_t nPoints, Float_t x[], Float_t y[], Color_t color = kBlack,
                Int_t lineStyle = 1) {
	TGraph* graph = new TGraph(nPoints, x, y);
	graph->SetLineWidth(2);
	graph->SetLineColor(color);
	graph->SetLineStyle(lineStyle);

	return graph;
}
