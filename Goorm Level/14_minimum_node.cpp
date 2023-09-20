#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<bool>>;

class Problem {
	Matrix mat;
	
	public:
	Problem(int n, int m) {
		mat = Matrix(n + 1, vector<bool>(n + 1));
		
		for (int i = 0; i < m; ++i) {
			int from, to;
			cin >> from >> to;
			mat[from][to] = true;
			mat[to][from] = true;
		}
	}
	
	int get_next_min(const vector<bool>& visited, const int cur) noexcept {
		for (size_t next = 0; next < mat.size(); ++next) {
			if (mat[cur][next]) {
				if (!visited[next])
					return next;	
			}
		}
		
		return -1;
}
	
	pair<int, int> get_min_node_path(const int start) {
		vector<bool> visited(mat.size());
		int cur = start;
		
		int count = 0;
		while (cur >= 0) {
			++count;
			visited[cur] = true;
			
			int next = get_next_min(visited, cur);
			if (next < 0)
				return { count, cur }; 
			
			cur = next;
		}
		
		return { -1, -1 };
	}
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	
	Problem problem(n, m);
	auto [ count, last ] = problem.get_min_node_path(k);
	cout << count << " " << last << "\n";
	
	return 0;
}