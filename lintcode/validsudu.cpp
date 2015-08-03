class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        int m=board.size();
        
        if(m==0){
            return false;
        }
        
        int n=board[0].size();
        
        if(n==0){
            return false;
        }
        
        //valid row first
        for(int i=0; i<m; i++){
            int count[9]={0};
            for(int j=0; j<n; j++){
                if(board[i][j]!='.'){
                    if(count[board[i][j]-'1']==0){
                       count[board[i][j]-'1']=1;
                    }else{
                       //already exist
                       return false;
                    }
                }
            }
        }
        
        //valid column second
        for(int i=0; i<n; i++){
            int count[9]={0};
            for(int j=0; j<m; j++){
                if(board[j][i]!='.'){
                    if(count[board[j][i]-'1']==0){
                       count[board[j][i]-'1']=1;
                    }else{
                       //already exist
                       return false;
                    }
                }
            }
        }
        
        //valid small 3x3 matrix
        
        for(int i=0; i<n/3; i++){
            for(int j=0; j<m/3; j++){
                int count[9]={0};
                
                for(int k=0; k<3; k++){
                    for(int l=0; l<3; l++){
                        if(board[i+k][j+l]!='.'){
                            if(count[board[i+k][j+l]-'1']==0){
                               count[board[i+k][j+l]-'1']=1;
                            }else{
                               //already exist
                               return false;
                            }
                        }
                    }
                    
                }
               
            }
        }
        
        return true;
    }
};
