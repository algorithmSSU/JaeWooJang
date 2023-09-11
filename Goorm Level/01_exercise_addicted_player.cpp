#include <iostream>

using namespace std;

inline int getRM(const int w, const int r) noexcept {
	return (w * (1.0 + (r / 30.0)));
}

int main() {
	int w, r;
	cin >> w >> r;
	
	cout << getRM(w, r) << "\n";
	
	return 0;
}