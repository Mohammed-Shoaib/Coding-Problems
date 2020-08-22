/*
Problem Statement: https://leetcode.com/problems/k-concatenation-maximum-sum/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int kConcatenationMaxSum(vector<int>& arr, int k) {
		int sum, left, mid, right, max_sum;
		sum = left = mid = right = max_sum = 0;
		
		// left sum
		kadane_algorithm(sum, max_sum, arr);
		left = sum;
		if (k == 1)
			return max_sum;
		
		// mid sum
		kadane_algorithm(sum, max_sum, arr);
		mid = sum - left;
		
		// right sum
		kadane_algorithm(sum, max_sum, arr);
		right = max_sum - (left + mid);
		
		// total sum
		max_sum = (left + (long long) mid * (k - 2) + right) % (int) (1e9 + 7);
		
		return max_sum;
	}
	
	void kadane_algorithm(int& sum, int& max_sum, vector<int>& arr) {
		for (int i = 0 ; i < arr.size() ; i++) {
			sum = max(arr[i], arr[i] + sum);
			max_sum = max(sum, max_sum);
		}
	}
};