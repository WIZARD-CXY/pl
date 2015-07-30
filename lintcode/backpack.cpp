class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        int n=A.size();
        vector<vector<bool> > dp(n+1,vector<bool>(m+1,0));
        
        // dp[i][j] means whether or not we can pick from some of
        // first i element and  put it into a j sized pack
        // dp[i][j]=dp[i-1][j] || dp[i-1][j-A[i-1]]
        
        dp[0][0]=1;
        
        for(int i=1;i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j]=dp[i-1][j] || (j>=A[i-1] && dp[i-1][j-A[i-1]]);
            }
        }
        
        for(int i=m; i>=0; i--){
            if(dp[n][i]){
                return i;
            }
        }
        
        return 0;
    }
};
