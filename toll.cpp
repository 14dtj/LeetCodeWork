/*
每经过一个结点i，都要花掉cost[i]元钱，如果没有足够的钱则不能经过。
在这个限制条件下找到0-N之间最短路径的权值
*/
#include "stdafx.h"
#include <iostream>
#define INT_MAX 100
#define money 10
#define n 5
using namespace std;

int edge[][n] = { { 0,10,INT_MAX,30,100 },
{ INT_MAX ,0,50,INT_MAX ,INT_MAX },
{ INT_MAX ,INT_MAX ,0,INT_MAX ,10 },
{ INT_MAX ,INT_MAX ,20,0,60 },
{ INT_MAX ,INT_MAX ,INT_MAX ,INT_MAX ,0 } };

int cost[n] = { 0,1,10,1,2 };
int states[n][money+1];
int dist[n][money+1];

int find_shortest_path() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= money; j++) {
			states[i][j] = 0;
			dist[i][j] = edge[0][i];
		}
	}
	dist[0][money] = 0;
	while (true) {
		int min = INT_MAX;
		int index = -1;
		int index_m = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= money; j++) {
				if (!states[i][j] && dist[i][j] < min) {
					index = i;
					index_m = j;
					min = dist[i][j];
				}
			}
		}
		if (index == -1 && index_m == -1) {
			break;
		}
		states[index][index_m] = 1;
		for (int i = 0; i < n; i++) {
			if ((index_m-cost[i]>=0) && !states[i][index_m] && edge[index][index_m] < INT_MAX &&
				dist[index][index_m] + edge[index][i] < dist[i][index_m]) {
				dist[i][index_m] = dist[index][index_m] + edge[index][i];
			}
		}
	}
	int min = INT_MAX;
	for (int i = money; i >= 0; i--) {
		if (dist[n - 1][i] < min) {
			min = dist[n - 1][i];
		}
	}
	return min;
}
int main()
{
	cout << find_shortest_path();
	system("pause");
	return 0;
}