/*
Problem Statement: https://leetcode.com/problems/k-concatenation-maximum-sum/
*/

class Solution {
public:
    int kConcatenationMaxSum(vector<int> &arr, int k) {
        int sum, left, mid, right, max_sum;
        sum = left = mid = right = max_sum = 0;
	    
	    // Left Sum
	    kadane_algorithm(sum, max_sum, arr);
        left = sum;
	    if (k == 1)
	    	return max_sum;

	    // Mid Sum
	    kadane_algorithm(sum, max_sum, arr);
	    mid = sum - left;

	    // Right Sum
	    kadane_algorithm(sum, max_sum, arr);
	    right = max_sum - (left + mid);

	    // Total Sum
	    max_sum = (left + (long long) mid * (k - 2) + right) % (int) (1e9 + 7);

	    return max_sum;
    }

    void kadane_algorithm(int &sum, int &max_sum, vector<int> &arr) {
    	for (int i = 0 ; i < arr.size() ; i++) {
	        sum = max(arr[i], arr[i] + sum);
	        max_sum = max(sum, max_sum);
	    }
    }
};