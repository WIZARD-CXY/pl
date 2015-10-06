class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        if(m==0){
            return;
        }
        
        int n=board[0].size();
        if(n==0){
            return;
        }
        
        //higher 1 bit store new state, lower new bit store old bits
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count=0;
                
                for(int k=max(0,i-1); k<min(m,i+2); k++){
                    for(int l=max(0,j-1); l<min(n,j+2); l++){
                        //skip the origin cell
                        if(k==i && l==j){
                            continue;
                        }
                        
                        count+=board[k][l]&1;
                    }
                }
                
                if(board[i][j]&1){
                    // old live cell
                    if(count==3 || count ==2){
                        board[i][j] |=2;
                    }
                }else{
                    //old dead cell
                    if(count==3){
                        board[i][j] |=2;
                    }
                }
            }
        }
        
        //right shift to set to the new state
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                board[i][j]>>=1;
            }
        }
    }
};