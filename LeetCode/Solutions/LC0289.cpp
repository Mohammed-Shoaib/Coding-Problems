/*
Problem Statement: https://leetcode.com/problems/game-of-life/
Time: O(m • n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int m = board.size(), n = board[0].size();
		
		// helper function
		auto count_alive = [&](int x, int y) {
			int alive = -board[x][y];
			for (int i = max(x - 1, 0); i <= min(x + 1, m - 1); i++)
				for (int j = max(y - 1, 0); j <= min(y + 1, n - 1); j++)
					alive += board[i][j] & 1;
			return alive;
		};
		
		// store next state on the next bit
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if ((count_alive(i, j) | board[i][j]) == 3)
					board[i][j] |= 2;
		
		// shift to new state
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				board[i][j] >>= 1;
	}
};