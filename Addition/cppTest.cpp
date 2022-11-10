#include <iostream>
#include <vector>

using namespace std;

#define BACKGROUND 100

#define PAPERWIDTH 10
#define PAPERHIGHT 10

void addPaper(vector<vector<bool>>& board, int x, int y);
int countPaper(vector<vector<bool>>& board);

int main() {
	vector<vector<bool>> board(BACKGROUND, vector<bool>(BACKGROUND, false));
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;

		addPaper(board, x, y);
	}

	cout << countPaper(board);

	return 0;
}

void addPaper(vector<vector<bool>>& board, int x, int y) {
	for (int i = y; i < y + PAPERHIGHT; ++i)
		for (int j = x; j < x + PAPERWIDTH; ++j)
			board[i][j] = true;
}

int countPaper(vector<vector<bool>>& board) {
	int cnt = 0;
	for (int i = 0; i < board.size(); ++i)
		for (int j = 0; j < board[i].size(); ++j)
			if (board[i][j])
				++cnt;

	return cnt;
}