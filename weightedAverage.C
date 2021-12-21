void weightedAverage() {
	vector<Double_t> data = {0.33, 0.32, 0.34, 0.36, 0.35, 0.36, 0.37, 0.44, 0.35};

	vector<Double_t> stat = {2.2, 2.7, 3.3, 3.7, 4.6, 5.3, 5.9, 6.4, 8.2};

	vector<Double_t> syst = {3.3, 3.4, 3.4, 3.5, 3.5, 4., 3.5, 3.4, 3.3};

	if (!(data.size() == stat.size())) {
		cout << endl
		     << "The two vectors do not have the same size !!!" << endl
		     << "Data = " << data.size() << ", stat = " << stat.size() << endl;
		return;
	}

	Double_t average = 0, statAverage = 0, sumWeights = 0;

	for (Int_t i = 0; i < data.size(); i++) {
		stat[i] = data[i] * stat[i] / 100.;

		syst[i] = data[i] * syst[i] / 100.;

		Double_t weight = 1. / (stat[i] * stat[i] + syst[i] * syst[i]);

		sumWeights += weight;

		average += data[i] * weight;
	}

	average /= sumWeights;

	statAverage = 1. / TMath::Sqrt(sumWeights);

	printf("%.3f +/- %.3f (stat) \n", average, statAverage);
}
