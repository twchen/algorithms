/*
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
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
    int countNodes(TreeNode* root) {
        int h = height(root);
        return countNodes(root, h - 1, 0);
    }

    // tail recursive
    int countNodes(TreeNode *root, int lh, int acc){
        if(!root) return acc;
        int rh = height(root->right);
        if(lh == rh)
            return countNodes(root->right, rh - 1, acc + (1 << lh));
        else
            return countNodes(root->left, lh - 1, acc + (1 << rh));
    }

    int height(TreeNode *root){
        int h = 0;
        while(root){
            root = root->left;
            ++h;
        }
        return h;
    }
};
