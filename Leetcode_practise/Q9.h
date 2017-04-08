#include "stl.h"
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)	return false;
		unsigned long long size = 1;
		
		while (x / (size * 10) != 0) {
			size *= 10;
		}

		for (unsigned long long  i = 1, j = size; i < j; i*=10, j/=10) {
			int a = x / i;
			a %= 10;
			int b = x / j;
			b %= 10;
			if (a != b)
				return false;
		}
		return true;
	}
};