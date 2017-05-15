/*
You are standing at the corner with coordinates 0,0. Your destination is at corner width,height. 
You will return the number of distinct paths that lead to your destination. Each path must use exactly width+height blocks. 
In addition, the city has declared certain street blocks untraversable. These blocks may not be a part of any path.
You will be given a String[] bad describing which blocks are bad. 
If (quotes for clarity) "a b c d" is an element of bad, it means the block from corner a,b to corner c,d is untraversable.
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct block {
	int x1;
	int y1;
	int x2;
	int y2;
	bool operator == (const block &value) const {
		return (x1 == value.x1 && y1 == value.y1 && x2 == value.x2 && y2 == value.y2)||
			(x1 == value.x2 && y1 == value.y2 && x2 == value.x1 && y2 == value.y1);
	}
};
vector<block> barriers;

void initialize(string bad[], int bad_num) {
	for (int i = 0; i < bad_num; i++) {
		string str = bad[i];
		block b;
		b.x1 = str[0] - '0';
		b.y1 = str[2] - '0';
		b.x2 = str[4] - '0';
		b.y2 = str[6] - '0';
		barriers.push_back(b);
	}
}

bool contains(int x1, int y1, int x2, int y2) {
	block b = { x1, y1, x2, y2 };
	for (int i = 0; i < barriers.size(); i++) {
		if (barriers[i] == b) {
			return  true;
		}
	}
	return false;
}
long num_ways(int width, int height) {
	vector<vector<long>> result(height+1,vector<long>(width+1));
	for (int i = 0; i <= width; i++) {
		for (int j = 0; j <= height; j++) {
			int left = 0;
			int down = 0;
			if (j>0 && !contains(i, j - 1, i, j)) {
				down = result[i][j - 1];
			}
			if (i > 0 && !contains(i - 1, j, i, j)) {
				left = result[i - 1][j];
			}
			result[i][j] = down + left;
			if (i == 0 && j==0) {
				result[i][j] = 1;
			}
		}
	}
	return result[width][height];
}
int main()
{
	string bad[] = { "0 0 0 1","6 6 5 6" };
	initialize(bad, 2);
	cout << num_ways(6,6) << endl;
	system("pause");
	return 0;
}

