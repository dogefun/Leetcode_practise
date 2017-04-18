#include "stl.h"
class Solution {
public:
	bool isValid(string s) {
		stack<char> sta;
		for (int i = 0; i < s.size(); i++) {
			switch (s[i]) {
			case '(':
				sta.push(')');
				break;
			case ')':
				if (sta.empty() || sta.top() != ')') {
					return false;
				}
				sta.pop();
				break;
			case '{':
				sta.push('}');
				break;
			case '}':
				if (sta.empty() || sta.top() != '}') {
					return false;
				}
				sta.pop();
				break;
			case '[':
				sta.push(']');
				break;
			case ']':
				if (sta.empty() || sta.top() != ']') {
					return false;
				}
				sta.pop();
				break;
			}
		}

		return sta.empty();
	}
};