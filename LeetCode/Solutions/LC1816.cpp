/*
Problem Statement: https://leetcode.com/problems/truncate-sentence/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string truncateSentence(string s, int k) {
		string t, token;
		istringstream ss(s);
		
		for (int i = 0; i < k; i++) {
			getline(ss, token, ' ');
			if (!t.empty())
				t += ' ';
			t += token;
		}
		
		return t;
	}
};