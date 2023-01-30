#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int problem2470() {
	int n;
	cin >> n;

	vector<int> input(n, 0);

	for (int i = 0; i < n; ++i)
		cin >> input[i];

	sort(input.begin(), input.end());

	int out_left = 0, out_right = 0;
	
	int l = 0;
	int r = input.size() - 1;

	int min = INT_MAX;
	while (l != r) {
		int diff = abs(input[l] + input[r]);
		if (diff < min) {
			min = diff;
			out_left = input[l];
			out_right = input[r];
		}

		((input[l] + input[r]) > 0) ? --r : ++l;
	}

	cout << out_left << " " << out_right;

	return 0;
}