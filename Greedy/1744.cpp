#include <iostream>
#include <queue>

using namespace std;

int problem1744() {
	int input;

	int n;
	cin >> n;

	priority_queue<int> arr;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		arr.push(input);
	}

	return 0;
}