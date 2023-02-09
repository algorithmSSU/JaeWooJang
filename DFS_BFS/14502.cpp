#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define EMPTY_SPACE	0
#define WALL		1
#define BACTERIA	2

using Matrix = vector<vector<int>>;

void set_wall	(Matrix& mat, pair<int, int>& pos);
void simulation	(Matrix& mat, vector<pair<int, int>>& bac_list);
int  evaluate	(Matrix& mat, int target);
void bfs		(Matrix& mat, int i, int j);
void copy_mat	(Matrix& dest, Matrix& src);
void printMat	(Matrix& mat);

int main() {
	int n, m;
	cin >> n >> m;

	Matrix mat = Matrix(n + 2, vector<int>(m + 2, 1));
	Matrix copied_mat = Matrix(n + 2, vector<int>(m + 2, 1));

	vector<pair<int, int>> bac_list;
	vector<pair<int, int>> empty_list;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mat[i][j];

			// 박테리아와 빈공간의 좌표를 별도의 벡터로 저장
			if (mat[i][j] == BACTERIA)
				bac_list.emplace_back(i, j);
			else if (mat[i][j] == EMPTY_SPACE)
				empty_list.emplace_back(i, j);
		}
	}

	int max = 0;
	int len = empty_list.size();
	// empty_list에서 3개를 뽑아 시뮬레이션
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

void set_wall(Matrix& mat, pair<int, int>& pos) {
	if ((pos.first < 0 || pos.first >= mat.size()) ||
		(pos.second < 0) || pos.second >= mat[pos.first].size())
		return;

	mat[pos.first][pos.second] = 1;
}

void simulation(Matrix& mat, vector<pair<int, int>>& bac_list) {
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
	if (!mat[i - 1][j]) {
		mat[i - 1][j] = BACTERIA;
		bfs(mat, i - 1, j);
	}

	if (!mat[i + 1][j]) {
		mat[i + 1][j] = BACTERIA;
		bfs(mat, i + 1, j);
	}

	if (!mat[i][j - 1]) {
		mat[i][j - 1] = BACTERIA;
		bfs(mat, i, j - 1);
	}

	if (!mat[i][j + 1]) {
		mat[i][j + 1] = BACTERIA;
		bfs(mat, i, j + 1);
	}
}

void printMat(Matrix& mat) {
	for (auto vec : mat) {
		for (auto val : vec)
			cout << val << " ";
		cout << "\n";
	}
}