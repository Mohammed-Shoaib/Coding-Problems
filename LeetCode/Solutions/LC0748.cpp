/*
Problem Statement: https://leetcode.com/problems/shortest-completing-word/
Time: O(n • max_len)
Space: O(max_len)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		string complete;
		int len = numeric_limits<int>::max();
		vector<int> freq = get_frequency(licensePlate);
		
		for (string& word: words) {
			if (word.length() >= len)
				continue;
			vector<int> cnt = get_frequency(word);
			if (all_of(cnt.begin(), cnt.end(), [&, i = 0](int& x) mutable {
				return x >= freq[i++];
			})) {
				complete = word;
				len = word.length();
			}
		}
		
		return complete;
	}
	
	vector<int> get_frequency(string& s) {
		vector<int> freq(26);
		for (char& c: s)
			if (isalpha(c))
				freq[tolower(c) - 'a']++;
		return freq;
	}
};