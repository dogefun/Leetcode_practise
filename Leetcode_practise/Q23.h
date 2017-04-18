#include "stl.h"
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) {
			return NULL;
		}
		else if (lists.size() == 1) {
			return lists[0];
		}

		while (lists.size() > 1) {
			vector<ListNode *> newlists;
			for (int i = 0; i < lists.size(); i += 2) {
				if (i + 1 >= lists.size()) {
					newlists.push_back(lists[i]);
				}
				else {
					newlists.push_back(merge(lists[i], lists[i + 1]));
				}
			}
			lists.swap(newlists);
		}

		return lists[0];
	}

	ListNode* merge(ListNode* a, ListNode* b) {
		ListNode *n = new ListNode(1);
		ListNode *tmp = n;

		while (true) {
			if (a == NULL || b == NULL) {
				tmp->next = a ? a : b;
				return n->next;
			}

			if (a->val > b->val) {
				tmp->next = b;
				b = b->next;
			}
			else {
				tmp->next = a;
				a = a->next;
			}
			tmp = tmp->next;
		}

	}
};