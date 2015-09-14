class TrieNode{
public:
    bool isWord;
    TrieNode *child[26];
    
    TrieNode(){
        isWord=false;
        for(int i=0; i<26; i++){
            child[i]=NULL;
        }
    }
    
};
class Solution {
public:
    Solution(){
        root = new TrieNode();
    }
    ~Solution(){
        if(root){
            delete root;
        }
    }
    void add(string word){
        TrieNode *p=root;
        
        for(auto c : word){
            int idx=c-'a';
            if(p->child[idx]==NULL){
                p->child[idx]=new TrieNode();
            }
            p=p->child[idx];
        }
        p->isWord=true;
    }
    bool isprefix(string word){
        TrieNode *p=root;
        
        for(auto c : word){
            int idx=c-'a';
            if(p->child[idx]==NULL){
                return false;
            }
            p=p->child[idx];
        }
        return true;
    }
    
    bool search(string word){
        TrieNode *p=root;
        
        for(auto c : word){
            int idx=c-'a';
            if(p->child[idx]==NULL){
                return false;
            }
            p=p->child[idx];
        }
        return p->isWord;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> resset;
        vector<string> res;
        int m=board.size();
        if(m==0){
            return res;
        }
        
        int n=board[0].size();
        
        vector<vector<bool> > vis(m,vector<bool>(n,false));
        if(n==0){
            return res;
        }
        // search words in the trie tree
        for(auto word : words){
            add(word);
        }
        string path;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                helper(board,path,i,j,resset,vis);
            }
        }
        
        for(auto item : resset){
            res.push_back(item);
        }
        return res;
    };
    void helper(vector<vector<char> > &board, string &path, int x, int y, set<string> &res,vector<vector<bool> > &vis){
        if(x<0 || x>=board.size() || y<0 || y >=board[0].size()){
            return;
        }
        
        if(vis[x][y]){
            return;
        }
        
        if(!isprefix(path)){
            return;
        }
        
        path.push_back(board[x][y]);
        vis[x][y]=1;
        
        if(search(path)){
            //search forward no need to return
            res.insert(path);
        }
        
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        
        for(int i=0; i<4; i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            
            helper(board,path,newx,newy,res,vis);
        }
        
        vis[x][y]=0;
        path.pop_back();
    }
    TrieNode *root;
};