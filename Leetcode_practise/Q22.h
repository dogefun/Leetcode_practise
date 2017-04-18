#include "stl.h"
class Solution {
public:
	vector<string> res;
	vector<string> generateParenthesis(int n) {
		string s;
		generate(s, n, n);
		return res;
	}

	void generate(string str, int left, int right) {
		if (left == 0 && right == 0) {
			res.emplace_back(str);
			return;
		}
		if (left > right) {
			return;
		}

		if (left > 0) {
			generate(str + "(", left - 1, right);
		}
		if (right > 0) {
			generate(str + ")", left, right - 1);
		}
	}
};