class Solution {
public:
    int count=0;
    int totalNQueens(int n) {
        vector<bool> col(n,0);// record the col vis 
        vector<bool> diag(2*n,0); // record the diag vis
        vector<bool> anti_diag(2*n,0); // record the anti-diag vis
        //p[i] records the i-th row's queen position
        vector<int> p(n,0);
        
        helper(p,col,diag,anti_diag,0,n);
        
        return count;
    }
    
    void helper(vector<int> &p, vector<bool> &col ,vector<bool> &diag, vector<bool> &anti_diag,int cur,int n){
        // visit cur-th row
        if(cur==n){
            //meet the end
            count++;
            return;
        }
        
        for(int j=0; j<n; j++){
            if(col[j] || diag[cur-j+n] || anti_diag[cur+j]){
                //pos j is not ok
                continue;
            }
            
            p[cur]=j;
            col[j]=diag[cur-j+n]=anti_diag[cur+j]=1;
            helper(p,col,diag,anti_diag,cur+1,n);
            col[j]=diag[cur-j+n]=anti_diag[cur+j]=0;
        }
    }
};