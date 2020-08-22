/*
Problem Statement: https://leetcode.com/problems/3sum/
Time: O(n²)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int> nums) {
		int l, r, sum, n = nums.size();
		vector<vector<int>> triplets;
		sort(nums.begin(), nums.end());
		
		for (int i = 0; i < n && nums[i] <= 0; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			l = i + 1;
			r = n - 1;
			while (l < r) {
				sum = nums[i] + nums[l] + nums[r];
				if (sum == 0) {
					triplets.push_back({nums[i], nums[l], nums[r]});
					while (l < r && nums[l] == nums[l + 1])
						l++;
					while (l < r && nums[r] == nums[r - 1])
						r--;
					l++;
				}
				else if (sum < 0)
					l++;
				else
					r--;
			}
		}
		
		return triplets;
	}
};