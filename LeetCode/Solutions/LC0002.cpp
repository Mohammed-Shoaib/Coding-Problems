/*
Problem Statement: https://leetcode.com/problems/add-two-numbers/
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	int sum, carry = 0;
        ListNode *head, *l = new ListNode(0);
        head = l;

        // Add lists l1 and l2 while maintaining carry
    	while (l1 && l2) {
    		sum = l1->val + l2->val + carry;
    		l->next = new ListNode(sum % 10);
    		l = l->next;
    		l1 = l1->next;
    		l2 = l2->next;
    		carry = sum / 10;
    	}

    	// Add remaining of l1
    	while (l1) {
    		sum = l1->val + carry;
    		l->next = new ListNode(sum % 10);
    		l = l->next;
    		l1 = l1->next;
    		carry = sum / 10;
    	}

    	// Add remaining of l2
    	while (l2) {
    		sum = l2->val + carry;
    		l->next = new ListNode(sum % 10);
    		l = l->next;
    		l2 = l2->next;
    		carry = sum / 10;
    	}

    	// Check if carry still exists
    	if (carry)
    		l->next = new ListNode(carry);

    	return head->next;
    }
};