/*
Problem Statement: https://leetcode.com/problems/non-decreasing-array/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		// helps to undo the modification
		pair<int, int> copy;
		int n = nums.size();
		
		// get the position that ruins the sorted order
		for (int i = 1; i < n; i++) {
			if (nums[i - 1] <= nums[i])
				continue;
			else if (i > 1 && nums[i - 2] > nums[i])
				copy = {i    , exchange(nums[i], nums[i - 1])};
			else
				copy = {i - 1, exchange(nums[i - 1], nums[i])};
			
			bool sorted = is_sorted(nums.begin(), nums.end());
			nums[copy.first] = copy.second;
			
			return sorted;
		}
		
		return true;
	}
};