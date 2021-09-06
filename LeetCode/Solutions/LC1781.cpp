/*
Problem Statement: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
Time: O(n²)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int beautySum(string s) {
		int beauty = 0, n = s.length();
		
		for (int i = 0; i < n; i++) {
			int min_f, max_f = 0;
			vector<int> freq(26);
			
			for (int j = i; j < n; j++) {
				max_f = min_f = max(++freq[s[j] - 'a'], max_f);
				for (int& x: freq)
					if (x)
						min_f = min(x, min_f);
				beauty += max_f - min_f;
			}
		}
		
		return beauty;
	}
};