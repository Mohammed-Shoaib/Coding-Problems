/*
Problem Statement: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
*/

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
		int m, n, side;
		m = mat.size();
		n = mat[0].size();
		side = 0;
		int prefix[m + 1][n + 1] = {};

		// 2D cumulative prefix sum
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				int r, c, sum;
				tie(r, c) = make_tuple(i - side - 1, j - side - 1);
				prefix[i][j] = mat[i - 1][j - 1] + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
				
				if (min(r, c) >= 0) {
					sum = prefix[i][j] - prefix[i][c] - prefix[r][j] + prefix[r][c];
					side += sum <= threshold;
				}
			}
		
		return side;
    }
};