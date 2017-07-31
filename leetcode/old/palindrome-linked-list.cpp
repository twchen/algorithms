/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode *fast = head, *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverseList(slow);
        // ListNode *temp = slow;
        while(slow){
            if(head->val != slow->val){
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        // reverseList(temp);
        return true;
    }
    
    ListNode *reverseList(ListNode *head){
        ListNode *curr = NULL;
        while(head){
            ListNode *next = head->next;
            head->next = curr;
            curr = head;
            head = next;
        }
        return curr;
    }
};
