/*
Problem Statement: https://leetcode.com/problems/decompress-run-length-encoded-list/
*/

class Solution {
public:
	vector<int> decompressRLElist(vector<int>& nums) {
		vector<int> d;
		for (int i = 0; i < nums.size(); i += 2)
			d.insert(d.end(), nums[i], nums[i + 1]);
		return d;
	}
};