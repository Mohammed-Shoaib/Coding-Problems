/*
Problem Statement: https://leetcode.com/problems/find-longest-awesome-substring/
Time: O(m • n)
Space: O(2ᵐ)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int longestAwesome(string s) {
		int max_l, b, m = 10, n = s.length();
		vector<int> mp(1 << m, n);
		mp[0] = -1;
		max_l = b = 0;

		for (int i = 0; i < n; i++) {
			b ^= 1 << (s[i] - '0');
			max_l = max(i - mp[b], max_l);
			for (int j = 0; j < m; j++)
				max_l = max(i - mp[b ^ (1 << j)], max_l);
			mp[b] = min(i, mp[b]);
		}

		return max_l;
	}
};