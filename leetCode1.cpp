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
	ListNode temp1(5);
	l1 = &temp1;
	ListNode* l2;
	ListNode temp4(5);
	l2 = &temp4;
	ListNode start(-1);
	ListNode* temp = &start;
	int carry = 0;
	while (l1) {
		if (l2) {		
			int x = l1->val + l2->val + carry;
			carry = x / 10;
			temp->next = new ListNode(x%10);
			temp = temp->next;
			l2 = l2->next;
			l1 = l1->next;
		}
		else {
			int x = l1->val + carry;
			carry = x / 10;
			temp->next = new ListNode(x % 10);
			temp = temp->next;
			l1 = l1->next;
		}
	}

	while (l2) {
		int x = l2->val + carry;
		carry = x / 10;
		temp->next = new ListNode(x%10);
		temp = temp->next;
		l2 = l2->next;
	}
	if (carry != 0) {
		temp->next = new ListNode(carry);
	}
	ListNode* pr = start.next;
	while (pr) {
		cout << pr->val << endl;
		pr = pr->next;
	}
	system("pause");
}

