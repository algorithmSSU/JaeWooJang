#include <iostream>
#include <iomanip>
#include <functional>

using namespace std;

int problem14425(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	int cnt = 0;

	cin >> n >> m;

	int* arr = new int[n];
	hash<string> str_hash;
	string input;
	int tmp;

	for (int i = 0; i < n; ++i) {
		cin >> input;
		arr[i] = str_hash(input);
	}

	for (int j = 0; j < m; ++j) {
		cin >> input;
		tmp = str_hash(input);

		for (int i = 0; i < n; ++i)
			if (arr[i] == tmp)
				++cnt;
	}

	cout << cnt << "\n";

	delete[] arr;

	return 0;
}