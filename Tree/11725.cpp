#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int problem11725() {
	int n = 0;

	cin >> n;

	vector<vector<int>> mat(n + 1, vector<int>());
	
	// 노드간 연결 입력 받기 -> set에 저장
	for (int i = 0; i < n - 1; ++i) {
		int vert1, vert2;

		cin >> vert1 >> vert2;

		mat[vert1].emplace_back(vert2);
		mat[vert2].emplace_back(vert1);
	}

	// answer : 해당 인덱스의 노드의 부모 값 저장
	vector<int> answer(n + 1, 0);
	queue<int> que;

	que.push(1);
	while (!que.empty()) {
		int current = que.front();
		que.pop();

		// 자식 idx에 현재 값(부모) 저장
		for (int i = 0; i < mat[current].size(); ++i) {
			// 이미 부모가 있는경우 <= 현재 값의 부모(자식X)
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