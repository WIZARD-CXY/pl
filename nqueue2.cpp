class Solution {
public:
    vector<int> columns;
    vector<int> diags;
    vector<int> anti_diags;
    int count=0;
    
    int totalNQueens(int n) {
        columns.assign(n,0);
        diags.assign(2*n,0);
        anti_diags.assign(2*n,0);
        
        vector<int> C(n,0); // C[i] indicates the i-th row's queen's location
        dfs(C,0);
        
        return count;
    }
    
    void dfs(vector<int> C, int row){
        int n=C.size();
        
        if(row==n){
            count++;
        }
        
        for(int i=0; i<n; i++){
            //try one column by one column
            int ok = (columns[i]==0) && (diags[row+i]==0) && (anti_diags[row-i+n]==0);
            
            if(!ok){
                continue;
            }
            
            C[row]=i;
            columns[i]=diags[row+i]=anti_diags[row-i+n]=1;
            
            //try next row
            dfs(C,row+1);
            columns[i]=diags[row+i]=anti_diags[row-i+n]=0;
        }
    }
};