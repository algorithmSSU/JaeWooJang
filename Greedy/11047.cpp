#include <iostream>
#include <vector>

using namespace std;

int problem11047() {
	int n, k;
	cin >> n >> k;

	vector<int> coinType(n);
	for (int i = 0; i < n; ++i)
		cin >> coinType[i];

	int count = 0;

	// ū ������ ���� �켱������ �����Ѵ�.
	for (int i = n - 1; i > -1; --i) {
		count += k / coinType[i];
		k %= coinType[i];
	}

	cout << count;

	return 0;
}