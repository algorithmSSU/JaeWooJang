#include <iostream>
#include <vector>

using namespace std;
/* <문제 풀이 흐름>
 * 1. graph문제이니 11724번에서 제작한 class VertexMatrix를 재활용하여 풀어보자 => 시간 초과
 * 2. 희소 행렬인 점을 고려하여 행렬 Matrix -> Linked List Graph로 전환하고, 종료 조건을 매번 검사하고,
 *    class가 아닌 전역 함수로 제작하여 시간을 단축 시키자 => 성공
 * 3. 종료조건을 매번 검사하지 않고, 모든 depth를 계산한 이후에 종료 조건을 검사한다 => 시간 초과
 * 
 * + 행렬 Matrix로 접근한 케이스를 해당 스크립트 아래에 주석으로 넣어 두었다.
 */

/* dfs : 종료 조건을 만족하면 바로 벗어나도록 설계
 * 
 * => 종료 조건을 매순간 검사하지 않고, dfs 함수에서 최대 depth를 max로 반환하고
 * 결과적으로 나오는 max가 5보다 큰지 별도로 비교하도록 풀어 보았는데 시간 초과가 발생한다.
 * 과연 이것이 올바른 알고리즘인지 상당히 의심스럽다.
 * 종료조건이 문제에 의존적이라는 점에서
 * 과연 알고리즘을 위한 문제인지, 문제를 위한 알고리즘인지 의문이 든다. 
 * 
 *   => 탐색의 목적이 엄연히 다르다. 해당 발상은 BFS에나 적합한 발상이다.
 *      우선적으로, DFS는 최적해를 반환하지 않는다. 해당 서술에서는 각 반환값의 최대값을 종합한다 하였는데,
 *		해당 알고리즘은 브루트포스와 다를바 없다.
 *		DFS의 목적은 빠르게 파고들며 탐색하는 것이다.
 *		그렇기에 문제에서 요구하는 특정 깊이 이상에 도달하면 탐색의 성공을 의미하고 바로 반환을 하는것이 맞다.
 *		굳이 해당 깊이로 더이상 파고들 필요도, 다른 곳을 파고들 필요도 없다.
 *		
 *		따라서 가장 올바른 것은, 종료 조건 또한 함수의 인자로 전달 하거나, define으로 전처리를 하거나
 *		전역으로 설정하여 문제 의존성을 줄이고
 *		해당 조건이 만족하는지 매번 검사 하는 것이 옳다. 멍청아
 * 
 */
bool dfs(vector<int>* g, bool* isVisit, int cur, int depth) {
	if (depth >= 5)
		return true;

	for (int i = 0; i < g[cur].size(); ++i) {
		if (!isVisit[g[cur][i]]) {
			isVisit[cur] = true;
			if (dfs(g, isVisit, g[cur][i], depth + 1))
				return true;
			isVisit[cur] = false;
		}
	}

	return false;
}

int problem13023() {
	int n, m;
	bool is5Friends = false;
	cin >> n >> m;

	/* Initialize Part */
	vector<int>* graph = new vector<int>[n];

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); 
		graph[b].push_back(a);
	}

	bool* isVisit = new bool[n];
	for (int i = 0; i < n; ++i)
		isVisit[i] = false;

	/* Calculating Part */
	for (int i = 0; i < n; ++i)
		if (is5Friends = dfs(graph, isVisit, i, 1))
			break;

	/* Printing Part */
	cout << is5Friends;

	delete[] graph;
	return 0;
}
/*
 * [ 행렬 Matrix로 구현한 Case ]
 * 
 * 최대 2000 * 2000 사이즈임에 비해 edge의 수가 2000이하인 점을 보면 희소 행렬임을 알 수 있다.
 * 따라서 해당 방법은 Overhead가 상당하다.
 * 
 * 따라서 다음과 같은 문제를 볼때 Vertex의 수와 Edge의 수를 확인하고,
 * Linked List로 구현할지, Matrix로 구현할지 생각하고 시도해야한다.
 * 
class VertexMatrix {
public:
	int** mat;
	int size;

	VertexMatrix(int m) {
		size = m;

		mat = new int* [size];
		for (int i = 0; i < size; ++i)
			mat[i] = new int[size];

		// Matrix Init
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j)
				mat[i][j] = 0;

			// Self Connection
			mat[i][i] = 1;
		}
	}

	~VertexMatrix() {
		for (int i = 0; i < size; ++i)
			delete[] mat[i];
		delete[] mat;

		mat = NULL;
	}

	void push(int a, int b) {
		mat[a][b] = 1;
		mat[b][a] = 1;
	}

	int getMaxDepth() {
		bool* isVisit = new bool[size];
		int max = 1;

		for (int i = 0; i < size; ++i)
			isVisit[i] = false;

		for (int i = 0; i < size; ++i) {
			int tmp = getMaxDepthFromStart(i, isVisit, 0);
			if (tmp > max)
				max = tmp;
		}

		delete[] isVisit;

		return max;
	}

	int getMaxDepthFromStart(int s, bool* isVisit, int depth) {
		int max = depth;
		for (int i = 0; i < size; ++i) {
			if (!isVisit[i])
				if (mat[s][i]) {
					isVisit[i] = true;
					int tmp = getMaxDepthFromStart(i, isVisit, depth + 1);
					isVisit[i] = false;

					if (tmp > max)
						max = tmp;
				}

		}

		return max;
	}
};
*/