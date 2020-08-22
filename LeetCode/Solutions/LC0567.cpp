/*
Problem Statement: https://leetcode.com/problems/permutation-in-string/
Time: O(m + n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int m = s1.length(), n = s2.length();
		vector<int> freq(26);
		
		for (char& c: s1)
			freq[c - 'a']++;
		
		for (int i = 0; i < n; i++) {
			freq[s2[i] - 'a']--;
			if (i >= m)
				freq[s2[i - m] - 'a']++;
			bool zeros = all_of(freq.begin(), freq.end(), [](int& x) { return x == 0; });
			if (zeros)
				return true;
		}
		
		return false;
	}
};