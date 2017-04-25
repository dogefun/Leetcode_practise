#include "stl.h"
struct node {
	string s;
	int time = 0;
	int nowtime = 0;
	node *next = 0;
	node(const string &ss) { s = ss; };
};
class Solution {
public:
	int fuckhash(const string &s) {
		int hashval = 0;
		for (int i = 0; i < s.size() && i < 2; i++) {
			hashval = hashval * 26 + (s[i] - 'a');
		}
		return hashval;
	}

	vector<int> findSubstring(string s, vector<string>& words) {
		vector<node*> nl(677, NULL);
		vector<node*> all;
		for (int i = 0; i < words.size(); i++) {
			int x = fuckhash(words[i]);
			if (nl[x] == 0) {
				nl[x] = new node(words[i]);
				all.push_back(nl[x]);
			}
			node *tmp = nl[x];
			while (tmp->next != 0 && tmp->s != words[i]) tmp = tmp->next;
			if (tmp->s != words[i]) {
				tmp->next = new node(words[i]);
				all.push_back(tmp->next);
				tmp->next->time++;
			}
			else {
				tmp->time++;
			}
		}

		int size = words[0].size();
		vector<int> res;
		for (int i = 0; i < s.size() - size * words.size() + 1; i++) {
			int j = i;
			for (auto a = all.begin(); a != all.end(); a++) {
				(*a)->nowtime = (*a)->time;
			}
			for (; j < i + size * words.size(); j += size) {
				auto fw = s.substr(j, size);
				auto x = fuckhash(fw);
				auto tmp2 = nl[x];
				while (tmp2 != 0 && tmp2->s != fw) {
					tmp2 = tmp2->next;
				}
				if (tmp2 != 0 && tmp2->s == fw) {
					tmp2->nowtime--;
					if (tmp2->nowtime < 0)	break;
				}
				else break;
			}
			if (j == i + size * words.size()) 	res.emplace_back(i);
		}
		return res;
	}
};