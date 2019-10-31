/*
Problem Code: https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem
*/

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* head, int data) {
	SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
	if (!head)
		head = node;
	else {
		node->next = head;
		head = node;
	}
	return head;
}