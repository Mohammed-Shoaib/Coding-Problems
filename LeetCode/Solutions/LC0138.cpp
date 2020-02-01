/*
Problem Statement: https://leetcode.com/problems/copy-list-with-random-pointer/
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
		unordered_map<Node*, Node*> m;
        Node *temp1, *prev, *temp2, *head2;
		head2 = prev = nullptr;

		// Clone nodes of linked list
		temp1 = head;
		while (temp1) {
			temp2 = new Node(temp1->val);
			if (prev)
				prev->next = temp2;
			else
				head2 = temp2;
			m[temp1] = temp2;
			prev = temp2;
			temp1 = temp1->next;
		}

		// Assign random pointers
		temp1 = head;
		temp2 = head2;
		while (temp1) {
			if (temp1->random)
				temp2->random = m[temp1->random];
			else
				temp2->random = nullptr;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}

		return head2;
    }
};