/*
Problem Statement: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
*/

class Codec {
public:
	string serialize(TreeNode* root) {
		if (!root)
			return "#";
		else
			return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
	}

	TreeNode* deserialize(string data) {
		string token;
		queue<string> nodes;
		istringstream ss(data);
		while (getline(ss, token, ','))
			nodes.push(token);
		return deserialize(nodes);
	}

	TreeNode* deserialize(queue<string>& nodes) {
		string s = nodes.front();
		nodes.pop();
		if (s == "#")
			return nullptr;
		TreeNode* node = new TreeNode(stoi(s));
		node->left = deserialize(nodes);
		node->right = deserialize(nodes);
		return node;
	}
};