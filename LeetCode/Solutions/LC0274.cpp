/*
Problem Statement: https://leetcode.com/problems/h-index/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		vector<int> prefix(n + 1);
		
		for (int& citation: citations)
			prefix[min(citation, n)]++;
		
		for (int i = n - 1; i >= 0; i--)
			prefix[i] += prefix[i + 1];
		
		for (int i = n; i > 0; i--)
			if (prefix[i] >= i)
				return i;
		
		return 0;
	}
};