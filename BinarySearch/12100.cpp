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
		// ���ʺ��� ������ ��������
		for (int x = 1; x <= width; ++x) {
			// pre_y : y�� ���ʿ��� ���� �������� ���� ����� ��ġ
			int pre_y = 0;

			// ���ʺ��� �Ʒ��� ��������
			for (int y = 2; y <= hight; ++y) {
				if (arr[y][x] == 0)
					continue;

				// Case : ���� ���� ���� �������� ���
				if (arr[y][x] == arr[pre_y][x])
					arr[pre_y++][x] *= 2;

				// Case : ���� ���� �ٸ� ���
				else 
					arr[++pre_y][x] = arr[y][x];

				arr[y][x] = 0;
			}
		}
	}

	void move_down() {
		// ���ʺ��� ������ ��������
		for (int x = 1; x <= width; ++x) {
			// pre_y : y�� �Ʒ������� ���� �������� ���� ����� ��ġ
			int pre_y = hight + 1;
			
			// �Ʒ��ʺ��� ���� ��������
			for (int y = hight - 1; y > 0; --y) {
				if (arr[y][x] == 0)
					continue;

				// Case : �Ʒ��� ���� ���� �������� ���
				if (arr[y][x] == arr[pre_y][x])
					arr[pre_y--][x] *= 2;

				// Case : �Ʒ��� ���� �ٸ� ���
				else
					arr[--pre_y][x] = arr[y][x];

				arr[y][x] = 0;
			}
		}
	}

	void move_left() {
		// ���ʺ��� �Ʒ��� ��������
		for (int y = 1; y <= hight; ++y) {
			// pre_x : x�� ���� �������� ���� �������� ���� ����� ��ġ
			int pre_x = 0;

			// ���ʺ��� ������ ��������
			for (int x = 2; x <= width; ++x) {
				if (arr[y][x] == 0)
					continue;

				// Case : ���� ���� ���� �������� ���
				if (arr[y][x] == arr[y][pre_x])
					arr[y][pre_x++] *= 2;

				// Case : �Ʒ��� ���� �ٸ� ���
				else
					arr[y][++pre_x] = arr[y][x];

				arr[y][x] = 0;
			}
		}
	}

	void move_right() {
		// ���ʺ��� �Ʒ��� ��������
		for (int y = 1; y <= hight; ++y) {
			// pre_x : x�� ������ �������� ���� �������� ���� ����� ��ġ
			int pre_x = width + 1;

			// ���ʺ��� ������ ��������
			for (int x = width - 1; x > 0; --x) {
				if (arr[y][x] == 0)
					continue;

				// Case : ���� ���� ���� �������� ���
				if (arr[y][x] == arr[y][pre_x])
					arr[y][pre_x--] *= 2;

				// Case : �Ʒ��� ���� �ٸ� ���
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