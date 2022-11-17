#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 100000001

// bynarySearch : k번째 음식은 테이블이 몇 바퀴 회전한 이후에 먹는지를 return 하는 재귀 함수
int binarySearch(vector<int>& arr, long long k, int min, int max) {
    if (min > max)
        return max;

    int mid = (min + max) / 2;

    long long sum = 0;
    // mid번 테이블이 회전할 때
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] >= mid)
            sum += mid;
        else
            sum += arr[i];
    }

    //cout << min << " " << max << " (" << mid <<") : " << sum << " " << k << "\n";

    if (sum < k) return binarySearch(arr, k, mid + 1, max);
    else if (sum > k) return binarySearch(arr, k, min, mid - 1);

    return mid;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;

    int max = *max_element(food_times.begin(), food_times.end());
    //int min = *min_element(food_times.begin(), food_times.end());

    // #Case Check : 만일 시간내로 다 먹는 경우
    long long total = 0;
    for (const auto val : food_times)
        total += val;

    if (total <= k)
        return -1;

    // cycle : 테이블이 cycle번 회전한 이후 k번째 음식이 존재
    int cycle = binarySearch(food_times, k, 0, max);

    //int cycle = binarySearch(food_times, k, min, max);
    // => Error!! 만일 k가 min 보다 작을경우 커버 불가

    // eaten : 테이블이 cycle번 회전하는 동안 먹은 음식의 총합
    long long eaten = 0;
    for (const auto val : food_times) {
        if (val >= cycle)
            eaten += cycle;
        else
            eaten += val;
    }

    // restFodds : 아직 남아있는 음식의 인덱스 저장
    vector<int> restFoods;
    for (int i = 0; i < food_times.size(); ++i)
        if (food_times[i] > cycle)
            restFoods.emplace_back(i + 1);

    // 마지막 바퀴에서 idx번째 음식이 전체에서 k번째로 먹는 음식
    long long idx = k - eaten;
    answer = restFoods[idx];

    return answer;
}
