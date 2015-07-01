class Solution {
public:
    
    bool dfs(vector<vector<char> > &board,string &word, int index, int i, int j,vector<vector<bool> > &vis){
        if(index==word.size()){
            return true;
        }
        
        if(i<0 || j <0 || i>=board.size() || j >= board[0].size()){
            return false; // cross the out line
        }
        
        if(vis[i][j]){
            return false;// already visited
        }
        
        if(board[i][j]!=word[index]){
            return false; // current is not equal, prune it
        }
        
        vis[i][j]=1;
        
        bool ret = dfs(board,word,index+1,i-1,j,vis) || // search up 
                   dfs(board,word,index+1,i+1,j,vis) || // search down
                   dfs(board,word,index+1,i,j-1,vis) || // search left
                   dfs(board,word,index+1,i,j+1,vis);   // search right
        vis[i][j]=0;
        
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
    
        vector<vector<bool> > vis(m,vector<bool>(n,0));
        
        for(int i=0; i<m ;i++){
            for(int j=0; j<n; j++){
                if(dfs(board,word,0,i,j,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};