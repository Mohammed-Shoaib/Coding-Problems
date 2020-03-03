/*
Problem Statement: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
*/

class Solution {
public:
    string removeDuplicates(string& s, int k) {
        stack< pair<char, int> > st;

		for (int i = 0; i < s.length(); i++) {
			if (st.empty() || st.top().first != s[i])
				st.push({s[i], 1});
			else if (st.top().second + 1 == k)
				st.pop();
			else
				st.top().second++;
		}

		s = "";
		while (!st.empty()) {
			s += string(st.top().second, st.top().first);
			st.pop();
		}
		reverse(s.begin(), s.end());

		return s;
    }
};