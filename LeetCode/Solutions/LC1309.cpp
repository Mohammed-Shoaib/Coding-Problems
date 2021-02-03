/*
Problem Statement: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
*/

class Solution {
public:
	string freqAlphabets(string& s) {
		string t;
		int n = s.length();
		for (int i = 0; i < n; i++) {
			if (i < n - 2 && s[i + 2] == '#') {
				t += 'a' + (s[i] - '0') * 10 + (s[i + 1] - '1');
				i += 2;
			}
			else
				t += 'a' + s[i] - '1';
		}
		return t;
	}
};