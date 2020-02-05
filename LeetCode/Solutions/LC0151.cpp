/*
Problem Statement: https://leetcode.com/problems/reverse-words-in-a-string/
*/

class Solution {
public:
    string reverseWords(string s) {
		int l, i, j, n = s.length();
		reverse(s.begin(), s.end());
		for (l = i = j = 0; j < n; j++) {
			while (i < n && s[i] == ' ')
				i++;
			j = i;
			while (j < n && s[j] != ' ')
				j++;
			reverse(s.begin() + i, s.begin() + j);
			if (l && i != j)
				s[l++] = ' ';
			while (i != j)
				s[l++] = s[i++];
		}
		s.resize(l);
		return s;
    }
};