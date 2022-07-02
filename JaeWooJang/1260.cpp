#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void DFS(vector<int>*, int, int);
void BFS(vector<int>*, int, int);
void insertValue(vector<int>*, int);

int problem1260(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int vertexNum, edgeNum, startPoint;

	cin >> vertexNum >> edgeNum >> startPoint;

	// Liked List�� �̿��� ����� ǥ��
	vector<int>* arr = new vector<int>[vertexNum + 1];

	for (int i = 0; i < edgeNum; i++) {
		int start, end;
		cin >> start >> end;

		// insertValue => arr[]�� �������ĵȴ�.
		insertValue(&arr[start], end);
		insertValue(&arr[end], start);
	}

	DFS(arr, vertexNum, startPoint);
	BFS(arr, vertexNum, startPoint);

	delete[] arr;

	return 0;
}

// insertValue : arr�� value�� ����
void insertValue(vector<int>* arr, int value) {
	for (vector<int>::iterator it = arr->begin(); it != arr->end(); it++)
		if (*it >= value) {
			arr->insert(it, value);
			return;
		}

	arr->push_back(value);
}

void DFS(vector<int>* arr, int vertexNum, int start) {
	stack<int> DFSstack;
	vector<int> visited(vertexNum + 1, 0);

	// �� ������ ���Ͽ�, �ش� �������� �������� �̵��� ������ ����ų iterator(index)
	vector<int>::iterator* pIndex = new vector<int>::iterator[vertexNum + 1];
	for (int i = 1; i < vertexNum + 1; i++)
		pIndex[i] = arr[i].begin();

	// ������ �湮
	cout << start << ' ';
	DFSstack.push(start);
	visited[start] = 1;

	while (!DFSstack.empty()) {
		int cur = DFSstack.top();

		// �湮�� �� �ִ� ���� ������ �ִ� ���
		if (pIndex[cur] != arr[cur].end()) {
			// ���� ������ ó�� �湮�ϴ� ���
			if (!visited[*pIndex[cur]]) {
				// ���� ���� stack�� �߰�, �湮 ó��, ���
				cout << *pIndex[cur] << ' ';
				DFSstack.push(*pIndex[cur]);
				visited[*pIndex[cur]] = 1;

				pIndex[cur]++;
			}
			// ���� ������ ������ �湮�� ���
			else pIndex[cur]++;
		}
		// ���̻� �湮�� ������ ���� ���
		else DFSstack.pop();
	}
	cout << '\n';

	delete[] pIndex;
}

void BFS(vector<int>* arr, int vertexNum, int start) {
	queue<int> BFSqueue;
	vector<int> visited(vertexNum + 1, 0);

	BFSqueue.push(start);

	while (!BFSqueue.empty()) {
		int cur = BFSqueue.front();

		// ���� ��带 ó��	�湮�ϴ� ���
		if (!visited[cur]) {
			cout << cur << ' ';
			visited[cur] = 1;

			// ���� ������ ��� ������ queue�� �߰�
			for (vector<int>::iterator it = arr[cur].begin(); it != arr[cur].end(); it++)
				if (!visited[*it])
					BFSqueue.push(*it);
		}
		BFSqueue.pop();
	}
	cout << '\n';
}