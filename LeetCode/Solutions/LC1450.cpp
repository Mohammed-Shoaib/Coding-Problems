/*
Problem Statement: https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int busy = 0, n = startTime.size();
		for (int i = 0; i < n; i++)
			busy += (startTime[i] <= queryTime && queryTime <= endTime[i]);
		return busy;
	}
};