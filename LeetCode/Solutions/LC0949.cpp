/*
Problem Statement: https://leetcode.com/problems/largest-time-for-given-digits/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string largestTimeFromDigits(vector<int>& A) {
		string t;
		sort(A.begin(), A.end());
		
		do {
			if (10 * A[0] + A[1] <= 23 && A[2] <= 5)
				t = max(convert(A), t);
		} while (next_permutation(A.begin(), A.end()));
		
		return t;
	}
	
	string convert(vector<int>& A) {
		string s;
		for (int i = 0; i < A.size(); i++) {
			if (i == 2)
				s += ':';
			s += A[i] + '0';
		}
		return s;
	}
};