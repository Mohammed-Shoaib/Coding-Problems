/*
Problem Statement: https://leetcode.com/problems/find-k-closest-elements/
Time: O(log n + k)
Space: O(k)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int mid, beg = 0, end = arr.size() - k;
		vector<int> closest;
		
		while (beg < end) {
			int mid = beg + (end - beg) / 2;
			if (x - arr[mid] <= arr[mid + k] - x)
				end = mid;
			else
				beg = mid + 1;
		}
		
		for (int i = beg; i < beg + k; i++)
			closest.push_back(arr[i]);
		
		return closest;
	}
};