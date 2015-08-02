class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    struct TrieNode{
        bool isWord;
        TrieNode *child[26];
        
        TrieNode():isWord(false){
            for(auto c : child){
                c=NULL;
            }
        }
    };
    
    TrieNode *root;
    
    Solution(){
        root=new TrieNode;
    }
    
    void insert(string s){
        //insert a string into trie tree
        TrieNode *p=root;
        
        for(auto c : s){
            int index=c-'a';
            if(p->child[index]==NULL){
                p->child[index]=new TrieNode;
            }
            p=p->child[index];
        }
        p->isWord=true;
    }
    
    bool search(string s){
        //find a given string is in a trie or not
        TrieNode *p=root;
        
        for(auto c : s){
            int idx=c-'a';
            if(p->child[idx]==NULL){
                return false;
            }
            p=p->child[idx];
        }
        
        return p->isWord;
    }
    
    bool isPrefix(string s){
        TrieNode *p=root;
        
        for(auto c : s){
            int idx=c-'a';
            if(p->child[idx]==NULL){
                return false;
            }
            
            p=p->child[idx];
        }
        
        return true;
    }
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        vector<string> res;
        
        int m=board.size();
        
        if(m==0){
            return res;
        }
        
        int n=board[0].size();
        
        if(n==0){
            return res;
        }
        
        //vis matrix
        vector<vector<bool> > vis(m,vector<bool>(n,0));
        
        //insert every word into a trie
        for(auto word : words){
            insert(word);
        }
        
        //search start
        set<string> tmp;
        string s;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j]){
                    dfs(board,s,vis,tmp,i,j);
                }
            }
        }
        
        for(auto x : tmp){
            res.push_back(x);
        }
        
        return res;
    }
    
    bool isValid(vector<vector<char> > &board, int x, int y, vector<vector<bool> > &vis){
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || vis[x][y]){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<char> > &board, string &s, vector<vector<bool> >  &vis, set<string> &tmp,int x, int y){
        // mark as visited
        vis[x][y]=1;
        s.push_back(board[x][y]);
                
        if(search(s)){
            tmp.insert(s);
        }
        
        if(!isPrefix(s)){
            //prune
            vis[x][y]=0;
            s.pop_back();
            
            return;
        }
        
        int dx[]={0,-1,0,1};
        int dy[]={1,0,-1,0};
        
        for(int i=0; i<4; i++){
            //search right, up, left, down 4 direction
            int xx=x+dx[i];
            int yy=y+dy[i];
            
            if(isValid(board,xx,yy,vis)){
                //valid search the next;
                dfs(board,s,vis,tmp,xx,yy);
            }
        }
        
        vis[x][y]=0;
        s.pop_back();
    }
};
