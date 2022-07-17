#include <iostream>
#include <vector>

using namespace std;

class Tree {
private:
	static int vertexNum;
	static Tree* instance;

	Tree(int n) {
		if (tree.size())
			tree.clear();

		tree.reserve(n + 1);
		for (int i = 0; i < n + 1; ++i)
			tree.emplace_back();

		vertexNum = n;
	}

public:
	// pair<int, int> => <vertex, weight>
	static vector<vector<pair<int, int>>> tree;

	static Tree& getInstance(int n) {
		if (instance == NULL)
			instance = new Tree(n);

		return *instance;
	}

	void setValue(int curVertex) {
		int input, weight;

		cin >> input;
		while (input > 0) {
			cin >> weight;
			// <vertex, weight>
			tree[curVertex].emplace_back(input, weight);

			cin >> input;
		}
	}

	int getDiameter() {
		vector<bool> isVisit(vertexNum + 1, 0);
		// pair<int, int> => <vertex number, length> 

		/* find some terminal */
		isVisit[1] = true;
		pair<int, int> terminal = dfs(1, isVisit, 0);
		isVisit[1] = false;

		/* find another terminal */
		isVisit[terminal.first] = true;
		pair<int, int> another_terminal = dfs(terminal.first, isVisit, 0);
		isVisit[terminal.first] = false;

		return another_terminal.second;
	}

	pair<int, int> dfs(int cur, vector<bool>& isVisit, int len) {
		// pair<int, int> => <vertex number, length> 
		pair<int, int> max = { cur, len };

		for (const auto& node : tree[cur]) {
			if (!isVisit[node.first]) {
				isVisit[node.first] = true;
				pair<int, int> tmp = dfs(node.first, isVisit, len + node.second);
				isVisit[node.first] = false;

				// case : found max
				if (tmp.second > max.second) {
					max.first = tmp.first;
					max.second = tmp.second;
				}
			}
		}

		return max;
	}
};

int Tree::vertexNum = 0;
Tree* Tree::instance = NULL;
vector<vector<pair<int, int>>> Tree::tree;

int problem1167() {
	int n;
	cin >> n;

	Tree tree = Tree::getInstance(n);

	for (int i = 0; i < n; ++i) {
		int curVertex;
		cin >> curVertex;

		tree.setValue(curVertex);
	}

	cout << tree.getDiameter();

	return 0;
}
