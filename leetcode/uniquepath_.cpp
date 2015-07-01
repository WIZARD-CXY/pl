class Solution {
public:
    int f[101];
    int uniquePaths(int m, int n) {
        memset(f,0,sizeof(f));
        f[0]=1;
        
        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                f[j]=f[j-1]+f[j];
            }
        }
        return f[n-1];
    }

};