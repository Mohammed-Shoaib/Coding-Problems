/*
Problem Statement: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string removeDuplicates(string s, int k) {
		int n = s.length();
		stack<pair<char, int>> st;
		
		for (char& c: s) {
			if (st.empty() || st.top().first != c)
				st.push({c, 1});
			else if (++st.top().second == k)
				st.pop();
		}
		
		string t;
		while (!st.empty()) {
			t += string(st.top().second, st.top().first);
			st.pop();
		}
		reverse(t.begin(), t.end());
		
		return t;
	}
};