/*
Problem Statement: https://leetcode.com/problems/rank-transform-of-an-array/
*/

class Solution {
public:
	vector<int> arrayRankTransform(vector<int>& arr) {
		vector<int> copy(arr);
		unordered_map<int, int> rank;
		
		sort(copy.begin(), copy.end());
		for (int& a: copy)
			rank.emplace(a, rank.size() + 1);
		for (int& a: arr)
			a = rank[a];
		
		return arr;
	}
};