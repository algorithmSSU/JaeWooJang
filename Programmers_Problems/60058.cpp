#include <string>
#include <vector>

using namespace std;

using sIter = string::iterator;

// makeRightStr : "�������� ���ڿ�"�� str�� "�ùٸ� ���ڿ�"�� ��ȯ
void makeRightStr(string& str) {
    // 1. �� ���ڿ��� ��� ��ȯ���� ��ȯ
    if (str.empty())
        return;

    bool isRight = true;
    int cnt = 0;
    int mid = 0;

    // 2. �������� ��ȣ ���ڿ� u, v�� �����ϴ� mid ã�� 
    do {
        if (str[mid] == '(')
            ++cnt;
        else
            --cnt;

        // 3. u�� �ùٸ� ��ȣ ���ڿ����� �Ǵ�
        if (cnt < 0)
            isRight = false;
        // cnt�� 0�̴� == '('�� ')'�� ������ ����
    } while ((++mid < str.length()) && cnt);

    // 3-1, 4-2. v�� ��������� �ùٸ� ���ڿ��� �����
    string right_v = str.substr(mid);
    makeRightStr(right_v);

    // 3-1. u�� �ùٸ� ���ڿ��� ���
    if (isRight) {
        str = str.substr(0, mid) + right_v;
    }
    // 4. u�� �ùٸ� ���ڿ��� �ƴ� ��� 
    else {
        string out;
        out.reserve(str.length());

        // 4-1 ~ 4-3
        out = "(" + right_v + ")";

        // 4-4 : + ${w[1:-2].invert}
        for (int i = 1; i < mid - 1; ++i)
            out += (str[i] == '(') ? ')' : '(';

        // out --> str�� ����
        str = out;
    }
}

string solution(string p) {
    makeRightStr(p);
    return p;
}