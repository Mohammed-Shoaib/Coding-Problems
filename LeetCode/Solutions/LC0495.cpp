/*
Problem Statement: https://leetcode.com/problems/teemo-attacking/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int total, beg;
		total = beg = 0;
		
		for (int& t: timeSeries) {
			total += min(duration, t + duration - beg);
			beg = t + duration;
		}
		
		return total;
	}
};