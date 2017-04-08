#include "stl.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *res = new ListNode(0);
		ListNode *tmp = res;
		int add = 0;
		while (true) {
			int a = 0, b = 0;
			if (l1 != 0) {
				a = l1->val;
				l1 = l1->next;
			}
			if (l2 != 0) {
				b = l2->val;
				l2 = l2->next;
			}

			int sum = a + b + add;
			add = sum / 10;
			sum %= 10;
			tmp->next = new ListNode(sum);
			tmp = tmp->next;
			if (!l1 && !l2 && !add)
				break;
		}
		return res->next;
	}
};