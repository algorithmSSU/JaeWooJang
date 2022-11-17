#include <string>
#include <vector>
#include <iostream>

using namespace std;

using Matrix = vector<vector<int>>;

Matrix copyMatrix(Matrix& mat);


/* printMat : 디버깅용 매트릭스 출력 함수 */
void printMat(Matrix& mat) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
    cout << "\n\n";
}

/* setWorld : 문재 해결을 위해 확장시킨 world 매트릭스 중앙에 lock의 값을 세팅해줌 */
void setWorld(Matrix& world, Matrix& lock, int KeySize) {
    int blank = KeySize - 1;
    for (int i = 0; i < lock.size(); ++i) {
        for (int j = 0; j < lock.size(); ++j)
            world[i + blank][j + blank] = lock[i][j];
    }
}

/* checkUnlock : key가 넣어진 world가 모두 가득차는지 확인 */
bool checkUnlock(Matrix& world, int keysize) {
    for (int i = keysize - 1; i <= world.size() - keysize; ++i) {
        for (int j = keysize - 1; j <= world.size() - keysize; ++j) {
            if (world[i][j] != 1)
                return false;
        }
    }

    //printMat(world);
    return true;
}

/* tryFit : world의 (x, y)를 왼쪽상단으로 하여 key를 삽입 */
bool tryFit(Matrix& world, Matrix& key, int x, int y) {
    for (int i = 0; i < key.size(); ++i) {
        for (int j = 0; j < key.size(); ++j) {
            world[x + i][y + j] += key[i][j];

            // 하나라도 걸리는 경우 빠른 종료
            if (world[x + i][y + j] > 1) {
                //printMat(world);
                return false;
            }
        }
    }
    //printMat(world);
    return checkUnlock(world, key.size());
}

/* tryUnlock : world에 대하여 가능한 모든 (x, y)에 대해 key를 tryFit()시도 */
bool tryUnlock(Matrix& world, Matrix& key) {
    int width = world.size() - key.size() + 1;

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < width; ++j) {
            Matrix copyWorld = copyMatrix(world);
            if (tryFit(copyWorld, key, i, j))
                return true;
        }
    }
    return false;
}

/* rotation90 : 입력된 매트릭스를 90도 회전 */
void rotation90(vector<vector<int>>& mat) {
    int n = mat.size();
    Matrix copyMat = copyMatrix(mat);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            mat[i][n - j - 1] = copyMat[j][i];
}

/* copyMatrix : 매트릭스를 목사하여 반환 */
Matrix copyMatrix(const Matrix& mat) {
    Matrix copyMat;

    copyMat.reserve(mat.size());
    for (int i = 0; i < mat.size(); ++i) {
        copyMat.emplace_back();
        for (int j = 0; j < mat.size(); ++j) {
            copyMat[i].emplace_back(mat[i][j]);
        }
    }

    return copyMat;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = key.size();
    int N = lock.size();

    int worldSize = M + M + N - 2;

    // world : lock의 외각을 확장한 Matrix
    Matrix world(worldSize, vector<int>(worldSize, 0));
    setWorld(world, lock, M);

    // 90
    for (int i = 0; i < 4; ++i) {
        if (tryUnlock(world, key))
            return true;

        rotation90(key);
    }

    return false;
}