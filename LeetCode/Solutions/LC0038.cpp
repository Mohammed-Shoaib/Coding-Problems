/*
Problem Statement: https://leetcode.com/problems/count-and-say/
Time: O(n • 2ⁿ)
Space: O(2ⁿ)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string countAndSay(int n) {
		string s = "1";
		while (--n)
			s = convert(s);
		return s;
	}
	
	string convert(string& s) {
		string t;
		int n = s.length();
		
		for (int i = 0, j = 0; i < n; j = i) {
			while (i < n && s[j] == s[i])
				i++;
			t += i - j + '0';
			t += s[j];
		}
		
		return t;
	}
};