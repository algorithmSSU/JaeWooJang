#include <array>
#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<int>>;

const int CLOUD = 1;
const array<pair<int, int>, 8> dir = { { { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, 
									{ -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 } } };

inline void set_flag(Matrix& mat, const int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (mat[i][j] != CLOUD) {
				for (const auto& [ dr, dc ] : dir) {
					int r = i + dr;
					int c = j + dc;

					if (mat[r][c] == CLOUD)
						--mat[i][j];
				}
			}
		}
	}
}

inline int count_flag(const Matrix& mat, const int n, const int k) noexcept {
	int count = 0;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (mat[i][j] == -k)
				++count;
	
	return count;
}

int main() {
	int n, k;
	cin >> n >> k;
	
	Matrix mat(n + 2, vector<int>(n + 2));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> mat[i][j];
	
	set_flag(mat, n);
	cout << count_flag(mat, n, k) << "\n";
	
	return 0;
}