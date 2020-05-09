/*
Problem Statement: https://leetcode.com/problems/jump-game/
*/

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int reach = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i > reach)
				return false;
			reach = max(i + nums[i], reach);
		}
		return true;
	}
};