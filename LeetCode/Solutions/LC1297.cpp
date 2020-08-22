/*
Problem Statement: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
*/

class Solution {
public:
	int maxFreq(string& s, int maxLetters, int minSize, int maxSize) {
		int occ = 0;
		bitset<26> b;
		unordered_map<string, int> freq;
		
		for (int i = 0; i <= s.length() - minSize; i++) {
			string sub = s.substr(i, minSize);
			b.reset();
			for (char c: sub)
				b.set(c - 'a');
			if (b.count() <= maxLetters)
				occ = max(++freq[sub], occ);
		}
		
		return occ;
	}
};