#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define EMPTY_SPACE	0
#define WALL		1
#define BACTERIA	2

using Matrix = vector<vector<int>>;
using Point = pair<int, int>;

void copy_mat(Matrix& dest, Matrix& src);
void set_wall(Matrix& mat, Point& pos);
void simulation(Matrix& mat, vector<Point>& bac_list);
int evaluate(Matrix& mat, int target);
void bfs(Matrix& mat, int i, int j);
void printMat(Matrix& mat);

const int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

int problem14502() {
	int n, m;
	cin >> n >> m;

	Matrix mat = Matrix(n + 2, vector<int>(m + 2, 1));
	Matrix copied_mat = Matrix(n + 2, vector<int>(m + 2, 1));

	// 박테리아와 빈 공간을 각각 리스트로 관리
	vector<Point> bac_list;
	vector<Point> empty_list;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mat[i][j];
			if (mat[i][j] == BACTERIA)
				bac_list.emplace_back(i, j);
			else if (mat[i][j] == EMPTY_SPACE)
				empty_list.emplace_back(i, j);
		}
	}

	int max = 0;
	int len = empty_list.size();
	// 빈 공간 리스트에서 3개의 공간을 선택하여 벽 설치
	for (int i = 0; i < len - 2; ++i) {
		for (int j = i + 1; j < len - 1; ++j) {
			for (int k = j + 1; k < len; ++k) {
				copy_mat(copied_mat, mat);

				set_wall(copied_mat, empty_list[i]);
				set_wall(copied_mat, empty_list[j]);
				set_wall(copied_mat, empty_list[k]);

				simulation(copied_mat, bac_list);
				int score = evaluate(copied_mat, EMPTY_SPACE);

				if (score > max)
					max = score;
			}
		}
	}
	cout << max;

	return 0;
}

void copy_mat(Matrix& dest, Matrix& src) {
	if ((dest.size() != src.size()) || dest[0].size() != src[0].size())
		return;

	for (int i = 0; i < src.size(); ++i)
		for (int j = 0; j < src[i].size(); ++j)
			dest[i][j] = src[i][j];
}

void set_wall(Matrix& mat, Point& pos) {
	if ((pos.first < 0 || pos.first >= mat.size()) ||
		(pos.second < 0) || pos.second >= mat[pos.first].size())
		return;

	mat[pos.first][pos.second] = 1;
}

void simulation(Matrix& mat, vector<Point>& bac_list) {
	for (auto bac : bac_list)
		bfs(mat, bac.first, bac.second);
}

int evaluate(Matrix& mat, int target) {
	int score = 0;
	for (auto vec : mat)
		for (auto value : vec)
			if (value == target)
				++score;

	return score;
}

void bfs(Matrix& mat, int i, int j) {
	// 모든 방향에 대해서
	for (int d = 0; d < 4; ++d) {
		// 확산이 가능하면 확산
		if (!mat[i + dir[d][0]][j + dir[d][1]]) {
			mat[i + dir[d][0]][j + dir[d][1]] = BACTERIA;
			bfs(mat, i + dir[d][0], j + dir[d][1]);
		}
	}
}