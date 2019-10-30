/*
Problem Code: https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem
*/

void printLinkedList(SinglyLinkedListNode* head) {
	while (head) {
		cout << head->data << endl;
		head = head->next;
	}
}