#include "stl.h"

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		int size = 0;
		while (size < strs[0].size()) {
			for (auto i = strs.begin(); i != strs.end(); i++) {
				if (i->size() <= size || i->at(size) != strs[0][size]) {
					return strs[0].substr(0, size);
				}
			}
			++size;
		}
		return strs[0].substr(0, size);

	}
};