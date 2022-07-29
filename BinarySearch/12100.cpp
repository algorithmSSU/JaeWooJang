#include <iostream>
#include <cstring>

using namespace std;

#define MAX_SIZE 22
#define COMMAND_LEN 5

class BoardGame {
private:
	int width;
	int hight;

public:
	long long arr[MAX_SIZE][MAX_SIZE];

	BoardGame() {
		memset(arr, -1, MAX_SIZE * MAX_SIZE);
	}

	void getInput(int n) {
		width = n;
		hight = n;

		/* set value */
		for (int y = 1; y <= hight; ++y)
			for (int x = 1; x <= width; ++x)
				cin >> arr[y][x];
	}

	void move_up() {
		// ���ʺ��� ������ ��������
		for (int x = 1; x <= width; ++x) {
			// insertPoint
			int insertPoint = 1;

			int upper = 1;
			int lower = 1;
			while (lower <= width) {
				for (upper = lower; arr[upper][x] == 0; ++upper);
				if (upper > width)
					break;
				for (lower = upper + 1; arr[lower][x] == 0; ++lower);

				long long value;

				// �� ���� ���� �������� ���
				if (arr[upper][x] == arr[lower][x]) {
					value = arr[upper][x] * 2;
					arr[upper][x] = 0;
					arr[lower][x] = 0;
				}
				// �� ���� �ٸ� ���
				else {
					value = arr[upper][x];
					arr[upper][x] = 0;
				}

				arr[insertPoint++][x] = value;
			}
		}
	}

	void move_down() {
		// ���ʺ��� ������ ��������
		for (int x = 1; x <= width; ++x) {
			// insertPoint
			int insertPoint = hight;

			int upper = hight;
			int lower = hight;
			while (upper > 0) {
				for (lower = upper; arr[lower][x] == 0; --lower);
				if (lower < 1)
					break;
				for (upper = lower - 1; arr[upper][x] == 0; --upper);

				long long value;
				// �� ���� ���� �������� ���
				if (arr[upper][x] == arr[lower][x]) {
					value = arr[lower][x] * 2;
					arr[upper][x] = 0;
					arr[lower][x] = 0;
				}
				// �� ���� �ٸ� ���
				else {
					value = arr[lower][x];
					arr[lower][x] = 0;
				}

				arr[insertPoint--][x] = value;
			}
		}
	}

	void move_left() {
		// ���ʺ��� �Ʒ��� ��������
		for (int y = 1; y <= hight; ++y) {
			// insertPoint
			int insertPoint = 1;

			int left = 1;
			int right = 1;

			// �� ���� ���� �������� ���
			while (right <= width) {
				for (left = right; arr[y][left] == 0; ++left);
				if (left > width)
					break;
				for (right = left + 1; arr[y][right] == 0; ++right);

				long long value;
				// �� ���� ���� �������� ���
				if (arr[y][left] == arr[y][right]) {
					value = arr[y][left] * 2;
					arr[y][left] = 0;
					arr[y][right] = 0;
				}
				// �� ���� �ٸ� ���
				else {
					value = arr[y][left];
					arr[y][left] = 0;
				}

				arr[y][insertPoint++] = value;
			}
		}
	}

	void move_right() {
		// ���ʺ��� �Ʒ��� ��������
		for (int y = 1; y <= hight; ++y) {
			// insertPoint
			int insertPoint = width;

			int left = width;
			int right = width;

			// �� ���� ���� �������� ���
			while (right > 0) {
				for (right = left; arr[y][right] == 0; --right);
				if (right < 1)
					break;
				for (left = right - 1; arr[y][left] == 0; --left);

				long long value;
				// �� ���� ���� �������� ���
				if (arr[y][left] == arr[y][right]) {
					value = arr[y][left] * 2;
					arr[y][left] = 0;
					arr[y][right] = 0;
				}
				// �� ���� �ٸ� ���
				else {
					value = arr[y][right];
					arr[y][right] = 0;
				}
				arr[y][insertPoint--] = value;
			}
		}
	}

	void inputRand() {
		while (1) {
			int x = rand() % width + 1;
			int y = rand() % hight + 1;

			if (arr[x][y] == 0) {
				arr[x][y] = 1;
				break;
			}
		}
	}

	void move(char command) {
		if (command == 'w')
			move_up();

		else if (command == 'a')
			move_left();

		else if (command == 's')
			move_down();

		else if (command == 'd')
			move_right();
	}

	int getMax() {
		long long max = 0;
		for (int y = 1; y <= hight; ++y)
			for (int x = 1; x <= width; ++x)
				if (arr[y][x] > max)
					max = arr[y][x];

		return max;
	}

	void copy(BoardGame& target) {
		memcpy(this->arr, target.arr, sizeof(target.arr));
		this->width = target.width;
		this->hight = target.hight;
	}

	void print_mat() {
		for (int y = 1; y <= hight; ++y) {
			for (int x = 1; x <= width; ++x)
				cout << arr[y][x] << " ";
			cout << "\n";
		}
	}
};

char const cmd[4] = { 'w', 'a', 's', 'd' };

long long travle(BoardGame& cur, int len) {
	long long max = 0;

	if (len >= COMMAND_LEN)
		max = cur.getMax();
	else {
		BoardGame next;
		for (int i = 0; i < 4; ++i) {
			next.copy(cur);
			next.move(cmd[i]);
			long long tmp = travle(next, len + 1);
			if (tmp > max)
				max = tmp;
		}
	}

	return max;
}


int main(void) {
	int size;

	cin >> size;
	BoardGame game;
	game.getInput(size);

	char command[6] = { 0 };
	game.move_up();
	game.print_mat();
	//cout << travle(game, 0);

	return 0;
}