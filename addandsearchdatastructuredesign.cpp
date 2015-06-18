class TrieNode{
public:
    bool isWord;
    TrieNode *child[26];
    
    TrieNode():isWord(false){
        for(int i=0; i<26; i++){
            child[i]=NULL;
        }
    }
};

class WordDictionary {
private:
    TrieNode *root;
public:
    WordDictionary(){
        root= new TrieNode();
    }
    ~WordDictionary()
    {
        if(root){
            delete root;
        }    
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p =root;
        
        for(int i=0; i<word.size(); i++){
            int k=word[i]-'a';
            
            if(p->child[k]==NULL){
                p->child[k]=new TrieNode();
            }
            p=p->child[k];
        }
        
        p->isWord=true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return helper(word,root);
    }
    
    bool helper(string word, TrieNode* root){
        if(!root){
            return false;
        }
        
        TrieNode *p=root;
        
        for(int i=0; i<word.size(); i++){
            if(p && word[i]!='.'){
                int k=word[i]-'a';
                p=p->child[k];
            }else if (p && word[i]=='.'){
                TrieNode *tmp=p;
                for(int j=0; j<26; j++){
                    p=tmp->child[j];
                    if(helper(word.substr(i+1),p)){
                        return true;
                    }
                }
            }else break;
        }
        if(!p){
            return false;
        }
        
        return p->isWord;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

