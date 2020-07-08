/*
Problem Statement: https://leetcode.com/problems/plus-one/
Time: O(n)
Space: O(n)
*/

class Solution {
public:
	vector<int> plusOne(vector<int> digits) {
		int n = digits.size();
		for (int i = n - 1; i >= 0; i--) {
			digits[i] = (digits[i] + 1) % 10;
			if (digits[i])
				return digits;
		}
		digits.resize(n + 1);
		digits[0] = 1;
		return digits;
	}
};