/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined
between two nodes v and w as the lowest node in T that has both v and w as descendants
(where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is
LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the
LCA definition.
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        list<TreeNode*> p1, p2;
        findPath(root, p, p1);
        findPath(root, q, p2);
        if(p1.empty() || p2.empty()) return nullptr;
        auto it1 = p1.rbegin();
        auto it2 = p2.rbegin();
        while(it1 != p1.rend() && it2 != p2.rend() && *it1 == *it2){
            ++it1;
            ++it2;
        }
        return *(--it1);
    }

    bool findPath(TreeNode* root, TreeNode *p, list<TreeNode*>& path){
        if(root == nullptr || p == nullptr) return false;
        if(root == p || findPath(root->left, p, path) || findPath(root->right, p, path)){
            path.push_back(root);
            return true;
        }
        return false;
    }
};

// a simpler method, but a little hard to understand
// credit: https://discuss.leetcode.com/topic/18561/4-lines-c-java-python-ruby
class Solution {
public:
    // if return value is nullptr, neither p nor q is in this tree;
    // otherwise, if both p and q is in this tree, the return value is the LCA;
    // if only one of them is in this tree, the return value is the one in this tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : !right ? left : root; // if both left and right subtrees contains at least one of them, the result is root
    }
};
