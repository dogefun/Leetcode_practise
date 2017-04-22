#pragma once
#include "stl.h"
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int end = 0;
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] != val) nums[end++] = nums[i];
		nums.erase(nums.begin() + end, nums.end());
		return nums.size();
	}
};