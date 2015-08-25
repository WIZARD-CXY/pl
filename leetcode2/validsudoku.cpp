class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int count[10];
        
        //valid row by row
        for(int i=0; i<9; i++){
            memset(count,0,sizeof(count));
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    continue;
                }
                
                if((++count[board[i][j]-'0'])>1){
                    return false;
                }
            }
        }
        
        //valid col by col
        for(int i=0; i<9; i++){
            memset(count,0,sizeof(count));
            for(int j=0; j<9; j++){
                if(board[j][i]=='.'){
                    continue;
                }
                
                if((++count[board[j][i]-'0'])>1){
                    return false;
                }
            }
        }
        
        //valid matrix
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                memset(count,0,sizeof(count));
                
                for(int k=0; k<3; k++){
                    for(int l=0; l<3; l++){
                        if(board[3*i+k][3*j+l]=='.'){
                            continue;
                        }
                        
                        if((++count[board[3*i+k][3*j+l]-'0'])>1){
                            return false;
                        }
                    }
                }
                
            }
        }
        
        return true;
    }
};