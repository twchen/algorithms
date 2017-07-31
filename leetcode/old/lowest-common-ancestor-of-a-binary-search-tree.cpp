/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
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
/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == q)
            return p;
        auto lpath = findPath(root, p);
        auto rpath = findPath(root, q);
        auto lit = lpath->rbegin();
        auto rit = rpath->rbegin();
        for(; lit != lpath->rend() && rit != rpath->rend() && *lit == *rit; ++lit, ++rit);
        TreeNode *ret = *(--lit);
        delete lpath;
        delete rpath;
        return ret;
    }
    
    bool _findPath(TreeNode *root, TreeNode *p){
        if(root == p){
            path->push_front(p);
            return true;
        }
        if(root == NULL)
            return false;
        if(_findPath(root->left, p) || _findPath(root->right, p)){
            path->push_back(root);
            return true;
        }
        return false;
    }
    
    deque<TreeNode*> *findPath(TreeNode *root, TreeNode *p){
        path = new deque<TreeNode*>;
        _findPath(root, p);
        return path;
    }
    
    deque<TreeNode*> *path;
};
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root || p == root || q == root) return root; // assume p, q are always in the BST
       TreeNode *left = lowestCommonAncestor(root->left, p, q);
       TreeNode *right = lowestCommonAncestor(root->right, p , q);
       if (left && right) return root;
       return left ? left : right;
    }
};
