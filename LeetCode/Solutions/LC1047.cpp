/*
Problem Statement: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string removeDuplicates(string& S) {
		string st;
		for (char& c: S) {
			if (st.size() && st.back() == c)
				st.pop_back();
			else
				st += c;
		}
		return st;
	}
};