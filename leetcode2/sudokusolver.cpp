class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
    
    bool isvalid(vector<vector<char> > &board, int x, int y){
        //check col
        for(int i=0; i<9; i++){
            if(i!=y){
                if(board[x][y]==board[x][i]){
                    return false;
                }
            }
        }
        
        // check row
        for(int i=0; i<9; i++){
            if(i!=x){
                if(board[x][y]==board[i][y]){
                    return false;
                }
            }
        }
        
        //check small 3x3 box
        for(int i=x/3*3; i<x/3*3+3; i++){
            for(int j=y/3*3; j<y/3*3+3; j++){
                if(x!=i && y!=j){
                    if(board[x][y]==board[i][j]){
                       return false;
                    }
                }
                
            }
        }
        
        return true;
    }
    
    bool helper(vector<vector<char>> &board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    //try the 1~9 in board[i][j]
                    for(char c='1'; c<='9'; c++){
                        board[i][j]=c;
                        if(isvalid(board,i,j) && helper(board)){
                            return true;
                        }
                    }
                    board[i][j]='.';
                    return false;
                }
            }
        }
        return true;
    }
};