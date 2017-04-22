#pragma once
#include "stl.h"
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int end = 1;
		for (int i = 1; i < nums.size(); i++) 
			if (nums[i - 1] != nums[i]) nums[end++] = nums[i];
		nums.erase(nums.begin() + end, nums.end());
		return nums.size();
	}

	int anotherMethod(vector<int>& nums) {
		//use func unique
		auto end = unique(nums.begin(), nums.end());
		nums.erase(end, nums.end());
		return nums.size();
	}
};