/*
Problem Statement: https://leetcode.com/problems/minimum-window-substring/
*/

class Solution {
public:
	string minWindow(string s, string t) {
		int cnt, start, n, l, r;
		cnt = t.length();
		start = n = l = r = 0;
		unordered_map<char, int> freq;

		for (char& c: t)
			freq[c]++;

		while (r < s.length()) {
			if (freq[s[r]] > 0)
				cnt--;
			freq[s[r++]]--;
			if (cnt == 0) {
				while (freq[s[l]] < 0)
					freq[s[l++]]++;
				if (n == 0 || r - l < n) {
					start = l;
					n = r - l;
				}
				freq[s[l++]]++;
				cnt++;
			}
		}

		return s.substr(start, n);
	}
};