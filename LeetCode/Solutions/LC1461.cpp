/*
Problem Statement: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
*/

class Solution {
public:
	bool hasAllCodes(string s, int k) {
		int b, n;
		b = 0;
		n = s.length();
		vector<bool> seen(1 << k);

		for (int i = 0; i < n; i++) {
			b &= (1 << (k - 1)) - 1;
			b <<= 1;
			b |= s[i] - '0';
			if (i >= k - 1)
				seen[b] = true;
		}

		return all_of(seen.begin(), seen.end(), [](bool x) { return x; });
	}
};