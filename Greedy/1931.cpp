#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int problem1931() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int count = 0;
	int bound = 0;

	int num;
	cin >> num;

	vector<pair<int, int>> arr;

	for (int i = 0; i < num; ++i) {
		int start, end;
		cin >> start >> end;
		//during = end - start;
		arr.emplace_back(end, start);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < num; ++i) {
		if (arr[i].second >= bound) {
			bound = arr[i].first;
			++count;
		}
	}

	cout << count;

	return 0;
}