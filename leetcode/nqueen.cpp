class Solution {
public:
    vector<int> columns;
    vector<int> diags;
    vector<int> anti_diags;
    
    vector<vector<string> > res;
    
    vector<vector<string> > solveNQueens(int n) {
        columns=vector<int>(n,0);
        diags=vector<int>(2*n,0);
        anti_diags=vector<int>(2*n,0);
        
        vector<int> C(n,0); //c[i]indicate the i-th row's queen location
        dfs(C,0);
        
        return res;
    }
    
    void dfs(vector<int> C,int row){
        int n=C.size();
        if(row==n){
            //get one solution
            vector<string> sol;
            for(int i=0; i<n; i++){
                string temp=string(n,'.');
                for(int j=0; j<n; j++){
                    if(j==C[i]){
                        temp[j]='Q';
                    }
                }
                sol.push_back(temp);
            }
            res.push_back(sol);
            return;
        }
        
        for(int j=0; j<n; j++){
            //try one column by one column;
            int ok = (columns[j]==0) && (diags[row+j]==0) && (anti_diags[row-j+n]==0);
            
            if(!ok){
                continue;// not valid, try next column 
            }
            // ok set the new queen in [row][j]
            C[row]=j;
            //mark it 
            columns[j]=diags[row+j]=anti_diags[row-j+n]=1;
            dfs(C,row+1);
            // unmark it
            columns[j]=diags[row+j]=anti_diags[row-j+n]=0;
        }
    }
};