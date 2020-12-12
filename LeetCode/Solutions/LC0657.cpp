/*
Problem Statement: https://leetcode.com/problems/di-string-match/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool judgeCircle(string moves) {
		pair<int, int> pos;
		
		for (char& c: moves) {
			if (c == 'L')
				pos.first++;
			else if (c == 'R')
				pos.first--;
			else if (c == 'U')
				pos.second++;
			else
				pos.second--;
		}
		
		return pos == make_pair(0, 0);
	}
};