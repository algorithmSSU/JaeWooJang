#include <string>
#include <vector>
#include <iostream>

using namespace std;

using Matrix = vector<vector<int>>;

void printMat(Matrix& mat) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}

void setWorld(Matrix& world, Matrix& lock, int KeySize) {
    int blank = KeySize - 1;
    for (int i = 0; i < lock.size(); ++i) {
        for (int j = 0; j < lock.size(); ++j)
            world[i + blank][j + blank] = lock[i][j];
    }
}

Matrix rotation90(Matrix& mat) {
    int n = mat.size();

    Matrix out(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            out[i][n - j - 1] = mat[j][i];
        }
    }

    return out;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;

    int M = key.size();
    int N = lock.size();

    int worldSize = M + M + N - 2;

    Matrix world(worldSize, vector<int>(worldSize, 0));
    setWorld(world, lock, M);

    for (int i = 0)

        printMat(world);


    return answer;
}