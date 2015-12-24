/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursive
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL){
            return minDepth(root->right) + 1;
        }
        if(root->right == NULL){
            return minDepth(root->left) + 1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

// iterative using BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while(q.size()){
            int size = q.size();
            while(size--){
                TreeNode *node = q.front(); q.pop();
                if(node->left == NULL && node->right == NULL)
                    return depth;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ++depth;
        }
    }
};
