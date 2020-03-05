/*
Problem Statement: https://leetcode.com/problems/path-with-maximum-gold/
*/

class Solution {
public:
	int x[4] = {0, 0, -1, 1};
	int y[4] = {-1, 1, 0, 0};

	int DFS(int i, int j, vector< vector<int> > &grid) {
		// Base Cases
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
			return 0;
		
		int max_gold, temp;
		temp = grid[i][j];
		max_gold = grid[i][j] = 0;
		
		// Loop through all directions
		for(int k = 0; k < 4; k++)
			max_gold = max(DFS(i + y[k], j + x[k], grid), max_gold);

		grid[i][j] = temp;

		return max_gold + grid[i][j];
	}

    int getMaximumGold(vector< vector<int> > &grid) {
		int path = 0;

		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				path = max(DFS(i, j, grid), path);
		
		return path;
    }
};