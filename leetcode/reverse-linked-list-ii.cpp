/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev, *last, *curr, *rhead = nullptr, *temp;
        int i = 1;
        prev = &dummy;
        while(i < m){
            prev = prev->next;
            ++i;
        }
        last = curr = prev->next;
        while(i <= n){
            temp = curr;
            curr = curr->next;
            temp->next = rhead;
            rhead = temp;
            ++i;
        }
        prev->next = rhead;
        last->next = curr;
        return dummy.next;
    }
};

// reverse in place
// 1->2->3->4->5->NULL
// 1->3->2->4->5->NULL
// 1->4->3->2->5->NULL
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy, *curr, *temp;
        int i = 1;
        while(i < m){
            prev = prev->next;
            ++i;
        }
        curr = prev->next;
        while(i < n){
            temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
            ++i;
        }
        return dummy.next;
    }
};
