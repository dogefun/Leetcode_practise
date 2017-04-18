#include "stl.h"
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *begin = new ListNode(0);
		ListNode *tmp = begin;
		while (true) {
			if (l1 == NULL || l2 == NULL) {
				tmp->next = l1 ? l1 : l2;
				break;
			}
			if (l1->val < l2->val) {
				tmp->next = l1;
				l1 = l1->next;
			}
			else {
				tmp->next = l2;
				l2 = l2->next;
			}
			tmp = tmp->next;
		}
		return begin->next;
	}
};