/*
Problem Statement: https://leetcode.com/problems/combination-sum-ii/
Time: O(2ⁿ)
Space: O(2ⁿ)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		int n = candidates.size();
		vector<int> comb;
		vector<vector<int>> combs;
		
		// for optimization
		sort(candidates.begin(), candidates.end());
		
		// helper function
		function<void(int, int)> dfs = [&](int pos, int sum) {
			if (sum >= target) {
				if (sum == target)
					combs.push_back(comb);
				return;
			}
			for (int i = pos; i < n; i++) {
				if (sum + candidates[i] > target)
					break;
				else if (i > pos && candidates[i - 1] == candidates[i])
					continue;
				comb.push_back(candidates[i]);
				dfs(i + 1, sum + candidates[i]);
				comb.pop_back();
			}
		};
		dfs(0, 0);
		
		return combs;
	}
};