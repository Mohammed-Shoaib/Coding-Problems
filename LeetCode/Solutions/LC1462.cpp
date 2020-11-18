/*
Problem Statement: https://leetcode.com/problems/course-schedule-iv/
*/

class Solution {
public:
	vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		vector<bool> res;
		vector<vector<bool>> d(n, vector<bool>(n));

		// initialize
		for(auto& e: prerequisites)
			d[e[0]][e[1]] = true;
		
		// Warshall's algorithm
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					d[i][j] = d[i][j] | (d[i][k] & d[k][j]);
		
		// process queries
		for (auto& e: queries)
			res.push_back(d[e[0]][e[1]]);
		
		return res;
	}
};