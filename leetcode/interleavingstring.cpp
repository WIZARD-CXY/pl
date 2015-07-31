class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int m=s1.size();
        int n=s2.size();
        int p=s3.size();
        
        if((m+n)!=p){
            return false;
        }
        
        // dp[i][j] means using s1[0,i) and s2[0,j) whether can match s3[0,i+j)
        // default all is false except dp[0][0]
        vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));
        
        dp[0][0]=true;
        // initial first column only using s1
        for(int i=1; i<=m; i++){
            if(s1[i-1]==s3[i-1]){
               dp[i][0]=true;
            }else{
                break;
            }
           
        }
        
        // initial first row only using s2
        for(int j=1; j<=n; j++){
            if(s2[j-1]==s3[j-1]){
               dp[0][j]=true;
            }else{
                break;
            }
        }
        
        // fill the other dp[i][j]
        // dp[i][j] = (s1[i-1]==s3[i+j-1] && dp[i-1][j]) ||(s2[j-1]==s3[i+j-1] && dp[i][j-1])
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                /*if(s1[i-1]==s3[i+j-1]){
                    dp[i][j]=dp[i-1][j];
                }*/
                dp[i][j] = (s1[i-1]==s3[i+j-1] && dp[i-1][j]) ||(s2[j-1]==s3[i+j-1] && dp[i][j-1]);
                /*if(s2[j-1]==s3[i+j-1]){
                    dp[i][j]= dp[i][j-1] || dp[i][j]; 
                }*/
            }
        }
        
        return dp[m][n];
    }
};