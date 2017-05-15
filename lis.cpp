/**
* longest increasing subsequence
**/

#include "stdafx.h"
using namespace std;

int LIS(int a[],int length) {
	int *d = new int[length];
	int max = 0;
	int i;
	for (i = 0; i < length; i++) {
		int j = 0;
		d[i] = 0;
		for (j = 0; j < i; j++) {
			if (a[j]<=a[i])
				d[i] = d[j] + 1;
		}
		if (d[i] == 0) {
			d[i] = 1;
		} 
		if (d[i] > max) {
			max = d[i];
		}
	}
	delete[] d;
	return max;
}

