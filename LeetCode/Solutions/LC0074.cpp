/*
Problem Statement: https://leetcode.com/problems/search-a-2d-matrix/
*/

class Solution {
public:
	bool searchMatrix(vector< vector<int> >& matrix, int target) {
		if (matrix.empty())
			return false;
		
		int n, m, low, high, mid, ele;
		m = matrix.size();
		n = matrix[0].size();
		low = 0;
		high = m * n - 1;
		
		while (low <= high) {
			mid = (low + high) / 2;
			ele = matrix[mid / n][mid % n];
			
			if (ele == target)
				return true;
			else if (ele < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
		
		return false;
	}
};