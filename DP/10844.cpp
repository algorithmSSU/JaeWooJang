#include <iostream>
#include <vector>

using namespace std;

long long getStairCnt(int n);

int problem10844() {
	int n = 0; 
	cin >> n;

	cout << getStairCnt(n);

	return 0;
}

long long getStairCnt(int n) {
	vector<long long> numCnt[]{ 
		vector<long long>(10, 1),
		vector<long long>(10, 1)
		};
	
	numCnt[0][0] = 0;
	numCnt[1][0] = 0;

	int cur = 0;
	int next = 1;

	for (int i = 1; i < n; ++i) {
		numCnt[next][0] = numCnt[cur][1];

		for (int j = 1; j < 9; ++j)
			numCnt[next][j] = 
				(numCnt[cur][j - 1] + numCnt[cur][j + 1]) % 1000000000LL;

		numCnt[next][9] = numCnt[cur][8];

		int tmp = cur;
		cur = next;
		next = tmp;
	}

	long long sum = 0;
	for (int i = 0; i < 10; ++i)
		sum += numCnt[cur][i];

	return sum % 1000000000LL;
}