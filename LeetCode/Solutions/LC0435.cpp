/*
Problem Statement: https://leetcode.com/problems/non-overlapping-intervals/
Time: O(n • log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int cnt = 0, end = numeric_limits<int>::min();
		
		sort(intervals.begin(), intervals.end(), [](auto& l, auto& r) {
			return l[1] < r[1];
		});
		
		for (auto& interval: intervals) {
			if (end > interval[0])
				cnt++;
			else
				end = interval[1];
		}
		
		return cnt;
	}
};