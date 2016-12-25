/*
Given a string, find the length of the longest substring without repeating characters.
*/

#include "stdafx.h"
#include <string>
using namespace std;

int main()
{
	string s = "p";
	int length = 0;
	int max = 1;
	if (s.length == 0) {
		max = 0;
	}
	for (int i = 0; i < s.length(); i++) {
		if (max < length) {
			max = length;
		}
		string result = "";
		length = 0;
		for (int j = i; j < s.length(); j++) {
			size_t found = result.find(s[j]);
			if (found != std::string::npos) {
				break;
			}
			else {
				length++;
				result += s[j];
			}
		}
	}
	cout << max << endl;
	system("pause");
}

