#include <iostream>
#include <vector>

using namespace std;

inline int get_taste(const int n) noexcept {
	int before, cur = 0;
	bool is_rasing = true;
	
	cin >> before;
	int sum = before;
	for (int i = 1; i < n; ++i) {
		cin >> cur;
		if (is_rasing) {
			if (cur < before)
				is_rasing = false;
		}
		
		else {
			if (cur > before)
				return 0;
		}
		
		sum += cur;
		before = cur;
	}
	
	return sum;
}

int main() {
	int n;
	cin >> n;
	
	cout << get_taste(n) << "\n";
	
	return 0;
}