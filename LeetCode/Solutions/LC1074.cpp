/*
Problem Statement: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
Time: O(m² • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int cnt = 0, m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> prefix(m + 1, vector<int>(n + 1));
		
		// 2d prefix sum
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				prefix[i + 1][j + 1] = matrix[i][j] + prefix[i + 1][j] + prefix[i][j + 1] - prefix[i][j];
		
		for (int i = 0; i < m; i++)
			for (int j = i; j < m; j++) {
				// count subarrays with sum equal to target
				unordered_map<int, int> mp;
				mp[0] = 1;
				for (int k = 0; k < n; k++) {
					int sum = prefix[j + 1][k + 1] - prefix[i][k + 1];
					if (mp.count(sum - target))
						cnt += mp[sum - target];
					mp[sum]++;
				}
			}
		
		return cnt;
	}
};