/*
Problem Statement: https://leetcode.com/problems/goal-parser-interpretation/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string interpret(string command) {
		string s;
		int n = command.length();
		
		for (int i = 0; i < n; i++) {
			if (command[i] == 'G') {
				s += 'G';
				continue;
			}
			if (command[i + 1] == 'a') {
				s += "al";
				i += 2;
			}
			else
				s += 'o';
			i++;
		}
		
		return s;
	}
};