#include <iostream>
#include <vector>
//#include "mytool.h"

using namespace std;

int min(int _Left, int _Mid, int _Right);

int problem1915() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<char>> mat;
	vector<vector<int>> sol;

	mat.reserve(n + 2);
	sol.reserve(n + 2);
	for (int i = 0; i < n + 2; ++i) {
		mat.emplace_back(m + 2, 0);
		sol.emplace_back(m + 2);
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> mat[i][j];

	int max = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (mat[i][j] != '0') {
				sol[i][j] = min(sol[i - 1][j], sol[i][j - 1], sol[i - 1][j - 1]) + 1;

				if (sol[i][j] > max)
					max = sol[i][j];
			}
		}
	}

	//print_mat(sol);

	cout << max * max;

	//print_mat<char>(mat);


	return 0;

}

int min(int _Left, int _Mid, int _Right) {
	int _Min = (_Left < _Mid) ? _Left : _Mid;
	return ((_Min < _Right) ? _Min : _Right);
}