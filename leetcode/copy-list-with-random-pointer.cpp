/*
A linked list is given such that each node contains an additional random pointer
which could point to any node in the list or null.

Return a deep copy of the list.
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        Map m;
        if(!head) return nullptr;
        RandomListNode *copy = helper(head, m);
        m[nullptr] = nullptr;
        RandomListNode *cur = copy;
        while(cur){
            cur->random = m[head->random];
            cur = cur->next;
            head = head->next;
        }
        return copy;
    }

private:
    typedef map<RandomListNode *, RandomListNode *> Map;
    RandomListNode *helper(RandomListNode *head, Map &m){
        if(!head) return nullptr;
        RandomListNode *copy = new RandomListNode(head->label);
        copy->next = helper(head->next, m);
        m[head] = copy;
        return copy;
    }
};

// O(1) space, O(n) time
// credit: https://discuss.leetcode.com/topic/5831/2-clean-c-algorithms-without-using-extra-array-hash-table-algorithms-are-explained-step-by-step
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return nullptr;
        RandomListNode *cur, *copy, *new_head;
        // step 1: copy the list
        // the random pointer points to copy
        // the next pointer of copy points to the original random pointer
        for(cur = head; cur != nullptr; cur = cur->next){
            copy = new RandomListNode(cur->label);
            copy->next = cur->random;
            cur->random = copy;
        }
        new_head = head->random;

        // step 2: fix the random pointer of new list
        for(cur = head; cur != nullptr; cur = cur->next){
            copy = cur->random;
            copy->random = (copy->next ? copy->next->random : nullptr);
        }
        
        // step 3: separate two lists
        // i.e. fix the random pointer of the original list
        // and the next pointer of new list
        for(cur = head; cur != nullptr; cur = cur->next){
            copy = cur->random;
            cur->random = copy->next;
            copy->next = (cur->next ? cur->next->random : nullptr);
        }
        return new_head;
    }
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return nullptr;
        // step 1: duplicate nodes
        // the next pointer of current node points to the copy
        // the next pointer of the copy points to the original next
        RandomListNode *curr = head, *copy;
        while(curr){
            copy = new RandomListNode(curr->label);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // step 2: copy random links
        curr = head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        // separate lists
        // =========================================
        // method 1
        /*
        RandomListNode *new_head = head->next;
        curr = head;
        while(true){
            copy = curr->next;
            curr->next = copy->next;
            curr = curr->next;
            if(curr){
                copy->next = curr->next;
            }else{
                copy->next = nullptr;
                break;
            }
        }
        return new_head;
        */
        // method 2
        RandomListNode dummpy(0);
        copy = &dummpy;
        curr = head;
        while(curr){
            copy->next = curr->next;
            copy = copy->next;
            curr->next = copy->next;
            curr = curr->next;
        }
        return dummpy.next;
        // ==========================================
    }
};
