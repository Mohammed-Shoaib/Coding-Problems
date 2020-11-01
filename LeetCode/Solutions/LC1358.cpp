/*
Problem Statement: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
*/

class Solution {
public:
	int numberOfSubstrings(string& s) {
		int subs = 0;
		vector<int> cnt(3);
		
		for (int i = 0, j = 0; i < s.length(); i++) {
			cnt[s[i] - 'a']++;
			while(!count(cnt.begin(), cnt.end(), 0))
				cnt[s[j++] - 'a']--;
			subs += j;
		}

		return subs;
	}
};