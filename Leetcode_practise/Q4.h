#include "stl.h"
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() && nums2.empty()) return 0;
		int half = (nums1.size() + nums2.size()) / 2 + 1;
		int a, b = 0;
		int i = 0, j = 0;
		while (i + j < half) {
			a = b;
			if (i == nums1.size()) {
				b = nums2[j++];
				continue;
			}
			if (j == nums2.size()) {
				b = nums1[i++];
				continue;
			}
			b = nums1[i] < nums2[j] ? b = nums1[i++] : b = nums2[j++];

		}
		if ((nums1.size() + nums2.size()) % 2) {
			a = b;
		}
		return (a + b) * 1.0 / 2;
	}
};