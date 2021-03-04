/*
Problem Statement: https://leetcode.com/problems/make-the-string-great/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string makeGood(string s) {
		vector<char> st;
		for (char& c: s) {
			if (!st.empty() && abs(c - st.back()) == 32)
				st.pop_back();
			else
				st.push_back(c);
		}
		return string(st.begin(), st.end());
	}
};