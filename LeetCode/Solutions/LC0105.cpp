/*
Problem Statement: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int pos = 0, n = inorder.size();
		unordered_map<int, int> mp;

		// helper function
		function<TreeNode*(int, int)> build = [&](int beg, int end) -> TreeNode* {
			if (beg >= end)
				return nullptr;
			
			int mid = mp[preorder[pos]];
			TreeNode* node = new TreeNode(preorder[pos]);
			pos++;
			
			node->left  = build(beg, mid);
			node->right = build(mid + 1, end);
			
			return node;
		};

		// store position of elements in map
		for (int i = 0; i < n; i++)
			mp[inorder[i]] = i;
		
		return build(0, n);
	}
};