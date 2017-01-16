/*
Serialization is the process of converting a data structure or object into a sequence of bits
so that it can be stored in a file or memory buffer, or transmitted across a network connection
link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on
how your serialization/deserialization algorithm should work. You just need to ensure that
a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree.
You do not necessarily need to follow this format, so please be creative and come up with
different approaches yourself.
Note: Do not use class member/global/static variables to store states.
Your serialize and deserialize algorithms should be stateless.
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string temp(5, '\0');
        temp[0] = 0x1;
        const string nil(1, '\0');
        queue<TreeNode*> q;
        stringstream ss;
        q.push(root);
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            if(cur == nullptr) ss << nil;
            else{
                int val = cur->val;
                for(int i = 1; i < 5; ++i){
                    temp[i] = (val & 0xff);
                    val >>= 8;
                }
                ss << temp;
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        queue<TreeNode**> q;
        q.push(&root);
        for(int i = 0; i < data.size(); ++i){
            auto cur_ptr = q.front(); q.pop();
            if(data[i] == '\0') *cur_ptr = nullptr;
            else{
                int val = chars_to_int(data[i+1], data[i+2], data[i+3], data[i+4])
                auto cur = new TreeNode(val);
                q.push(&(cur->left));
                q.push(&(cur->right));
                *cur_ptr = cur;
                i += 4;
            }
        }
        return root;
    }

private:
    int chars_to_int(unsigned char byte0, unsigned char byte1, unsigned char byte2, unsigned char byte3){
        return byte0 | (byte1 << 8) | (byte2 << 16) | (byte3 << 24);
    }
};
