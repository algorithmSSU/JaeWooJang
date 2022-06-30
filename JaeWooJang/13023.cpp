#include <iostream>
#include <vector>

using namespace std;
/* <���� Ǯ�� �帧>
 * 1. graph�����̴� 11724������ ������ class VertexMatrix�� ��Ȱ���Ͽ� Ǯ��� => �ð� �ʰ�
 * 2. stack���� �����Ͽ��� DFS -> ��� DFS�� �����Ͽ� stack���� �ҿ�Ǵ� �ð��� �ٿ����� => �ð� �ʰ�
 * 3. ��� ����� ���� ����Ͽ� ��� Matrix -> Linked List Graph�� ��ȯ�ϰ�, ���� ������ �Ź� �˻��ϰ�,
 *    class�� �ƴ� ���� �Լ��� �����Ͽ� �ð��� ���� ��Ű�� => ����
 * 4. ���������� �Ź� �˻����� �ʰ�, ��� depth�� ����� ���Ŀ� ���� ������ �˻��Ѵ� => �ð� �ʰ�
 * 
 * + ��� Matrix�� ������ ���̽��� �ش� ��ũ��Ʈ �Ʒ��� �ּ����� �־� �ξ���.
 */

/* dfs : ���� ������ �����ϸ� �ٷ� ������� ����
 * 
 * => ���� ������ �ż��� �˻����� �ʰ�, dfs �Լ����� �ִ� depth�� max�� ��ȯ�ϰ�
 * ��������� ������ max�� 5���� ū�� ������ ���ϵ��� Ǯ�� ���Ҵµ� �ð� �ʰ��� �߻��Ѵ�.
 * ���� �̰��� �ùٸ� �˰������� ����� �ǽɽ�����.
 * ���������� ������ �������̶�� ������
 * ���� �˰����� ���� ��������, ������ ���� �˰������� �ǹ��� ���.
 * 
 * ���������� �ƿ� �ٸ� �˰������� Ǫ�°��� ���� �����̱� ����Ѵ�.
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
 * [ ��� Matrix�� ������ Case ]
 * 
 * �ִ� 2000 * 2000 �������ӿ� ���� edge�� ���� 2000������ ���� ���� ��� ������� �� �� �ִ�.
 * ���� �ش� ����� Overhead�� ����ϴ�.
 * 
 * ���� ������ ���� ������ ���� Vertex�� ���� Edge�� ���� Ȯ���ϰ�,
 * Linked List�� ��������, Matrix�� �������� �����ϰ� �õ��ؾ��Ѵ�.
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