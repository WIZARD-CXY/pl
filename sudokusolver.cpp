class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool isValid(vector<vector<char> > &board, int x, int y){
        //check if board[x][y] already exists in the x-th row?
        for(int i=0; i<9; i++){
            if( i!=y && board[x][y]==board[x][i]){
                return false;
            }
        }
        
        //check if board[x][y] already exists in the y-th column? 
        for(int i=0; i<9; i++){
            if( i!=x && board[x][y]==board[i][y]){
                return false;
            }
        }
        
        //check if board[x][y] already exists in the small 3x3 box?
        int m=x/3*3;
        int n=y/3*3;
        
        for(int i=x/3*3; i<x/3*3+3; i++){
            for(int j=y/3*3; j<y/3*3+3; j++){
                if((i!=x || j!=y) && board[x][y]==board[i][j]){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<char> > &board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(char c='1'; c<='9'; c++){
                        board[i][j]=c;
                        if(isValid(board,i,j) && solve(board)){
                            return true;
                        }
                        board[i][j]='.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
};