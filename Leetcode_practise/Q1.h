#include "stl.h"

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> num(nums);
		sort(num.begin(), num.end());

		for (int i = 0; i < num.size(); i++)
		{
			int left = i + 1;
			int right = num.size() - 1;

			while (left < right) {
				int mid = left + ((right - left) >> 2);
				if (num[mid] + num[i] < target) {
					left = mid + 1;
				}
				else {
					right = mid;
				}
			}
			if (num[i] + num[left] == target) {
				int a = -1, b;
				for (int j = 0; j < nums.size(); j++) {
					if (a == -1 && num[i] == nums[j]) {
						a = j;
						if (num[i] == num[left]) continue;
					}
					if (num[left] == nums[j]) {
						b = j;
					}
				}

				return vector<int>{a, b};
			}
		}
		return vector<int>();
	}
};