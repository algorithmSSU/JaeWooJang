#include <iostream>
#include <queue>

using namespace std;

class VertexMatrix {
public :
	int** mat;
	int size;

	VertexMatrix(int m) {
		size = m;

		mat = new int* [size + 1];
		for (int i = 0; i < size + 1; ++i)
			mat[i] = new int[size + 1];

		// Matrix Init 
		for (int i = 0; i <= size; ++i) {
			for (int j = 0; j <= size; ++j)
				mat[i][j] = 0;

			// Self Connection
			mat[i][i] = 1;
		}
	}

	~VertexMatrix() {
		for (int i = 0; i < size + 1; ++i)
			delete[] mat[i];
		delete[] mat;

		mat = NULL;
	}

	void push(int a, int b) {
		mat[a][b] = 1;
		mat[b][a] = 1;
	}

	int travleAll() {
		bool* isVisit = new bool[size + 1];
		int cnt = 0;

		for (int i = 1; i <= size; ++i)
			isVisit[i] = false;

		for (int i = 1; i <= size; ++i)
			cnt += travle(i, isVisit);

		delete[] isVisit;

		return cnt;
	}

	// travle : visit all vertex conneted with vertex i
	// return << 0 : already travled, 1 : travle new group
	int travle(int i, bool* isVisit) {
		if (isVisit[i])
			return 0;
		
		// BFS Visit
		queue<int>* que = new queue<int>;
		que->push(i);

		while (!que->empty()) {
			int val = que->front();
			que->pop();

			if (isVisit[val])
				continue;

			isVisit[val] = true;

			for (int i = 1; i <= size; ++i)
				if (mat[val][i] == 1)
					que->push(i);
		}
	
		return 1;
	}

};

int problem11724() {
	int m, n;

	cin >> n >> m;

	VertexMatrix vMat(n);

	// Matrix Setting
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		vMat.push(a, b);
	}

	cout << vMat.travleAll();

	return 0;
}