/*
Problem Statement: https://leetcode.com/problems/fizz-buzz/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> res(n);
		for (int i = 1; i <= n; i++) {
			string s;
			if (i % 3 == 0)
				s = "Fizz";
			if (i % 5 == 0)
				s += "Buzz";
			if (s.empty())
				s = to_string(i);
			res[i - 1] = s;
		}
		return res;
	}
};