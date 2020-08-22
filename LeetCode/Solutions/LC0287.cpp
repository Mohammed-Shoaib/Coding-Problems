/*
Problem Statement: https://leetcode.com/problems/find-the-duplicate-number/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow, fast;
		slow = fast = 0;
		
		// floyd's cycle-finding algorithm
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);
		
		// find the entrance to the cycle
		slow = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		
		return slow;
	}
};