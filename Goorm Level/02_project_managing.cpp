#include <iostream>
#include <vector>

using namespace std;

inline pair<int, int> getTime(const int t, const int m, const int duration) noexcept {
	int time = t * 60 + m;
	int after = ((time + duration) % 1440);
	return { after / 60, after % 60 };
}

int main() {
	int n, t, m;
	cin >> n;
	cin >> t >> m;
	
	int duration = 0;
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		
		duration += c;
	}
	
	auto [ hh, mm ] = getTime(t, m, duration);
	cout << hh << " " << mm << "\n";
	
	return 0;
}