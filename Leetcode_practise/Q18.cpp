#include "stl.h"
struct ListNode {
     int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *remove = head;
		ListNode *index = head;
		if (index == NULL)   return head->next;
		for (int i = 0; i < n; i++) {
			index = index->next;
			if (index == NULL)   return head->next;
		}

		while (index->next != NULL) {
			index = index->next;
			remove = remove->next;
		}
		remove->next = remove->next->next;
		return head;
	}
};