/*
Problem Statement: https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/
Time: O(n² + (n / k)ᵏ)
Space: O(n² + k)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	double getProbability(vector<int>& balls) {
		int k, n;
		double valid, total;
		k = balls.size();
		valid = total = 0;
		n = accumulate(balls.begin(), balls.end(), 0);
		double nCr[n + 1][n + 1];
		
		// initialize nCr
		for (int i = 0; i < n; i++)
			nCr[i][0] = 1;
		for (int i = 1; i < n; i++)
			nCr[0][i] = 0;
		for (int i = 1; i < n; i++)
			for (int j = 1; j < n; j++)
				nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
		
		// helper function
		function<void(int, int, double, int, int)> state = [&](int pos, int taken, double ways, int box_1, int box_2) {
			if (pos == k) {
				if (taken == n / 2) {
					valid += (box_1 == box_2) * ways;
					total += ways;
				}
				return;
			}
			for (int i = 0; i <= balls[pos]; i++)
				state(pos + 1,
					  taken + i,
					  ways * nCr[balls[pos]][i],
					  box_1 + (i > 0),
					  box_2 + (balls[pos] - i > 0));
		};
		state(0, 0, 1, 0, 0);
		
		return valid / total;
	}
};