/*
Problem Statement: https://leetcode.com/problems/increasing-decreasing-string/
*/

class Solution {
public:
	string sortString(string& s) {
		string res;
		bool asc = true;
		vector<int> freq(26);
		
		for (char c: s)
			freq[c - 'a']++;
		
		while (res.length() < s.length()) {
			for (int pos, i = 0; i < freq.size(); i++) {
				pos = (asc) ? i : freq.size() - i - 1;
				if (freq[pos] > 0) {
					res += 'a' + pos;
					freq[pos]--;
				}
			}
			asc = !asc;
		}
		
		return res;
	}
};