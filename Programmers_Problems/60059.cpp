#include <string>
#include <vector>
#include <iostream>

using namespace std;

using Matrix = vector<vector<int>>;

Matrix copyMatrix(Matrix& mat);


/* printMat : ������ ��Ʈ���� ��� �Լ� */
void printMat(Matrix& mat) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
    cout << "\n\n";
}

/* setWorld : ���� �ذ��� ���� Ȯ���Ų world ��Ʈ���� �߾ӿ� lock�� ���� �������� */
void setWorld(Matrix& world, Matrix& lock, int KeySize) {
    int blank = KeySize - 1;
    for (int i = 0; i < lock.size(); ++i) {
        for (int j = 0; j < lock.size(); ++j)
            world[i + blank][j + blank] = lock[i][j];
    }
}

/* checkUnlock : key�� �־��� world�� ��� ���������� Ȯ�� */
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

/* tryFit : world�� (x, y)�� ���ʻ������ �Ͽ� key�� ���� */
bool tryFit(Matrix& world, Matrix& key, int x, int y) {
    for (int i = 0; i < key.size(); ++i) {
        for (int j = 0; j < key.size(); ++j) {
            world[x + i][y + j] += key[i][j];

            // �ϳ��� �ɸ��� ��� ���� ����
            if (world[x + i][y + j] > 1) {
                //printMat(world);
                return false;
            }
        }
    }
    //printMat(world);
    return checkUnlock(world, key.size());
}

/* tryUnlock : world�� ���Ͽ� ������ ��� (x, y)�� ���� key�� tryFit()�õ� */
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

/* rotation90 : �Էµ� ��Ʈ������ 90�� ȸ�� */
void rotation90(vector<vector<int>>& mat) {
    int n = mat.size();
    Matrix copyMat = copyMatrix(mat);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            mat[i][n - j - 1] = copyMat[j][i];
}

/* copyMatrix : ��Ʈ������ ����Ͽ� ��ȯ */
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

    // world : lock�� �ܰ��� Ȯ���� Matrix
    Matrix world(worldSize, vector<int>(worldSize, 0));
    setWorld(world, lock, M);

    return answer;
}