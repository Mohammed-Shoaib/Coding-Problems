/*
Problem Statement: https://leetcode.com/problems/intersection-of-two-arrays-ii/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums;
		unordered_map<int, int> freq;
		
		for (int& x: nums1)
			freq[x]++;
		
		for (int& x: nums2) {
			auto it = freq.find(x);
			if (it != freq.end() && it->second) {
				it->second--;
				nums.push_back(x);
			}
		}
		
		return nums;
	}
};