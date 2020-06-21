/*
Problem Statement: https://leetcode.com/problems/h-index-ii/
*/

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n, mid, low, high;
		low = 0;
		n = high = citations.size();

		while (low < high) {
			mid = (low + high) / 2;
			if (citations[mid] >= n - mid)
				high = mid;
			else
				low = mid + 1;
		}
		
		return n - low;
	}
};