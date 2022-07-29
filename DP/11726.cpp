#include <iostream>
#include <vector>

using namespace std;

int problem11726() {
	int n;
	cin >> n;

	pair<int, int> arr[2];
	int cur = 1;
	int next = 0;

	arr[cur].first = 1;
	arr[cur].second = 0;

	for (int i = 1; i < n; ++i) {
		arr[next].first = (arr[cur].first + arr[cur].second) % 10007;
		arr[next].second = arr[cur].first;

		int tmp = next;
		next = cur;
		cur = tmp;
	}

	cout << (arr[cur].first + arr[cur].second) % 10007;

	return 0;
}