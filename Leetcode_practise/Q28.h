#include "stl.h"
class Solution {
public:
	vector<int> makenext(string str) {
		vector<int> next(str.size() + 1);
		next[0] = 0;
		for (int i = 1; i < str.size(); i++) {
			int k = next[i - 1];
			while (k != 0 && str[k] != str[i]) k = next[k - 1];
			next[i] = str[k] != str[i] ? 0 : k + 1;
		}
		return next;
	}

	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		auto x = makenext(needle);
		int m = 0;
		for (int i = 0; i < haystack.size(); i++) {
			while (m > 0 && needle[m] != haystack[i])
				m = x[m - 1];
			if (haystack[i] == needle[m]) {
				m++;
			}
			if (m == needle.size())
				return i - m + 1;
		}

		return -1;
	}
};