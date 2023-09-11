#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class BinaryCounter {
	static vector<int> dp;
	public:
	static inline void set_range(const int n) {
		dp = vector<int>(n, 0);
	}
	
	static inline int get_one_count(const int n) noexcept {
		if (dp[n] <= 0) {
			int rest = n;	
			while (rest > 0) {
				dp[n] += rest % 2;
				rest *= 0.5;
			}
		}

		return dp[n];	
	}

	static inline bool compare(const int left, const int right) noexcept {
		if (get_one_count(left) == get_one_count(right))
			return left > right;
		
		return (get_one_count(left) > get_one_count(right));
	}
};

vector<int> BinaryCounter::dp;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	
	int max = *max_element(nums.begin(), nums.end());
	BinaryCounter::set_range(max + 1);
	
	sort(nums.begin(), nums.end(), BinaryCounter::compare);
	
	cout << nums[k - 1] << "\n";
	
	return 0;
}