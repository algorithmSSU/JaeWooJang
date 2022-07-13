#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<long long>& arr, int left, int right, long long target);

int problem2343() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	int upperBound = 0;
	int lowerBound = 0;

	int sum = 0;

	/* get input */
	vector<long long> arr;
	arr.reserve(n + 2);

	arr.emplace_back(0);
	for (int i = 0; i < n; ++i) {
		int input = 0;
		cin >> input;
		sum += input;
		arr.emplace_back(sum);

		if (input > lowerBound)
			lowerBound = input;
	}
	arr.emplace_back(sum);

	upperBound = sum;
	while (lowerBound <= upperBound) {
		int mid = (lowerBound + upperBound) * 0.5;

		int cnt = 0;

		int left = 1;
		while (left <= n) {
			left = binarySearch(arr, left, n, mid + arr[left - 1]);
			++cnt;
		}

		if (cnt <= m)
			upperBound = mid - 1;
		else
			lowerBound = mid + 1;
	}
	
	cout << lowerBound;

	return 0;
}

// find the smallest index grater than target
int binarySearch(vector<long long>& arr, int left, int right, long long target) {
	if (left > right)
		return left;

	int mid = (left + right) * 0.5;

	if (arr[mid] > target)
		return binarySearch(arr, left, mid - 1, target);
	else if (arr[mid] < target)
		return binarySearch(arr, mid + 1, right, target);
	else
		return mid + 1;
}