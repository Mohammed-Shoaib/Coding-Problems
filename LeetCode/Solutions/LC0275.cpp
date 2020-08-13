/*
Problem Statement: https://leetcode.com/problems/h-index-ii/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n, mid, low, high;
		low = 0;
		n = high = citations.size();
		
		while (low < high) {
			mid = low + (high - low) / 2;
			if (citations[mid] >= n - mid)
				high = mid;
			else
				low = mid + 1;
		}
		
		return n - low;
	}
};