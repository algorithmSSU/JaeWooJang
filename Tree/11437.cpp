#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Node {
public:
	int parent = -1;
	int level = -1;
	set<int> child;
};

int findLCA(vector<Node>& tree, int v1, int v2);
void buildTree(vector<Node>& tree);

int problem11437() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;

	vector<Node> tree(n + 1);

	for (int i = 0; i < n - 1; ++i) {
		int vert1, vert2;

		cin >> vert1 >> vert2;

		tree[vert1].child.insert(vert2);
		tree[vert2].child.insert(vert1);
	}

	buildTree(tree);

	int leafNodeMax = 1;
	while (leafNodeMax != 1)

		cin >> m;

	for (int i = 0; i < m; ++i) {
		int vert1, vert2;
		cin >> vert1 >> vert2;

		cout << findLCA(tree, vert1, vert2) << "\n";
	}
	return 0;
}

int findLCA(vector<Node>& tree, int v1, int v2) {
	while (tree[v1].level != tree[v2].level) {
		if (tree[v1].level > tree[v2].level)
			v1 = tree[v1].parent;
		else
			v2 = tree[v2].parent;
	}

	while (v1 != v2) {
		v1 = tree[v1].parent;
		v2 = tree[v2].parent;
	}

	return v1;
}

void buildTree(vector<Node>& tree) {
	tree[1].parent = -1;
	tree[1].level = 1;

	queue<int> treeBuilder;
	treeBuilder.push(1);

	while (!treeBuilder.empty()) {
		int cur = treeBuilder.front();
		treeBuilder.pop();

		// 연결된 노드 집합 중 부모 제거 -> 자식 노드 집합
		tree[cur].child.erase(tree[cur].parent);

		// 자식들의 부모 및 레벨 설정
		for (auto iter = tree[cur].child.begin(); iter != tree[cur].child.end(); ++iter) {
			tree[*iter].parent = cur;
			tree[*iter].level = tree[cur].level + 1;
			treeBuilder.push(*iter);
		}
	}

	return;
}