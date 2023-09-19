#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int bandage = 1;
const int medicin = 7;
const int painkiller = 14;

const vector<int> items = { painkiller, medicin, bandage };

inline int min_count(int n) noexcept {
	int count = 0;
	
	for (const auto item : items) {
		count += (n / item);
		n %= item;
	}

	return count;
}

int main() {
	int n;
	cin >> n;
	
	cout << min_count(n) << "\n";
	
	return 0;
}