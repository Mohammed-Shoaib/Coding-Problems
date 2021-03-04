/*
Problem Statement: https://leetcode.com/problems/kth-missing-positive-number/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		int mid, low = 0, high = arr.size();

		while (low < high) {
			mid = low + (high - low) / 2;
			if (arr[mid] - mid - 1 >= k)
				high = mid;
			else
				low = mid + 1;
		}

		return low + k;
	}
};