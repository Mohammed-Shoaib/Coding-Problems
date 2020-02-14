/*
Problem Statement: https://leetcode.com/problems/coin-change/
*/

class Solution {
private:
	int inf = numeric_limits<int>::max();
public:
    int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, inf);

		// Dynamic Programming
		dp[0] = 0;
		for (int c: coins)
			for (int i = c; i <= amount; i++)
				if (dp[i - c] != inf)
					dp[i] = min(1 + dp[i - c], dp[i]);
					
		return (dp[amount] == inf) ? -1 : dp[amount];
    }
};