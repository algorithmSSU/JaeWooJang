// 1. weak�� ���̸� ����Ͽ� weak_dist�� ����� �����Ͽ� ���� �õ�
//    => ���ӵ� ��θ� ����� �� ������

// 2. �ش��� �����Ѵٸ�, ���� � �� ���� ������ � �� ����� ������ �̴�.
//    + ���� �� �̵��Ÿ��� ���� ����� ������ �̵� �Ѵ�.
//    => �� weak ���� ���������� �Ͽ� ���� �� �̵��Ÿ��� ������� �̵�

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

// ���� ����� ��򰡿� ����
// ������ ���� weak_dist�� �ִ밪�� dist�� �ִ밪 �񱳷� �������� Ȯ��

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

        // �� idx�� �������� �����ϴ� ��� ���
        for (int startIdx = 0; startIdx < weak.size(); ++startIdx) {

        }

        print(dists);
        */

    return answer;
}