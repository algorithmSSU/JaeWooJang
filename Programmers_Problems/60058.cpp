#include <string>
#include <vector>

using namespace std;

using sIter = string::iterator;

// makeRightStr : "균형잡힌 문자열"인 str을 "올바른 문자열"로 전환
void makeRightStr(string& str) {
    // 1. 빈 문자열의 경우 변환없이 반환
    if (str.empty())
        return;

    bool isRight = true;
    int cnt = 0;
    int mid = 0;

    // 2. 균형잡힌 괄호 문자열 u, v를 구분하는 mid 찾기 
    do {
        if (str[mid] == '(')
            ++cnt;
        else
            --cnt;

        // 3. u가 올바른 괄호 문자열인지 판단
        if (cnt < 0)
            isRight = false;
        // cnt가 0이다 == '('와 ')'의 개수가 같다
    } while ((++mid < str.length()) && cnt);

    // 3-1, 4-2. v를 재귀적으로 올바른 문자열로 만든다
    string right_v = str.substr(mid);
    makeRightStr(right_v);

    // 3-1. u가 올바른 문자열인 경우
    if (isRight) {
        str = str.substr(0, mid) + right_v;
    }
    // 4. u가 올바른 문자열이 아닌 경우 
    else {
        string out;
        out.reserve(str.length());

        // 4-1 ~ 4-3
        out = "(" + right_v + ")";

        // 4-4 : + ${w[1:-2].invert}
        for (int i = 1; i < mid - 1; ++i)
            out += (str[i] == '(') ? ')' : '(';

        // out --> str로 복사
        str = out;
    }
}

string solution(string p) {
    makeRightStr(p);
    return p;
}