/*
Problem Statement: https://leetcode.com/problems/letter-case-permutation/
Time: O(2ⁿ • n)
Space: O(2ⁿ)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<string> letterCasePermutation(string S) {
		vector<string> perms = { "" };
		
		for (char& c: S) {
			vector<string> state;
			for (string& perm: perms) {
				state.push_back(perm + (char) tolower(c));
				if (isalpha(c))
					state.push_back(perm + (char) toupper(c));
			}
			perms = move(state);
		}
		
		return perms;
	}
};