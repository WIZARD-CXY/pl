class TrieNode{
public:
    bool isWord;
    TrieNode *child[26];
    
    TrieNode(){
        isWord=false;
        memset(child,NULL,sizeof(child));
    }
};

class WordDictionary {
public:
    WordDictionary(){
        root =new TrieNode();
    }
    ~WordDictionary(){
        if(root){
            delete root;
        }
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p=root;
        
        for(auto c: word){
            int idx=c-'a';
            
            if(p->child[idx]==NULL){
                p->child[idx]=new TrieNode();
            }
            p=p->child[idx];
        }
        
        p->isWord=true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return helper(word,root);
    }
    
    bool helper(string word, TrieNode *root){
        if(root==NULL){
            return false;
        }
        
        TrieNode *p=root;
        
        for(int i=0; i<word.size(); i++){
            if(word[i]=='.'){
                int j;
                string wordafter=word.substr(i+1);
                for(j=0; j<26; j++){
                    // check 26 substree if one is ok is ok
                    if(helper(wordafter,p->child[j])){
                        return true;
                    }
                }
                
                if(j==26){
                    return false;
                }
            }else{
                int idx=word[i]-'a';
                if(p->child[idx]==NULL){
                    return false;
                }
                p=p->child[idx];
            }
        }
        
        return p->isWord;
    }
    
    TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");