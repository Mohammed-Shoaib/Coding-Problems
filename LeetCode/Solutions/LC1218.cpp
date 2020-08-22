/*
Problem Statement: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int longestSubsequence(vector<int>& arr, int difference) {
		int max_len = 0;
		unordered_map<int, int> freq;
		
		for (int& x: arr) {
			freq[x] = 1 + freq[x - difference];
			max_len = max(freq[x], max_len);
		}
		
		return max_len;
	}
};