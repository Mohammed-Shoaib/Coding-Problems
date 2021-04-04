/*
Problem Statement: https://leetcode.com/problems/sort-colors/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int beg, mid, end;
		beg = mid = 0;
		end = nums.size() - 1;
		while (mid <= end) {
			if (nums[mid] == 0)
				swap(nums[beg++], nums[mid++]);
			else if (nums[mid] == 2)
				swap(nums[mid], nums[end--]);
			else
				mid++;
		}
	}
};