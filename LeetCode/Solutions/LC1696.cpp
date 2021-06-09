/*
Problem Statement: https://leetcode.com/problems/jump-game-vi/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxResult(vector<int> nums, int k) {
		int n = nums.size();
		deque<int> d{0};
		
		// dynamic programming + monotonic deque
		for (int i = 1; i < n; i++) {
			if (i - d.front() > k)
				d.pop_front();
			nums[i] += nums[d.front()];
			while (!d.empty() && nums[d.back()] <= nums[i])
				d.pop_back();
			d.push_back(i);
		}
		
		return nums[d.back()];
	}
};