/*
Problem Statement: https://leetcode.com/problems/summary-ranges/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		vector<pair<int, int>> ranges;
		
		for (int& x: nums) {
			if (ranges.empty() || ranges.back().second + 1 != x)
				ranges.push_back({x, x});
			else
				ranges.back().second++;
		}
		
		for (auto& p: ranges) {
			res.push_back(to_string(p.first));
			if (p.first != p.second)
				res.back() += "->" + to_string(p.second);
		}
		
		return res;
	}
};