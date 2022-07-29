#pragma once

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_arr(const vector<T>& arr) {
	for (const auto val : arr)
		cout << val << " ";
	cout << "\n";
}

template <typename T>
void print_mat(vector<vector<T>>& mat) {
	for (const auto arr : mat)
		print_arr(arr);
	cout << "\n";
}

void print_mat(vector<vector<pair<int, int>>>& mat) {
	for (const auto arr : mat) {
		for (const auto val : arr)
			cout << "(" << val.first << ", " << val.second << ") ";
		cout << "\n";
	}
}

int mymin(int _Left, int _Mid, int _Right) {
	int _Min = (_Left < _Mid) ? _Left : _Mid;
	return ((_Min < _Right) ? _Min : _Right);
}