#include <iostream>
#include <vector>

using namespace std;

#define add 1
#define sum 2

class SegmentTree {
public:
	vector<long long> tree;
	vector<bool> isNeedUpdate;
	int leafNodeMax;
	int leafNodeNum;

	SegmentTree(int n) {
		leafNodeNum = n;

		leafNodeMax = 1;
		while (leafNodeMax < n)
			leafNodeMax *= 2;

		tree = vector<long long>(leafNodeMax * 4, 0);
		isNeedUpdate = vector<bool>(leafNodeMax * 4, false);
	}

	SegmentTree& getInput() {
		for (int i = leafNodeMax; i < leafNodeMax + leafNodeNum; ++i)
			cin >> tree[i];

		_setIsNeedUpdate(leafNodeMax, leafNodeMax + leafNodeNum, true);
		return *this;
	}

	void build() {
		for (int i = leafNodeMax - 1; i > 0; --i)
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}

	void printTree() {
		cout << "####\n";
		for (int i = 1; i <= leafNodeMax; i *= 2) {
			for (int j = 0; j < i; ++j)
				cout << tree[i + j] << " ";

			cout << "\n";
		}

		cout << "####\n\n";
	}


	void addInRange(int left, int right, long long adder) {
		if (left > right) {
			int tmp = left;
			left = right;
			right = tmp;
		}

		_addInRange(left + leafNodeMax - 1, right + leafNodeMax - 1, adder);
		_setIsNeedUpdate(left + leafNodeMax - 1, right + leafNodeMax - 1, true);
	}

	long long sumInRange(int left, int right) {
		return _sumInRange(left, right, 1, leafNodeMax, 1);
	}

private:
	void _addInRange(int left, int right, long long adder) {
		for (int i = left; i <= right; ++i)
			tree[i] += adder;
	}

	void _setIsNeedUpdate(int left, int right, bool state) {
		left /= 2;
		right /= 2;

		while (left > 0) {
			for (int i = left; i <= right; ++i)
				isNeedUpdate[i] = state;

			left /= 2;
			right /= 2;
		}
	}

	long long _sumInRange(int left, int right, int begin, int end, int idx) {
		// #Case OutSide
		if ((left > end) || (right < begin))
			return 0;

		// #Case Inside
		if ((left <= begin) && (right >= end))
			return _valueAt(idx);

		// #Case Both -> divide and conquer

		long long mid = (long long)((begin + end) / 2);
		long long val1 = _sumInRange(left, right, begin, mid, idx * 2);
		long long val2 = _sumInRange(left, right, mid + 1, end, idx * 2 + 1);

		return (long long)(val1 + val2);
	}

	long long _valueAt(int idx) {
		if (isNeedUpdate[idx]) {
			tree[idx] = _valueAt(idx * 2) + _valueAt(idx * 2 + 1);
			isNeedUpdate[idx] = false;
		}

		return tree[idx];
	}
};

int prbolem10999() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	SegmentTree tree(n);
	tree.getInput();

	for (int i = 0; i < m + k; ++i) {
		int command = 0;
		cin >> command;

		int left, right;

		switch (command) {
		case add :
			long long adder;
			cin >> left >> right >> adder;

			tree.addInRange(left, right, adder);

			break;

		case sum :
			cin >> left >> right;

			cout << tree.sumInRange(left, right) << "\n";

			break;
		}
	}

	return 0;
}