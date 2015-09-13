class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isWord=false;
        memset(child,NULL,sizeof(child));
    }
    bool isWord;
    TrieNode *child[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p=root;
        
        for(auto c: word){
            int idx=c-'a';
            
            if(p->child[idx]==NULL){
                p->child[idx]=new TrieNode;
            }
            p=p->child[idx];
        }
        
        p->isWord=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p=root;
        
        for(auto c: word){
            int idx=c-'a';
            if(p->child[idx]==NULL){
                return false;
            }
            p=p->child[idx];
        }
        
        return p->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p=root;
        
        for(auto c: prefix){
            int idx=c-'a';
            if(p->child[idx]==NULL){
                return false;
            }
            p=p->child[idx];
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