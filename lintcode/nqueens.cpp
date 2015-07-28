class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        
        // use back-track to solve
        vector<vector<string> > res;
        vector<bool> col(n,0);// record the col vis 
        vector<bool> diag(2*n,0); // record the diag vis
        vector<bool> anti_diag(2*n,0); // record the anti-diag vis
        //p[i] records the i-th row's queen position
        vector<int> p(n,0);
        
        dfs(res,p,0,n,col,diag,anti_diag);
        
        return res;
    }
    
    void dfs(vector<vector<string> > &res, vector<int> &p, int row, int n,vector<bool> &col, vector<bool> &diag, vector<bool> &anti_diag){
        if(row==n){
            // a solution is found
            vector<string> path;
            for(int i=0; i<n; i++){
                string tmp(n,'.');
                tmp[p[i]]='Q';
                path.push_back(tmp);
            }
            
            res.push_back(path);
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
            
            dfs(res,p,row+1,n,col,diag,anti_diag);
            
            col[i]=diag[row-i+n]=anti_diag[row+i]=0;
            
        }
    }
};

