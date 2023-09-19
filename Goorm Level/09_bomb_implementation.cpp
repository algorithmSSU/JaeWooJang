#include <array>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
using Matrix = vector<vector<T>>;

const array<pair<int, int>, 5> dir = { { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }, { 0, 0 } } };

inline int get_max(const Matrix<int>& mat) noexcept {
	int max = 0;
	
	for (const auto& vec : mat)
		for (const auto val : vec)
			if (val > max)
				max = val;
	
	return max;
}

int main() {
	int n, k;
	cin >> n >> k;
	
	Matrix<char> ground(n + 2, vector<char>(n + 2));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> ground[i][j];
	
	Matrix<int> mat(n + 2, vector<int>(n + 2));
	for (int i = 0; i < k; ++i) {
		int cur_r, cur_c;
		cin >> cur_r >> cur_c;
		
		for (const auto& [ dr, dc ] : dir) { 	
			int r = cur_r + dr;
			int c = cur_c + dc;
			
			switch (ground[r][c]) {
				case '0':
					++mat[r][c]; break;
					
				case '#':
					break;
					
				case '@':
					mat[r][c] += 2; break;
			}
		}
	}
	
	cout << get_max(mat) << "\n";
	
	return 0;
}