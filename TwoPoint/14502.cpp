#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> input(n, 0);

	for (int i = 0; i < n; ++i)
		cin >> input[i];

	sort(input.begin(), input.end());

	int min = INT_MAX;
	pair<int, int> out;

	int l = 0;
	int r = input.size() - 1;

	while (l != r) {
		int diff = abs(input[l] + input[r]);
		if (diff < min) {
			min = diff;
			out.first = input[l];
			out.second = input[r];
		}

		((input[l] + input[r]) > 0) ? --r : ++l;
	}

	cout << out.first << " " << out.second;

	return 0;
}