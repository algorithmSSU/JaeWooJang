#include <iostream>
#include <vector>

using namespace std;


bool isOutSide(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if (x1 < x4 && x2 > x3 &&
		y1 > y4 && y2 < y3)
		return false;

	return true;
}

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if (x1 < x3 && x2 > x4 &&
		y1 < y3 && y2 > y4)
		return true;

	return false;
}

class MatrixSegmentTree {
public:
	vector<vector<vector<long long>>> tree;
	int hight;
	int width;
	int leafNodeNum;

	MatrixSegmentTree(int n) {
		leafNodeNum = n;

		hight = 1;
		width = 1;
		while (width < n) {
			width *= 2;
			++hight;
		}

		tree = vector<vector<vector<long long>>>(hight + 1, vector<vector<long long>>());

		int len = width;
		for (int i = 1; i <= hight; ++i) {
			tree[i] = vector<vector<long long>>(len, vector<long long>(len, 0));
			len /= 2;
		}
	}

	MatrixSegmentTree& getInput() {
		for (int i = 0; i < width; ++i)
			for (int j = 0; j < width; ++j)
				cin >> tree[1][i][j];

		return *this;
	}

	void build() {
		for (int h = 1; h < hight; ++h) {
			for (int i = 0; i < tree[h + 1].size(); ++i) {
				for (int j = 0; j < tree[h + 1].size(); ++j) {
					tree[h + 1][i][j] = tree[h][i * 2][j * 2] + tree[h][i * 2 + 1][j * 2]
						+ tree[h][i * 2][j * 2 + 1] + tree[h][i * 2 + 1][j * 2 + 1];
				}
			}
		}
	}

	void print() {
		for (auto a : tree) {
			for (auto b : a) {
				for (auto c : b) {
					cout << c << " ";
				}
				cout << "\n";
			}
			cout << "\n\n";
		}
	}
	
	void change(int x, int y, long long value) {
		_change(x - 1, y - 1, value);
	}

	long long sumInRange(int x1, int y1, int x2, int y2) {
		return _sumInRange(x1 - 1, y1 - 1,  x2 - 1, y2 - 1, 0, width, 0, width, hight);
	}

private:
	void _change(int x, int y, long long value) {
		tree[1][x][y] = value;

		for (int h = 1; h < hight; ++h) {
			int nextX = x / 2;
			int nextY = y / 2;

			tree[h + 1][x / 2][y / 2] = tree[h][x][y] + tree[h][x + 1][y] +
				tree[h][x][y + 1] + tree[h][x + 1][y + 1];

			x = nextX;
			y = nextY;
		}
	}

	long long _sumInRange(int x1, int y1, int x2, int y2, int beginx, int beginy, int endx, int endy, int hight) {
		// #Case OutSide
		if (isOutSide(x1, y1, x2, y2, beginx, beginy, endx, endy))
			return 0;

		if (isInside(x1, y1, x2, y2, beginx, beginy, endx, endy))

		return 1;
	}
};

int problem11638() {
	int n, m;
	cin >> n >> m;

	MatrixSegmentTree tree(n);
	tree.getInput().build();
	tree.print();

	return 0;
}