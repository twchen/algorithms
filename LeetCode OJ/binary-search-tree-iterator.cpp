/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        cur = root;
        if(cur != NULL){
            while(cur->left){
                s.push(cur);
                cur = cur->left;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur != NULL;
    }

    /** @return the next smallest number */
    int next() {
        int n = cur->val;
        if(cur->right){
            cur = cur->right;
            while(cur->left){
                s.push(cur);
                cur = cur->left;
            }
        }else if(!s.empty()){
            cur = s.top();
            s.pop();
        }else{
            cur = NULL;
        }
        return n;
    }

private:
    TreeNode *cur;
    stack<TreeNode*> s;
};

/*
Running time and space complexity analysis
Clearly, the time and space complexity of hasNext() are both O(1).
Time complexity of next(): traversing the whole bst tree (call next n times) will follow each pointer exactly once, and the number of pointers is O(n), so the amortized cost of next() is O(1)
Space complexity: the number of elements in the stack at any time is at most the height of the tree, so space complexity is O(h)
 */
