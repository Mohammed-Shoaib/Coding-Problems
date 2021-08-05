/*
Problem Statement: https://leetcode.com/problems/4sum-ii/
Time: O(n²)
Space: O(n²)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int cnt = 0;
		unordered_map<int, int> freq;
		
		// pre-process
		for (int& c: C)
			for (int& d: D)
				freq[c + d]++;
		
		// two-sum
		for (int& a: A)
			for (int& b: B)
				if (freq.count(- a - b))
					cnt += freq[- a - b];
		
		return cnt;
	}
};