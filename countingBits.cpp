#include "stdafx.h"
using namespace std;
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> result;
		for (int i = 0; i <=num; i++) {
			int count = 0;
			int quotient = i/2;
			int remainder = i % 2;
			while (quotient != 0) {
				count += remainder;
				remainder = quotient % 2;
				quotient = quotient / 2;
			}
			cout << endl;
			count += remainder;
			result.push_back(count);
		}
		return result;
	}
};
int main()
{
	Solution s;
	vector<int> result = s.countBits(5);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	system("pause");
}