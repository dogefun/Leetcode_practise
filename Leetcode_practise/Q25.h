#include "stl.h"
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* go(ListNode* head, int k) {
		ListNode* tmp = head;
		ListNode* tmp2 = head;
		ListNode *h = new ListNode(1);
		h->next = head;
		while (--k) {
			tmp = tmp2->next;
			tmp2->next = tmp2->next->next;
			tmp->next = h->next;
			h->next = tmp;
		}
		return h->next;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode res(0);
		res.next = head;
		ListNode *tmp = &res;
		int i = 0;
		while (head) {
			head = head->next;
			if (++i == k) {
				auto f = tmp->next;
				tmp->next = go(tmp->next, k);
				tmp = f;
				i = 0;
			}
		}
		return res.next;
	}
};