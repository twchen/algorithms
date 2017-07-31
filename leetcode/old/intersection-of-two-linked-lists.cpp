/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// simpler solution
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        ListNode *currA = headA, *currB = headB;
        while(currA != currB){
            currA = currA ? currA->next : headB; // when currA reaches the end of list A, currA = headB, effectively concats B after A
            currB = currB ? currB->next : headA; // concats A after B, so two lists have the same length
        }
        return currA;
    }
};

// my solution
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = length(headA);
        int l2 = length(headB);
        int diff = l1 - l2;
        if(diff > 0){
            while(diff--)
                headA = headA->next;
        }
        else{
            diff = -diff;
            while(diff--)
                headB = headB->next;
        }
        while(headA && headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    
    int length(ListNode *head){
        int l = 0;
        for(; head; ++l)
            head = head->next;
        return l;
    }
};
