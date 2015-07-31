class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        int m=s1.size();
        int n=s2.size();
        int k=s3.size();
        
        if(m+n != k){
            return false;
        }
        
        //dp[i][j] means using s1[0...i) and s2[0...j) can match s3 [0,i+j-1)
        
        vector<vector<bool> > dp(m+1,vector<bool>(n+1,0));
        dp[0][0]=1;
        
        //initial the first column using only s1
        for(int i=1; i<=m; i++){
            if(s1[i-1]==s3[i-1]){
                dp[i][0]=1;
            }else{
                break;//leave all other to 0
            }
        }
        
        //initial the first row using only s2
        for(int j=1; j<=n; j++){
            if(s2[j-1]==s3[j-1]){
                dp[0][j]=1;
            }else{
                break;
            }
        }
        
        //fill the other dp
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                dp[i][j]=(s1[i-1]==s3[i-1+j] && dp[i-1][j]) || (s2[j-1]==s3[i+j-1] && dp[i][j-1]);
            }
        }
        
        return dp[m][n];
        
        
    }
};
