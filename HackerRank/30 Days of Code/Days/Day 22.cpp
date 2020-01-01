/*
Problem Statement: https://www.hackerrank.com/challenges/30-binary-search-trees/problem
*/

#include <iostream>
#include <algorithm>

using namespace std;

int getHeight(Node* node) {
	if (!node)
		return -1;
	else
		return 1 + max(getHeight(node->left), getHeight(node->right));
}