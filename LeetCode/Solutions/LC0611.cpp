/*
Problem Statement: https://leetcode.com/problems/valid-triangle-number/
Time: O(n²)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int triangleNumber(vector<int> nums) {
		int cnt = 0, n = nums.size();
		sort(nums.begin(), nums.end());
		
		for (int i = 2; i < n; i++) {
			int l = 0, r = i - 1;
			while (l < r) {
				if (nums[l] + nums[r] <= nums[i])
					l++;
				else {
					cnt += r - l;
					r--;
				}
			}
		}
		
		return cnt;
	}
};