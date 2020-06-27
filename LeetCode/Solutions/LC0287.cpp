/*
Problem Statement: https://leetcode.com/problems/find-the-duplicate-number/
*/

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow, fast;
		slow = fast = 0;
		
		// floyd's algorithm
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);

		// find the entrance to the cyle
		slow = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}

		return slow;
	}
};