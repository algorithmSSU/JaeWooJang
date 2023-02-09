#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;
using Matrix = vector<vector<int>>;

inline int minimum(int a, int b) {
	return (a < b) ? a : b;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	Matrix mat(n + 1, vector<int>(n + 1, INT_MAX));

	for (int i = 0; i < m; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;

		mat[from][to] = cost;
	}

	int start, end;
	cin >> start >> end;

	vector<int> isVisisted(n + 1, INT_MAX);
	isVisisted[start] = 0;
	for (int i = 0; i < n + 1; ++i) {

	}



	cout << mat[start][end];

	return 0;
}