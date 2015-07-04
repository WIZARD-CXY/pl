class Solution {
public:
    struct TrieNode{
        bool isWord;
        TrieNode *child[26];
        
        TrieNode():isWord(false){
            for(int i=0; i<26; i++){
                child[i]=NULL;
            }
        }
    } *root;
    
    Solution(){
        root=new TrieNode();
    }
    bool search(string s){
        TrieNode *p = root;
        for(auto &c : s){
            int i=c-'a';
            if(p->child[i]==NULL){
                return false;
            }
            p=p->child[i];
        }
        return p->isWord;
    }
    
    bool isPrefix(string s){
        TrieNode *p=root;
        
        for(auto &c: s){
            int i=c-'a';
            if(p->child[i]==NULL){
                return false;
            }
            p=p->child[i];
        }
        
        return true;
    }
    
    void insert(string s){
        TrieNode *p=root;
        
        for(auto &c: s){
            int i= c-'a';
            if(p->child[i]==NULL){
                p->child[i]=new TrieNode();
            }
            p=p->child[i];
        }    
        
        p->isWord=true;
    }
    
    void dfs(set<string> &st, string &s, vector<vector<char> > &board, int x, int y, vector<vector<bool> > &vis){
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        
        vis[x][y]=1;
        
        for(int i=0; i<4; i++){
            //search up,down,left,right directions
            int xx=x+dx[i];
            int yy=y+dy[i];
            
            if(isValid(board,xx,yy,vis)){
               s.push_back(board[xx][yy]);
               if(search(s)){
                   st.insert(s);
               }
               if(isPrefix(s)){
                   dfs(st,s,board,xx,yy,vis);
               }
               s.pop_back();
            }
        }
        vis[x][y]=0;
    }
    
    bool isValid(vector<vector<char> > &board, int i, int j, vector<vector<bool> > &vis){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || vis[i][j]){
            return false;
        }
        return true;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        
        if(words.size()==0){
            return res;
        }
        
        int m=board.size();
        if(m==0){
            return res;
        }
        int n=board[0].size();
        if(n==0){
            return res;
        }
        
        vector<vector<bool> > vis(m,vector<bool>(n,false));
        
        // insert the words into trie tree
        for(auto &word : words){
            insert(word);
        }
        
        string s;
        set<string> st;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                s.push_back(board[i][j]);
                if(search(s)){
                    st.insert(s);
                }
                if(isPrefix(s)){
                    //search the next char
                    dfs(st,s,board,i,j,vis);
                }
                s.pop_back();
            }
        }
        
        for(auto &word : st){
            res.push_back(word);
        }
        
        return res;
        
    }
};