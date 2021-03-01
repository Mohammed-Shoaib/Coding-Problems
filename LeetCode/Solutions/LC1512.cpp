/*
Problem Statement: https://leetcode.com/problems/number-of-good-pairs/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int numIdenticalPairs(vector<int>& nums) {
		int cnt = 0;
		unordered_map<int, int> freq;
		for (int& x: nums)
			cnt += freq[x]++;
		return cnt;
	}
};