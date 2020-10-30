/*
Problem Statement: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
*/

class Solution {
public:
	int numOfSubarrays(vector<int>& arr, int k, int threshold) {
		int cnt = 0;
		double sum = accumulate(arr.begin(), arr.begin() + k - 1, 0);
		for (int i = k - 1; i < arr.size(); i++) {
			sum += arr[i];
			cnt += (sum / k >= threshold);
			sum -= arr[i - k + 1];
		}
		return cnt;
	}
};