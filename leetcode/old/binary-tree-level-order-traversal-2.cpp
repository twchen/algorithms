/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL)
            return vector<vector<int>>();
        queue<TreeNode*> q;
        vector<vector<int>> rev;
        q.push(root);
        while(q.size()){
            int size = q.size();
            rev.push_back(vector<int>());
            auto it = rev.rbegin();
            while(size--){
                auto node = q.front(); q.pop();
                it->push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        // reverse vector;
        vector<vector<int>> ret;
        for(auto it = rev.rbegin(); it != rev.rend(); ++it){
            ret.push_back(*it);
        }
        return ret;
    }
};
