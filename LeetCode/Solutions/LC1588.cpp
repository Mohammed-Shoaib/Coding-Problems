/*
Problem Statement: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int sumOddLengthSubarrays(vector<int>& arr) {
		int sum = 0, n = arr.size();
		
		for (int i = 0; i < n; i++) {
			int odd, subarrays;
			subarrays = (i + 1) * (n - i);
			odd = (subarrays + 1) / 2;
			sum += arr[i] * odd;
		}
		
		return sum;
	}
};