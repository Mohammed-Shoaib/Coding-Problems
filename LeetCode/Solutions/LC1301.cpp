/*
Problem Statement: https://leetcode.com/problems/number-of-paths-with-max-score/
*/

class Solution {
public:
	vector<int> pathsWithMaxScore(vector<string>& board) {
		int mod, n, val;
		mod = 1e9 + 7;
		n = board.size();
		vector< vector<int> > score(n + 1, vector<int>(n + 1)), paths(n + 1, vector<int>(n + 1));
		
		// Helper function
		auto process = [&](int u, int v, int i, int j) {
			if (score[u][v] < score[i][j]) {
				score[u][v] = score[i][j];
				paths[u][v] = paths[i][j];
			}
			else if (score[u][v] == score[i][j])
				paths[u][v] = (paths[u][v] + paths[i][j]) % mod;
		};

		// Initialize
		paths[0][0] = 1;
		board[0][0] = board[n - 1][n - 1] = '0';

		// Dynamic Programming
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				val = board[i - 1][j - 1] - '0';
				if (val > 9)
					continue;
				process(i, j, i - 1, j);
				process(i, j, i, j - 1);
				process(i, j, i - 1, j - 1);
				if (paths[i][j])
					score[i][j] += val;
			}
		
		return {score[n][n], paths[n][n]};
	}
};