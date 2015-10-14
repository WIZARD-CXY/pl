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
                int j;
                //meet 
                for(j=0; j<26; j++){
                    if(helper(word.substr(i+1),p->child[j])){
                        return true;
                    }
                }

                // if all the child are failed return false
                if(j==26){
                    return false;
                }
            }
            
            if(!p){
                return false;
            }
        }
       
        return p->isWord;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");