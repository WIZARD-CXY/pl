class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        
        if(m==0){
            return 0;
        }
        int n=matrix[0].size();
        
        if(n==0){
            return 0;
        }
        
        int maxlen=0;
        int dp[m][n];
        
        for(int i=0; i<m; i++){
            dp[i][0]=matrix[i][0]-'0';
            maxlen=max(maxlen,dp[i][0]);
        }
        
        for(int i=0; i<n; i++){
            dp[0][i]=matrix[0][i]-'0';
            maxlen=max(maxlen,dp[0][i]);
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    maxlen=max(maxlen,dp[i][j]);
                }else{
                    dp[i][j]=0;
                }
            }
        }
        
        return maxlen*maxlen;
        
    }
};