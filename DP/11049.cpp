#include <iostream>
#include <vector>

using namespace std;

long long getMin(const vector<long long>& arr, int n );
long long min(const vector<vector<long long>>& mat, const vector<long long>& arr, const int i, const int j);

int problem11049() {
	int n;
	cin >> n;

	vector<long long> arr(n + 1);
	for (int i = 0; i < n; ++i)
		cin >> arr[i] >> arr[i + 1];

	cout << getMin(arr, n);

	return 0;
}

long long getMin(const vector<long long>& arr, int n) {
	vector<vector<long long>> mat;
	for (int i = 0; i < n; ++i)
		mat.emplace_back(n, 0);

	for (int unionSize = 1; unionSize < n; ++unionSize) {
		for (int i = 0; i < n - unionSize; ++i) {
			int j = i + unionSize;
			mat[i][j] = min(mat, arr, i, j);
		}
	}

	return mat[0][n - 1];
}

long long min(const vector<vector<long long>>& mat, const vector<long long>& arr, const int i, const int j) {
	// { i ~ j 까지의 곱 } = min ({ i ~ k 까지의 곱 } + { k * j까지의 곱 } + 두 행렬 곱하는 크기)
	long long min = mat[i][i] + mat[i + 1][j] + arr[i] * arr[i + 1] * arr[j + 1];

	for (int k = i + 1; k < j; ++k) {
		long long tmp = mat[i][k] + mat[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
		if (tmp < min)
			min = tmp;
	}

	return min;
}