/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
*/

#include "stdafx.h"
#include <string>
using namespace std;
bool isParlindrom(string str);
int main()
{
	string s = "civilranynars";
	string pal = "";
	string result = "";
	int max = 0;
	int len = 0;
	for (int j = 0; j < s.length(); j++) {
		for (int i = j; i < s.length(); i++) {
			string sub = s.substr(j, i+1-j);
			cout << sub << endl;
			if (isParlindrom(sub)) {
				pal = sub;
				len = sub.length();
			}
		}
		if (len > max) {
			max = len;
			result = pal;
		}
		len = 0;
	}
	cout << "result:"<<result << endl;
	system("pause");
}
bool isParlindrom(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != str[str.length() - i - 1])
			return false;
	}
	return true;
}

