/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head, *prev = NULL;
        while(n--){
            fast = fast->next;
        }
        while(fast){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if(prev == NULL){
            head = head->next;
            delete slow;
        }else{
            prev->next = slow->next;
            delete slow;
        }
        return head;
    }
};

// use a dummy head to avoid using prev
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;
        while(n--)
            fast = fast->next;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return dummy.next;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *slow = &dummy; // use head as fast
        while(--n) // note that n-- is changed to --n because fast pointer(head) has already move one step. and the loop will terminate because n is always valid, thus n >= 1
            head = head->next;
        while(head->next){
            head = head->next;
            slow = slow->next;
        }
        head = slow->next; // use head to store the node to be deleted
        slow->next = head->next;
        delete head;
        return dummy.next;
    }
};