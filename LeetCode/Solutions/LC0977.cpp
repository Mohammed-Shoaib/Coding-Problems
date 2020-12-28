/*
Problem Statement: https://leetcode.com/problems/squares-of-a-sorted-array/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		int pos, n = A.size();
		int low = 0, high = n - 1;
		vector<int> squares;
		
		while (low <= high) {
			if (abs(A[low]) > A[high])
				pos = low++;
			else
				pos = high--;
			squares.push_back(A[pos] * A[pos]);
		}
		reverse(squares.begin(), squares.end());
		
		return squares;
	}
};