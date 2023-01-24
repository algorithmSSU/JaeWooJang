#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

using Matrix = vector<vector<int>>;

void printMat(Matrix& mat);

int main() {
	int n, m;
	cin >> n >> m;

	Matrix mat = Matrix(n + 2, vector<int>(m + 2, 1));

	for (int i = 0; i < len - 2; ++i) {
		for (int j = i; j < len - 1; ++j) {
			for (int k = j; k < len; ++k) {
				i;
				j;
				k;

				=>



			}
		}
	}
	vector<pair<int, int>> bac_list;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mat[i][j];
			if (mat[i][j] == 2)
				bac_list.emplace_back(i, j);
		}
	}

	printMat(mat);

	for (auto bac : bac_list) {
		bfs(mat, bac.first, bac.second);
	}

	//printMat(mat);

	return 0;
}

void bfs(Matrix& mat, int i, int j) {
	if (!mat[i - 1][j]) {
		mat[i - 1][j] = 2;
		bfs(mat, i - 1, j);
	}

	if (!mat[i + 1][j]) {
		mat[i + 1][j] = 2;
		bfs(mat, i + 1, j);
	}

	if (!mat[i][j - 1]) {
		mat[i][j - 1] = 2;
		bfs(mat, i, j - 1);
	}

	if (!mat[i][j + 1]) {
		mat[i][j + 1] = 2;
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