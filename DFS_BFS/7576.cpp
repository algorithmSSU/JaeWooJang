#include <iostream>
#include <vector>
#include <queue>

#define TOMATO	1
#define WALL	-1

using namespace std;

using Point = pair<int, int>;
using Matrix = vector<vector<int>>;

const int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

int bfs(Matrix& mat, int cur, int cycle);
bool checkAll(Matrix& mat);

queue<Point> tomato_list[2];

int problem7576() {
	int m, n;

	cin >> m >> n;

	Matrix mat = Matrix(n + 2, vector<int>(m + 2, -1));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mat[i][j];

			if (mat[i][j] == TOMATO)
				tomato_list[0].emplace(i, j);
		}
	}

	int cycle = bfs(mat, 0, 0);

	// 모든 토마토가 숙성되었는지 확인 
	if (checkAll(mat))
		cout << cycle;
	else
		cout << -1;

	return 0;
}

int bfs(Matrix& mat, int cur, int cycle) {
	// 새로 익은 토마토가 없는 경우 => 종료
	if (tomato_list[cur].empty())
		return cycle - 1;

	// 토마토 새로 익을 토마토 큐 선택
	int next = (cur == 1) ? 0 : 1;

	// BFS
	while (!tomato_list[cur].empty()) {
		Point tomato = tomato_list[cur].front();
		tomato_list[cur].pop();

		// i, j는 좌표
		int i = tomato.first;
		int j = tomato.second;

		// 위 아래 양 옆을 기준으로
		for (int d = 0; d < 4; ++d) {
			// 숙성 가능 한 경우
			if (!mat[i + dir[d][0]][j + dir[d][1]]) {
				// 숙성 및 새로 익을 토마토 리스트에 추가
				mat[i + dir[d][0]][j + dir[d][1]] = TOMATO;
				tomato_list[next].emplace(i + dir[d][0], j + dir[d][1]);
			}
		}
	}

	// 새로 익을 토마토 리스트
	return bfs(mat, next, cycle + 1);
}

bool checkAll(Matrix& mat) {
	for (auto vec : mat) {
		for (auto val : vec)
			if (!val)
				return false;
	}

	return true;
}