/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        stack<TreeNode*> odd, even;
        even.push(root);
        bool is_even_level = true;
        auto prev = &even, cur = &odd;
        while(!prev->empty()){
            vector<int> level;
            while(!prev->empty()){
                auto node = prev->top();
                prev->pop();
                level.push_back(node->val);
                if(is_even_level){
                    if(node->left) cur->push(node->left);
                    if(node->right) cur->push(node->right);
                }else{
                    if(node->right) cur->push(node->right);
                    if(node->left) cur->push(node->left);
                }
            }
            res.push_back(level);
            is_even_level = !is_even_level;
            swap(prev, cur);
        }
        return res;
    }
};
