/*
Problem Statement: https://leetcode.com/problems/goat-latin/
Time: O(n + a²)
Space: O(n + a²)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string toGoatLatin(string S) {
		string T, a, word;
		istringstream ss(S);
		unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
		
		while (ss >> word) {
			if (vowels.count(tolower(word[0])))
				T += word;
			else
				T += word.substr(1) + word[0];
			a += 'a';
			T += "ma" + a + ' ';
		}
		T.pop_back();
		
		return T;
	}
};