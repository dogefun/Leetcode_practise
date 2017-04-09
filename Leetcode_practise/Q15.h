#include "stl.h"
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.empty()) return res;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int left = i + 1;
			int right = nums.size() - 1;
			int tar = -nums[i];
			while (left < right) {
				int sum = nums[left] + nums[right];
				if (sum > tar) {
					right--;
				}
				else if (sum < tar) {
					left++;
				}
				else {
					res.push_back({ nums[i],nums[left],nums[right] });
					while (nums[++left] == nums[left - 1] && left < right);
					while (nums[--right] == nums[right + 1] && left < right);
				}
			}
		}

		return res;
	}
};