/*
Problem Statement: https://leetcode.com/problems/third-maximum-number/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		int64_t mn = numeric_limits<int64_t>::min();
		vector<int64_t> mx(3, mn);
		
		for (int& x: nums) {
			if (x == mx[0] || x == mx[1] || x == mx[2])
				continue;
			else if (mx[0] < x)
				mx[2] = exchange(mx[1], exchange(mx[0], x));
			else if (mx[1] < x)
				mx[2] = exchange(mx[1], x);
			else if (mx[2] < x)
				mx[2] = x;
		}
		
		return (mx[2] == mn) ? mx[0] : mx[2];
	}
};