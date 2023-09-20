#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using Matrix = vector<vector<bool>>;

inline void bfs(const Matrix& mat, vector<bool>& is_visited, const int start) {
	queue<int> que;
	que.emplace(start);
	is_visited[start] = true;
	
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		
		for (int next = 1; next < mat.size(); ++next) {
			if (mat[cur][next] && mat[next][cur]) {
				if (!is_visited[next]) {
					is_visited[next] = true;
					que.emplace(next);
				}
			}
		}
	}
}

inline int get_union_count(const Matrix& mat) {
	vector<bool> is_visited(mat.size());
	
	int count = 0;
	for (int i = 1; i < mat.size(); ++i) {
		if (!is_visited[i]) {
			++count;
			bfs(mat, is_visited, i);
		}
	}
	
	return count;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	Matrix islands(n + 1, vector<bool>(n + 1));
	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		
		islands[from][to] = true;
	}
	
	cout << get_union_count(islands) << "\n";
	
	return 0;
}