class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        
        // use dp[i][j] means the distance that words1[0...i) change to words[0,j)
        int m=word1.size();
        int n=word2.size();
        
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        
        for(int j=0; j<=n; j++){
            //insert new element to change to words2
            dp[0][j]=j;
        }
        
        for(int i=0; i<=m; i++){
            // delete element to change to empty word2
            dp[i][0]=i;
        }
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    // three way to change add, delete ,replace
                    dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+1);
                }
            }
        }
        
        return dp[m][n];
    }
};

