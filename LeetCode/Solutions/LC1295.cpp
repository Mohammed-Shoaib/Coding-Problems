/*
Problem Statement: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
*/

class Solution {
public:
	int findNumbers(vector<int>& nums) {
		int cnt = 0;
		for (int num: nums)
			if (length(num) % 2 == 0)
				cnt++;
		return cnt;
	}

	int length(int num) {
		if (num == 0)
			return 1;
		int len = 0;
		for (len = 0; num != 0; len++)
			num /= 10;
		return len;
	}
};