#include <iostream>
#include <vector>

using namespace std;

int problem11726() {
	int n;
	cin >> n;

	// pair<int, int> => < end with vertical, end with horizontal >
	pair<int, int> arr[2];
	int cur = 1;
	int next = 0;

	arr[cur].first = 1;
	arr[cur].second = 0;

	for (int i = 1; i < n; ++i) {
		// Case 1 : End with Vertical
		arr[next].first = (arr[cur].first + arr[cur].second) % 10007;
		// Case 2 : End with Horiontal
		arr[next].second = arr[cur].first;

		int tmp = next;
		next = cur;
		cur = tmp;
	}

	cout << (arr[cur].first + arr[cur].second) % 10007;

	return 0;
}