#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printSolution(int testCase, int treeCnt);
bool bfs_with_check_loop(vector<vector<int>>& arr, vector<bool>& isVisit, int start);

int problem4803() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/*
	 * n : vertext num
	 * m : edge num
	 */
	int n, m;
	cin >> n >> m;

	int testCase = 0;
	// Exit Code : "0 0"
	while (n != 0 || m != 0) {
		vector<vector<int>> arr = vector<vector<int>>(n + 1, vector<int>());
		vector<bool> isVisit(n + 1, false);

		++testCase;

		/* Get Input */
		for (int i = 0; i < m; ++i) {
			int ver1, ver2;
			cin >> ver1 >> ver2;

			arr[ver1].emplace_back(ver2);
			arr[ver2].emplace_back(ver1);
		}

		/* 전 탐색 */
		int treeCnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (isVisit[i] == false) {
				isVisit[i] = true;
				bool isTree = bfs_with_check_tree(arr, isVisit, i);

				if (isTree)
					++treeCnt;
			}
		}

		/* Print Solution */
		printSolution(testCase, treeCnt);
		
		cin >> n >> m;
	}

	return 0;
}

// bfs하며 루프가 있는지 여부를 반환
bool bfs_with_check_tree(vector<vector<int>>& arr, vector<bool>& isVisit, int start) {
	bool isTree = true;

	queue<int> que;
	que.emplace(start);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		int loopChecker = 0;
		for (int i = 0; i < arr[cur].size(); ++i) {
			// #Case : 기존에 방문한 노드
			if (isVisit[arr[cur][i]])
				++loopChecker;

			// #Case : 처음 방문하는 노드
			else {
				isVisit[arr[cur][i]] = true;
				que.push(arr[cur][i]);
			}
		}

		if (loopChecker > 1)
			isTree = false;
	}

	return isTree;
}

void printSolution(int testCase, int treeCnt) {
	cout << "Case " << testCase << ": ";

	switch (treeCnt) {
	case 0:
		cout << "No trees.\n"; break;

	case 1:
		cout << "There is one tree.\n"; break;

	default:
		cout << "A forest of " << treeCnt << " trees.\n"; break;
	}
}