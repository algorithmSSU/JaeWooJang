#include <iostream>
#include <vector>

using namespace std;

pair<int, int> dfs(vector<bool>& isVisit, vector<vector<pair<int, int>>>& arr, int cur, int sum);

int main() {
	int n;
	cin >> n;

	vector<vector<pair<int, int>>> arr(n + 1, vector<pair<int, int>>());

	for (int i = 0; i < n - 1; ++i) {
		int parent, child, weith;
		cin >> parent >> child >> weith;

		arr[parent].emplace_back(child, weith);
		arr[child].emplace_back(parent, weith);
	}

	vector<bool> isVisit(n + 1, false);
	isVisit[1] = true;
	pair<int, int> edge = dfs(isVisit, arr, 1, 0);
	isVisit[1] = false;

	isVisit[edge.second] = true;
	pair<int, int> result = dfs(isVisit, arr, edge.second, 0);
	isVisit[edge.second] = false;

	cout << result.first;

	return 0;
}

pair<int, int> dfs(vector<bool>& isVisit, vector<vector<pair<int, int>>>& arr, int cur, int sum) {
	pair<int, int> result = make_pair(sum, cur);

	for (int i = 0; i < arr[cur].size(); ++i) {
		if (!isVisit[arr[cur][i].first]) {
			isVisit[arr[cur][i].first] = true;
			pair<int, int> tmp = dfs(isVisit, arr, arr[cur][i].first, sum + arr[cur][i].second);
			if (tmp.first > result.first)
				result = tmp;
			isVisit[arr[cur][i].first] = false;
		}
	}

	return result;
}