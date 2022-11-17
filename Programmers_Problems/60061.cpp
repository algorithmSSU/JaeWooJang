#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define WORLD_SIZE 128

#define PILLAR  1
#define BEAM    2

#define X       0
#define Y       1
#define TYPE    2
#define COMMAND 3

int world[WORLD_SIZE][WORLD_SIZE] = { { 0 } };

// (x, y)�� type�� ��ġ(����) ��������
bool isStable(int x, int y, int type) {
    // #Case : ���
    if (type == PILLAR) {
        // �ٴ� ���� ��ġ
        if (y == 0)
            return true;

        // ���� ���� �� ��
        if ((world[y][x - 1] & BEAM) || (world[y][x] & BEAM))
            return true;

        // �ٸ� ����� ��
        if (world[y - 1][x] & PILLAR)
            return true;
    }

    // #Case : ��
    else if (type == BEAM) {
        // ���� ���� ��� ��
        if ((world[y - 1][x] & PILLAR) || (world[y - 1][x + 1] & PILLAR))
            return true;

        // ���� ���� �ٸ� ���� ���ÿ� ����
        if ((world[y][x - 1] & BEAM) && world[y][x + 1] & BEAM)
            return true;
    }

    return false;
}

void tryToBuild(int x, int y, int type) {
    if (isStable(x, y, type))
        world[y][x] |= type;
}

bool isUnable(int x, int y, int type) {
    if ((world[y][x] & type) && (!isStable(x, y, type)))
        return true;

    return false;
}

void destroy(int x, int y, int type) {
    if (world[y][x] & type) {
        world[y][x] &= ~type;

        // #Case : ����� ����
        if (type == PILLAR) {
            // �ٷ� �� ����� ������ ���
            if (isUnable(x, y + 1, PILLAR))
                world[y][x] |= type;

            // ���� ���� ���� ������ ���
            else if (isUnable(x - 1, y + 1, BEAM))
                world[y][x] |= type;

            // ������ ���� ���� ������ ���
            else if (isUnable(x, y + 1, BEAM))
                world[y][x] |= type;
        }

        // #Case : ���� ����
        else if (type == BEAM) {
            // ���� �� ����� ���� �� ���
            if (isUnable(x, y, PILLAR))
                world[y][x] |= type;

            // ������ �� ����� ������ ���
            else if (isUnable(x + 1, y, PILLAR))
                world[y][x] |= type;

            // ���ʿ� ���� ������ ���
            else if (isUnable(x - 1, y, BEAM))
                world[y][x] |= type;

            // �����ʿ� ���� ������ ���
            else if (isUnable(x + 1, y, BEAM))
                world[y][x] |= type;
        }
    }
}

void printWorld(vector<vector<int>>& answer) {
    for (int x = 0; x <= 100; ++x) {
        for (int y = 0; y <= 100; ++y) {
            if (world[y][x] & PILLAR)
                answer.emplace_back(vector<int>({ x, y, 0 }));

            if (world[y][x] & BEAM)
                answer.emplace_back(vector<int>({ x, y, 1 }));
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (const auto build : build_frame) {
        int type = build[TYPE] + 1;

        // #Case : ��ġ�ϴ� ���
        if (build[COMMAND]) {
            tryToBuild(build[X], build[Y], type);
        }

        // #Case : �����ϴ� ���
        else {
            destroy(build[X], build[Y], type);
        }
    }

    printWorld(answer);

    return answer;
}

/*
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define PILLAR  1
#define BEAM    2

using Matrix = vector<vector<int>>;

int world[128][128] = { { 0 } };


// (x, y)�� type�� ��ġ(����) ��������
bool isStable(int x, int y, int type) {
    // #Case : ���
    if (type == PILLAR) {
        // �ٴ� ���� ��ġ
        if (y == 0)
            return true;

        // ���� ���� �� ��
        if ((world[y][x - 1] & BEAM) || (world[y][x] & BEAM))
            return true;

        // �ٸ� ����� ��
        if (world[y - 1][x] & PILLAR)
            return true;
    }

    // #Case : ��
    else if (type == BEAM) {
        // ���� ���� ��� ��
        if ((world[y - 1][x] & PILLAR) || (world[y - 1][x + 1] & PILLAR))
            return true;

        // ���� ���� �ٸ� ���� ���ÿ� ����
        if ((world[y][x - 1] & BEAM) && world[y][x + 1] & BEAM)
            return true;
    }

    return false;
}

void tryToBuild(int x, int y, int type) {
    if (isStable(x, y, type))
        world[y][x] |= type;
}

void destroy(int x, int y, int type);

void checkAndDestroy(int x, int y, int type) {
    if ((world[y][x] & type) && (!isStable(x, y, type)))
        destroy(x, y, type);
}

void destroy(int x, int y, int type) {
    if (world[y][x] & type) {
        world[y][x] &= ~type;

        // #Case : ����� ����
        if (type == PILLAR) {
            // �ٷ� �� ����� ������ ���
            checkAndDestroy(x, y + 1, PILLAR);

            // ���� ���� ���� ������ ���
            checkAndDestroy(x - 1, y + 1, BEAM);

            // ������ ���� ���� ������ ���
            checkAndDestroy(x, y + 1, BEAM);
        }

        // #Case : ���� ����
        else if (type == BEAM) {
            // ���� �� ����� ���� �� ���
            checkAndDestroy(x, y, PILLAR);

            // ������ �� ����� ������ ���
            checkAndDestroy(x + 1, y, PILLAR);

            // ���ʿ� ���� ������ ���
            checkAndDestroy(x - 1, y, BEAM);

            // �����ʿ� ���� ������ ���
            checkAndDestroy(x + 1, y, BEAM);
        }
    }
}

void print() {
    for (int i = 9; i >= 0; --i) {
        for (int j = 0; j < 10; ++j)
            cout << world[i][j] << " ";
        cout << "\n";
    }
    cout << "\n\n";
}

void printWorld(vector<vector<int>>& answer) {
    for (int x = 0; x <= 100; ++x) {
        for (int y = 0; y <= 100; ++y) {
            if (world[y][x] & PILLAR)
                answer.emplace_back(vector<int>({x, y, 0}));

            if (world[y][x] & BEAM)
                answer.emplace_back(vector<int>({x, y, 1}));
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    int i = 1;
    for (const auto build : build_frame) {
        int type = build[2] + 1;

        cout << i++ << " " << build[0] << " "<< build[1]<< " " << type<< " ";

        // ��ġ�ϴ� ���
        if (build[3]) {
            cout << "��ġ\n";
            tryToBuild(build[0], build[1], type);
        }

        // �����ϴ� ���
        else {
            cout << "����\n";
            destroy(build[0], build[1], type);
        }

        print();
    }

    printWorld(answer);

    return answer;
}
*/