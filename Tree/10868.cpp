#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000000

int findMin(vector<int>& tree, int left, int right, int begin, int end, int idx);

int problem10868() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int leafNodeMax = 1;
	while (leafNodeMax < n)
		leafNodeMax *= 2;

	vector<int> tree(leafNodeMax * 2, MAX);

	for (int i = leafNodeMax; i < leafNodeMax + n; ++i)
		cin >> tree[i];

	for (int i = leafNodeMax - 1; i > 0; --i)
		tree[i] = (tree[i * 2] < tree[i * 2 + 1]) ? tree[i * 2] : tree[i * 2 + 1];

	for (int i = 0; i < m; ++i) {
		int left, right;
		cin >> left >> right;

		cout << findMin(tree, left, right, 1, leafNodeMax, 1) << "\n";
	}

	return 0;
}

int findMin(vector<int>& tree, int left, int right, int begin, int end, int idx) {
	// #Case OutSide
	if ((left > end) || (right < begin))
		return MAX;

	// #Case Inside
	if ((left <= begin) && (right >= end))
		return tree[idx];

	// #Case Both -> divide and conquer
		
	int mid = (begin + end) / 2;
	int val1 = findMin(tree, left, right, begin, mid, idx * 2);
	int val2 = findMin(tree, left, right, mid + 1, end, idx * 2 + 1);

	return ((val1 < val2) ? val1 : val2);
}