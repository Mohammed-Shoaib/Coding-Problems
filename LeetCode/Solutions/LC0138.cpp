/*
Problem Statement: https://leetcode.com/problems/copy-list-with-random-pointer/
*/

class Solution {
public:
	Node* copyRandomList(Node* head) {
		Node *head2, *temp1, *temp2;

		// clone nodes of linked list
		temp1 = head;
		while (temp1) {
			temp2 = new Node(temp1->val);
			temp2->next = temp1->next;
			temp1->next = temp2;
			temp1 = temp2->next;
		}
		head2 = (head) ? head->next : nullptr;

		// assign random pointers
		temp1 = head;
		while (temp1) {
			temp2 = temp1->next;
			if (temp1->random)
				temp2->random = temp1->random->next;
			temp1 = temp2->next;
		}

		// undo rewirings
		temp1 = head;
		while (temp1) {
			temp2 = temp1->next;
			if (temp2)
				temp1->next = temp2->next;
			temp1 = temp2;
		}

		return head2;
	}
};