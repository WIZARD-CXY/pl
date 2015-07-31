class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int m=A.size();
        int n=B.size();
        
        // dp[i][j] means the A[0,i) and B [0,j) the lcs's len
        
        vector<vector<int> > dp(2,vector<int>(n+1,0));
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(A[i-1]==B[j-1]){
                    dp[1][j]=dp[0][j-1]+1;
                }else{
                    dp[1][j]=max(dp[0][j],dp[1][j-1]);
                }
            }
            dp[0]=dp[1];
        }
        
        return dp[1][n];
    }
};

