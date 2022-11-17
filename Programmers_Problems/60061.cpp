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

// (x, y)에 type이 설치(존재) 가능한지
bool isStable(int x, int y, int type) {
    // #Case : 기둥
    if (type == PILLAR) {
        // 바닥 위에 설치
        if (y == 0)
            return true;

        // 보의 한쪽 끝 위
        if ((world[y][x - 1] & BEAM) || (world[y][x] & BEAM))
            return true;

        // 다른 기둥의 위
        if (world[y - 1][x] & PILLAR)
            return true;
    }

    // #Case : 보
    else if (type == BEAM) {
        // 한쪽 끝이 기둥 위
        if ((world[y - 1][x] & PILLAR) || (world[y - 1][x + 1] & PILLAR))
            return true;

        // 양쪽 끝이 다른 보와 동시에 연결
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

        // #Case : 기둥을 제거
        if (type == PILLAR) {
            // 바로 위 기둥이 존재할 경우
            if (isUnable(x, y + 1, PILLAR))
                world[y][x] |= type;

            // 왼족 위에 보가 존재할 경우
            else if (isUnable(x - 1, y + 1, BEAM))
                world[y][x] |= type;

            // 오른쪽 위에 보가 존재할 경우
            else if (isUnable(x, y + 1, BEAM))
                world[y][x] |= type;
        }

        // #Case : 보를 제거
        else if (type == BEAM) {
            // 왼쪽 위 기둥이 존재 할 경우
            if (isUnable(x, y, PILLAR))
                world[y][x] |= type;

            // 오른쪽 위 기둥이 존재할 경우
            else if (isUnable(x + 1, y, PILLAR))
                world[y][x] |= type;

            // 왼쪽에 보가 존재할 경우
            else if (isUnable(x - 1, y, BEAM))
                world[y][x] |= type;

            // 오른쪽에 보가 존재할 경우
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

        // #Case : 설치하는 경우
        if (build[COMMAND]) {
            tryToBuild(build[X], build[Y], type);
        }

        // #Case : 삭제하는 경우
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


// (x, y)에 type이 설치(존재) 가능한지
bool isStable(int x, int y, int type) {
    // #Case : 기둥
    if (type == PILLAR) {
        // 바닥 위에 설치
        if (y == 0)
            return true;

        // 보의 한쪽 끝 위
        if ((world[y][x - 1] & BEAM) || (world[y][x] & BEAM))
            return true;

        // 다른 기둥의 위
        if (world[y - 1][x] & PILLAR)
            return true;
    }

    // #Case : 빔
    else if (type == BEAM) {
        // 한쪽 끝이 기둥 위
        if ((world[y - 1][x] & PILLAR) || (world[y - 1][x + 1] & PILLAR))
            return true;

        // 양쪽 끝이 다른 보와 동시에 연결
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

        // #Case : 기둥을 제거
        if (type == PILLAR) {
            // 바로 위 기둥이 존재할 경우
            checkAndDestroy(x, y + 1, PILLAR);

            // 왼족 위에 보가 존재할 경우
            checkAndDestroy(x - 1, y + 1, BEAM);

            // 오른쪽 위에 보가 존재할 경우
            checkAndDestroy(x, y + 1, BEAM);
        }

        // #Case : 보를 제거
        else if (type == BEAM) {
            // 왼쪽 위 기둥이 존재 할 경우
            checkAndDestroy(x, y, PILLAR);

            // 오른쪽 위 기둥이 존재할 경우
            checkAndDestroy(x + 1, y, PILLAR);

            // 왼쪽에 보가 존재할 경우
            checkAndDestroy(x - 1, y, BEAM);

            // 오른쪽에 보가 존재할 경우
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

        // 설치하는 경우
        if (build[3]) {
            cout << "설치\n";
            tryToBuild(build[0], build[1], type);
        }

        // 삭제하는 경우
        else {
            cout << "삭제\n";
            destroy(build[0], build[1], type);
        }

        print();
    }

    printWorld(answer);

    return answer;
}
*/