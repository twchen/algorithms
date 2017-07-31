/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // iterative solution
    ListNode* reverseList(ListNode* head) {
        ListNode *rlist = NULL;
        ListNode *curr = head;
        ListNode *temp;
        while(curr){
            temp = new ListNode(curr->val);
            temp->next = rlist;
            rlist = temp;
            curr = curr->next;
        }
        return rlist;
    }
    /*
    // recursive solution
    ListNode *reverseList(ListNode *head){
        ListNode **dummy;
        return reverseList(head, dummy);
    }
    ListNode *reverseList(ListNode *head, ListNode **&last){
        if(head == NULL)
            return NULL;
        if(head->next == NULL){
            ListNode *rHead = new ListNode(head->val);
            last = &(rHead->next);
            return rHead;
        }
        ListNode **temp;
        ListNode *rHead = reverseList(head->next, temp);
        *temp = new ListNode(head->val);
        last = &((*temp)->next);
        return rHead;
    }
    */
};
