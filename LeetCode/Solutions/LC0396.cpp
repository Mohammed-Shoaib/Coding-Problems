/*
Problem Statement: https://leetcode.com/problems/rotate-function/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		int64_t n, max_sum, sum, total;
		n = A.size();
		sum = total = 0;
		
		// initialization
		for (int i = 0; i < n; i++) {
			total += A[i];
			sum += i * A[i];
		}
		max_sum = sum;
		
		// sliding window
		for (int i = 1; i < n; i++) {
			sum += n * A[i - 1] - total;
			max_sum = max(sum, max_sum);
		}
		
		return max_sum;
	}
};