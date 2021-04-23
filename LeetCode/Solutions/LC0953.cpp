/*
Problem Statement: https://leetcode.com/problems/verifying-an-alien-dictionary/
Time: O(n • max_len)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		int n = words.size();
		vector<int> mp(26);
		
		for (int i = 0; i < order.length(); i++)
			mp[order[i] - 'a'] = i;
		
		return is_sorted(words.begin(), words.end(), [&mp](string& l, string& r) {
			int m = l.length(), n = r.length();
			
			for (int i = 0; i < min(m, n); i++)
				if (l[i] != r[i])
					return mp[l[i] - 'a'] < mp[r[i] - 'a'];
			
			return m < n;
		});
	}
};