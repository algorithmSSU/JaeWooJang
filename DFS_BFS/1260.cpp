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

	// Liked List를 이용한 행렬의 표현
	vector<int>* arr = new vector<int>[vertexNum + 1];

	for (int i = 0; i < edgeNum; i++) {
		int start, end;
		cin >> start >> end;

		// insertValue => arr[]가 삽입정렬된다.
		insertValue(&arr[start], end);
		insertValue(&arr[end], start);
	}

	DFS(arr, vertexNum, startPoint);
	BFS(arr, vertexNum, startPoint);

	delete[] arr;

	return 0;
}

// insertValue : arr에 value를 삽입
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

	// 각 정점에 대하여, 해당 정점에서 다음으로 이동할 정점을 가르킬 iterator(index)
	vector<int>::iterator* pIndex = new vector<int>::iterator[vertexNum + 1];
	for (int i = 1; i < vertexNum + 1; i++)
		pIndex[i] = arr[i].begin();

	// 시작점 방문
	cout << start << ' ';
	DFSstack.push(start);
	visited[start] = 1;

	while (!DFSstack.empty()) {
		int cur = DFSstack.top();

		// 방문할 수 있는 다음 정점이 있는 경우
		if (pIndex[cur] != arr[cur].end()) {
			// 다음 정점에 처음 방문하는 경우
			if (!visited[*pIndex[cur]]) {
				// 다음 정점 stack에 추가, 방문 처리, 출력
				cout << *pIndex[cur] << ' ';
				DFSstack.push(*pIndex[cur]);
				visited[*pIndex[cur]] = 1;

				pIndex[cur]++;
			}
			// 다음 정점에 기존에 방문한 경우
			else pIndex[cur]++;
		}
		// 더이상 방문할 정점이 없는 경우
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

		// 현재 노드를 처음	방문하는 경우
		if (!visited[cur]) {
			cout << cur << ' ';
			visited[cur] = 1;

			// 접근 가능한 모든 정점을 queue에 추가
			for (vector<int>::iterator it = arr[cur].begin(); it != arr[cur].end(); it++)
				if (!visited[*it])
					BFSqueue.push(*it);
		}
		BFSqueue.pop();
	}
	cout << '\n';
}