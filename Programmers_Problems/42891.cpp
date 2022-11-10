#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100000001

int getMin(vector<int>& arr, int lowerBound) {
    int min = MAX;

    for (const auto val : arr)
        if (val >= lowerBound && val < min)
            min = val;

    return min;
}

int getElementNum(vector<int>& arr, int lowerBound) {
    int cnt = 0;

    for (const auto val : arr)
        if (val >= lowerBound)
            ++cnt;

    return cnt;
}

int sum(vector<int>& arr) {
    int sum = 0;
    for (const auto val : arr)
        sum += val;
    return sum;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;

    long long cycle = 0;
    long long eaten = 0;

    // #Case : 시간내로 다 먹는 경우
    if (k >= sum(food_times))
        return -1;

    int min = getMin(food_times, cycle);
    int restFoodNum = getElementNum(food_times, cycle);

    while (eaten + min * restFoodNum <= k) {
        eaten += min * restFoodNum;
        cycle += min;

        min = getMin(food_times, cycle);
        restFoodNum = getElementNum(food_times, cycle);
    }

    int idx = 0;
    while (food_times[idx] <= cycle)
        ++idx;

    while (eaten < k) {
        if (food_times[idx] > cycle)
            ++eaten;

        ++idx;
        if (idx >= food_times.size())
            idx = 0;
    }

    answer = idx + 1;

    return answer;
}
