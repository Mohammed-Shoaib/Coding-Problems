/*
Problem Statement: https://www.hackerrank.com/challenges/30-linked-list-deletion/problem
*/

#include <iostream>

using namespace std;

Node* removeDuplicates(Node* head) {
	Node *node, *temp = head;
	while (temp) {
		node = temp->next;
		if (node && temp->data == node->data) {
			temp->next = node->next;
			delete node;
		}
		else
			temp = temp->next;
	}
	return head;
}