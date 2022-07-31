#include <iostream>
#include <vector>

using namespace std;

#define MIN -1001

int max(int _Left, int _Right);

int problem13398() {
	int n;
	cin >> n;

	// 어떤 마이너스를 0으로 바꾼 경우의 최대
	vector<int> max_with_zero(n);
	// 어떠한 마이너스도 0으로 바꾸지 않은 경우의 최대 
	vector<int> max_without_zero(n);

	max_with_zero[0] = MIN;
	cin >> max_without_zero[0];

	for (int i = 1; i < n; ++i) {
		int input;
		cin >> input;

		// For Max With Zero 
		int val1 = max_with_zero[i - 1] + input;	// with zero + input
		int val2 = max_without_zero[i - 1];			// without zero + 0

		max_with_zero[i] = max(val1, val2);


		// For Max With Out Zero
		val1 = input;								// new start
		val2 = max_without_zero[i - 1] + input;		// without zero + input

		max_without_zero[i] = max(val1, val2);
	}

	/* Search Max */
	int max = MIN;
	for (const auto val : max_with_zero)
		if (val > max)
			max = val;

	for (const auto val : max_without_zero)
		if (val > max)
			max = val;
	cout << max;

	return 0;
}
/*
int max(int _Left, int _Right) {
	return ((_Left > _Right) ? _Left : _Right);
}
*/