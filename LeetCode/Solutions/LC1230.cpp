/*
Problem Statement: https://leetcode.com/problems/toss-strange-coins/
*/

class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        double dp[prob.size() + 1][target + 1] = {};
        dp[0][0] = 1.0;

        for (int i = 1; i <= prob.size(); i++)
            for (int j = 0; j <= target; j++) {
                if (j == 0)
                    dp[i][j] = dp[i - 1][j] * (1 - prob[i - 1]);
                else
                    dp[i][j] = dp[i - 1][j] * (1 - prob[i - 1]) + dp[i - 1][j - 1] * prob[i - 1];
            }

        return dp[prob.size()][target];
    }
};