/*
Problem Statement: https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int n = p.length();
		vector<int> pos;
		vector<int> freq(26);
		
		for (char& c: p)
			freq[c - 'a']++;
		
		for (int i = 0; i < s.length(); i++) {
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