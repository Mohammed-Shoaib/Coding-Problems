/*
Problem Statement: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int largestSumAfterKNegations(vector<int> A, int K) {
		int n = A.size();
		
		sort(A.begin(), A.end());
		for (int i = 0; i < n && K && A[i] < 0; i++, K--)
			A[i] *= -1;
		int mn = *min_element(A.begin(), A.end());
		
		return accumulate(A.begin(), A.end(), 0) - 2 * mn * (K & 1);
	}
};