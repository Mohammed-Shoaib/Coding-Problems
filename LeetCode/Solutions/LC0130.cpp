/*
Problem Statement: https://leetcode.com/problems/surrounded-regions/
*/

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;
		
		int m, n;
		m = board.size();
		n = board[0].size();
		
		// traverse neighbours easily
		vector<int> xdir = {-1, 0, 1, 0};
		vector<int> ydir = {0, -1, 0, 1};
		
		// flood-fill
		function<void(int, int)> dfs = [&](int i, int j) {
			// base cases
			if (i < 0 || i == m || j < 0 || j == n || board[i][j] != 'O')
				return;
			
			// visit position (i, j)
			board[i][j] = '*';
			for (int k = 0; k < xdir.size(); k++)
				dfs(i + xdir[k], j + ydir[k]);
		};
		
		// go through the borders
		for (int i = 0; i < n; i++) {
			dfs(0, i);
			dfs(m - 1, i);
		}
		for (int i = 0; i < m; i++) {
			dfs(i, 0);
			dfs(i, n - 1);
		}
		
		// capture surrounded regions
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == '*')
					board[i][j] = 'O';
			}
	}
};