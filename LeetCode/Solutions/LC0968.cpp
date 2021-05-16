/*
Problem Statement: https://leetcode.com/problems/binary-tree-cameras/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minCameraCover(TreeNode* root) {
		int cameras = 0;
		
		/*
		0: not monitored
		1: monitored because it has a camera
		2: monitored through child, does not have a camera
		*/
		function<int(TreeNode*)> dfs = [&](TreeNode* node) {
			if (!node)
				return 2;
			int left = dfs(node->left), right = dfs(node->right);
			
			if (left == 0 || right == 0) {
				cameras++;
				return 1;
			}
			else if (left == 1 || right == 1)
				return 2;
			else
				return 0;
		};
		
		if (dfs(root) == 0)
			cameras++;
		
		return cameras;
	}
};