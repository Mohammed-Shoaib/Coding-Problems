/*
Problem Statement: https://leetcode.com/problems/matchsticks-to-square/
Time: O(n • 2ⁿ)
Space: O(n + 2ⁿ)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool makesquare(vector<int>& matchsticks) {
		int used = 0, k = 4, n = matchsticks.size();
		int64_t length = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
		vector<vector<int>> dp(1 << n, vector<int>(k, -1));
		
		// base case
		if (length % k != 0)
			return false;
		length /= k;
		
		// helper function
		function<bool(int, int)> state = [&](int used, int sides) -> bool {
			if (sides == 4)
				return true;
			else if (dp[used][sides] != -1)
				return dp[used][sides];
			
			bool res = false;
			int perimeter = 0;
			
			for (int i = 0; i < n; i++)
				if ((used >> i) & 1)
					perimeter += matchsticks[i];
			
			for (int i = 0; i < n; i++) {
				if ((used >> i) & 1)
					continue;
				used ^= 1 << i;
				bool inc = (perimeter + matchsticks[i]) % length == 0;
				res |= state(used, sides + inc);
				used ^= 1 << i;
				if (res)
					break;
			}
			
			return dp[used][sides] = res;
		};
		
		return state(0, 0);
	}
};