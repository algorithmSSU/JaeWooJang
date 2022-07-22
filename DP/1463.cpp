#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000000

int calculate(vector<int>& arr, int n);
int min(int a, int b, int c);

int problem1463() {
	int n;
	cin >> n;

	// 중복 사용을 위한 결과값 저장 메모리
	vector<int> arr(n + 1, -1);
	arr[0] = MAX;
	arr[1] = 0;
		
	cout << calculate(arr, n);

	return 0;
}

int calculate(vector<int>& arr, int n) {
	// Case : 사전에 계산이 이루어진 경우
	if (arr[n] != -1)
		return arr[n];

	// Case : 처음 계산을 하는 경우 (재귀)
	int division3 = ((n % 3) == 0) ? calculate(arr, n / 3) : MAX; 
	int division2 = ((n % 2) == 0) ? calculate(arr, n / 2) : MAX;
	int minus1 = calculate(arr, n - 1);

	// 3가지 결과 값 중 최소값 저장
	arr[n] = min(division3, division2, minus1) + 1;

	return arr[n];
}

int min(int a, int b, int c) {
	int min = (a < b) ? a : b;
	min = (c < min) ? c : min;

	return min;
}