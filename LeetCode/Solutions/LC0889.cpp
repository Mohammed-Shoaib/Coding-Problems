/*
Problem Statement: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		int pos = 0, n = post.size();
		unordered_map<int, int> mp;

		// helper function
		function<TreeNode*(int)> build = [&](int prev) -> TreeNode* {
			// base cases
			if (pos == n || prev < mp[pre[pos]])
				return nullptr;
			
			prev = mp[pre[pos]];
			TreeNode* node = new TreeNode(pre[pos]);
			pos++;

			node->left = build(prev);
			node->right = build(prev);

			return node;
		};

		// store position of elements in map
		for (int i = 0; i < post.size(); i++)
			mp[post[i]] = i;
		
		return build(n);
	}
};