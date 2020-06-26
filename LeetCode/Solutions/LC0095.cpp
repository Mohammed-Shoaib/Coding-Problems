/*
Problem Statement: https://leetcode.com/problems/unique-binary-search-trees-ii/
*/

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return {};
		return generateTrees(1, n);
	}

	vector<TreeNode*> generateTrees(int beg, int end) {
		if (beg > end)
			return {nullptr};
		vector<TreeNode*> trees;
		
		for(int i = beg; i <= end; i++) {
			vector<TreeNode*> left, right;
			left = generateTrees(beg, i - 1);
			right = generateTrees(i + 1, end);
			
			for (auto& l: left)
				for (auto& r: right) {
					TreeNode* root = new TreeNode(i, l, r);
					trees.push_back(root);
				}
		}
		
		return trees;
	}
};