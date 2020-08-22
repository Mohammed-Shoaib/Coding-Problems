/*
Problem Statement: https://leetcode.com/problems/find-all-anagrams-in-a-string/
Time: O(m + n)
Space: O(m)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int m = s.length(), n = p.length();
		vector<int> pos, freq(26);
		
		for (char& c: p)
			freq[c - 'a']++;
		
		for (int i = 0; i < m; i++) {
			freq[s[i] - 'a']--;
			if (i >= n)
				freq[s[i - n] - 'a']++;
			bool zeros = all_of(freq.begin(), freq.end(), [](int& x) { return x == 0; });
			if (zeros)
				pos.push_back(i + 1 - n);
		}
		
		return pos;
	}
};