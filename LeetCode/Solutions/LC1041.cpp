/*
Problem Statement: https://leetcode.com/problems/robot-bounded-in-circle/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isRobotBounded(string instructions) {
		vector<int> pos = {0, 0}, dir = {0, 1};
		
		for (char& c: instructions) {
			if (c == 'G')
				pos = {pos[0] + dir[0], pos[1] + dir[1]};
			else if (c == 'L')
				dir = {-dir[1], dir[0]};
			else
				dir = {dir[1], -dir[0]};
		}
		
		return pos == vector<int>{0, 0} || dir != vector<int>{0, 1};
	}
};