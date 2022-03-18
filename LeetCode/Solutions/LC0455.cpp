/*
Problem Statement: https://leetcode.com/problems/assign-cookies/
Time: O(m • log m + n • log n)
Space: O(m + n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int cnt = 0, m = g.size(), n = s.size();
		
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		
		for (int i = 0; cnt < m && i < n; i++)
			if (s[i] >= g[cnt])
				cnt++;
		
		return cnt;
	}
};