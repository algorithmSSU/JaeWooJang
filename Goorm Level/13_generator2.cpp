#include <array>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Matrix = vector<vector<int>>;

class Problem {
	static constexpr int TYPE_COUNT = 30;
	static constexpr int VISITED = 0;
	
	const array<pair<int, int>, 4> dir = { { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } } };
	Matrix mat;
	int n;
	public:
	Problem(int n) : n{n} {
		mat = Matrix(n + 2, vector<int>(n + 2));
		for (int r = 1; r <= n; ++r)
			for (int c = 1; c <=n; ++c)
				cin >> mat[r][c];
	}
	
	int get_area(const int start_r, const int start_c, const int type) {
		queue<pair<int, int>> que;
		que.emplace(start_r, start_c);
		mat[start_r][start_c] = VISITED;
		
		int count = 1;
		while (!que.empty()) {
			auto [ r, c ] = que.front();
			que.pop();
			
			for (const auto& [ dr, dc ] : dir) {
				if (mat[r + dr][c + dc] == type) {
					++count;
					mat[r + dr][c + dc] = VISITED;
					que.emplace(r + dr, c + dc);
				} 
			}
		}
		
		return count;
	}
	
	static bool compare(const int left, const int right) noexcept {
		return left <= right;
	}
	
	int get_max_block(const int k) {
		vector<int> types(TYPE_COUNT + 1);
		for (int r = 1; r <= n; ++r) {
			for (int c = 1; c <= n; ++c) {
				if (mat[r][c] != VISITED) {
					int type = mat[r][c];
					int area = get_area(r, c, type);
					if (area >= k)
						++types[type];
				}
			}
		}
		
		auto max_iter = max_element(types.begin(), types.end(), compare);
		return distance(types.begin(), max_iter);
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	
	Problem problem(n);
	cout << problem.get_max_block(k) << "\n";
	
	return 0;
}