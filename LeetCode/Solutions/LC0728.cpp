/*
Problem Statement: https://leetcode.com/problems/self-dividing-numbers/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> res;
		for (int i = left; i <= right; i++)
			if (self_divide(i))
				res.push_back(i);
		return res;
	}
	
	bool self_divide(int num) {
		int copy = num;
		
		if (num == 0)
			return false;
		
		while (num) {
			int rem = num % 10;
			if (rem == 0 || copy % rem != 0)
				return false;
			num /= 10;
		}
		
		return true;
	}
};