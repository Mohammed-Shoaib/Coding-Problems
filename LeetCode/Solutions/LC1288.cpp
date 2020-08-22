/*
Problem Statement: https://leetcode.com/problems/remove-covered-intervals/
Time: O(n • log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int removeCoveredIntervals(vector<vector<int>>& intervals) {
		int cnt, min_y, n;
		cnt = min_y = 0;
		n = intervals.size();
		sort(intervals.begin(), intervals.end());
		
		for (int i = 0; i < n; i++)
			if (min_y < intervals[i][1]) {
				min_y = intervals[i][1];
				cnt++;
			}
		
		return cnt;
	}
};