/*
Problem Statement: https://leetcode.com/problems/reverse-only-letters/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string reverseOnlyLetters(string S) {
		int i = 0, j = static_cast<int>(S.length()) - 1;
		
		while (i < j) {
			if (!isalpha(S[i]))
				i++;
			else if (!isalpha(S[j]))
				j--;
			else
				swap(S[i++], S[j--]);
		}
		
		return S;
	}
};