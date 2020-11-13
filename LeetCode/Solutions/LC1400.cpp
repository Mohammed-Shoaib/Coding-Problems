/*
Problem Statement: https://leetcode.com/problems/construct-k-palindrome-strings/
*/

class Solution {
public:
	bool canConstruct(string& s, int k) {
		bitset<26> b;
		for (char c: s)
			b.flip(c - 'a');
		return b.count() <= k && k <= s.length();
	}
};