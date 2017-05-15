/*
* 1,7,4,9,2,5 is a zig-zag sequence because the differences (6,-3,5,-7,3) are alternately positive and negative.
*/
#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int longestZigZag(int sequence[], int length) {
	if (length <= 2) {
		return length;
	}
	int *positive = new int[length];
	int *negative = new int[length];
	for (int i = 0; i < length; i++) {
		positive[i] = negative[i] = 1;
		for (int j = 0; j < i; j++) {
			if (sequence[i] - sequence[j]>0) {
				positive[i] = std::max(negative[j] + 1, positive[i]);
			}
			else if (sequence[i] - sequence[j] < 0) {
				negative[i] = std::max(positive[j] + 1, negative[i]);
			}
		}
	}
	int negative_len = negative[length - 1];
	int positive_len = positive[length - 1];
	delete[] positive;
	delete[] negative;
	return std::max(negative_len,positive_len);
}
