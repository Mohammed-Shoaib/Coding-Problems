/*
Problem Statement: https://leetcode.com/problems/sum-of-unique-elements/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int sumOfUnique(vector<int>& nums) {
		int sum = 0;
		unordered_map<int, int> freq;
		
		for (int& x: nums)
			freq[x]++;
		
		for (auto& [k, v]: freq)
			if (v == 1)
				sum += k;
		
		return sum;
	}
};