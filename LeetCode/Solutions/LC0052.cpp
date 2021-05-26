/*
Problem Statement: https://leetcode.com/problems/n-queens-ii/
Time: O(n!)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int totalNQueens(int n) {
		int cnt = 0;
		vector<int> row(n), col(n), dig(2 * n - 1), rdig(2 * n - 1);
		
		// helper functions
		auto valid = [&](int x, int y) {
			return x >= 0 && x < n && y >= 0 && y < n;
		};
		
		auto taken = [&](int x, int y) {
			return !valid(x, y) || row[x] || col[y] || dig[x - y + n - 1] || rdig[x + y];
		};
		
		auto mark = [&](int x, int y, bool val) {
			if (!valid(x, y))
				return;
			row[x] = col[y] = dig[x - y + n - 1] = rdig[x + y] = val;
		};
		
		function<void(int)> dfs = [&](int i) {
			// base case
			if (i == n) {
				cnt++;
				return;
			}
			
			// backtracking
			for (int j = 0; j < n; j++) {
				if (taken(i, j))
					continue;
				mark(i, j, true);
				dfs(i + 1);
				mark(i, j, false);
			}
		};
		dfs(0);
		
		return cnt;
	}
};