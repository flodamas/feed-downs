#ifdef __CLING__

#include "data/lhcb7and8TeV.C"
#include "myPlot.C"

#endif

const Color_t color1P = kRed;
const Color_t color2P = kAzure + 1;
const Color_t color3P = kGreen + 2;

void drawLHCb() {

  // Feed-downs to Y(1S)
  auto canv1S = myCanvas("canv1S");
  // canv1S->SetLogx();
  // canv1S->SetLogy();

  const char *title1S =
      ";#it{p}_{T}^{#varUpsilon(1S)} (GeV/#it{c});#chi_{b}-to-#varUpsilon(1S) "
      "feed-down fraction (in %)";

  auto stat1Pto1S =
      myStatGraph(title1S, nPoints1Pto1S_lhcb, pt1Pto1S_lhcb,
                  frac1Pto1S_lhcb8TeV, stat1Pto1S_lhcb8TeV, color1P);

  auto syst1Pto1S =
      mySystGraph(nPoints1Pto1S_lhcb, pt1Pto1S_lhcb, frac1Pto1S_lhcb8TeV,
                  syst1Pto1S_lhcb8TeV, color1P);

  stat1Pto1S->Draw("APZ");
  syst1Pto1S->Draw("2");

  auto stat2Pto1S =
      myStatGraph(title1S, nPoints2Pto1S_lhcb, pt2Pto1S_lhcb,
                  frac2Pto1S_lhcb8TeV, stat2Pto1S_lhcb8TeV, color2P, 21);

  auto syst2Pto1S =
      mySystGraph(nPoints2Pto1S_lhcb, pt2Pto1S_lhcb, frac2Pto1S_lhcb8TeV,
                  syst2Pto1S_lhcb8TeV, color2P);

  stat2Pto1S->Draw("PZ");
  syst2Pto1S->Draw("2");

  auto stat3Pto1S =
      myStatGraph(title1S, nPoints3Pto1S_lhcb, pt3Pto1S_lhcb,
                  frac3Pto1S_lhcb8TeV, stat3Pto1S_lhcb8TeV, color3P);

  auto syst3Pto1S =
      mySystGraph(nPoints3Pto1S_lhcb, pt3Pto1S_lhcb, frac3Pto1S_lhcb8TeV,
                  syst3Pto1S_lhcb8TeV, color3P);

  stat3Pto1S->Draw("PZ");
  syst3Pto1S->Draw("2");

  auto *legend1S = new TLegend(.2, .9, .45, .65, "LHCb 8 TeV data");
  legend1S->AddEntry(stat1Pto1S, "#chi_{b}(1P) #rightarrow #varUpsilon(1S)",
                     "p");
  legend1S->AddEntry(stat2Pto1S, "#chi_{b}(2P) #rightarrow #varUpsilon(1S)",
                     "p");
  legend1S->AddEntry(stat3Pto1S, "#chi_{b}(3P) #rightarrow #varUpsilon(1S)",
                     "p");
  legend1S->Draw();

  canv1S->SaveAs("figures/lhcb8TeV.eps", "RECREATE");
  canv1S->Close();
}
