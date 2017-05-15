/**
*height represents how high each type of flower grows, bloom represents the morning that each type of flower springs from the ground, 
and wilt represents the evening that each type of flower shrivels up and dies. Each element in bloom and wilt will be a number 
between 1 and 365 inclusive, and wilt[i] will always be greater than bloom[i].
You must plant all of the flowers of the same type in a single row for appearance, and you also want to have the tallest flowers as close
as possible. However, if a flower type is taller than another type, and both types can be out of the ground at the same time, the shorter 
flower must be planted in front of the taller flower to prevent blocking.
**/

#include "stdafx.h"
using namespace std;
void get_ordering(int height[], int bloom[], int wilt[],int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < i; j++) {
			if (height[j] > height[i] && bloom[i]<=wilt[j]||
				height[j] < height[i] && bloom[i]>wilt[j]) {
				//swap
				int temp = height[i];
				height[i] = height[j];
				height[j] = temp;
				temp = bloom[i];
				bloom[i] = bloom[j];
				bloom[j] = temp;
				temp = wilt[i];
				wilt[i] = wilt[j];
				wilt[j] = temp;
			}
		}
	}
	for (int i = 0; i < length; i++) {
		cout << height[i] << " ";
	}
}


int main()
{

	int height[] ={ 5,4,3,2,1 };
	int bloom[] = { 1,1,1,1,1 };
	int wilt[] = { 365,365,365,365,365 };

	get_ordering(height, bloom, wilt, 5);
	system("pause");
	return 0;
}

