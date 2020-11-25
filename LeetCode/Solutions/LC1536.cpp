/*
Problem Statement: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
Time: O(n • n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minSwaps(vector<vector<int>>& grid) {
		int swaps = 0, n = grid.size();
		vector<int> zeros(n);

		// preprocess
		for (int i = 0; i < n; i++)
			for (int j = n - 1; j >= 0 && !grid[i][j]; j--)
				zeros[i]++;

		// insertion sort-ish
		for (int j, i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (zeros[j] == -1)
					continue;
				else if (zeros[j] >= n - i - 1) {
					zeros[j] = -1;
					break;
				}
				swaps++;
			}
			if (j == n)
				return -1;
		}

		return swaps;
	}
};