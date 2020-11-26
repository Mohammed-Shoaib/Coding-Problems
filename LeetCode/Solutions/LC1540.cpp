/*
Problem Statement: https://leetcode.com/problems/can-convert-string-in-k-moves/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool canConvertString(string s, string t, int k) {
		if (s.length() != t.length())
			return false;
		
		int mod = 26, n = s.length();
		vector<int> freq(mod);
		
		for (int i = 0; i < n; i++) {
			int x = (t[i] - s[i] + mod) % mod;
			if (x > 0 && mod * freq[x] + x > k)
				return false;
			freq[x]++;
		}
		
		return true;
	}
};