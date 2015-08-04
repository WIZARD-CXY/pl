class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        int n=A.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }else{
                    if(j<A[i-1]){
                        dp[i][j]=dp[i-1][j];
                    }else{
                        dp[i][j]=max(dp[i-1][j],dp[i-1][j-A[i-1]]+V[i-1]);
                    }
                }
            }
        }
        
        
        return dp[n][m];
    }
};
