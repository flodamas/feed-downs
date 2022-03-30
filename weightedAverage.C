void weightedAverage() {
	vector<Double_t> data = {36, 40};

	vector<Double_t> stat = {14, 9};

	vector<Double_t> syst = {8, 12};

	if (!(data.size() == stat.size())) {
		cout << endl
		     << "The two vectors do not have the same size !!!" << endl
		     << "Data = " << data.size() << ", stat = " << stat.size() << endl;
		return;
	}

	Double_t average = 0, statAverage = 0, systAverage = 0, sumWeights = 0;

	for (Int_t i = 0; i < data.size(); i++) {
		//stat[i] = data[i] * stat[i] / 100.;

		//syst[i] = data[i] * syst[i] / 100.;

		Double_t weight = 1. / (stat[i] * stat[i]);

		sumWeights += weight;

		average += data[i] * weight;

		systAverage += syst[i] * weight;
	}

	average /= sumWeights;

	statAverage = 1. / TMath::Sqrt(sumWeights);

	systAverage /= sumWeights;

	printf("%.0f +/- %.0f (stat) +/- %.0f (syst)\n", average, statAverage, systAverage);
}
