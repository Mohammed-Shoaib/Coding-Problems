/*
Problem Statement: https://leetcode.com/problems/maximum-product-of-word-lengths/
Time: O(n² + n • max_len)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxProduct(vector<string>& words) {
		int max_prod = 0, n = words.size();
		vector<int> freq(n);
		
		for (int i = 0; i < n; i++)
			for (char& c: words[i])
				freq[i] |= 1 << (c - 'a');
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				if ((freq[i] & freq[j]) == 0) {
					int prod = words[i].length() * words[j].length();
					max_prod = max(prod, max_prod);
				}
		
		return max_prod;
	}
};