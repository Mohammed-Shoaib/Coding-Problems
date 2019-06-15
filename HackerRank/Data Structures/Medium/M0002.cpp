/*
Problem Code: https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem
*/

bool has_cycle(SinglyLinkedListNode* head) {
	if (!head)
		return false;
	SinglyLinkedListNode *a, *b;
	a = b = head;
	while (a && b && b->next) {
		a = a->next;
		b = b->next->next;
		if (a == b)
			return true;
	}
	return false;
}