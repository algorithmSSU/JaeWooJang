#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void get_LCS_Arr(vector<vector<int>>& arr, const char* const str1, const char* const str2);
string get_LCS_Str(const vector<vector<int>>& arr, const char* const str1, const char* const str2);

int problem9252() {
	char str1[1002] = { '0' };
	char str2[1002] = { '0' };

	cin >> &str1[1] >> &str2[1];

	vector<vector<int>> arr;
	get_LCS_Arr(arr, str1, str2);
	
	// LCS_len
	cout << arr[strlen(str1) - 1][strlen(str2) - 1] << "\n";
	cout << get_LCS_Str(arr, str1, str2);

	return 0;
}

void get_LCS_Arr(vector<vector<int>>& arr, const char* const str1, const char* const str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	/* Initialize */
	arr.reserve(len1);
	for (int i = 0; i < len1; ++i)
		arr.emplace_back(len2, 0);

	/* Calculate */
	// arr[i][j] : str1의 길이가 i인 부분 문자열과 str2의 길이가 j인 부분 문자열의 LCS 길이
	for (int i = 1; i < len1; ++i) {
		for (int j = 1; j < len2; ++j) {
			// Case : 두 부분문자열이 같은 문자로 끝나는 경우
			if (str1[i] == str2[j])
				arr[i][j] = arr[i - 1][j - 1] + 1;

			// Case : 두 부문문자열이 다른 문자로 끝나는 경우
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}
}

string get_LCS_Str(const vector<vector<int>>& arr, const char* const str1, const char* const str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	string out(arr[len1 - 1][len2 - 1], 0);

	// Case : LCS가 없는 경우
	if (arr[len1 - 1][len2 - 1] == 0)
		return out;

	// idx : LCS의 저장될 인덱스
	int idx = arr[len1 - 1][len2 - 1];

	int i = len1;
	int j = len2;

	while (i > 0 && j > 0) {
		// Case : 같은 문자인 경우
		if (str1[i] == str2[j]) {
			out[idx--] = str1[i];
			--i; --j;
		}

		// Case : 다른 문자인 경우 => LCS가 큰 값 방향으로 이동
		else if (arr[i][j - 1] > arr[i - 1][j])
			--j;
		else
			--i;
	}

	return out;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}