/*
Problem Statement: https://leetcode.com/problems/ugly-number/
Time: O(log n)
Space: O(1)
*/

class Solution {
public:
	bool isUgly(int num) {
		for(int f: {2, 3, 5})
			while (num && num % f == 0)
				num /= f;
		return num == 1;
	}
};