#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;

int isConnected(Graph& graph, int from, int to);
void dfs(Graph& graph, vector<int>& isVisited, int start);

int problem9205() {
	int t;
	cin >> t;

	for (int test_case = 0; test_case < t; ++test_case) {
		int n;
		cin >> n;

		// Linked List Graph 
		Graph graph = Graph(n + 2);

		vector<pair<int, int>> pos(n + 2, make_pair(0, 0));
		for (int i = 0; i < n + 2; ++i)
			cin >> pos[i].first >> pos[i].second;

		for (int i = 0; i < n + 2; ++i) {
			for (int j = i + 1; j < n + 2; ++j) {
				// if two point's distance less then 1000 (= 20 coke * 50 m/coke ) => there are conneted
				if (abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second) <= 1000) {
					// i'th & j'th is connected
					graph[i].emplace_back(j);
					graph[j].emplace_back(i);
				}
			}
		}

		// check which home(0) to place(n + 1) is Connected
		if (isConnected(graph, 0, n + 1))
			cout << "happy\n";
		else
			cout << "sad\n";
	}

	return 0;
}

int isConnected(Graph& graph, int from, int to) {
	vector<int> isVisited(graph.size(), 0);

	isVisited[from] = 1;
	dfs(graph, isVisited, from);

	return isVisited[to];
}

void dfs(Graph& graph, vector<int>& isVisited, int cur) {
	// for every edge with current position,
	for (int i = 0; i < graph[cur].size(); ++i) {
		// if Haven't visited yet
		if (!isVisited[graph[cur][i]]) {
			// visit and continue
			isVisited[graph[cur][i]] = 1;
			dfs(graph, isVisited, graph[cur][i]);
		}
	}
}