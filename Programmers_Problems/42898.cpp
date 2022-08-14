//https://school.programmers.co.kr/learn/courses/30/lessons/42898
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    // 값을 기록할 matrix
    vector<vector<int>> mat(n + 2, vector<int>(m + 2, 0));

    // 물 웅덩이 저장
    for (int i = 0; i < puddles.size(); ++i)
        mat[puddles[i][1]][puddles[i][0]] = -1;

    mat[1][1] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mat[i][j] == 0) {
                // 왼쪽에서 해당 칸에 접근 하는 경우의 수
                if (mat[i - 1][j] > 0)
                    mat[i][j] = (mat[i][j] + mat[i - 1][j]) % 1000000007;

                // 위쪽에서 해당칸에 접근 하는 경우의 수
                if (mat[i][j - 1] > 0)
                    mat[i][j] = (mat[i][j] + mat[i][j - 1]) % 1000000007;
            }
        }
    }

    answer = mat[n][m];

    return answer;
}