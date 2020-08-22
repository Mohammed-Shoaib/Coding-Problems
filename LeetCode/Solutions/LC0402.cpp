/*
Problem Statement: https://leetcode.com/problems/remove-k-digits/
*/

class Solution {
public:
	string removeKdigits(string num, int k) {
		string st;
		
		for (char& c: num) {
			while (k && !st.empty() && st.back() > c) {
				st.pop_back();
				k--;
			}
			if (!st.empty() || c != '0')
				st.push_back(c);
		}
		
		while (k-- && !st.empty())
			st.pop_back();
		
		return st.empty() ? "0" : st;
	}
};