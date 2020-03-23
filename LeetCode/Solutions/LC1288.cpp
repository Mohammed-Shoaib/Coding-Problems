/*
Problem Statement: https://leetcode.com/problems/remove-covered-intervals/
*/

class Solution {
public:
    int removeCoveredIntervals(vector< vector<int> >& intervals) {
		int count, min_y;
		count = min_y = 0;
		sort(intervals.begin(), intervals.end());

		for (int i = 0; i < intervals.size(); i++)
			if (min_y < intervals[i][1]) {
				min_y = intervals[i][1];
				count++;
			}

		return count;
    }
};