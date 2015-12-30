/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

// use a dummy head so that we can use only one pointer to traverse the list and don't need to consider the delete-at-head case
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        while(head->next){
            if(head->next->val == val){
                ListNode *temp = head->next;
                head->next = temp->next;
                delete temp;
            }else{
                head = head->next;
            }
        }
        return dummy.next;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = NULL, *curr = head;
        while(curr){
            if(curr->val == val){
                if(prev == NULL){ // curr == head;
                    ListNode *temp = head;
                    head = head->next;
                    delete temp;
                    curr = head;
                }
                else{
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
