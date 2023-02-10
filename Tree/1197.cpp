#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> isVisited;

struct Edge {
	int from;
	int to;
	int weight;
};

bool compare(Edge& a, Edge& b) {
	return (a.weight < b.weight);
}

int get_root(int n) {
	if (isVisited[n] != n)
		isVisited[n] = get_root(isVisited[n]);

	return isVisited[n];
}

void set_root(int n, int root) {
	if (isVisited[n] != n)
		set_root(isVisited[n], root);

	isVisited[n] = root;
}

int main() {
	int v, e;
	cin >> v >> e;

	vector<Edge> edges;

	for (int i = 0; i < e; ++i) {
		Edge edge;
		cin >> edge.from >> edge.to >> edge.weight;

		edges.emplace_back(edge);
	}

	sort(edges.begin(), edges.end(), compare);

	isVisited = vector<int>(v + 1, 0);
	for (int i = 0; i <= v; ++i)
		isVisited[i] = i;

	long long sum = 0;
	int connectedVertexCnt = 1;
	for (auto edge : edges) {
		if (get_root(edge.from) != get_root(edge.to)) {
			sum += edge.weight;
			set_root(edge.to, get_root(edge.from));

			if (++connectedVertexCnt >= v)
				break;
		}
	}

	cout << sum;

	return 0;
}