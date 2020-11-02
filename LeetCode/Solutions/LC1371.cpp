/*
Problem Statement: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
*/

class Solution {
public:
	int findTheLongestSubstring(string& s) {
		int max_len, bm;
		max_len = bm = 0;
		unordered_map<int, int> m = {{0, -1}};
		unordered_map<char, int> v = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
		
		for (int i = 0; i < s.length(); i++) {
			if (v.count(s[i]))
				bm ^= 1 << v[s[i]];
			if (m.count(bm))
				max_len = max(i - m[bm], max_len);
			else
				m[bm] = i;
		}

		return max_len;
	}
};