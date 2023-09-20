#include <array>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Matrix = vector<vector<int>>;

constexpr int VISITED = 0;
const array<pair<int, int>, 4> dir = { { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } } };

inline void bfs(Matrix& mat, const int start_r, const int start_c) noexcept {
	queue<pair<int, int>> que;
	que.emplace(start_r, start_c);
	mat[start_r][start_c] = VISITED;
	
	while (!que.empty()) {
		auto [ r, c ] = que.front();
		que.pop();
		
		for (const auto [ dr, dc ] : dir) {
			if (mat[r + dr][c + dc]) {
				mat[r + dr][c + dc] = VISITED;
				que.emplace(r + dr, c + dc);
			}
		}
	}
}

inline int all_search(Matrix& mat, const int n) noexcept {
	int area_count = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (mat[i][j]) {
				++area_count;
				bfs(mat, i, j);
			}
		}
	}
	
	return area_count;
}

int main() {
	int n;
	cin >> n;
	
	Matrix mat(n + 2, vector<int>(n + 2, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> mat[i][j];
	
	cout << all_search(mat, n) << "\n";
	
	return 0;
}