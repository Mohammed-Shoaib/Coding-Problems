/*
Problem Statement: https://leetcode.com/problems/sort-the-matrix-diagonally/
*/

class Solution {
public:
	vector< vector<int> > diagonalSort(vector< vector<int> > mat) {
		int m, n;
		m = mat.size();
		n = mat[0].size();

		// Helper Function
		auto sort_diagonal = [&](int i, int j) {
			vector<int> d;
			for (int k = i, l = j; k < m && l < n; k++, l++)
				d.push_back(mat[k][l]);
			sort(d.begin(), d.end());
			for (int p = 0; p < d.size(); p++)
				mat[i++][j++] = d[p];
		};

		for (int i = 0; i < n; i++)
			sort_diagonal(0, i);
		for (int i = 1; i < m; i++)
			sort_diagonal(i, 0);
		
		return mat;
	}
};