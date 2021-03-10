/*
Problem Statement: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxDepth(string s) {
		int max_depth, depth;
		max_depth = depth = 0;
		for (char& c: s) {
			if (c == '(')
				depth++;
			else if (c == ')')
				depth--;
			max_depth = max(depth, max_depth);
		}
		return max_depth;
	}
};