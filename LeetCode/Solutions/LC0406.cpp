/*
Problem Statement: https://leetcode.com/problems/queue-reconstruction-by-height/
*/

class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		vector<vector<int>> q;
		
		sort(people.begin(), people.end(), [](auto& l, auto& r) {
			if (l[0] == r[0])
				return l[1] < r[1];
			else
				return l[0] > r[0];
		});
		
		for (auto& p: people)
			q.insert(q.begin() + p[1], p);
		
		return q;
	}
};