class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //use bfs to color all the outer row and col to 'Y'
        int m=board.size();
        if(m==0){
            return;
        }
        
        int n=board[0].size();
        if(n==0){
            return;
        }
        
        // search board 'O' to inner board 
        // first col and last col
        for(int i=0;i<m; i++){
            if(board[i][0]=='O'){
                bfs(board,i,0);
            }
            
            if(board[i][n-1]=='O'){
                bfs(board,i,n-1);
            }
        }
        //first row and last row
        for(int j=0; j<n; j++){
            if(board[0][j]=='O'){
                bfs(board,0,j);
            }
            
            if(board[m-1][j]=='O'){
                bfs(board,m-1,j);
            }
        }
        // change unchanged 'O' to 'X'
        change(board,'O','X');
        // flip back the 'O'
        change(board,'Y','O');
    }
    void bfs(vector<vector<char> > &board, int i, int j){
        board[i][j]='Y';
        int m=board.size();
        int n=board[0].size();
        
        queue<pair<int,int> > qq;
        qq.push(make_pair(i,j));
        
        while(!qq.empty()){
            pair<int,int> now = qq.front();
            qq.pop();
            int x=now.first;
            int y=now.second;
            
            //search the other four directions
            if(x>0 && board[x-1][y]=='O'){
                qq.push(make_pair(x-1,y));
                board[x-1][y]='Y';
            }
            
            if(x<m-1 && board[x+1][y]=='O'){
                qq.push(make_pair(x+1,y));
                board[x+1][y]='Y';
            }
            
            if(y>0 && board[x][y-1]=='O'){
                qq.push(make_pair(x,y-1));
                board[x][y-1]='Y';
            }
            
            if(y<n-1 && board[x][y+1]=='O'){
                qq.push(make_pair(x,y+1));
                board[x][y+1]='Y';
            }
        }
    }
    void change(vector<vector<char> > &board, char oldchar, char newchar){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==oldchar){
                    board[i][j]=newchar;
                }
            }
        }
    }
};