#include "stl.h"
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *res = new ListNode(1);
		res->next = head;
		ListNode *p = res;
		while (head != NULL && head->next != NULL) {
			ListNode *tmp = head->next;
			head->next = tmp->next;
			tmp->next = head;
			p->next = tmp;
			head = head->next;
			p = tmp->next;
		}

		return res->next;
	}
};