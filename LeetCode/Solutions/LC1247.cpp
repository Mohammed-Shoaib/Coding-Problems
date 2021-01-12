/*
Problem Statement: https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/
*/

class Solution {
public:
	int minimumSwap(string& s1, string& s2) {
		int xy, yx, swaps;
		xy = yx = 0;

		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] == s2[i])
				continue;
			else if (s1[i] == 'x')
				xy++;
			else
				yx++;
		}

		if ((xy + yx) & 1)
			return -1;
		
		swaps = xy / 2 + yx / 2;
		swaps += (xy & 1) * 2;

		return swaps;
	}
};