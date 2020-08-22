/*
Problem Statement: https://leetcode.com/problems/count-servers-that-communicate/
*/

class Solution {
public:
	int countServers(vector< vector<int> >& grid) {
		int servers, m, n;
		servers = 0;
		m = grid.size();
		n = grid[0].size();
		vector<int> row(m), col(n);
		
		// preprocess count of computers
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (grid[i][j]) {
					row[i]++;
					col[j]++;
				}
		
		// add server if connected with others
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (grid[i][j] && row[i] + col[j] > 2)
					servers++;
		
		return servers;
	}
};