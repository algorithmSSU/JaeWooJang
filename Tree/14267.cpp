#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int problem14267() {
	int n, m;
	cin >> n >> m;

	vector<int> parents(n + 1, 0);
	vector<int> weights(n + 1, 0);
	vector<vector<int>> childs(n + 1, vector<int>());

	int root = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> parents[i];

		// #Case root 
		if (parents[i] == -1)
			root = i;
		// #Case not root
		else 
			childs[parents[i]].emplace_back(i);
	}

	for (int i = 0; i < m; ++i) {
		int who, value;
		cin >> who >> value;

		weights[who] += value;
	}

	queue<int> que;
	que.push(root);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i = 0; i < childs[cur].size(); ++i) {
			weights[childs[cur][i]] += weights[cur];
			que.push(childs[cur][i]);
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << weights[i] << " ";

	return 0;
}