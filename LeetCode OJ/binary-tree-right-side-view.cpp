/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root) q.push(root);
        while(!q.empty()){
            int n = q.size();
            res.push_back(q.front()->val);
            while(n--){
                auto cur = q.front(); q.pop();
                if(cur->right) q.push(cur->right);
                if(cur->left) q.push(cur->left);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        res.clear();
        dfs(root, 0);
        return res;
    }
    
    void dfs(TreeNode *root, int depth){
        if(root){
            if(depth == res.size()) res.push_back(root->val);
            dfs(root->right, depth + 1);
            dfs(root->left, depth + 1);
        }
    }

private:
    vector<int> res;
};
