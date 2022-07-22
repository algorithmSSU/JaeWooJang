#include <iostream>
#include <vector>

using namespace std;

long long getCaseNum(vector<vector<vector<long long>>>& arr, int n, int l, int r);
void printArr(vector<vector<vector<long long>>>& arr);

int maint() {
	int n, l, r;

	cin >> n >> l >> r;

	vector<vector<vector<long long>>> arr;
	for (int i = 0; i <= n; ++i) {
		arr.emplace_back();
		for (int j = 0; j <= i; ++j)
			arr[i].emplace_back(i + 1, 0);
	}

	//printArr(arr);

	cout << getCaseNum(arr, n, l, r) << endl;
	printArr(arr);
	cout << getCaseNum(arr, n, l, r) << endl;

	return 0;
}

long long getCaseNum(vector<vector<vector<long long>>>& arr, int n, int l, int r) {
	if (n < 2)
		return arr[n][l][r] = 1;


	if (arr[n][l][r] != 0)
		return arr[n][l][r];

	int sum = 0;
	if (l - 1 > 0)
		for (int k = r; k <= n - l + 1; ++k)
			sum += getCaseNum(arr, n - 1, l - 1, k);
	if (r - 1 > 0)
		for (int k = l; k <= n - r + 1; ++k)
			sum += getCaseNum(arr, n - 1, k, r - 1);

	arr[n][l][r] = sum;

	return arr[n][l][r];
}

void printArr(vector<vector<vector<long long>>>& arr) {
	for (int n = 1; n < arr.size(); ++n) {
		cout << "n : " << n << "\n";
		for (int i = 1; i < arr[n].size(); ++i) {
			for (int j = 1; j < arr[n][i].size(); ++j)
				cout << arr[n][i][j] << " ";
			cout << "\n";
		}
		cout << "\n\n";
	}
}