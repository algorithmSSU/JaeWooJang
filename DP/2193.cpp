#include <iostream>
#include <vector>

using namespace std;

long long briendNum(vector<long long>& arr, int n);

int problem2193() {
	int n;

	cin >> n;
	vector<long long> arr(n + 1, 0);

	cout << briendNum(arr, n);

	return 0;
}

long long briendNum(vector<long long>& arr, int n) {
	if (n < 3)
		return 1;

	if (arr[n] != 0)
		return arr[n];


	// n(10{ n - 2 이친수 }) + n(100 { n - 1 이친수의 첫자리 제외 숫자 }) 
	arr[n] = briendNum(arr, n - 1) + briendNum(arr, n - 2);
	return arr[n];
}