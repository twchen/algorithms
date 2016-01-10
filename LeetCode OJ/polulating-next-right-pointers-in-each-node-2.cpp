/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// O(1) space, 36ms
// credits: https://leetcode.com/discuss/24398/simple-solution-using-constant-space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // curr: the current node at the current level
        // prev: the previous node at the next level
        TreeLinkNode *curr = root, *prev;
        TreeLinkNode dummy(0);
        while(curr){
            prev = &dummy;
            while(curr){
                if(curr->left){
                    prev->next = curr->left;
                    prev = prev->next;
                }
                if(curr->right){
                    prev->next = curr->right;
                    prev = prev->next;
                }
                curr = curr->next;
            }
            curr = (prev == &dummy) ? NULL : dummy.next; // or replace with the following two lines
            //curr = dummy.next;
            //dummy.next = NULL;
        }
    }
};

// O(1) space, 36ms, one while loop only
// credit: https://leetcode.com/discuss/44411/simple-40ms-c-o-n-o-1-solution-with-only-one-while-loop
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *curr = root, *prev = NULL, *head = NULL;
        // curr: the current node at the current level
        // prev: the previous node at the next level
        // head: the first node at the next level
        while(curr){
            if(curr->left){
                if(prev){
                    prev->next = curr->left;
                }else{
                    head = curr->left;
                }
                prev = curr->left;
            }
            if(curr->right){
                if(prev){
                    prev->next = curr->right;
                }else{
                    head = curr->right;
                }
                prev = curr->right;
            }
            curr = curr->next;
            if(!curr){
                curr = head;
                prev = NULL;
                head = NULL;
            }
        }
    }
};

// O(1) space, 40ms
// my solution
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *head = root, *curr;
        TreeLinkNode *p1, *p2;
        while(head){
            curr = head;
            head = getNext(curr, NULL);
            p1 = head;
            while(curr){
                p2 = getNext(curr, p1);
                p1->next = p2;
                p1 = p2;
            }
        }
    }
    
    TreeLinkNode *getNext(TreeLinkNode *&head, TreeLinkNode *prev){
        TreeLinkNode *next = NULL;
        while(head){
            if(head->left && head->left != prev){
                next = head->left;
                break;
            }
            if(head->right && head->right != prev){
                next = head->right;
                head = head->next;
                break;
            }
            head = head->next;
        }
        return next;
    }
};

// O(n) space, 40ms
// my solution
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(q.size()){
            int size = q.size();
            q.push(NULL);
            for(int i = 0; i < size; ++i){
                TreeLinkNode *curr = q.front(); q.pop();
                curr->next = q.front();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            q.pop();
        }
    }
};
