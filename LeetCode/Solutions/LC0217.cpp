/*
Problem Statement: https://leetcode.com/problems/contains-duplicate/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> seen;
		for (int& x: nums) {
			if (seen.count(x))
				return true;
			seen.insert(x);
		}
		return false;
	}
};