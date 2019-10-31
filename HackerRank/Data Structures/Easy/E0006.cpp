/*
Problem Code: https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem
*/

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
	SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
	if (!head)
		head = node;
	else {
		SinglyLinkedListNode* temp = head;
		while(temp->next)
			temp = temp->next;
		temp->next = node;
	}
	return head;
}