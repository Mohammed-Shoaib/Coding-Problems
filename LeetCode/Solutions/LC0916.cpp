/*
Problem Statement: https://leetcode.com/problems/word-subsets/
Time: O(A + B)
Space: O(A)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		vector<int> freq(26);
		vector<string> universal;
		
		for (string& word: B) {
			vector<int> cnt(26);
			for (char& c: word)
				freq[c - 'a'] = max(++cnt[c - 'a'], freq[c - 'a']);
		}
		
		for (string& word: A) {
			vector<int> cnt(26);
			
			for (char& c: word)
				cnt[c - 'a']++;
			
			auto it = mismatch(freq.begin(), freq.end(), cnt.begin(), [](int x, int y) {
				return x <= y;
			});
			
			if (it.first == freq.end())
				universal.push_back(word);
		}
		
		return universal;
	}
};