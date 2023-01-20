#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

#define MAX 100000001

// bynarySearch : k��° ������ ���̺��� �� ���� ȸ���� ���Ŀ� �Դ����� return �ϴ� ��� �Լ�
int binarySearch(vector<int>& arr, long long k, int min, int max) {
    if (min > max)
        return max;

    int mid = (min + max) / 2;

    long long sum = 0;
    // mid�� ���̺��� ȸ���� ��
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

    // #Case Check : ���� �ð����� �� �Դ� ���
    long long total = 0;
    for (const auto val : food_times)
        total += val;

    if (total <= k)
        return -1;

    // cycle : ���̺��� cycle�� ȸ���� ���� k��° ������ ����
    int cycle = binarySearch(food_times, k, 0, max);

    //int cycle = binarySearch(food_times, k, min, max);
    // => Error!! ���� k�� min ���� ������� Ŀ�� �Ұ�

    // eaten : ���̺��� cycle�� ȸ���ϴ� ���� ���� ������ ����
    long long eaten = 0;
    for (const auto val : food_times) {
        if (val >= cycle)
            eaten += cycle;
        else
            eaten += val;
    }

    // restFodds : ���� �����ִ� ������ �ε��� ����
    vector<int> restFoods;
    for (int i = 0; i < food_times.size(); ++i)
        if (food_times[i] > cycle)
            restFoods.emplace_back(i + 1);

    // ������ �������� idx��° ������ ��ü���� k��°�� �Դ� ����
    long long idx = k - eaten;
    answer = restFoods[idx];

    return answer;
}

void suffle(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        int x = rand() % arr.size();
        int y = rand() % arr.size();

        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }

}

int main() {
    srand(time(NULL));
    for (int testCase = 0; testCase < 100000000; ++testCase) {
        int n = rand() % 15 + 1;
        
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            arr[i] = i * 3 + 1;

        suffle(arr);

        long long k = rand() % 10000 + 1;

        int result1 = solution1(arr, k);
        int result2 = solution2(arr, k);

        if (result1 != result2) {
            cout << "dif!!\n";
            cout << "arr : [";
            for (const auto var : arr)
                cout << var << ", ";
            cout << "]\n";
            cout << "k : " << k << "\n";

            cout << "1 : " << result1 << "\n";
            cout << "2 : " << result2 << "\n";
            break;
        }
    }
}