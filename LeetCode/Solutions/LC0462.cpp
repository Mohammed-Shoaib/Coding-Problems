/*
Problem Statement: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minMoves2(vector<int> nums) {
		int moves = 0, n = nums.size();
		sort(nums.begin(), nums.end());
		
		for (int i = 0; i < n / 2; i++)
			moves += nums[n - i - 1] - nums[i];
		
		return moves;
	}
};