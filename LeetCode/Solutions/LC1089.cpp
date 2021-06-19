/*
Problem Statement: https://leetcode.com/problems/duplicate-zeros/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		int pos, zeros, n = arr.size();
		pos = zeros = 0;
		
		for (int& x: arr) {
			zeros += x == 0;
			pos++;
			if (pos + zeros >= n) {
				if (pos + zeros > n) {
					arr.back() = 0;
					pos--, zeros--;
				}
				break;
			}
		}
		
		for (int i = pos - 1; i >= 0; i--) {
			if (arr[i] == 0) {
				arr[i + zeros] = 0;
				zeros--;
			}
			arr[i + zeros] = arr[i];
		}
	}
};