#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000000

void change(vector<long long>& tree, int a, int b);
int multiple(vector<long long>& tree, int left, int right, int begin, int end, int idx);

int problem11505() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int leafNodeMax = 1;
	while (leafNodeMax < n)
		leafNodeMax *= 2;

	vector<long long> tree(leafNodeMax * 2, MAX);

	for (int i = leafNodeMax; i < leafNodeMax + n; ++i)
		cin >> tree[i];

	for (int i = leafNodeMax - 1; i > 0; --i) 
		tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % 1000000007;

	for (int i = 0; i < m + k; ++i) {
		int command, a, b;
		cin >> command >> a >> b;

		if (command == 1)
			change(tree, a + leafNodeMax - 1, b);
		else
			cout << multiple(tree, a, b, 1, leafNodeMax, 1) << "\n";
	}

	return 0;
}

void change(vector<long long>& tree, int target, int value) {
	tree[target] = value;

	for (int idx = target / 2; idx > 0; idx /= 2)
		tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % 1000000007;
}

int multiple(vector<long long>& tree, int left, int right, int begin, int end, int idx) {
	// #Case OutSide
	if ((left > end) || (right < begin))
		return 1;

	// #Case Inside
	if ((left <= begin) && (right >= end))
		return tree[idx];

	// #Case Both -> divide and conquer

	int mid = (begin + end) / 2;
	long long val1 = multiple(tree, left, right, begin, mid, idx * 2);
	long long val2 = multiple(tree, left, right, mid + 1, end, idx * 2 + 1);

	return ((val1 * val2) % 1000000007);
}