#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 22

class BoardGame {
private :
	int width;
	int hight;

public :
	int arr[MAX_SIZE][MAX_SIZE];

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
		// 왼쪽부터 오른쪽 방향으로
		for (int x = 1; x <= width; ++x) {
			// pre_y : y의 위쪽에서 가장 마지막에 값이 저장된 위치
			int pre_y = 0;

			// 위쪽부터 아래쪽 방향으로
			for (int y = 2; y <= hight; ++y) {
				if (arr[y][x] == 0)
					continue;

				// Case : 위의 수와 같아 합쳐지는 경우
				if (arr[y][x] == arr[pre_y][x])
					arr[pre_y++][x] *= 2;

				// Case : 위의 수와 다른 경우
				else 
					arr[++pre_y][x] = arr[y][x];

				arr[y][x] = 0;
			}
		}
	}

	void move_down() {
		// 왼쪽부터 오른쪽 방향으로
		for (int x = 1; x <= width; ++x) {
			// pre_y : y의 아래쪽으로 가장 마지막에 값이 저장된 위치
			int pre_y = hight + 1;
			
			// 아래쪽부터 위쪽 방향으로
			for (int y = hight - 1; y > 0; --y) {
				if (arr[y][x] == 0)
					continue;

				// Case : 아래의 수와 같아 합쳐지는 경우
				if (arr[y][x] == arr[pre_y][x])
					arr[pre_y--][x] *= 2;

				// Case : 아래의 수와 다른 경우
				else
					arr[--pre_y][x] = arr[y][x];

				arr[y][x] = 0;
			}
		}
	}

	void move_left() {
		// 윗쪽부터 아래쪽 방향으로
		for (int y = 1; y <= hight; ++y) {
			// pre_x : x의 왼쪽 방향으로 가장 마지막에 값이 저장된 위치
			int pre_x = 0;

			// 왼쪽부터 오른쪽 방향으로
			for (int x = 2; x <= width; ++x) {
				if (arr[y][x] == 0)
					continue;

				// Case : 왼쪽 수와 같아 합쳐지는 경우
				if (arr[y][x] == arr[y][pre_x])
					arr[y][pre_x++] *= 2;

				// Case : 아래의 수와 다른 경우
				else
					arr[y][++pre_x] = arr[y][x];

				arr[y][x] = 0;
			}
		}
	}

	void move_right() {
		// 윗쪽부터 아래쪽 방향으로
		for (int y = 1; y <= hight; ++y) {
			// pre_x : x의 오른쪽 방향으로 가장 마지막에 값이 저장된 위치
			int pre_x = width + 1;

			// 왼쪽부터 오른쪽 방향으로
			for (int x = width - 1; x > 0; --x) {
				if (arr[y][x] == 0)
					continue;

				// Case : 왼쪽 수와 같아 합쳐지는 경우
				if (arr[y][x] == arr[y][pre_x])
					arr[y][pre_x--] *= 2;

				// Case : 아래의 수와 다른 경우
				else
					arr[y][--pre_x] = arr[y][x];

				arr[y][x] = 0;
			}
		}
	}

	void print_mat() {
		for (int y = 1; y <= hight; ++y) {
			for (int x = 1; x <= width; ++x)
				cout << arr[y][x] << " ";
			cout << "\n";
		}
	}
};

int problem12100(void) {
	int size;
	cin >> size;

	BoardGame game;
	game.getInput(size);

	game.print_mat();
	while (true) {
		char ch;
		cin >> ch;

		if (ch == 'w')
			game.move_up();

		else if (ch == 'a')
			game.move_left();

		else if (ch == 's')
			game.move_down();

		else if (ch == 'd')
			game.move_right();

		else if (ch == 'q')
			break;

		game.print_mat();
	}
	
	return 0;
}