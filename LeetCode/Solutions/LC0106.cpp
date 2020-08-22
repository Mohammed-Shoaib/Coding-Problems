/*
Problem Statement: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int pos, n;
		unordered_map<int, int> mp;
		pos = n = inorder.size();
		
		// helper function
		function<TreeNode*(int, int)> build = [&](int beg, int end) -> TreeNode* {
			if (beg >= end)
				return nullptr;
			
			--pos;
			int mid = mp[postorder[pos]];
			TreeNode* node = new TreeNode(postorder[pos]);
			
			node->right = build(mid + 1, end);
			node->left  = build(beg, mid);
			
			return node;
		};
		
		// store position of elements in map
		for (int i = 0; i < n; i++)
			mp[inorder[i]] = i;
		
		return build(0, n);
	}
};