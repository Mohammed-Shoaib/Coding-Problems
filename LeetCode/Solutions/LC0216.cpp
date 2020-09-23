/*
Problem Statement: https://leetcode.com/problems/combination-sum-iii/
Time: O(2⁹)
Space: O(2⁹)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> comb;
		vector<vector<int>> combs;
		
		// helper function
		function<void(int, int)> dfs = [&](int num, int sum) {
			if (comb.size() == k && sum == n) {
				combs.push_back(comb);
				return;
			}
			else if (comb.size() > k || sum > n)
				return;
			for (int i = num; i <= 9; i++) {
				comb.push_back(i);
				dfs(i + 1, sum + i);
				comb.pop_back();
			}
		};
		dfs(1, 0);
		
		return combs;
	}
};