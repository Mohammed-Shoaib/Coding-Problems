/*
Problem Statement: https://leetcode.com/problems/top-k-frequent-elements/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> res;
		unordered_map<int, int> freq;
		vector<vector<int>> buckets(n + 1);
		
		for (int& num: nums)
			freq[num]++;
		
		for (auto& [key, val]: freq)
			buckets[val].push_back(key);
		
		for (int i = n; i > 0 && k; i--)
			for (int& num: buckets[i]) {
				res.push_back(num);
				k--;
			}
		
		return res;
	}
};