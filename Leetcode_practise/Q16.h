#include "stl.h"
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int res = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right) {
				int sum = nums[left] + nums[right] + nums[i];
				if (sum > target) {
					right--;
				}
				else if (sum < target) {
					left++;
				}
				else {
					return target;
				}
				res = abs(target - sum) < abs(target - res) ? sum : res;
			}
		}

		return res;
	}
};