/*
Problem Statement: https://leetcode.com/problems/valid-number/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isNumber(string s) {
		int n = s.length();
		bool dig, dec, exp;
		dig = dec = exp = false;
		
		// Pattern: ^[+-]?(\\d+(\\.\\d*)?|\\.\\d+)(e[+-]?\\d+)?$
		for (int i = 0; i < n; i++) {
			bool ok = true;
			char c = tolower(s[i]);
			if (c == '+' || c == '-')
				ok &= (i == 0 || tolower(s[i - 1]) == 'e');
			else if (c == 'e')
				ok &= exchange(dig, false) && !exchange(exp, true);
			else if (c == '.')
				ok &= !exp && !exchange(dec, true);
			else if (isdigit(c))
				dig = true;
			else
				ok = false;
			if (!ok)
				return false;
		}
		
		return dig;
	}
};