void computeWeightedAverage(Float_t data_1, Float_t stat_1, Float_t data_2, Float_t stat_2, Float_t data_3 = 0., Float_t stat_3 = 0.) {
	Float_t weight_1 = 1. / (stat_1 * stat_1);

	Float_t weight_2 = 1. / (stat_2 * stat_2);

	Float_t weight_3 = (stat_3) ? 1. / (stat_3 * stat_3) : 0;

	Float_t average = ((weight_1 * data_1) + (weight_2 * data_2) + (weight_3 * data_3)) / (weight_1 + weight_2 + weight_3);

	Float_t error = 1. / TMath::Sqrt(weight_1 + weight_2 + weight_3);

	cout << endl
	     << average << " +/- " << error << endl
	     << endl;
}
