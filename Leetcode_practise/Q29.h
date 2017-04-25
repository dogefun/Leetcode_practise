#include "stl.h"
class Solution {
public:
	int divide(int dividend, int divisor) {
		int sign = 1;
		if (dividend<0) sign = -sign;
		if (divisor<0) sign = -sign;

		long long tmp = abs((long long)dividend);
		long long tmp2 = abs((long long)divisor);
		long long res = 0;
		int c = 0;

		while (tmp > tmp2 << c) {
			++c;
		}
		if (tmp != tmp2 << c) {
			--c;
		}
		tmp2 <<= c;

		while (c-- >= 0)
		{
			res <<= 1;
			if (tmp >= tmp2) {
				tmp -= tmp2;
				res += 1;
			}
			tmp2 >>= 1;
		}

		res *= sign;
		if (res < INT_MIN || res > INT_MAX) {
			return INT_MAX;
		}
		return res;
	}
};