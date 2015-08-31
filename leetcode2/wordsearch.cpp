class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool> > vis(m,vector<bool>(n,0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++ ){
                if(!vis[i][j]){
                    if(dfs(board,i,j,vis,word,0)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char> > &board, int x, int y, vector<vector<bool> > &vis, string &word, int idx){
        if(x<0 || x >=board.size() || y<0 || y>=board[0].size() || vis[x][y]){
            return false;
        }
        
        if(board[x][y]!=word[idx]){
            return false;
        }
        
        //final match
        if(idx==word.size()-1){
            return true;
        }
        
        vis[x][y]=1;
        //try to dfs the other four dirs
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        
        bool res=false;
        
        for(int i=0; i<4; i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            
            if(dfs(board,newx,newy,vis,word,idx+1)){
                return true;
            }
        }
        vis[x][y]=0;
        
        return false;
    }
};