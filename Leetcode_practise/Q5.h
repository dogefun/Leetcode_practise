#include "stl.h"

class Solution {
public:
	string longestPalindrome(string s) {
		string t = "@#";
		for (int i = 0; i < s.size(); i++) {
			t += s[i] ;
			t += "#";
		}

		vector<int> len(t.size());
		int respos = 0;
		int reslen = 0;

		int pos = 1, mx = 1;
		for (int i = 1; i < t.size(); i++) {
			len[i] = mx > i ? min(mx - i,len[2 * pos - i]) : 1;
			while (t[i + len[i]] == t[i - len[i]]) {
				len[i]++;
			}
			if (mx < i + len[i]) {
				mx = i + len[i];
				pos = i;
			}
			if (reslen < len[i]) {
				respos = i;
				reslen = len[i];
			}
		}

		return s.substr((respos - reslen) / 2, reslen - 1);
	}
};
