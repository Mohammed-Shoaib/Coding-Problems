/*
Problem Statement: https://leetcode.com/problems/remove-covered-intervals/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int removeCoveredIntervals(vector<vector<int>> intervals) {
		int cnt, min_y;
		cnt = min_y = 0;
		
		sort(intervals.begin(), intervals.end(), [](auto& l, auto& r) {
			if (l[0] == r[0])
				return l[1] > r[1];
			else
				return l[0] < r[0];
		});
		
		for (auto& v: intervals)
			if (min_y < v[1]) {
				min_y = v[1];
				cnt++;
			}
		
		return cnt;
	}
};