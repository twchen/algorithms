/*
Serialization is the process of converting a data structure or object into a sequence of bits
so that it can be stored in a file or memory buffer, or transmitted across a network connection
link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction
on how your serialization/deserialization algorithm should work. You just need to ensure that a
binary search tree can be serialized to a string and this string can be deserialized to the
original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize
algorithms should be stateless.
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serialize_rec(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserialize_rec(data, 0, data.size());
    }

private:
    void serialize_rec(TreeNode* root, stringstream& ss){
        string temp(4, '\0');
        if(root){
            int val = root->val;
            for(int i = 0; i < 4; ++i){
                temp[i] = val & 0xff;
                val >>= 8;
            }
            ss << temp;
            serialize_rec(root->left, ss);
            serialize_rec(root->right, ss);
        }
    }
    
    TreeNode* deserialize_rec(const string& data, int first, int last){
        TreeNode* root = nullptr;
        if(first < last){
            int i = first;
            int val = chars_to_int(data[i], data[i+1], data[i+2], data[i+3]);
            root = new TreeNode(val);
            i += 4;
            while(i < last){
                int cur_val = chars_to_int(data[i], data[i+1], data[i+2], data[i+3]);
                if(cur_val > val) break;
                i += 4;
            }
            root->left = deserialize_rec(data, first + 4, i);
            root->right = deserialize_rec(data, i, last);
        }
        return root;
    }
    
    int chars_to_int(unsigned char byte0, unsigned char byte1, unsigned char byte2, unsigned char byte3){
        return byte0 | (byte1 << 8) | (byte2 << 16) | (byte3 << 24);
    }
};
