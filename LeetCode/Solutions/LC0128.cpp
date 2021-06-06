/*
Problem Statement: https://leetcode.com/problems/longest-consecutive-sequence/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int max_len = 0;
		unordered_set<int> seen(nums.begin(), nums.end());
		
		for (int x: seen) {
			if (seen.count(x - 1))
				continue;
			int y = x + 1;
			while (seen.count(y))
				y++;
			max_len = max(y - x, max_len);
		}
		
		return max_len;
	}
};