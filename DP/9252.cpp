#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>* getLCSArr(string& input1, string& input2);
string& getLCSStr(vector<vector<int>>& arr);

int main() {
	string input1, input2;

	cin >> input1 >> input2;

	vector<vector<int>>* arr = getLCSArr(input1, input2);
	
	cout << (*arr)[input1.length()][input2.length()];

	return 0;
}

vector<vector<int>>* getLCSArr(string& input1, string& input2) {
	int len1 = input1.length();
	int len2 = input2.length();

	vector<vector<int>>* arr = new vector<vector<int>>;
	for (int i = 0; i < len1 + 1; ++i)
		arr->emplace_back(len2 + 1, 0);

	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) {
			// ÀÌÀü LSC(arr[i - 1][j - 1]
			if (input1[i - 1] == input2[j - 1])
				(* arr)[i][j] = (*arr)[i - 1][j - 1] + 1;
			else {
				(*arr)[i][j] = max((*arr)[i - 1][j], (*arr)[i][j - 1]);
			}
		}
	}

	return arr;
}

string& getLCSStr(vector<vector<int>>& arr) {

}



int max(int a, int b) {
	return (a > b) ? a : b;
}