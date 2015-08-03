class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool res=false;
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        int m=board.size();
        if(m==0){
            return false;
        }
        
        int n=board[0].size();
        if(n==0){
            return false;
        }
        
        //vis matrix
        vector<vector<bool> > vis(m,vector<bool>(n,0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j]){
                    helper(board,word,0,vis,i,j);
                }
                if(res){
                    return res;
                }
            }
        }
        
        return false;
    }
    //dfs 
    void helper(vector<vector<char> > &board, string &word, int index, vector<vector<bool> > &vis , int x, int y){
        if(x<0 || x>= board.size() || y<0 || y>= board[0].size()){
            return;
        }
        
        if(vis[x][y]){
            return;
        }
        
        if(board[x][y]!=word[index]){
            // current not equal so prune
            return;
        }
        
         //currently match
        if(index==word.size()-1){
            res=true;
            return;
        }
       
        vis[x][y]=1;
        
        // use dfs to search 4 direction
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        for(int i=0; i<4; i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            
            helper(board,word,index+1,vis,xx,yy);
            if(res){
                //if res=true, prune the other direc search
                return;
            }
            
        }
        vis[x][y]=0;
    }
};
