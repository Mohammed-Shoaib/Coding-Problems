/*
Problem Statement: https://leetcode.com/problems/find-common-characters/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		int N = A.size();
		vector<string> common;
		vector<int> freq(26, numeric_limits<int>::max());
		
		for (string& s: A) {
			vector<int> cnt(26);
			for (char& c: s)
				cnt[c - 'a']++;
			for (int i = 0; i < freq.size(); i++)
				freq[i] = min(cnt[i], freq[i]);
		}
		
		for (char c = 'a'; c <= 'z'; c++)
			common.insert(common.end(), freq[c - 'a'], string(1, c));
		
		return common;
	}
};