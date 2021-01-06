/*
Problem Statement: https://leetcode.com/problems/roman-to-integer/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> mp = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}
		};
		int sum = 0, prev = mp['M'];
		
		for (char& c: s) {
			if (prev < mp[c])
				sum += mp[c] - 2 * prev;
			else
				sum += mp[c];
			prev = mp[c];
		}
		
		return sum;
	}
};