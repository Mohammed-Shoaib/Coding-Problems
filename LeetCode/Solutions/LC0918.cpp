/*
Problem Statement: https://leetcode.com/problems/maximum-sum-circular-subarray/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxSubarraySumCircular(vector<int>& A) {
		int max_sum, min_sum, sum, n;
		n = A.size();
		max_sum = maximum_subarray(A);
		min_sum = minimum_subarray(A);
		sum = accumulate(A.begin(), A.end(), 0);
		
		if (sum == min_sum)
			return max_sum;
		else
			return max(sum - min_sum, max_sum);
	}
	
	int maximum_subarray(vector<int>& A) {
		int max_sum, sum;
		max_sum = sum = A[0];
		for (int i = 1; i < A.size(); i++) {
			sum = max(A[i], sum + A[i]);
			max_sum = max(sum, max_sum);
		}
		return max_sum;
	}
	
	int minimum_subarray(vector<int>& A) {
		int min_sum, sum;
		min_sum = sum = A[0];
		for (int i = 1; i < A.size(); i++) {
			sum = min(A[i], sum + A[i]);
			min_sum = min(sum, min_sum);
		}
		return min_sum;
	}
};