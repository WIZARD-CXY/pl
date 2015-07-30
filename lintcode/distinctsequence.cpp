class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        int m=S.size();
        int n=T.size();
        
        //dp[i][j] means that s[0,i) transfer to t[0,j)'s method
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        
        for(int i=0; i<=m; i++){
            dp[i][0]=1;// only one way to change to empty, delete all chars
        }
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(S[i-1]==T[j-1]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1]; //delete S[i-1] or match S[i-1] and T[j-1]
                }else{
                    dp[i][j]=dp[i-1][j];//delete S[i-1]
                }
            }
        }
        
        return dp[m][n];
    }
};

