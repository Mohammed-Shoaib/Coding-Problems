/*
Problem Statement: https://leetcode.com/problems/permutation-in-string/
*/

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int n = s1.length();
		vector<int> freq(26);

		for (char& c: s1)
			freq[c - 'a']++;
		
		for (int i = 0; i < s2.length(); i++) {
			freq[s2[i] - 'a']--;
			if (i >= n)
				freq[s2[i - n] - 'a']++;
			bool zeros = all_of(freq.begin(), freq.end(), [](int& x) { return x == 0; });
			if (zeros)
				return true;
		}

		return false;
	}
};