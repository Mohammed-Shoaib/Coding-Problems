/*
Problem Statement: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|--------------------|------|-------|
| Operations         | Time | Space |
|--------------------|------|-------|
| FindElements(root) | O(n) | O(n)  |
| fix(val, node)     | O(n) | O(n)  |
| find(target)       | O(1) | O(1)  |
|--------------------|------|-------|
*/

class FindElements {
private:
	unordered_set<int> seen;
public:
	FindElements(TreeNode* root) {
		fix(0, root);
	}
	
	void fix(int val, TreeNode* node) {
		if (!node)
			return;
		seen.insert(val);
		fix(2 * val + 1, node->left);
		fix(2 * val + 2, node->right);
	}
	
	bool find(int target) {
		return seen.find(target) != seen.end();
	}
};