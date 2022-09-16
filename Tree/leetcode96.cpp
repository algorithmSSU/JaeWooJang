#include <iostream>
#include <vector>

using namespace std;

class Solution {
	static int arr[20];

public:
	static int numTrees(int n) {
		if (n < 2)
			return 1;

		if (arr[n] == 0) {
			int sum = 0;
			for (int i = 0; i < n; ++i)
				sum += numTrees(i) * numTrees(n - 1 - i);

			arr[n] = sum;
		}

		return arr[n];
	}
};

int main() { 
	int n;
	cin >> n;
	
	cout << Solution::numTrees(n);

	return 0;
}