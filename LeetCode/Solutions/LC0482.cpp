/*
Problem Statement: https://leetcode.com/problems/license-key-formatting/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string licenseKeyFormatting(string s, int k) {
		int n = s.length();
		string t;
		
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '-')
				continue;
			else if (t.length() % (k + 1) == k)
				t += '-';
			t += toupper(s[i]);
		}
		reverse(t.begin(), t.end());
		
		return t;
	}
};