#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Problem {
	vector<pair<int, int>> fruits; 
	public:
	Problem(int n) {
		fruits.reserve(n);
		for (int i = 0; i < n; ++i) {
			int price, calorie;
			cin >> price >> calorie;
			
			fruits.emplace_back(price, calorie);
		}
		sort(fruits.begin(), fruits.end(), compare);
	}
	
	static bool compare(const pair<int, int>& left, const pair<int, int>& right) noexcept {
		return ((left.second / left.first) > (right.second / right.first));
	}
	
	long long get_max_calories(int money) noexcept {
		long long calorie_sum = 0;
		
		for (const auto& [ price, calorie ] : fruits) {
			if (money >= price) {
				money -= price;
				calorie_sum += calorie;
			}
			else {
				calorie_sum += money * (calorie / price);
				break;
			}
		}
		
		return calorie_sum;
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	
	Problem problem(n);
	cout << problem.get_max_calories(k) << "\n";
	
	return 0;
}