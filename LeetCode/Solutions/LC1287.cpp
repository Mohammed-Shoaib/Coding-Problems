/*
Problem Statement: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
*/

class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		int n = arr.size();
		vector<int> pos = { n / 4, n / 2, 3 * n / 4};
		for (int& p: pos)
			if (binary_search(arr[p], arr) > n / 4.0)
				return arr[p];
		return -1;
	}

	int binary_search(int ele, vector<int>& arr) {
		int low, high;
		low = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), ele));
		high = distance(arr.begin(), upper_bound(arr.begin(), arr.end(), ele));
		return high - low;
	}
};