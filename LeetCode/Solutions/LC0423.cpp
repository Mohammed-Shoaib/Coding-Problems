/*
Problem Statement: https://leetcode.com/problems/reconstruct-original-digits-from-english/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string originalDigits(string s) {
		string digits;
		vector<int> cnt(10), freq(26);
		vector<string> mp = {
			"zero", "one", "two", "three", "four",
			"five", "six", "seven", "eight", "nine"
		};
		vector<pair<int, char>> order = {
			{0, 'z'}, {2, 'w'}, {4, 'u'}, {6, 'x'}, {8, 'g'},
			{1, 'o'}, {3, 'r'}, {5, 'f'}, {7, 's'}, {9, 'i'}
		};
		
		// preprocess
		for (char& c: s)
			freq[c - 'a']++;
		
		// compute the count of each digit
		for (auto& [d, k]: order) {
			cnt[d] = freq[k - 'a'];
			for (char& c: mp[d])
				freq[c - 'a'] -= cnt[d];
		}
		
		// create the original digits
		for (int i = 0; i < cnt.size(); i++)
			digits += string(cnt[i], i + '0');
		
		return digits;
	}
};