/*
Given a binary tree, determine if it is a valid binary search tree (BST).
*/

#include "stdafx.h"
using namespace std;
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		recursive(nums,0,result);
		return  result;
	}

	void recursive(vector<int>& nums,int begin,vector<vector<int>>& result) {
		if (begin >= nums.size()) {
			result.push_back(nums);
			return;
		}
		for (int i = begin; i < nums.size(); i++) {
			//swap
			int temp = nums[begin];
			nums[begin] = nums[i];
			nums[i] = temp;
			recursive(nums, begin + 1, result);
			//swap
			temp = nums[begin];
			nums[begin] = nums[i];
			nums[i] = temp;
		}
	}
};
int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	vector<vector<int>> result = s.permute(nums);
	for (int i = 0; i < result.size(); i++) {
		vector<int> vec = result[i];
		for (int j = 0; j < vec.size(); j++) {
			cout << vec[j];
		}
		cout << endl;
	}
	cout << result.size() << endl;
	system("pause");
}