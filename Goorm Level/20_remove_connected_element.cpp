#include <array>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using Matrix = vector<vector<char>>;
using Point = pair<int, int>;

class Problem {
	const array<array<int, 2>, 4> dir = { { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } } };

	Matrix mat;	
	int n;
	int k;
	
	public: 
	Problem(int n, int k) : n{n}, k{k} {
		mat = Matrix(n + 2, vector<char>(n + 2));
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				cin >> mat[i][j];
	}
	
	int bfs_with_mark(const int start_r, const int start_c, const char mark) {
		queue<Point> que;
		que.emplace(start_r, start_c);

		char target = mat[start_r][start_c];
		mat[start_r][start_c] = mark;

		int area = 1;
		// bfs with mark 
		while (!que.empty()) {
			const auto [ cur_r, cur_c ] = que.front();
			que.pop();

			for (const auto [ dr, dc ] : dir) {
				int r = cur_r + dr;
				int c = cur_c + dc;

				if (mat[r][c] == target) {
					++area;

					mat[r][c] = mark;
					que.emplace(r, c);
				}
			} 
		}

		return area;
	}
	
	void update(const int r, const int c, const char ch) noexcept {
		mat[r][c] = ch;

		// # : VISITED
		int area = bfs_with_mark(r, c, '#');

		if (area >= k)
			bfs_with_mark(r, c, '.');	// # -> .
		else
			bfs_with_mark(r, c, ch);		// # -> ch
	}

	void print() noexcept {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				cout << mat[i][j];
			cout << "\n";
		}
	}
};

int main() {
	int n, k, q;
	cin >> n >> k >> q;
	
	Problem problem(n, k);
	for (int i = 0; i < q; ++i) {
		int r, c;
		char ch;
		
		cin >> r >> c >> ch;
		problem.update(r, c, ch);
	}
	
	problem.print();
	
	return 0;
}