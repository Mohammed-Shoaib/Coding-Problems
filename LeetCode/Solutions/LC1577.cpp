/*
Problem Statement: https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/
Time: O(m • n)
Space: O(m + n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int numTriplets(vector<int>& nums1, vector<int>& nums2) {
		return count_triplets(nums1, nums2) + count_triplets(nums2, nums1);
	}
	
	int count_triplets(vector<int>& nums1, vector<int>& nums2) {
		int triplets, m, n;
		triplets = 0;
		m = nums1.size();
		n = nums2.size();
		
		for (int64_t x: nums1) {
			unordered_map<int64_t, int> freq;
			x *= x;
			for (int y: nums2) {
				if (x % y == 0)
					triplets += freq[x / y];
				freq[y]++;
			}
		}
		
		return triplets;
	}
};