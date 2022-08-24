#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
public :
	vector<long long> tree;
	int leafNodeMax;

	SegmentTree(int n) {
		leafNodeMax = 1;
		while (leafNodeMax < n)
			leafNodeMax *= 2;

		tree = vector<long long>(leafNodeMax * 2, 0);
	}

	SegmentTree& getInput(int n) {
		for (int i = leafNodeMax; i < leafNodeMax + n; ++i)
			cin >> tree[i];

		return *this;
	}

	void build() {
		for (int i = leafNodeMax - 1; i > 0; --i)
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}

	void change(int target, long long val) {
		_change(target + leafNodeMax - 1, val);
	}

	long long sumInRange(int left, int right) {
		return _sumInRange(left, right, 1, leafNodeMax, 1);
	}

private :
	void _change(int target, long long val) {
		tree[target] = val;

		for (int i = target / 2; i > 0; i /= 2)
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}

	long long _sumInRange(int left, int right, int begin, int end, int idx) {
		// #Case OutSide
		if ((left > end) || (right < begin))
			return 0;

		// #Case Inside
		if ((left <= begin) && (right >= end))
			return tree[idx];

		// #Case Both -> divide and conquer

		long long mid = (long long)((begin + end) / 2);
		long long val1 = _sumInRange(left, right, begin, mid, idx * 2);
		long long val2 = _sumInRange(left, right, mid + 1, end, idx * 2 + 1);

		return (long long)(val1 + val2);
	}
};

int problem2042() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	SegmentTree tree(n);
	tree.getInput(n).build();

	for (int i = 0; i < m + k; ++i) {
		long long command, val1, val2;
		cin >> command >> val1 >> val2;

		if (command == 1)
			tree.change(val1, val2);
		else
			cout << tree.sumInRange(val1, val2) << "\n";
	}

	return 0;
}