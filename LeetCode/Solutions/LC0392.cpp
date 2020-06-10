/*
Problem Statement: https://leetcode.com/problems/is-subsequence/
*/

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int i = 0;
		if (s.empty())
			return true;
		
		for (char& c: t) {
			i += (s[i] == c);
			if (i == s.length())
				return true;
		}

		return false;
	}
};