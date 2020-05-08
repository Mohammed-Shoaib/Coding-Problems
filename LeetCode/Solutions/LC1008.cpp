 /*
Problem Statement: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
*/

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
		int pos = 0;
		return construct(pos, numeric_limits<int>::max(), preorder);
    }

	TreeNode* construct(int& pos, int mx, vector<int>& preorder) {
		if (pos == preorder.size() || preorder[pos] > mx)
			return nullptr;
		TreeNode* node = new TreeNode(preorder[pos++]);
		node->left = construct(pos, node->val, preorder);
		node->right = construct(pos, mx, preorder);
		return node;
	}
};