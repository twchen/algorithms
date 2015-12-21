/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2)
            return l1 ? l1 : l2;
        ListNode *s, *l, *pos;
        if(l1->val < l2->val){
            s = l1; l = l2; pos = l2;
        }
        else{
            s = l2; l = l1; pos = l1;
        }
        ListNode *prev = s, *curr = s->next;
        while(pos){
            while(curr && curr->val <= pos->val){
                prev = curr;
                curr = curr->next;
            }
            ListNode *temp = pos;
            pos = pos->next;
            prev->next = temp;
            temp->next = curr;
            prev = prev->next;
        }
        return s;
    }
};
