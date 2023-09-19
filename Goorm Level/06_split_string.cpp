#include <iostream>
#include <map>

using namespace std;

inline map<string_view, int> get_string_map(const string_view& str) {
	map<string_view, int> str_map;
	
	for (size_t i = 1; i < str.length(); ++i) {
		for (size_t j = i + 1; j < str.length(); ++j) {
			str_map[str.substr(0, i)] = 1;			// left string
			str_map[str.substr(i, j - i)] = 1;	// mid string 
			str_map[str.substr(j)] = 1;					// right string
		}
	}
	
	int index = 0;
	for (auto iter = str_map.begin(); iter != str_map.end(); ++iter)
		iter->second = ++index;
	
	return str_map;
}

inline int get_max_point(const string_view& str) {
	map<string_view, int> str_map = get_string_map(str);
	
	int max = 0;
	for (size_t i = 1; i < str.length(); ++i) {
		for (size_t j = i + 1; j < str.length(); ++j) {
			int score = 0;
			score = str_map[str.substr(0, i)] +					// left string
							str_map[str.substr(i, j - i)] + 		// mid string
							str_map[str.substr(j)];							// right string
			
			if (score > max)
				max = score;
		}
	}
	
	return max;
}

int main() {
	int n;
	cin >> n;
	
	string str;
	cin >> str;
	
	cout << get_max_point(str) << "\n";
	
	return 0;
}