#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Graph = vector<vector<int>>;

class Web {
	Graph graph;
	int n;
	
	public :
	Web(int n, int m) : n{n} {
		graph = Graph(n + 1);
		
		for (int i = 0; i < m; ++i) {
			int from, to;
			cin >> from >> to;

			graph[from].emplace_back(to);
			graph[to].emplace_back(from);
		}
	}
	
	vector<int> get_most_density_graph() {
		vector<int> out;
		double min_density = 0;
		
		vector<bool> is_visited(n + 1);
		for (int i = 1; i <= n; ++i) {
			if (!is_visited[i]) {
				vector<int> sub_vertices = get_sub_vertices(is_visited, i);
				int edges_count = get_edge_count(sub_vertices);
				
				double density = (double)edges_count / sub_vertices.size();
				
				if (density > min_density) {
					min_density = density;
					out = vector<int>(sub_vertices.begin(), sub_vertices.end());
				}
			}
		}
		
		sort(out.begin(), out.end());
		
		return out;
	}
	
  int get_edge_count(const vector<int> vertices) noexcept {
		int count = 0;
		for (const auto vertice : vertices)
			count += graph[vertice].size();
		
		count *= 0.5;
		return count;
	}
	
	vector<int> get_sub_vertices(vector<bool>& is_visited, const int start) {
		vector<int> sub_vertices;
		
		queue<int> que;
		que.emplace(start);
		is_visited[start] = true;
		
		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			
			sub_vertices.emplace_back(cur);
			
			for (const auto next : graph[cur]) {
				if (!is_visited[next]) {
					is_visited[next] = true;
					que.emplace(next);
				}
			}
		}
		
		return sub_vertices;
	}
};

inline void print(const vector<int> vec) noexcept {
	for (const auto val : vec)
		cout << val << " ";
	cout << "\n";
}

int main() {
	int n, m;
	cin >> n >> m;
	
	Web web(n, m);
	vector<int> vertices = web.get_most_density_graph();
	print(vertices);
	
	return 0;
}