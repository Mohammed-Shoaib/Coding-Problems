/*
Problem Statement: https://leetcode.com/problems/first-unique-character-in-a-string/
Time: O(n)
Space: O(26)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int firstUniqChar(string s) {
		int n = s.length();
		vector<int> freq(26);
		
		for (char& c: s)
			freq[c - 'a']++;
		
		for (int i = 0; i < n; i++)
			if (freq[s[i] - 'a'] == 1)
				return i;
		
		return -1;
	}
};