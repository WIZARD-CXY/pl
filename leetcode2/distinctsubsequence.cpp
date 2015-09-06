class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        
        //dp[i][j] means the ways s[0..i) to transfer to t[0..j)
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        
        //initial the first col
        for(int i=0; i<=m; i++){
            //only one way to get s to empty string t
            dp[i][0]=1;
        }
        
        for(int i=1; i<=m; i++){
            for(int j=n;j>=1; j--){
                if(s[i-1]==t[j-1]){
                    // match s[i-1] and t[j-1] or delete s[i-1] to match
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};