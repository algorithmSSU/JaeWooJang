#include <string>
#include <vector>
#include <iostream>

using namespace std;

int compress(string& str, int n);

int solution(string s) {
    int answer = 0;
    int min = s.length();

    for (int i = 1; i <= s.length(); ++i) {
        // i개 단위로 압축시의 길이 
        int compressed_len = compress(s, i);
        if (compressed_len < min)
            min = compressed_len;
    }

    answer = min;
    return answer;
}

int compress(string& str, int n) {
    string subString = str.substr(0, n);
    int compresed_Len = 0;
    int sameCnt = 1;
    int index = 0;

    index += n;
    while (index <= str.length()) {
        // #Case : 이전의 부분 문자열과 동일한 경우
        if (subString.compare(str.substr(index, n)) == 0)
            ++sameCnt;

        // #Case : 이전과 다른 경우
        else {
            // '동일한 갯수'에 해당하는 길이
            if (sameCnt > 1)
                compresed_Len += to_string(sameCnt).length();
            // 부분 문자열의 길이 
            compresed_Len += n;

            // 다음 비교를 위한 값 초기화 
            sameCnt = 1;
            subString = str.substr(index, n);
        }

        index += n;
    }

    // 미출력 부분에 대한 처리 
    if (sameCnt > 1)
        compresed_Len += to_string(sameCnt).length() + n;

    // 나머지에 대한 처리
    compresed_Len += n - (index - str.length());

    return compresed_Len;
}
/*
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

int getLengthOfNum(int n);
int compress(string* s, int n);

int solution(string s) {
    int answer = 0;

    answer = s.length();
    int k = 0;
    for (int i = 1; i <= s.length(); ++i) {
        int tmp = compress(&s, i);
        if (tmp < answer) {
            answer = tmp;
            k = i;
        }
    }

    return answer;
}


int compress(string* str, int n) {
    int comLen = 0;
    int len = str->length();
    int i;
    char* tmp = new char[n + 1];
    char* s = new char[len + 1];
    strcpy(s, str->c_str());

    int cnt = 1;

    int index = 0;
    strncpy(tmp, &s[index], sizeof(char) * n);
    tmp[n] = 0;

    index += n;
    while (index <= len) {
        for (i = 0; i < n; ++i) {
            if (tmp[i] != s[index + i])
                break;
        }

        if (i == n)
            ++cnt;
        else {
            comLen += n;
            if (cnt > 1)
                comLen += getLengthOfNum(cnt);

            cnt = 1;

            strncpy(tmp, &s[index], sizeof(char) * n);
            tmp[n] = 0;
        }

        index += n;
    }

    if (cnt > 1)
        comLen += getLengthOfNum(cnt) + n;

    comLen += len - index + n;

    delete[] tmp;
    delete[] s;

    return comLen;
}

int getLengthOfNum(int n) {
    int tmp = 1;
    int len = 0;
    while (n >= tmp) {
        tmp *= 10;
        ++len;
    }

    return len;
}
*/