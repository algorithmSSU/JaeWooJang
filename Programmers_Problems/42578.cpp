//https://school.programmers.co.kr/learn/courses/30/lessons/42578
#include <string>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    hash<string> str_hash;
    vector<pair<int, int>> hash_clothes;

    for (const auto cloth : clothes) {
        int hash_val = str_hash(cloth[1]);

        int i;
        for (i = 0; i < hash_clothes.size(); ++i) {
            if (hash_clothes[i].first == hash_val) {
                // 옷의 종류가 같은 경우
                ++hash_clothes[i].second;
                break;
            }
        }

        if (i == hash_clothes.size())
            hash_clothes.emplace_back(hash_val, 1);
    }

    // 경우의 수 계산
    for (const auto hash_clothe : hash_clothes)
        answer *= (hash_clothe.second + 1);

    // 아무것도 입지 않는 경우 제외
    answer--;

    return answer;
}