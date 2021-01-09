/*
Problem Statement: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Time: O(n • 4ⁿ)
Space: O(4ⁿ)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		int n = digits.length();
		vector<string> res, mp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		
		for (int i = 0; i < n; i++) {
			vector<string> state;
			if (res.empty())
				res = { "" };
			for (string& s: res)
				for (char& c: mp[digits[i] - '2'])
					state.push_back(s + c);
			res = state;
		}
		
		return res;
	}
};