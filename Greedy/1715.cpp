#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int problem1715() {
	int input;
	
	int n;
	cin >> n;

	// �������� �켱���� ť
	priority_queue<int, vector<int>, greater<int>> arr;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		arr.push(input);
	}

	int sum = 0;
	while (arr.size() > 1) {
		// ���� �� ���� ���ϱ�
		int a = arr.top(); arr.pop();
		int b = arr.top(); arr.pop();

		// ���� ���� �ٽ� �켱���� ť�� �߰�
		arr.push(a + b);
		sum += a + b;
	}

	cout << sum;

	return 0;
}