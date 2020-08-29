/*
Problem Statement: https://leetcode.com/problems/find-right-interval/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		int n = intervals.size();
		map<int, int> mp;
		vector<int> res(n, -1);
		
		for (int i = 0; i < n; i++)
			mp[intervals[i][0]] = i;
		
		for (int i = 0; i < n; i++) {
			auto it = mp.lower_bound(intervals[i][1]);
			if (it != mp.end())
				res[i] = it->second;
		}
		
		return res;
	}
};