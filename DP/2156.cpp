#include <iostream>
#include <vector>

using namespace std;

int maxDrink(vector<int>& maxOut, vector<int>& input, int n);
int max(vector<int>& arr);

int problem2156() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	// maxOut[i] : max drunk count unitl i
	vector<int> maxOut(n + 1, -1);
	vector<int> input(n + 1, 0);

	for (int i = 0; i < n; ++i)
		cin >> input[i];

	cout << maxDrink(maxOut, input, n);

	return 0;
}

int maxDrink(vector<int>& maxOut, vector<int>& input, int n) {
	if (n < 0)
		return 0;

	if (n < 2)
		return maxDrink(maxOut, input, n - 1) + input[n];

	if (maxOut[n] < 0) {
		vector<int> cases(3);
		int sum = 0;

		cases[0] = maxDrink(maxOut, input, n - 1);
		cases[1] = maxDrink(maxOut, input, n - 2) + input[n];
		cases[2] = maxDrink(maxOut, input, n - 3) + input[n] + input[n - 1];

		maxOut[n] = max(cases);
	}
			
	return maxOut[n];
}

//> max : return max value in vector
int max(vector<int>& arr) {
	int max = 0;

	for (auto value : arr) {
		if (value > max)
			max = value;
	}

	return max;
}