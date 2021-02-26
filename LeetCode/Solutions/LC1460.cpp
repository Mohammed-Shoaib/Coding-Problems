/*
Problem Statement: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
*/

class Solution {
public:
	bool canBeEqual(vector<int>& target, vector<int>& arr) {
		unordered_map<int, int> freq;
		for (int& x: target)
			freq[x]++;
		for (int& x: arr)
			freq[x]--;
		for (auto& [k, v]: freq)
			if (v)
				return false;
		return true;
	}
};