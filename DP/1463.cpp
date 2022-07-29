#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000000

int calculate(vector<int>& arr, int n);
int min(int a, int b, int c);

int problem1463() {
	int n;
	cin >> n;

	// �ߺ� ����� ���� ����� ���� �޸�
	vector<int> arr(n + 1, -1);
	arr[0] = MAX;
	arr[1] = 0;
		
	cout << calculate(arr, n);

	return 0;
}

int calculate(vector<int>& arr, int n) {
	// Case : ������ ����� �̷���� ���
	if (arr[n] != -1)
		return arr[n];

	// Case : ó�� ����� �ϴ� ��� (���)
	int division3 = ((n % 3) == 0) ? calculate(arr, n / 3) : MAX; 
	int division2 = ((n % 2) == 0) ? calculate(arr, n / 2) : MAX;
	int minus1 = calculate(arr, n - 1);

	// 3���� ��� �� �� �ּҰ� ����
	arr[n] = min(division3, division2, minus1) + 1;

	return arr[n];
}

int amin(int a, int b, int c) {
	int min = (a < b) ? a : b;
	min = (c < min) ? c : min;

	return min;
}