/*
Problem Statement: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int longestSubstring(string s, int k) {
		return longest_substring(0, s.length(), k, s);
	}
	
	int longest_substring(int beg, int end, int k, string& s) {
		if (end - beg < k)
			return 0;
		
		int i, j, max_len = 0;
		vector<int> freq(26);
		
		for (i = beg; i < end; i++)
			freq[s[i] - 'a']++;
		
		if (all_of(freq.begin(), freq.end(), [&k](int& x) { return !x || x >= k; }))
			return end - beg;
		
		for (i = j = beg; j < end; j++)
			if (freq[s[j] - 'a'] < k) {
				max_len = max(longest_substring(i, j, k, s), max_len);
				i = j + 1;
			}
		max_len = max(longest_substring(i, j, k, s), max_len);
		
		return max_len;
	}
};