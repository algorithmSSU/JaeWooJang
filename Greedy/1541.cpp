#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int problem1541() {
	char exper[51];
	int length;

	cin >> exper;
	length = strlen(exper);

	vector<int> numArr;

	int value = 0;
	int sum = 0;

	bool isBracket = false;
	for (int i = 0; i < length; ++i) {
		// Case : Operator
		if ((exper[i] == '+') || (exper[i] == '-')) {
			if (!isBracket) {
				sum += value;
				if (exper[i] == '-')
					isBracket = true;
			}
			else
				sum -= value;

			value = 0;
		}
		// Case : Value
		else
			value = value * 10 + exper[i] - '0';
	}
	if (!isBracket)
		sum += value;
	else
		sum -= value;

	cout << sum;

	return 0;
}