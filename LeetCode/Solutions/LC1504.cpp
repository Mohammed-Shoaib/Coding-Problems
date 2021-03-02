/*
Problem Statement: https://leetcode.com/problems/count-submatrices-with-all-ones/
Time: O(m • n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int numSubmat(vector<vector<int>>& mat) {
		int rects, m, n;
		rects = 0;
		m = mat.size();
		n = mat[0].size();
		vector<int> h(n);
		
		// histogram model
		for (int i = 0; i < m; i++) {
			stack<int> st;
			vector<int> dp(n);
			
			// update heights of rows
			for (int j = 0; j < n; j++)
				h[j] = mat[i][j] * (h[j] + 1);
			
			// dynamic programming
			for (int j = 0; j < n; j++) {
				// monotonic stack with non-decreasing heights
				while (!st.empty() && h[st.top()] >= h[j])
					st.pop();
				
				if (st.empty())
					dp[j] = h[j] * (j + 1);
				else
					dp[j] = dp[st.top()] + h[j] * (j - st.top());
				
				rects += dp[j];
				st.push(j);
			}
		}
		
		return rects;
	}
};