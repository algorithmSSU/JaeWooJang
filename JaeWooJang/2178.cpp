#include <iostream>
#include <queue>

using namespace std;

struct Point {
	char x;
	char y;
	short depth;
};

void frameMat(char** mat, int width, int high, char ch);
int BFS(char** mat, char n, char m);

int problem2178() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	// mat : ������ ������ ���
	//? => static �迭�� ����� ���� ������ �� ������ ���鿡�� ����������..? (size�� 100 100 ���� �̱� ����)
	char** mat = new char* [n + 2];
	for (int i = 0; i < n + 2; ++i)
		mat[i] = new char[m + 2];

	// �׵θ��� ���� ó�� for 1) ������ ����� ���� ���� ����
	//						  2) �˻��� ������ ���̱� ����
	frameMat(mat, m + 2, n + 2, '0');

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> mat[i][j];

	int len = BFS(mat, n, m);

	cout << len;


	/* Free Memory Part */
	for (int i = 0; i < n + 2; ++i) {
		delete[] mat[i];
		mat[i] = NULL;
	}
	delete[] mat;
	mat = NULL;

	return 0;
}

int BFS(char** mat, char n, char m) {
	Point cur = { 1, 1, 1 };
	Point next;
	int len = -1;

	queue<Point> que;
	que.push(cur);
	mat[1][1] = 0;

	char delta[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	while (!que.empty()) {
		cur = que.front();
		que.pop();

		if ((cur.x == m) && (cur.y == n)) {
			len = cur.depth;
			break;
		}

		next.depth = cur.depth + 1;
		for (int i = 0; i < 4; ++i) {
			next.x = cur.x + delta[i][0];
			next.y = cur.y + delta[i][1];

			if (mat[next.y][next.x] == '1') {
				mat[next.y][next.x] = 0;
				que.push(next);
			}
		}
	}

	return len;
}

// initMat : ����� �׵θ��� ch���� ä��
void frameMat(char** mat, int width, int high, char ch) {
	// ����, ���� �׵θ�
	for (int i = 0; i < high; ++i) {
		mat[i][0] = ch;
		mat[i][width - 1] = ch;
	}

	// ���, �ϴ� �׵θ� 
	for (int j = 0; j < width; ++j) {
		mat[0][j] = ch;
		mat[high - 1][j] = ch;
	}
}