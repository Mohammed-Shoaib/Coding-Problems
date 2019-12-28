/*
Problem Statement: https://www.hackerrank.com/challenges/30-linked-list/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	Node* insert(Node* head, int data) {
		Node* node = new Node(data);

		if (!head)
			head = node;
		else {
			Node* temp = head;
			while (temp->next)
				temp = temp->next;
			temp->next = node;
		}

		return head;
	}

	void display(Node* head) {
		Node* start = head;
		while (start) {
			cout << start->data << " ";
			start = start->next;
		}
	}
};