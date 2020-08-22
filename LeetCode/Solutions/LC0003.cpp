/*
Problem Statement: https://leetcode.com/problems/longest-substring-without-repeating-characters/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len, low, high;
		unordered_map<char, int> map;
		len = low = high = 0;
		
		for (int i = 0; i < s.length(); i++, high++) {
			if (map.find(s[i]) != map.end())
				low = max(map[s[i]] + 1, low);
			map[s[i]] = i;
			len = max(high - low + 1, len);
		}
		
		return len;
	}
};