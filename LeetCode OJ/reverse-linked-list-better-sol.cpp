/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

class Solution {
public:
    /*
    // iterative solution
    ListNode* reverseList(ListNode* head) {
        ListNode *node = NULL;
        while (head) {
            ListNode *nxt = head->next;
            head->next = node;
            node = head;
            head = nxt;
        }
        return node;
    }
    */
    // recursive solution
    ListNode* reverseList(ListNode* head) {
        return reverse(head, NULL);
    }

    ListNode* reverse(ListNode* head, ListNode* node) {
        if (head==nullptr)
            return node;
        ListNode *nxt = head->next;
        head->next = node;
        return reverse(nxt, head);
    }
};
