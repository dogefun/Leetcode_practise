#include "stl.h"
class Solution {
public:
	int reverse(int x) {
		bool fushu = 0;
		if (x < 0) {
			fushu = true;
			x = -x;
		}
		string a = to_string(x);
		a = string(a.rbegin(), a.rend());

		try {
			x = stoi(a);
		}
		catch (exception e) {
			return 0;
		}
		if (fushu)
			x = -x;
		return x;
	}
};