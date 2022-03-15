/*
Problem Statement: https://leetcode.com/problems/reverse-vowels-of-a-string/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string reverseVowels(string s) {
		int n = s.length(), i = 0, j = n - 1;
		unordered_set<char> vowels;
		
		// initialization
		for (char c: {'a', 'e', 'i', 'o', 'u'}) {
			vowels.insert(c);
			vowels.insert(toupper(c));
		}
		
		// reverse vowels
		while (i < j) {
			if (!vowels.count(s[i]))
				i++;
			else if (!vowels.count(s[j]))
				j--;
			else
				swap(s[i++], s[j--]);
		}
		
		return s;
	}
};