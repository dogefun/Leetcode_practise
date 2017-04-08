#include "stl.h"
class Solution {
public:
	string convert(string s, int numRows) {
		string res;
		int go = numRows - 1;
		if (!go)  return s;
		for (int i = 0; i < numRows; i++)
			for (int j = i; j < s.size(); j += (go - j % go) * 2)
				res += s[j];

		return res;
	}
};