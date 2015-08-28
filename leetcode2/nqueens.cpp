class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res;
        
        vector<int> p(n); // p[i] records i-th row queen position
        vector<bool> col(n,0); //col[i]==1 indicate i-th col is used 
        vector<bool> diag(2*n,0); //diag[i-j+n];
        vector<bool> anti_diag(2*n,0); // anti_diag[i+j]
        
        helper(res,p,col,diag,anti_diag,0,n);
        
        return res;
        
    }
    
    void helper(vector<vector<string> > &res, vector<int> &p, vector<bool> &col ,vector<bool> &diag, vector<bool> &anti_diag,int cur,int n){
        // visit cur-th row
        if(cur==n){
            //meet the end
            vector<string> tmp;
            for(int i=0; i<n; i++){
                string row(n,'.');
                row[p[i]]='Q';
                tmp.push_back(row);
            }
            
            res.push_back(tmp);
            return;
        }
        
        for(int j=0; j<n; j++){
            if(col[j] || diag[cur-j+n] || anti_diag[cur+j]){
                //pos j is not ok
                continue;
            }
            
            p[cur]=j;
            col[j]=diag[cur-j+n]=anti_diag[cur+j]=1;
            helper(res,p,col,diag,anti_diag,cur+1,n);
            col[j]=diag[cur-j+n]=anti_diag[cur+j]=0;
        }
    }
};