/*
Problem Statement: https://leetcode.com/problems/k-diff-pairs-in-an-array/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		int cnt = 0;
		unordered_map<int, int> freq;
		
		for (int& x: nums)
			freq[x]++;
		
		for (auto& [x, v]: freq)
			if (freq.count(x - k) && freq[x - k] > (k == 0))
				cnt++;
		
		return cnt;
	}
};