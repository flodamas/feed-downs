void weightedAverage() {
	vector<Double_t> data = {0.46, 0.49, 0.5, 0.5, 0.48, 0.47, 0.53, 0.58, 0.56};

	vector<Double_t> stat = {1.9, 2.2, 2.8, 3.2, 4., 4.7, 5., 5.7, 6.6};

	vector<Double_t> syst = {3., 3., 3.2, 3.1, 3.3, 3.8, 3.1, 3.1, 3.};

	if (!(data.size() == stat.size())) {
		cout << endl
		     << "The two vectors do not have the same size !!!" << endl
		     << "Data = " << data.size() << ", stat = " << stat.size() << endl;
		return;
	}

	Double_t average = 0, statAverage = 0, systAverage = 0, sumWeights = 0;

	for (Int_t i = 0; i < data.size(); i++) {
		stat[i] = data[i] * stat[i] / 100.;

		syst[i] = data[i] * syst[i] / 100.;

		Double_t weight = 1. / (stat[i] * stat[i]);

		sumWeights += weight;

		average += data[i] * weight;

		systAverage += syst[i] * weight;
	}

	average /= sumWeights;

	statAverage = 1. / TMath::Sqrt(sumWeights);

	systAverage /= sumWeights;

	printf("%.3f +/- %.3f (stat) +/- %.3f (syst)\n", average, statAverage, systAverage);
}
