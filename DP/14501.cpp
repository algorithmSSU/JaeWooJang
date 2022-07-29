#include <iostream>
#include <vector>

using namespace std;

int noName(vector<pair<int, int>>& arr, int n, int cur);

int problem14501() {
	int n;
	cin >> n;
	
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i].first >> arr[i].second;

	cout << noName(arr, n, 0);

	return 0;
}

int noName(vector<pair<int, int>>& arr, int endDate, int cur) {
	if (cur == endDate)
		return 0;

	int next = cur + arr[cur].first;
	int value1 = 0;
	int value2 = 0;

	if (next <= endDate)
		// Case : �ش� ��¥�� ����� �޴� ���
		value1 = noName(arr, endDate, next) + arr[cur].second;

	if (cur + 1 <= endDate)
		// Case : �ش� ��¥�� ����� ���� �ʴ� ���
		value2 = noName(arr, endDate, cur + 1);

	return max(value1, value2);
}