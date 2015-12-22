/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode *root, int sum){
        if(!root)
            return false;
        if(!root->left && !root->right){
            return root->val == sum;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
    /*
    // wrong answer. because a leaf is a node whose two children are null.
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        return _hasPathSum(root, sum, 0);
    }
    
    bool _hasPathSum(TreeNode *root, int sum, int parentSum){
        if(root == NULL){
            return parentSum == sum;
        }
        parentSum += root->val;
        return _hasPathSum(root->left, sum, parentSum) || _hasPathSum(root->right, sum, parentSum);
    }
    */
};
