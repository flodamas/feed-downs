TCanvas *myCanvas(const char *name) {
  auto *c = new TCanvas(name, "", 700, 600);
  c->SetFillColor(0);
  return c;
}

const Float_t xErrorWidth = 0.5;

TGraphErrors *myStatGraph(const char *title, Int_t nPoints, Float_t x[],
                          Float_t y[], Float_t yErr[], Color_t color = kRed,
                          Int_t markerStyle = 20) {

  Float_t xErr[nPoints];

  for (Int_t i = 0; i < nPoints; i++)
    xErr[i] = 0;

  auto *graph = new TGraphErrors(nPoints, x, y, xErr, yErr);

  graph->SetTitle(title);
  graph->SetMarkerStyle(markerStyle);
  graph->SetMarkerColor(color);
  graph->SetLineColor(color); // for error bars
  graph->SetLineWidth(2);
  graph->SetMinimum(0.);
  graph->SetMaximum(50);

  graph->GetXaxis()->SetLimits(0, 40);

  return graph;
}

TGraphErrors *mySystGraph(Int_t nPoints, Float_t x[], Float_t y[],
                          Float_t yErr[], Color_t color = kRed) {
  Float_t xErr[nPoints];

  for (Int_t i = 0; i < nPoints; i++)
    xErr[i] = xErrorWidth;

  auto *graph = new TGraphErrors(nPoints, x, y, xErr, yErr);

  graph->SetFillStyle(0);
  graph->SetLineColor(color); // box

  return graph;
}

void drawHeaderLegend(const char *text, Float_t x = 0.2, Float_t y = 0.9) {
  TLatex *header = new TLatex();
  header->SetTextAlign(12);

  header->DrawLatexNDC(x, y, text);
}

void drawLegend(TObject *graph, const char *text, Float_t x, Float_t y = .84,
                const char *opt = "p") {
  TLegend *legend = new TLegend(x, y + 0.03, x + 0.2, y - 0.03);
  // legend->SetTextAlign(12);
  legend->SetFillStyle(0);
  legend->AddEntry(graph, text, opt);

  legend->Draw();
}

TGraph *myGraph(Int_t nPoints, Float_t x[], Float_t y[], Color_t color = kBlack,
                Int_t lineStyle = 1) {
  TGraph *graph = new TGraph(nPoints, x, y);
  graph->SetLineWidth(2);
  graph->SetLineColor(color);
  graph->SetLineStyle(lineStyle);

  return graph;
}
