/*
Problem Statement: https://leetcode.com/problems/car-pooling/
Time: O(n)
Space: O(m)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		int m = max_element(trips.begin(), trips.end(), [](vector<int>& l, vector<int>& r) {
			return l[2] < r[2];
		})->at(2);
		vector<int> cum_sum(m + 1);
		
		for (vector<int>& trip: trips) {
			cum_sum[trip[1]] += trip[0];
			cum_sum[trip[2]] -= trip[0];
		}
		
		for (int& x: cum_sum) {
			capacity -= x;
			if (capacity < 0)
				return false;
		}
		
		return true;
	}
};