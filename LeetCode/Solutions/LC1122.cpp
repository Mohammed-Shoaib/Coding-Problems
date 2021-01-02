/*
Problem Statement: https://leetcode.com/problems/relative-sort-array/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		vector<int> res;
		map<int, int> freq;
		
		for (int& x: arr1)
			freq[x]++;
		
		for (int& x: arr2) {
			auto it = freq.find(x);
			if (it != freq.end()) {
				res.insert(res.end(), it->second, it->first);
				freq.erase(it);
			}
		}
		
		for (auto& [k, v]: freq)
			res.insert(res.end(), v, k);
		
		return res;
	}
};