/*
Problem Statement: https://leetcode.com/problems/get-the-maximum-score/
Time: O(m + n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxSum(vector<int>& nums1, vector<int>& nums2) {
		int mod, m, n, i, j;
		long long max_1, max_2;
		mod = 1e9 + 7;
		m = nums1.size();
		n = nums2.size();
		max_1 = max_2 = i = j = 0;
		
		while (i < m && j < n) {
			if (nums1[i] < nums2[j])
				max_1 += nums1[i++];
			else if (nums1[i] > nums2[j])
				max_2 += nums2[j++];
			else
				max_1 = max_2 = max(max_1 + nums1[i++], max_2 + nums2[j++]);
		}
		while (i < m)
			max_1 += nums1[i++];
		while (j < n)
			max_2 += nums2[j++];
		
		return max(max_1, max_2) % mod;
	}
};