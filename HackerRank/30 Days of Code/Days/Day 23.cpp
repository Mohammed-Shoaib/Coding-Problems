/*
Problem Statement: https://www.hackerrank.com/challenges/30-binary-trees/problem
*/

#include <iostream>
#include <queue>

using namespace std;

void levelOrder(Node* node) {
	queue<Node*> q;
	q.push(node);

	while (!q.empty()) {
		node = q.front();
		cout << node->data << " ";
		q.pop();
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
	}
}