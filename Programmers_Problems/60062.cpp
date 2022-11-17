// 1. weak간 차이를 계산하여 weak_dist를 만들어 정렬하여 접근 시도
//    => 연속된 경로를 고려할 수 없었음

// 2. 해답이 존재한다면, 원의 어떤 한 점은 무조건 어떤 한 경로의 시작점 이다.
//    + 가장 긴 이동거리를 가진 사람은 무조건 이동 한다.
//    => 각 weak 별로 시작점으로 하여 가장 긴 이동거리를 가진사람 이동

#include <algorithm>
#include <string>
#include <vector>
#include <set>

#include <iostream>

using namespace std;

void print(vector<int> arr) {
    for (int j = 0; j < arr.size(); ++j)
        cout << arr[j] << " ";

    cout << "\n";
}

// 가장 긴놈이 어딘가에 들어간다
// 들어오기 전에 weak_dist의 최대값과 dist의 최대값 비교로 가능한지 확인

int solution(int n, vector<int> weak, vector<int> dists) {
    int answer = dists.size() + 1;
    int i;

    sort(dists.begin(), dists.end(), greater<>());
    vector<set<int>> candidate(weak.size());

    vector<int> weak_dist(weak.size(), 0);
    for (i = 0; i < weak.size() - 1; ++i)
        weak_dist[i] = weak[i + 1] - weak[i];
    weak_dist[i] = n - weak[i] + weak[0];

    for (int i = 0; i < dists.size(); ++i) {
        for (int j = 0; j < weak_dist.size(); ++j)
            if (dists[i] >= weak_dist[j])
                candidate[j].insert(i);
    }

    for (int i = 0; i < candidate.size(); ++i) {
        cout << i << " : ";
        for (auto iter = candidate[i].begin(); iter != candidate[i].end(); ++i)
            cout << *iter << " ";

        cout << "\n";
    }





    /*

        print(weak_dist);

        sort(dists.begin(), dists.end(), greater<>());

        vector<bool> isUsed(dists.size(), 0);
        dists[0] = true;

        // 한 idx를 기준으로 시작하는 모든 경우
        for (int startIdx = 0; startIdx < weak.size(); ++startIdx) {

        }

        print(dists);
        */

    return answer;
}