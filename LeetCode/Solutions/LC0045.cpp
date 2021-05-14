/*
Problem Statement: https://leetcode.com/problems/jump-game-ii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int jump(vector<int>& nums) {
		int jumps, pos, max_pos, n = nums.size();
		jumps = pos = max_pos = 0;
		
		for (int i = 0; i + 1 < n; i++) {
			max_pos = max(i + nums[i], max_pos);
			if (i == pos) {
				jumps++;
				pos = max_pos;
			}
		}
		
		return jumps;
	}
};