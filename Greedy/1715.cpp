#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int problem1715() {
	int input;
	
	int n;
	cin >> n;

	// 오름차순 우선순위 큐
	priority_queue<int, vector<int>, greater<int>> arr;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		arr.push(input);
	}

	int sum = 0;
	while (arr.size() > 1) {
		// 작은 두 수를 더하기
		int a = arr.top(); arr.pop();
		int b = arr.top(); arr.pop();

		// 더한 수를 다시 우선순위 큐에 추가
		arr.push(a + b);
		sum += a + b;
	}

	cout << sum;

	return 0;
}