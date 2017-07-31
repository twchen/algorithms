/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height;
        return _isBalanced(root, height);
    }
    
    bool _isBalanced(TreeNode *root, int &height){
        if(root == NULL){
            height = 0;
            return true;
        }
        int lh, rh;
        if(_isBalanced(root->left, lh) && _isBalanced(root->right, rh) && abs(lh - rh) < 2){
            height = max(lh, rh) + 1;
            return true;
        }
        return false;
    }
};
