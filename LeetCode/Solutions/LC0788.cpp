/*
Problem Statement: https://leetcode.com/problems/rotated-digits/
Time: O(n • log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int rotatedDigits(int N) {
		int cnt = 0;
		for (int i = 1; i <= N; i++)
			cnt += is_good(i);
		return cnt;
	}
	
	bool is_good(int num) {
		bool found = false;
		unordered_set<int> good = {2, 5, 6, 9};
		unordered_set<int> invalid = {3, 4, 7};
		
		while (num) {
			if (invalid.count(num % 10))
				return false;
			found |= good.count(num % 10);
			num /= 10;
		}
		
		return found;
	}
};