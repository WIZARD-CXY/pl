//reference http://m.blog.csdn.net/blog/maverick1990/28275973
class Solution {
public:
    int n,m;
    void bfs(vector<vector<char> > &board, int x, int y){
        board[x][y]='Y';
        
        queue<pair<int,int> > qu;
        qu.push(make_pair(x,y));
        
        while(!qu.empty()){
            pair<int,int> temp=qu.front();
            qu.pop();
            
            x=temp.first;
            y=temp.second;
            
            if(x>0 && board[x-1][y]=='O'){
                qu.push(make_pair(x-1,y));
                board[x-1][y]='Y';
            }
            if(x<n-1 && board[x+1][y]=='O'){
                qu.push(make_pair(x+1,y));
                board[x+1][y]='Y';
            }
            if(y>0 && board[x][y-1]=='O'){
                qu.push(make_pair(x,y-1));
                board[x][y-1]='Y';
            }
            if(y<n-1 && board[x][y+1]=='O'){
                qu.push(make_pair(x,y+1));
                board[x][y+1]='Y';
            }
        }
        
    }
    void change(vector<vector<char> > &board, char originc, char newc){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==originc){
                    board[i][j]=newc;
                }
            }
        }
    }
    void solve(vector<vector<char>> &board) {
        n=board.size();
        if(n==0){
            return;
        }
        m=board[0].size();
        if(m==0){
            return;
        }
        
        //traverse outer column and row
        for(int i=0; i<m; i++){
            if(board[0][i]=='O'){
                bfs(board,0,i);
            }
            if(board[n-1][i]=='O'){
                bfs(board,n-1,i);
            } 
        }
        
        for(int i=0; i<n; i++){
            if(board[i][0]=='O'){
                bfs(board,i,0);
            }
            if(board[i][m-1]=='O'){
                bfs(board,i,m-1);
            }
        }
        
        change(board,'O','X');
        change(board,'Y','O');
        
    }
};