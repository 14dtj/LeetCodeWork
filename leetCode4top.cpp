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
	root = new TreeNode(10);
	TreeNode* left = new TreeNode(5);
	TreeNode* left_left = new TreeNode(1);
	TreeNode* left_right = new TreeNode(11);
	left->left = left_left;
	left->right = left_right;
	root->left = left;
}
bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
	if (!root) {
		return true;
	}
	if (min && root->left->val <= min->val || max && root->right->val >= max->val) {
		return false;
	}
	return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
}
bool isValidBST(TreeNode* root) {
	return isValidBST(root, NULL, NULL);
}


int main()
{
	init();
	cout << isValidBST(root) << endl;
	system("pause");
}


