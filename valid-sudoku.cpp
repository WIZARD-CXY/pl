class Solution {
public:
    int count[9];
    bool isValidSudoku(vector<vector<char> > &board) {
        return isValidRow(board) && isValidCol(board) && isValidBox(board); 
        
    }
    
    bool isValidRow(vector<vector<char> > &board){
         for(int i=0; i<9;  i++){
             memset(count,0,sizeof(count));
             for(int j=0; j<9; j++){
                 if(board[i][j]=='.'){
                     continue;
                 }else{
                    if((++count[board[i][j]-'1'])>1){
                        return false;
                    }
                 }
             }
         }
         return true;
    }
    
        
    bool isValidCol(vector<vector<char> > &board){
         for(int i=0; i<9;  i++){
             memset(count,0,sizeof(count));
             for(int j=0; j<9; j++){
                 if(board[j][i]=='.'){
                     continue;
                 }else{
                    if((++count[board[j][i]-'1'])>1){
                        return false;
                    }
                 }
             }
         }
         return true;
    }
    bool isValidBox(vector<vector<char> > &board){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                memset(count,0,sizeof(count));
                
                for(int k=0; k<3; k++){
                    for(int l=0; l<3; l++){
                        if(board[3*i+k][3*j+l]=='.'){
                            continue;
                        }else{
                            if((++count[board[3*i+k][3*j+l]-'1'])>1){
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