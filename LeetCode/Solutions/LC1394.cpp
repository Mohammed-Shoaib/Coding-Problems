/*
Problem Statement: https://leetcode.com/problems/find-lucky-integer-in-an-array/
*/

class Solution {
public:
	int findLucky(vector<int>& arr) {
		int lucky = -1;
		unordered_map<int, int> freq;
		for (int& num: arr)
			freq[num]++;
		for (auto& [k, v]: freq)
			if (k == v)
				lucky = max(k, lucky);
		return lucky;
	}
};