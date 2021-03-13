/*
Problem Statement: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
Time: O(n)
Space: O(2ᵏ)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool hasAllCodes(string s, int k) {
		int n, cnt, code, size;
		n = s.length();
		cnt = code = 0;
		size = 1 << k;
		vector<bool> codes(size);
		
		// sliding window
		for (int i = 0; i < n; i++) {
			code = (code << 1) & (size - 1);
			code |= s[i] - '0';
			if (i >= k - 1) {
				cnt += !codes[code];
				codes[code] = true;
			}
			if (cnt == size)
				return true;
		}
		
		return false;
	}
};