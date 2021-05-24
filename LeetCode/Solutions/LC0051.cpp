/*
Problem Statement: https://leetcode.com/problems/n-queens/
Time: O(n!)
Space: O(n!)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> boards;
		vector<string> board(n, string(n, '.'));
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
				boards.push_back(board);
				return;
			}
			
			// backtracking
			for (int j = 0; j < n; j++) {
				if (taken(i, j))
					continue;
				mark(i, j, true);
				board[i][j] = 'Q';
				dfs(i + 1);
				board[i][j] = '.';
				mark(i, j, false);
			}
		};
		dfs(0);
		
		return boards;
	}
};