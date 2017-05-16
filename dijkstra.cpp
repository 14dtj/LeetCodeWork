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
int states[n];
int dist[n];
int m_left[n];

int find_shortest_path() {
	for (int i = 0; i < 5; i++) {
		states[i] = 0;
		dist[i] = edge[0][i];
		m_left[i] = money;
		if (i != 0 && dist[i] < INT_MAX) {
			m_left[i] = money - cost[i];
		}
	}
	states[0] = 1;
	for (int i = 0; i < n-1; i++) {
		int min = INT_MAX;
		int index = 0;
		for (int j = 0; j < n; j++) {
			if (!states[j] && dist[j] < min) {
				index = j;
				min = dist[j];
			}
		}
		states[index] = 1;
		for (int k = 0; k < n; k++) {
			int left = m_left[k] - cost[k] - cost[index];
			if (left>=0 && !states[k] && edge[index][k] < INT_MAX &&
				dist[index] + edge[index][k] < dist[k]) {
				m_left[k] = left;
				dist[k] = dist[index] + edge[index][k];
			}
		}
	}
	return dist[n - 1];
}
int main()
{
	cout << find_shortest_path();
	system("pause");
	return 0;
}