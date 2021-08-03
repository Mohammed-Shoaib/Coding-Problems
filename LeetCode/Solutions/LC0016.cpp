/*
Problem Statement: https://leetcode.com/problems/3sum-closest/
Time: O(n²)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int threeSumClosest(vector<int> nums, int target) {
		int n = nums.size(), closest = numeric_limits<int>::max();
		sort(nums.begin(), nums.end());
		
		for (int i = 0; i < n; i++) {
			int l = i + 1, r = n - 1;
			while (l < r) {
				int sum = nums[i] + nums[l] + nums[r] - target;
				if (abs(sum) < abs(closest))
					closest = sum;
				if (sum < 0)
					l++;
				else
					r--;
			}
		}
		
		return closest + target;
	}
};