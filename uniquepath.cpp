class Solution {
public:
    int f[101][101];
    int uniquePaths(int m, int n) {
        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++){
                f[i][j]=-1;
            }
        }
        
        return helper(m,n);
    }
    
    int helper(int m,int n){
        if(f[m][n]!=-1){
            return f[m][n];
        }
        
        if(m==0 || n==0){
            return 0;
        }
        if(m==1 && n==1){
            return 1;
        }
        
        f[m-1][n]=helper(m-1,n);
        f[m][n-1]=helper(m,n-1);
        
        return f[m-1][n]+f[m][n-1];
    }
};  