/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        DFS(root, "");
        return paths;
    }
    
    void DFS(TreeNode *root, string parent_path){
        if(!root) return;
        if(!root->left && !root->right){
            paths.push_back(parent_path + to_string(root->val));
            return;
        }
        parent_path += to_string(root->val) + "->";
        DFS(root->left, parent_path);
        DFS(root->right, parent_path);
    }

private:
    vector<string> paths;
};
