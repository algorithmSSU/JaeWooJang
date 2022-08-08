#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int problem1744() {
	int input;

	int n;
	cin >> n;

	vector<int> positive_arr;
	vector<int> negative_arr;

	for (int i = 0; i < n; ++i) {
		cin >> input;
		if (input > 0)
			positive_arr.emplace_back(input);
		else
			negative_arr.emplace_back(input);
	}

	long long sum = 0;
	sort(positive_arr.begin(), positive_arr.end());
	sort(negative_arr.begin(), negative_arr.end(), std::greater<>());

	int i, j;
	for (i = positive_arr.size() - 1; i >= 1; i -= 2) {
		int tmp1 = positive_arr[i] * positive_arr[i - 1];
		int tmp2 = positive_arr[i] + positive_arr[i - 1];

		sum += (tmp1 > tmp2) ? tmp1 : tmp2;
	}

	for (j = negative_arr.size() - 1; j >= 1; j -= 2) {
		int tmp1 = negative_arr[j] * negative_arr[j - 1];
		int tmp2 = negative_arr[j] + negative_arr[j - 1];

		sum += (tmp1 > tmp2) ? tmp1 : tmp2;
	}

	if (i >= 0)
		sum += positive_arr[i];
	if (j >= 0)
		sum += negative_arr[j];

	cout << sum;

	return 0;
}
