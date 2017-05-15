#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_max(int arr[][3], int rows) {
	vector<vector<int>> s(rows, vector<int>(3));
	s[0][0] = arr[0][0];
	s[0][1] = arr[0][1]+s[0][0];
	s[1][0] = arr[1][0]+s[0][0];
	for (int i = 1; i < rows; i++) {
		for (int j = 1; j < 3; j++) {
			int m = std::max(s[i - 1][j], s[i][j - 1]);
			s[i][j] = arr[i][j] + m;
		}
	}
	int max = s[rows - 1][2];
	return max;
}

