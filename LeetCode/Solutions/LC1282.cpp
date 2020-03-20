/*
Problem Statement: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
*/

class Solution {
public:
    vector< vector<int> > groupThePeople(vector<int>& groupSizes) {
		int pos, n = groupSizes.size();
		vector< vector<int> > groups;
		vector< vector<int> > group(n + 1);

		for (int i = 0; i < n; i++) {
			pos = groupSizes[i];
			group[pos].push_back(i);
			
			if (group[pos].size() == pos) {
				groups.push_back(group[pos]);
				group[pos].clear();
			}
		}
		
		return groups;
    }
};