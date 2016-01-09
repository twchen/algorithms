/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// O(1) space
class Solution {
public:
    // assume we can populate the next pointers at level k,
    // then we can treat the nodes at level k as a linked list connected by next pointers
    // then it is easy to populate the next pointers at level k+1 by traversing the linked list at level k
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode *head = root, *curr;
        while(head->left){
            curr = head;
            while(curr){
                curr->left->next = curr->right;
                if(curr->next){
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            head = head->left;
        }
    }
};

// O(n) space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(q.size()){
            int size = q.size();
            q.push(NULL); // a dummy NULL pointer to avoid checking whether we have reach the last node in a level
            for(int i = 0; i < size; ++i){
                TreeLinkNode *curr = q.front(); q.pop();
                curr->next = q.front();
                if(curr->left){
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            q.pop(); // pop the NULL pointer at the end;
        }
    }
};
