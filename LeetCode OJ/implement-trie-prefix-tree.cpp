class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        children.reserve(26);
        for(int i=0; i<26; ++i)
            children[i] = nullptr;
        isLeaf = false;
    }
    
    vector<TrieNode*> children;
    bool isLeaf;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for(int i=0; i<word.size(); ++i){
            char c = word[i];
            if(cur->children[c - 'a'] == NULL)
                cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->isLeaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        for(int i=0; i<word.size() && cur != nullptr; ++i){
            char c = word[i];
            cur = cur->children[c - 'a'];
        }
        return cur != nullptr && cur->isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(int i=0; i<prefix.size() && cur != nullptr; ++i){
            char c = prefix[i];
            cur = cur->children[c - 'a'];
        }
        return cur != nullptr;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


// reuse same code and add destructor
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        children.reserve(26);
        for(int i=0; i<26; ++i)
            children[i] = nullptr;
        isLeaf = false;
    }
    
    ~TrieNode(){
        for(auto node: children)
            delete node;
    }
    vector<TrieNode*> children;
    bool isLeaf;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie(){
        delete root;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for(int i=0; i<word.size(); ++i){
            char c = word[i];
            if(cur->children[c - 'a'] == NULL)
                cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->isLeaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = find(word);
        return cur != nullptr && cur->isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

private:
    TrieNode* root;
    TrieNode *find(const string &s){
        TrieNode *cur = root;
        for(int i=0; i<s.size() && cur != nullptr; ++i)
            cur = cur->children[s[i] - 'a'];
        return cur;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");