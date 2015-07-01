class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *child[26];
    bool isWord;
    TrieNode() :isWord(false){
        for(int i=0; i<26; i++){
            child[i]=NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *p =root;
        for(int i=0; i<s.size(); i++){
            int k=s[i]-'a';
            if(!p->child[k]){
                p->child[k]= new TrieNode();
            }
            p=p->child[k];
        }
        p->isWord=true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *p =root;
        for(int i=0; i<key.size(); i++){
            int k=key[i]-'a';
            if(!p->child[k]){
                return false;
            }
            p=p->child[k];
        }
        return p->isWord;
        
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        
        for(int i=0; i<prefix.size(); i++){
            int k=prefix[i]-'a';
            if(!p->child[k]){
                return false;
            }
            p=p->child[k];
        }
        
        return true;
        
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");