/*
Problem Statement: https://leetcode.com/problems/count-good-triplets/
Time: O(n³)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
		int good = 0, n = arr.size();
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				if (abs(arr[i] - arr[j]) > a)
					continue;
				for (int k = j + 1; k < n; k++)
					good += (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c);
			}
		return good;
	}
};