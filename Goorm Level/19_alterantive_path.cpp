#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Graph = vector<vector<int>>;

class City {
	Graph graph;
	int n;
	public: 
	City(int n, int m) : n{n} {
		graph = Graph(n + 1);
		
		for (int i = 0; i < m; ++i) {
			int from, to;
			cin >> from >> to;

			// double direction
			graph[from].emplace_back(to);
			graph[to].emplace_back(from);
		}
	}
	
	inline int getMinPathWithBan(const int from, const int to, const int ban) {
		if (from == ban || to == ban)
			return -1;
		
		vector<bool> isVisited(n + 1);
		isVisited[ban] = true;
		
		queue<pair<int, int>> que; // <cur, dist>
		que.emplace(from, 1);
		
		while (!que.empty()) {
			auto [ cur, dist ] = que.front();
			que.pop();
			
			if (cur == to)
				return dist;
			
			for (const auto next : graph[cur]) {
				if (!isVisited[next]) {
					isVisited[next] = true;
					que.emplace(next, dist + 1);
				}
			}
		}
		
		return -1;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	
	int start, end;
	cin >> start >> end;
	
	City city(n, m);
	
	for (int ban = 1; ban <= n; ++ban)
		cout << city.getMinPathWithBan(start, end, ban) << "\n";
	
	return 0;
}