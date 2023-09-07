#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<int>>;

class Coordinate {
	Matrix vertical_mat;
	Matrix horizontal_mat;
	
	int n;
	
	inline void _drawline_horizontal(const int y0, const int x0, const int x1) noexcept {
		for (int j = x0; j <= x1; ++j)
			++horizontal_mat[y0][j];
	}
	
	inline void _drawline_vertical(const int y0, const int x0, const int y1) noexcept {
		for (int i = y0; i <= y1; ++i)
			++vertical_mat[i][x0];
	}
	
public:
	Coordinate(int n) : n{n} {
		vertical_mat = Matrix(n + 1, vector<int>(n + 1));
		horizontal_mat = Matrix(n + 1, vector<int>(n + 1));
	}

	inline void drawline(const int y, const int x, const char dir) noexcept {
		switch (dir) {
			case 'U':
				_drawline_vertical(1, x, y); break;
				
			case 'D':
				_drawline_vertical(y, x, n); break;
				
			case 'L':
				_drawline_horizontal(y, 1, x); break;
				
			case 'R':
				_drawline_horizontal(y, x, n); break;
		}
	}
	
	inline long long getCountPoint() noexcept {
		long long sum = 0;
		
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				//! Attention : Overflow 및 형변환 유의 
				long long count = (long long)horizontal_mat[i][j] * (long long)vertical_mat[i][j];
				sum += count;
			}
		}
		
		return sum;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	Coordinate coordinate(n);
	for (int i = 0; i < m; ++i) {
		int y, x;
		char dir;
		
		cin >> y >> x >> dir;
		coordinate.drawline(y, x, dir);
	}
	
	cout << coordinate.getCountPoint() << "\n";
	
	return 0;
}