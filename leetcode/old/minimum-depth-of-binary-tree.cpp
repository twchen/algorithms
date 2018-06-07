/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path
from the root node down to the nearest leaf node.
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
        queue<TreeNode*> q;
        int depth = 0;
        if(root) q.push(root);
        while(!q.empty()){
            int s = q.size();
            ++depth;
            for(int i = 0; i < s; ++i){
                TreeNode* node = q.front();
                q.pop();
                if(!node->left && !node->right) return depth;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return 0;
    }
};

// not a good solution ...
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int l_depth = numeric_limits<int>::max();
        int r_depth = numeric_limits<int>::max();
        if(root->left){
            l_depth = minDepth(root->left);
        }
        if(root->right){
            r_depth = minDepth(root->right);
        }
        return min(l_depth, r_depth) + 1;
    }
};
