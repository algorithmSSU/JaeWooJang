#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int problem11725() {
	int n = 0;

	cin >> n;

	vector<vector<int>> mat(n + 1, vector<int>());

	for (int i = 0; i < n - 1; ++i) {
		int vert1, vert2;

		cin >> vert1 >> vert2;

		mat[vert1].emplace_back(vert2);
		mat[vert2].emplace_back(vert1);
	}

	vector<int> answer(n + 1, 0);
	queue<int> que;

	que.push(1);
	while (!que.empty()) {
		int current = que.front();
		que.pop();

		for (int i = 0; i < mat[current].size(); ++i) {
			if (!answer[mat[current][i]]) {
				que.push(mat[current][i]);
				answer[mat[current][i]] = current;
			}
		}
	}

	/* Print Ansewr */
	for (int i = 2; i <= n; ++i)
		cout << answer[i] << "\n";

	return 0;
}