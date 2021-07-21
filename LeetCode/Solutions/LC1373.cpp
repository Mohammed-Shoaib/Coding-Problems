/*
Problem Statement: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
*/

class Solution {
private:
	int max_sum = 0;

	struct Node {
		bool valid;
		int sum, min, max;

		Node(TreeNode* node) : sum(node->val), min(node->val), max(node->val), valid(true) {}
	};

public:
	Node get_sum(TreeNode* node) {
		Node curr(node);
		if (node->left) {
			Node left = get_sum(node->left);
			curr.min = left.min;
			curr.sum += left.sum;
			curr.valid &= (left.max < node->val && left.valid);
		}
		if (node->right) {
			Node right = get_sum(node->right);
			curr.max = right.max;
			curr.sum += right.sum;
			curr.valid &= (right.min > node->val && right.valid);
		}
		if (curr.valid)
			max_sum = max(curr.sum, max_sum);
		return curr;
	}

	int maxSumBST(TreeNode* root) {
		get_sum(root);
		return max_sum;
	}
};