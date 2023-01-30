#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int _binary_search(vector<int>& arr, int min, int max, int boundary);
int min_cut_hight(vector<int>& trees, int boundary);

int problem2805() {
	int n, m;
	cin >> n >> m;

	vector<int> trees(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> trees[i];

	cout << min_cut_hight(trees, m);

	return 0;
}

int min_cut_hight(vector<int>& trees, int boundary) {
	// 정렬 할 필요 없이 전체 배열 내에서 max만 찾아내면 된다.
	//sort(trees.begin(), trees.end());
	//int max = trees[trees.size() - 1];
	int max = 0;
	for (const auto val : trees)
		if (val > max)
			max = val;

	return _binary_search(trees, 0, max, boundary);
}

int _binary_search(vector<int>& arr, int min, int max, int boundary) {
	if (min > max)
		return max;

	int mid = (min + max) / 2;

	long long cuting_sum = 0;
	for (auto val : arr) {
		if (val > mid)
			cuting_sum += (val - mid);
	}

	// #Case : 더 많이 자른 경우 -> 더 높은 곳에서 잘라야 함
	if (cuting_sum > boundary)
		return _binary_search(arr, mid + 1, max, boundary);
	// #Case : 길이가 부족한 경우 -> 더 낮은 곳에서 잘라야 함
	else if (cuting_sum < boundary)
		return _binary_search(arr, min, mid - 1, boundary);

	return mid;
}