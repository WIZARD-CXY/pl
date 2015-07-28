class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int count=0;
    int totalNQueens(int n) {
        // write your code here

        vector<bool> col(n,0);// record the col vis 
        vector<bool> diag(2*n,0); // record the diag vis
        vector<bool> anti_diag(2*n,0); // record the anti-diag vis
        //p[i] records the i-th row's queen position
        vector<int> p(n,0);
        
        dfs(p,0,n,col,diag,anti_diag);
        
        return count;
    }
    
    void dfs(vector<int> &p, int row, int n,vector<bool> &col, vector<bool> &diag, vector<bool> &anti_diag){
        if(row==n){
            // a solution is found
            count++;
            return;
        }
        
        for(int i=0; i<n; i++){
            //try every column left to right
            if(col[i] || diag[row-i+n] || anti_diag[row+i]){
                // not ok with the previous row queen pos
                continue;
            }
            
            p[row]=i;
            col[i]=diag[row-i+n]=anti_diag[row+i]=1;
            
            //search the next row
            
            dfs(p,row+1,n,col,diag,anti_diag);
            
            col[i]=diag[row-i+n]=anti_diag[row+i]=0;
            
        }
    }
};

