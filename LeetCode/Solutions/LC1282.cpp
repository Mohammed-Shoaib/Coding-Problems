/*
Problem Statement: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		int n = groupSizes.size();
		vector<vector<int>> groups, group(n + 1);
		
		for (int i = 0; i < n; i++) {
			int pos = groupSizes[i];
			group[pos].push_back(i);
			
			if (group[pos].size() == pos) {
				groups.push_back(group[pos]);
				group[pos].clear();
			}
		}
		
		return groups;
	}
};