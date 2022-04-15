{
	gStyle->SetTextFont(42);
	// For the canvas:
	gStyle->SetCanvasBorderMode(0);
	gStyle->SetCanvasColor(kWhite);
	gStyle->SetCanvasDefH(600); // Height of canvas
	gStyle->SetCanvasDefW(600); // Width of canvas
	gStyle->SetCanvasDefX(0);   // POsition on screen
	gStyle->SetCanvasDefY(0);

	// For the Pad:
	gStyle->SetPadBorderMode(0);
	// gStyle->SetPadBorderSize(Width_t size = 1);
	gStyle->SetPadColor(kWhite);
	gStyle->SetPadGridX(false);
	gStyle->SetPadGridY(false);
	gStyle->SetGridColor(kGray + 1);
	gStyle->SetGridStyle(3);
	gStyle->SetGridWidth(1);

	// For the frame:
	gStyle->SetFrameBorderMode(0);
	gStyle->SetFrameBorderSize(1);
	gStyle->SetFrameFillColor(0);
	gStyle->SetFrameFillStyle(0);
	gStyle->SetFrameLineColor(1);
	gStyle->SetFrameLineStyle(1);
	gStyle->SetFrameLineWidth(1);

	// For the histo:
	// gStyle->SetHistFillColor(1);
	// gStyle->SetHistFillStyle(0);
	gStyle->SetHistLineColor(1);
	gStyle->SetHistLineStyle(0);
	gStyle->SetHistLineWidth(2);
	// gStyle->SetLegoInnerR(Float_t rad = 0.5);
	// gStyle->SetNumberContours(Int_t number = 20);

	gStyle->SetEndErrorSize(2);
	// gStyle->SetErrorMarker(20);
	// gStyle->SetErrorX(0.);

	gStyle->SetMarkerStyle(1);

	// For the fit/function:
	gStyle->SetOptFit(1);
	gStyle->SetFitFormat("5.4g");
	gStyle->SetFuncColor(2);
	gStyle->SetFuncStyle(1);
	gStyle->SetFuncWidth(1);

	// For the legend
	gStyle->SetLegendBorderSize(0);
	gStyle->SetLegendFont(42);
	gStyle->SetLegendTextSize(.055);
	gStyle->SetFillStyle(0);

	// For the date:
	gStyle->SetOptDate(0);
	// gStyle->SetDateX(Float_t x = 0.01);
	// gStyle->SetDateY(Float_t y = 0.01);

	// For the statistics box:
	gStyle->SetOptFile(0);
	gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
	gStyle->SetStatColor(kWhite);
	gStyle->SetStatFont(42);
	gStyle->SetStatFontSize(0.025);
	gStyle->SetStatTextColor(1);
	gStyle->SetStatFormat("6.4g");
	gStyle->SetStatBorderSize(1);
	gStyle->SetStatH(0.1);
	gStyle->SetStatW(0.15);
	// gStyle->SetStatStyle(Style_t style = 1001);
	// gStyle->SetStatX(Float_t x = 0);
	// gStyle->SetStatY(Float_t y = 0);

	// Margins:
	gStyle->SetPadTopMargin(0.02);
	gStyle->SetPadBottomMargin(0.15);
	gStyle->SetPadLeftMargin(0.12);
	gStyle->SetPadRightMargin(0.025);

	// For the Global title:

	gStyle->SetOptTitle(1);
	gStyle->SetTitleAlign(23);
	gStyle->SetTitleFont(42);
	gStyle->SetTitleColor(1);
	gStyle->SetTitleTextColor(1);
	gStyle->SetTitleFillColor(0);
	gStyle->SetTitleFontSize(0.05);
	// gStyle->SetTitleH(0); // Set the height of the title box
	// gStyle->SetTitleW(0); // Set the width of the title box
	gStyle->SetTitleX(0.5); // Set the position of the title box
	gStyle->SetTitleStyle(0);
	gStyle->SetTitleBorderSize(0);

	// For the axis titles:

	gStyle->SetTitleColor(1, "XYZ");
	gStyle->SetTitleFont(42, "XYZ");
	gStyle->SetTitleSize(0.06, "XYZ");
	// gStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the
	// size? gStyle->SetTitleYSize(Float_t size = 0.02);
	gStyle->SetTitleXOffset(1.05);
	gStyle->SetTitleYOffset(1.);
	// gStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

	// For the axis labels
	gStyle->SetLabelColor(1, "XYZ");
	gStyle->SetLabelFont(42, "XYZ");
	gStyle->SetLabelOffset(0.007, "XYZ");
	gStyle->SetLabelSize(0.05, "XYZ");

	// For the axis:

	gStyle->SetAxisColor(1, "XYZ");
	gStyle->SetStripDecimals(kTRUE);
	gStyle->SetTickLength(0.03, "XYZ");
	gStyle->SetNdivisions(510, "XYZ");
	gStyle->SetPadTickX(1); // To get tick marks on the opposite side of the frame
	gStyle->SetPadTickY(1);

	// Change for log plots:
	gStyle->SetOptLogx(0);
	gStyle->SetOptLogy(0);
	gStyle->SetOptLogz(0);

	gStyle->SetHatchesLineWidth(5);
	gStyle->SetHatchesSpacing(0.05);
}
