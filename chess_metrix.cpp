#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
long long howMany(int size, int start[], int end[], int numMoves) {
	vector<vector<vector<long long>>> metrix(size,vector<vector<long long>>(size,vector<long long>(numMoves+1)));
	int dists[] = { 1,  0, -1,  0,  0,  1,  0, -1,
		1,  1,  1, -1, -1, -1, -1,  1,
		-2,  1,  2,  1, -2, -1, -2,  1,
		-1, -2, -1,  2,  1,  2,  1, -2 };
	int start_x = start[0];
	int start_y = start[1];
	int end_x = end[0];
	int end_y = end[1];
	metrix[start_x][start_y][0] = 1;
	for (int k = 1; k <= numMoves; k++) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				for (int l = 0; l < 32; l+=2) {
					int bound_x = i + dists[l];
					int bound_y = j + dists[l + 1];
					if (bound_x >= 0 && bound_x < size && bound_y >= 0 && bound_y < size) {
						metrix[bound_x][bound_y][k] += metrix[i][j][k - 1];
					}
				}
			}
		}
	}
	return metrix[end_x][end_y][numMoves];
}
int main()
{
	int start[] = { 0,0 };
	int end[] = {0,99 };
	cout << howMany(100, start, end, 50);
	system("pause");
	return 0;
}