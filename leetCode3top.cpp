/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
*/

#include "stdafx.h"
#include <string>
using namespace std;
int main()
{
	string s = "cbbd";
	int len = s.size();
	if (len < 2) {
		cout << s;
	}
	int max_len = 0;
	int begin_index = 0;
	for (int i = 0; i < len-1; i++) {
		int left = i;
		int right = i;
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			left--;
			right++;
		}
		if (max_len < right - left - 1) {
			max_len = right - left - 1;
			begin_index = left + 1;
		}
		left = i;
		right = i + 1;
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			left--;
			right++;
		}
		if (max_len < right - left - 1) {
			max_len = right - left - 1;
			begin_index = left + 1;
		}
	}
	cout << s.substr(begin_index,max_len);
	system("pause");
}


