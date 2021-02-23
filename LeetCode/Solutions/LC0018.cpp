/*
Problem Statement: https://leetcode.com/problems/4sum/
Time: O(n³)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> fourSum(vector<int> nums, int target) {
		int n = nums.size();
		vector<int> state;
		vector<vector<int>> quadruplets;
		
		// helper function to solve two sum
		auto two_sum = [&](int pos, int sum, vector<int>& state) {
			int beg = pos, end = n - 1;
			
			// two-pointer technique
			while (beg < end) {
				int curr = sum + nums[beg] + nums[end];
				if (curr == target) {
					quadruplets.push_back(state);
					quadruplets.back().push_back(nums[beg]);
					quadruplets.back().push_back(nums[end]);
					
					// avoid duplicates
					while (beg < end && nums[beg] == nums[beg + 1])
						beg++;
					while (beg < end && nums[end - 1] == nums[end])
						end--;
					beg++, end--;
				}
				else if (curr < target)
					beg++;
				else
					end--;
			}
		};
		
		// helper function to solve general case
		function<void(int, int, int, vector<int>&)> k_sum = [&](int k, int pos, int sum, vector<int>& state) {
			// base case
			if (k == 2)
				return two_sum(pos, sum, state);
			
			// recurse
			for (int i = pos; i < n; i++) {
				if (i - 1 >= pos && nums[i - 1] == nums[i])
					continue;
				state.push_back(nums[i]);
				k_sum(k - 1, i + 1, sum + nums[i], state);
				state.pop_back();
			}
		};
		
		sort(nums.begin(), nums.end());
		k_sum(4, 0, 0, state);
		
		return quadruplets;
	}
};