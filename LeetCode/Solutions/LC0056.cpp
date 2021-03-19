/*
Problem Statement: https://leetcode.com/problems/merge-intervals/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>> intervals) {
		int n = intervals.size();
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> res = { intervals[0] };
		
		for (int i = 1; i < n; i++) {
			vector<int>& prev = res.back();
			if (prev[1] < intervals[i][0])
				res.push_back(intervals[i]);
			else
				prev[1] = max(intervals[i][1], prev[1]);
		}
		
		return res;
	}
};