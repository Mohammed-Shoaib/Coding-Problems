/*
Problem Statement: https://leetcode.com/problems/count-binary-substrings/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int countBinarySubstrings(string s) {
		char last = '2';
		int prev, subs, cnt;
		subs = prev = cnt = 0;
		
		for (char& c: s) {
			if (c == exchange(last, c))
				cnt++;
			else
				prev = exchange(cnt, 1);
			subs += prev >= cnt;
		}
		
		return subs;
	}
};