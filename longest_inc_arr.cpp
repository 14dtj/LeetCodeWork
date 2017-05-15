// dynamciplan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//在非递减序列 arr[s..e]（闭区间）上二分查找第一个大于等于key的位置，如果都小于key，就返回e+1
int binarySearch(int array[], int begin, int end, int key) {
	if (array[end] < key) {
		return end + 1;
	}
	int mid;
	while (begin < end) {
		mid = (begin + end) / 2;
		if (key <= array[mid]) {
			end = mid;
		}
		else {
			begin = mid + 1;
		}
	}
	return end;
}
int quickLIS(int a[], int length) {
	int i;
	int *end = new int[length];
	end[0] = a[0];
	int end_pos = 0;
	for (i = 1; i < length; i++) {
		int pos = binarySearch(end, 0, end_pos, a[i]);
		cout << i<<": "<<pos << endl;
		end[pos] = a[i];
		if (end_pos < pos) {
			end_pos = pos;
		}
	}
	return end_pos + 1;
}

