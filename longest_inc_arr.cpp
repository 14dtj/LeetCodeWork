// dynamciplan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//�ڷǵݼ����� arr[s..e]�������䣩�϶��ֲ��ҵ�һ�����ڵ���key��λ�ã������С��key���ͷ���e+1
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

