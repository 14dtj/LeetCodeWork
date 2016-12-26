/*
Given a binary tree, determine if it is a valid binary search tree (BST).
*/

#include "stdafx.h"
#include <limits> 
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* root;
void init() {
	root = new TreeNode(5);
	TreeNode* left = new TreeNode(NULL);
	TreeNode* right = new TreeNode(NULL);
	root->left = left;
	root->right = right;
}
bool isValidBST(TreeNode* root) {
	if (!root) {
		return true;
	}
	int max_int = (numeric_limits<int>::max)();
	int min_int = (numeric_limits<int>::min)();
	if (root->val >= max_int || root->val <= min_int) {
		return false;
	}
	if (root->left) {
		if (root->left->val >= root->val) {
			return false;
		}
	}
	if (root->right) {
		if (root->right->val <= root->val) {
			return false;
		}
	}

	return isValidBST(root->left) && isValidBST(root->right);
	
}
int main()
{
	init();
	cout << isValidBST(root) << endl;
	system("pause");
}


