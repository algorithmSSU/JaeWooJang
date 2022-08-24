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

static int findLCA(vector<Node>& tree, int v1, int v2);
void buildTree(vector<Node>& tree);

int problem11438() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;

	vector<set<int>> tree(n + 1);
	vector<int> level(n + 1);
	vector<vector<int>> parent(n + 1, vector<int>());

	for (int i = 0; i < n - 1; ++i) {
		int vert1, vert2;

		cin >> vert1 >> vert2;

		tree[vert1].insert(vert2);
		tree[vert2].insert(vert1);
	}

	//buildTree(tree);

	cin >> m;

	for (int i = 0; i < m; ++i) {
		int vert1, vert2;
		cin >> vert1 >> vert2;

		//cout << findLCA(tree, vert1, vert2) << "\n";
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

void buildTree(vector<set<int>>& tree, vector<int>& level, vector<vector<int>>& parent) {
	parent[1].emplace_back(1);
	level[1] = 1;

	queue<int> treeBuilder;
	treeBuilder.push(1);

	while (!treeBuilder.empty()) {
		int cur = treeBuilder.front();
		treeBuilder.pop();

		// 연결된 노드 집합 중 부모 제거 -> 자식 노드 집합
		tree[cur].erase(parent[cur][0]);

		// 자식들의 부모 및 레벨 설정
		for (auto iter = tree[cur].begin(); iter != tree[cur].end(); ++iter) {
			parent[*iter].emplace_back(cur);
			level[*iter] = level[cur] + 1;

			treeBuilder.push(*iter);
		}
	}

	return;
}