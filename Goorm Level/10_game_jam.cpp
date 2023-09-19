#include <iostream>
#include <vector>

using namespace std;

struct Cell;

template <class T>
using Matrix = vector<vector<T>>;
using Board = Matrix<Cell>;

constexpr bool VISITED = true;

struct Cell {
	int dist;
	int dr;
	int dc;
	
	Cell(int dist, int dr, int dc) : dist{dist}, dr{dr}, dc{dc} {}
};

struct Player {
	int r;
	int c;
	
	Player(int r, int c) : r{r}, c{c} {}
};

class Game {
	Player& player;
	Board& board;
	size_t board_size;
	public:
	Game(Player& player, Board& board) : player{player}, board{board}, board_size{board.size()} {}
	
	int play() {
		Matrix<bool> visited(board_size, vector<bool>(board_size));
		
		while (!visited[player.r][player.c]) {
			const Cell& command = board[player.r][player.c];
			bool is_end = move(visited, command.dist, command.dr, command.dc);

			if (is_end)
				break;
		}
		
		return get_point(visited);
	}
	
	bool move(Matrix<bool>& visited, int dist, int dr, int dc) {
		while (dist-- > 0) {
			if (visited[player.r][player.c])
				return true;
			
			visited[player.r][player.c] = true;
			player.r = (player.r + dr + board_size) % board_size;
			player.c = (player.c + dc + board_size) % board_size;
		}
		
		return false;
	}
	
	int get_point(const Matrix<bool>& visited) {
		int count = 0;
		
		for (const auto& vec : visited)
			for (const auto val : vec)
				if (val)
					++count;
		
		return count;
	}
};

inline pair<int, int> dir_to_delta(const char dir) noexcept {
	switch (dir) {
		case 'L':
			return { 0, -1 };
		case 'R':
			return { 0, 1 };

		case 'U':
			return { -1, 0 };

		case 'D':
			return { 1, 0 };
	}
	return { -1, -1 }; 
}

inline Board get_board(int n) noexcept {
	Board board(n, vector<Cell>());
	
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			int dist;
			char dir;
			cin >> dist >> dir;
			
			auto [ dr, dc ] = dir_to_delta(dir);
			board[r].emplace_back(dist, dr, dc);
		}
	}
	
	return board;
}

int main() {
	int n;
	cin >> n;

	int r, c;
	cin >> r >> c;
	Player goorm(r - 1, c - 1);
	
	cin >> r >> c;
	Player player(r - 1, c - 1);
	
	Board board = get_board(n);
	
	Game game_goorm(goorm, board);
	Game game_player(player, board);
	
	int score_goorm = game_goorm.play();
	int score_player = game_player.play();
	
	if (score_player > score_goorm)
		cout << "player " << score_player;
	else
		cout << "goorm " << score_goorm;
	
	return 0;
}