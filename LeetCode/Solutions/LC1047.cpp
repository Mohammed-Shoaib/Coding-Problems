/*
Problem Statement: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
*/

class Solution {
public:
	string removeDuplicates(string& S) {
		string st;
		for (int i = 0; i < S.length(); i++)
			if (st.size() && st.back() == S[i])
				st.pop_back();
			else
				st += S[i];
		return st;
	}
};