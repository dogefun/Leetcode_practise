#include "stl.h"
class Solution {
public:
	int myAtoi(string str) {
		bool negative = false;
		int i;
		for (i = 0; i < str.size(); i++) {
			switch (str[i]) {
			case ' ':
				continue;
			case '-':
				negative = true;
				i++;
				break;
			case '+':
				i++;
				break;
			}
			break;
		}

		int res = 0;
		for (int j = 0; i < str.size(); i++, j++) {
			auto x = str[i] - '0';
			if (!(x >= 0 && x <= 9)) {
				break;
			}
			int tmp = res;
			res = res * 10 + x;

			if (((j > 8) && (tmp > 0 && res < 0)) || j >= 10) {
				if (negative) {
					return -2147483648;
				}
				else {
					return 2147483647;
				}
			}
		}

		if (negative)
			res = -res;
		return res;
	}
};