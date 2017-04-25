#include "stl.h"
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> mark(257, 0);
		int res = 0;
		int i = 0, j = 0;
		for (; j < s.size(); ++j) {
			++mark[s[j]];
			if (mark[s[j]] > 1) {
				res = max(res, j - i);
				for (;i <= j; ++i) {
					--mark[s[i]];
					if (mark[s[j]] == 1) {
						++i;
						break;
					}
				}
			}
		}
		res = max(res, j - i);
		return res;
	}
};