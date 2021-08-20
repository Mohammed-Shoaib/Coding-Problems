/*
Problem Statement: https://leetcode.com/problems/custom-sort-string/
Time: O(m + n)
Space: O(m + n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string customSortString(string order, string str) {
		string sorted;
		vector<int> freq(26);
		
		for (char& c: str)
			freq[c - 'a']++;
		
		for (char& c: order)
			sorted += string(exchange(freq[c - 'a'], 0), c);
		
		for (char c = 'a'; c <= 'z'; c++)
			sorted += string(freq[c - 'a'], c);
		
		return sorted;
	}
};