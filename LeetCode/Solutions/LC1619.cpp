/*
Problem Statement: https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	double trimMean(vector<int>& arr) {
		int sum, len, n = arr.size();
		len = 0.05 * n;
		sum = accumulate(arr.begin(), arr.end(), 0);
		
		nth_element(arr.begin(), arr.begin() + len, arr.end());
		for (int i = 0; i < len; i++)
			sum -= arr[i];
		
		nth_element(arr.begin(), arr.end() - len, arr.end());
		for (int i = 0; i < len; i++)
			sum -= arr[n - i - 1];
		
		return sum / (0.9 * n);
	}
};