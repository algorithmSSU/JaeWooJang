#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class PainSystem {
	const vector<int>& items;
	public:
	PainSystem(const vector<int>& items) : items{items} { }
	
	int get_min_count(int n) noexcept {
		vector<bool> visited(n + 1);
		queue<pair<int, int>> que;
		for (const auto item : items) {
			que.emplace(item, 1);
			visited[item] = true;
		}
		
		while (!que.empty()) {
			auto [ value, count ] = que.front();
			que.pop();
			
			if (value == n)
				return count;
			
			for (const auto item : items) {
				int next = value + item;
				if (next <= n) {
					if (!visited[next]) {
						visited[next] = true;
						que.emplace(next, count + 1);
					}
				}
			}
		}
		
		return -1;
	}
};

int main() {
	int n;
	cin >> n;
	
	constexpr int item_count = 2;
	vector<int> items(item_count);
	for (int i = 0; i < item_count; ++i)
		cin >> items[i];
	
	PainSystem pain_sys(items);
	cout << pain_sys.get_min_count(n) << "\n";
	
	return 0;
}