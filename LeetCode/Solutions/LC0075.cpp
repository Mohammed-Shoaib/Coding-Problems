/*
Problem Statement: https://leetcode.com/problems/sort-colors/
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