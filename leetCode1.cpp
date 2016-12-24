/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
*/

#include "stdafx.h"
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
int main()
{
	ListNode* l1;
	ListNode temp1(2);
	ListNode temp2(4);
	ListNode temp3(3);
	l1 = &temp1;
	l1->next = &temp2;
	temp2.next = &temp3;
	ListNode* l2;
	ListNode temp4(5);
	ListNode temp5(6);
	ListNode temp6(4);
	l2 = &temp4;
	l2->next = &temp5;
	temp5.next = &temp6;
	ListNode start(-1);
	ListNode* temp = &start;
	ListNode* sl1 = l1;
	while (sl1) {
		if (l2) {
			ListNode node(sl1->val + l2->val);
			if (temp->val == -1) {
				start = node;
			}
			else {
				temp->next = &node;
				temp = temp->next;
			}
			l2 = l2->next;
			sl1 = sl1->next;
		}
		else {
			ListNode node2(sl1->val);
			if (start.val == -1) {
				start = node2;
			}
			else {
				temp->next = &node2;
				temp = temp->next;
			}
			sl1 = sl1->next;
		}
	}

	while (l2) {
		ListNode node3(l2->val);
		if (start.val == -1) {
			start = node3;
		}
		else {
			temp->next = &node3;
			temp = temp->next;
		}
		l2 = l2->next;
	}
	system("pause");
}

