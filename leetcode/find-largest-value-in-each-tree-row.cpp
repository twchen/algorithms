/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> ans;
        if(root) q.push(root);
        while(q.size()){
            int n = q.size();
            int row_max = numeric_limits<int>::min();
            for(int i = 0; i < n; ++i){
                auto node = q.front();
                q.pop();
                if(row_max < node->val) row_max = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(row_max);
        }
        return ans;
    }
};
