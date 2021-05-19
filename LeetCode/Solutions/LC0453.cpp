/*
Problem Statement: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int moves = 0, mn = *min_element(nums.begin(), nums.end());
		for (int& x: nums)
			moves += x - mn;
		return moves;
	}
};