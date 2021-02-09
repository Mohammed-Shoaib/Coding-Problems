/*
Problem Statement: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
*/

class Solution {
public:
	vector<int> getNoZeroIntegers(int n) {
		for (int i = 1; i < n; i++)
			if (no_zero(i) && no_zero(n - i))
				return {i, n - i};
		return {};
	}

	bool no_zero(int num) {
		while (num) {
			if (num % 10 == 0)
				return false;
			num /= 10;
		}
		return true;
	}
};