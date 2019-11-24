/*
Problem Code: https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem
*/

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int pos) {
	SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
	if (!pos) {
		node->next = head;
		head = node;
	} else {
		SinglyLinkedListNode* temp = head;
		while(--pos)
			temp = temp->next;
		node->next = temp->next;
		temp->next = node;
	}
	return head;
}