/*
Problem Statement: https://leetcode.com/problems/sudoku-solver/
Time: O(9ⁿˣⁿ)
Space: O(n • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		int n = board.size();
		bool is_solved = false;
		vector<vector<int>> used(n, vector<int>(n));
		
		// helper functions
		auto populate = [&](int x, int y, int b) {
			used[x][y] |= 1 << b;
			for (int i = 0; i < n; i++)
				used[i][y] |= 1 << b;
			for (int j = 0; j < n; j++)
				used[x][j] |= 1 << b;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					used[i + (x / 3) * 3][j + (y / 3) * 3] |= 1 << b;
		};
		
		function<void(int)> state = [&](int pos) {
			// base case
			if (pos == n * n) {
				is_solved = true;
				return;
			}
			
			int x = pos / n, y = pos % n;
			vector<vector<int>> prev;
			if (board[x][y] != '.') {
				state(pos + 1);
				return;
			}
			
			for (int b = 1; b < 10; b++) {
				if (used[x][y] & (1 << b))
					continue;
				prev = used;
				board[x][y] = b + '0';
				populate(x, y, b);
				state(pos + 1);
				if (is_solved)
					return;
				board[x][y] = '.';
				used = prev;
			}
		};
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] != '.')
					populate(i, j, board[i][j] - '0');
		state(0);
	}
};