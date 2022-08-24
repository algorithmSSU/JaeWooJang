#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Node {
public :
	int parent;
	set<int> child;
};

int problem1063() {
	int n;
	cin >> n;

	vector<Node> tree(n + 1);

	int root = -1;

	for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;

		if (input < 0) {
			tree[i].parent = n;
			tree[n].child.insert(i);
		}

		else {
			tree[i].parent = input;
			tree[input].child.insert(i);
		}
	}

	int emptyNester;
	cin >> emptyNester;

	tree[tree[emptyNester].parent].child.erase(emptyNester);
	tree[emptyNester].child.clear();
	
	queue<int> que;
	que.push(n);

	int leafCnt = 0;

	while (!que.empty()) {
		int current = que.front();
		que.pop();

		if (tree[current].child.size() > 0) {
			for (auto iter = tree[current].child.begin();
				iter != tree[current].child.end(); ++iter) {

				if (tree[*iter].child.size() != 0)
					que.push(*iter);
				else
					++leafCnt;
			}
		}
	}

	cout << leafCnt;

	return 0;
}