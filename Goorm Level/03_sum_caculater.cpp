#include <iostream>

using namespace std;

inline int caclulate(const int num1, const int num2, const char oper) {
	switch (oper) {
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		case '*':
			return num1 * num2;
		case '/':
			return num1 / num2;
	}
	
	return -1;
}

int main() {
	int T;
	cin >> T;
	
	int sum = 0;
	for (int t = 0; t < T; ++t) {
		int num1, num2;
		char oper;
		cin >> num1 >> oper >> num2;
		
		sum += caclulate(num1, num2, oper);
	}
	
	cout << sum << "\n";
	
	return 0;
}