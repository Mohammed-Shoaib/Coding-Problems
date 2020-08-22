/*
Problem Statement: https://leetcode.com/problems/meeting-scheduler/
Time: O(m • log m + n • log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
		int m, n, i, j;
		m = slots1.size();
		n = slots2.size();
		i = j = 0;
		
		sort(slots1.begin(), slots1.end());
		sort(slots2.begin(), slots2.end());
		
		while (i < m && j < n) {
			int beg, end;
			beg = max(slots1[i][0], slots2[j][0]);
			end = min(slots1[i][1], slots2[j][1]);
			
			if (beg + duration <= end)
				return {beg, beg + duration};
			else if (slots1[i][1] < slots2[j][1])
				i++;
			else
				j++;
		}
		
		return {};
	}
};