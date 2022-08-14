//https://school.programmers.co.kr/learn/courses/30/lessons/43238
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    int times_len = times.size();
    int max = 0;

    // 가장 오래 걸리는 시간 찾기
    for (int i = 0; i < times.size(); ++i)
        if (times[i] > max)
            max = times[i];

    long long left = 1;
    long long right = (long long)max * n;

    // 이분 탐색으로 최소 시간 구하기
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < times_len; ++i)
            sum += mid / times[i];

        if (sum >= n)
            right = mid - 1;
        else
            left = mid + 1;
    }

    answer = left;

    return answer;
}