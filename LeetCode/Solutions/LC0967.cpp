/*
Problem Statement: https://leetcode.com/problems/numbers-with-same-consecutive-differences/
Time: O(2ⁿ • 10)
Space: O(2ⁿ • 10)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> numsSameConsecDiff(int N, int K) {
		vector<int> nums;

		// helper function
		function<void(int, int)> dfs = [&](int num, int n) {
			// base case
			if (n == 0) {
				nums.push_back(num);
				return;
			}

			// recurse
			int d = num % 10;
			if (d + K <= 9)	
				dfs(10 * num + (d + K), n - 1);
			if (K && d - K >= 0)
				dfs(10 * num + (d - K), n - 1);
		};

		for (int i = 1 - (N == 1); i <= 9; i++)
			dfs(i, N - 1);
		
		return nums;
	}
};