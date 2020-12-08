/*
Problem Statement: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxDepth(Node* root) {
		int depth = 0;
		
		if (!root)
			return 0;
		
		for (Node* child: root->children)
			depth = max(maxDepth(child), depth);
		
		return 1 + depth;
	}
};